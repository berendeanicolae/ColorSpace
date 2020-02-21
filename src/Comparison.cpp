#include "Comparison.h"
#include "Utils.h"
#include <cmath>

namespace ColorSpace {
	double EuclideanComparison::Compare(IColorSpace *a, IColorSpace *b) {
		Rgb rgb_a;
		Rgb rgb_b;

		a->ToRgb(&rgb_a);
		b->ToRgb(&rgb_b);

		return sqrt(SQR(rgb_a.r - rgb_b.r) + SQR(rgb_a.g - rgb_b.g) + SQR(rgb_a.b - rgb_b.b));
	}

	double Cie1976Comparison::Compare(IColorSpace *a, IColorSpace *b) {
		Lab lab_a;
		Lab lab_b;

		a->To<Lab>(&lab_a);
		b->To<Lab>(&lab_b);

		return sqrt(SQR(lab_a.l - lab_b.l) + SQR(lab_a.a - lab_b.a) + SQR(lab_a.b - lab_b.b));
	}

	Cie94Comparison::Application::Application(Cie94Comparison::APPLICATION appType) {
		switch (appType) {
		case GRAPHIC_ARTS:
			kl = 1.0;
			k1 = 0.045;
			k2 = 0.015;
			break;
		case TEXTILES:
			kl = 2.0;
			k1 = 0.048;
			k2 = 0.014;
			break;
		}
	}

	double Cie94Comparison::Compare(IColorSpace *a, IColorSpace *b, APPLICATION appType) {
		Application app(appType);
		Lab lab_a;
		Lab lab_b;

		a->To<Lab>(&lab_a);
		b->To<Lab>(&lab_b);

		double deltaL = lab_a.l - lab_b.l;
		double deltaA = lab_a.a - lab_b.a;
		double deltaB = lab_a.b - lab_b.b;

		double c1 = sqrt(SQR(lab_a.a) + SQR(lab_a.b));
		double c2 = sqrt(SQR(lab_b.a) + SQR(lab_b.b));
		double deltaC = c1 - c2;

		double deltaH = SQR(deltaA) + SQR(deltaB) - SQR(deltaC);

		double sl = 1.0;
		double sc = 1.0 + app.k1*c1;
		double sh = 1.0 + app.k2*c1;

		deltaL /= app.kl*sl;
		deltaC /= sc;

		return sqrt(SQR(deltaL) + SQR(deltaC) + deltaH/SQR(sh));
	}

	double Cie2000Comparison::Compare(IColorSpace *a, IColorSpace *b) {
		const double eps = 1e-5;
		Lab lab_a;
		Lab lab_b;

		a->To<Lab>(&lab_a);
		b->To<Lab>(&lab_b);

		// calculate ci, hi, i=1,2
		double c1 = sqrt(SQR(lab_a.a) + SQR(lab_a.b));
		double c2 = sqrt(SQR(lab_b.a) + SQR(lab_b.b));
		double meanC = (c1 + c2) / 2.0;
		double meanC7 = POW7(meanC);

		double g = 0.5*(1 - sqrt(meanC7 / (meanC7 + 6103515625.))); // 0.5*(1-sqrt(meanC^7/(meanC^7+25^7)))
		double a1p = lab_a.a * (1 + g);
		double a2p = lab_b.a * (1 + g);

		c1 = sqrt(SQR(a1p) + SQR(lab_a.b));
		c2 = sqrt(SQR(a2p) + SQR(lab_b.b));
		double h1 = fmod(atan2(lab_a.b, a1p) + 2*M_PI, 2*M_PI);
		double h2 = fmod(atan2(lab_b.b, a2p) + 2*M_PI, 2*M_PI);

		// compute deltaL, deltaC, deltaH
		double deltaL = lab_b.l - lab_a.l;
		double deltaC = c2 - c1;
		double deltah;

		if (c1*c2 < eps) {
			deltah = 0;
		}
		if (std::abs(h2 - h1) <= M_PI) {
			deltah = h2 - h1;
		}
		else if (h2 > h1) {
			deltah = h2 - h1 - 2* M_PI;
		}
		else {
			deltah = h2 - h1 + 2 * M_PI;
		}

		double deltaH = 2 * sqrt(c1*c2)*sin(deltah / 2);

		// calculate CIEDE2000
		double meanL = (lab_a.l + lab_b.l) / 2;
		meanC = (c1 + c2) / 2.0;
		meanC7 = POW7(meanC);
		double meanH;

		if (c1*c2 < eps) {
			meanH = h1 + h2;
		}
		if (std::abs(h1 - h2) <= M_PI + eps) {
			meanH = (h1 + h2) / 2;
		}
		else if (h1 + h2 < 2*M_PI) {
			meanH = (h1 + h2 + 2*M_PI) / 2;
		}
		else {
			meanH = (h1 + h2 - 2*M_PI) / 2;
		}

		double T = 1
			- 0.17*cos(meanH - DegToRad(30))
			+ 0.24*cos(2 * meanH)
			+ 0.32*cos(3 * meanH + DegToRad(6))
			- 0.2*cos(4 * meanH - DegToRad(63));
		double sl = 1 + (0.015*SQR(meanL - 50)) / sqrt(20 + SQR(meanL - 50));
		double sc = 1 + 0.045*meanC;
		double sh = 1 + 0.015*meanC*T;
		double rc = 2 * sqrt(meanC7 / (meanC7 + 6103515625.));
		double rt = -sin(DegToRad(60 * exp(-SQR((RadToDeg(meanH) - 275) / 25)))) * rc;

		return sqrt(SQR(deltaL / sl) + SQR(deltaC / sc) + SQR(deltaH / sh) + rt * deltaC / sc * deltaH / sh);
	}


	const double CmcComparison::defaultLightness = 2.;
	const double CmcComparison::defaultChroma = 1.;
	double CmcComparison::Compare(IColorSpace *a, IColorSpace *b) {
		Lch lch_a;
		Lch lch_b;

		a->To<Lch>(&lch_a);
		b->To<Lch>(&lch_b);

		double deltaL = lch_a.l - lch_b.l;
		double deltaC = lch_a.c - lch_b.c;
		double deltaH = 0;

		double f = sqrt(POW4(lch_a.c) / (POW4(lch_a.c) + 1900));
		double t = (164 <= lch_a.h && lch_a.h <= 345) ? (0.56 + std::abs(0.2*cos(lch_a.h + 168))) : (0.36 + std::abs(0.4*cos(lch_a.h + 35)));

		double sl = (lch_a.l < 16) ? 0.511 : (0.040975*lch_a.l / (1 + 0.01765*lch_a.l));
		double sc = 0.0638*lch_a.c / (1 + 0.0131*lch_a.c) + 0.638;
		double sh = sc*(f*t + 1 - f);

		return sqrt(SQR(deltaL / (defaultLightness*sl)) + SQR(deltaC / (defaultChroma*sc)) + SQR(deltaH / sh));
	}
}

