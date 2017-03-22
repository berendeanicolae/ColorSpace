#include "Comparison.h"
#define _USE_MATH_DEFINES
#include <cmath>

#define SQR(x) ((x)*(x))
#define DegToRad(x) ((x)*M_PI/180)

namespace ColorSpace {
	double EuclideanComparison::Compare(IColorSpace *a, IColorSpace *b) {
		Rgb rgb_a;
		Rgb rgb_b;

		a->ToRgb(&rgb_a);
		b->ToRgb(&rgb_b);

		return sqrt(SQR(rgb_a.r - rgb_b.r) + SQR(rgb_a.g - rgb_b.g) + SQR(rgb_a.b - rgb_a.b));
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
		Lab lab_a;
		Lab lab_b;

		a->To<Lab>(&lab_a);
		b->To<Lab>(&lab_b);

		// calculate ci, hi, i=1,2
		double c1 = sqrt(SQR(lab_a.a) + SQR(lab_a.b));
		double c2 = sqrt(SQR(lab_b.a) + SQR(lab_b.b));
		double meanC = (c1 + c2) / 2.0;

		double a1p = lab_a.a + lab_a.a / 2.0*(1 - sqrt(pow(meanC, 7) / (pow(meanC, 7) + pow(25, 7)))); // TODO: optimize
		double a2p = lab_b.a + lab_b.a / 2.0*(1 - sqrt(pow(meanC, 7) / (pow(meanC, 7) + pow(25, 7)))); // TODO: optimize

		c1 = sqrt(SQR(a1p) + SQR(lab_a.b));
		c2 = sqrt(SQR(a2p) + SQR(lab_b.b));
		double h1 = fmod(atan2(lab_a.b, a1p) * 180.0 / M_PI + 360.0, 360.0);
		double h2 = fmod(atan2(lab_b.b, a2p) * 180.0 / M_PI + 360.0, 360.0);

		// compute deltaL, deltaC, deltaH
		double deltaL = lab_b.l - lab_a.l;
		double deltaC = c2 - c1;
		double deltah;

		if (abs(h2 - h1) < 180) {
			deltah = h2 - h1;
		}
		else if (h2 > h1) {
			deltah = h2 - h1 - 360;
		}
		else {
			deltah = h2 - h1 + 360;
		}

		double deltaH = 2 * sqrt(c1*c2)*sin(deltah * M_PI / 180 / 2);

		// calculate CIEDE2000
		double meanL = (lab_a.l + lab_b.l) / 2;
		meanC = (c1 + c2) / 2.0;
		double meanH;

		if (abs(h1 - h2) <= 180) {
			meanH = (h1 + h2) / 2;
		}
		else if (h1 + h2 < 360) {
			meanH = (h1 + h2 + 360) / 2;
		}
		else {
			meanH = (h1 + h2 - 360) / 2;
		}

		double T = 1
			- 0.17*cos(DegToRad(meanH - 30))
			+ 0.24*cos(DegToRad(2 * meanH))
			+ 0.32*cos(DegToRad(3 * meanH + 6))
			- 0.2*cos(DegToRad(4 * meanH - 63));
		double sl = 1 + (0.015*SQR(meanL - 50)) / sqrt(20 + SQR(meanL - 50));
		double sc = 1 + 0.045*meanC;
		double sh = 1 + 0.015*meanC*T;
		double rt = -2 * sqrt(pow(meanC, 7) / (pow(meanC, 7) + pow(25, 7))) * sin(DegToRad(60 * exp(-SQR((meanH - 275) / 25))));

		return sqrt(SQR(deltaL/sl)+SQR(deltaC/sc)+SQR(deltaH/sh)+rt*deltaC/sc*deltaH/sh);
	}

	double CmcComparison::Compare(IColorSpace *a, IColorSpace *b) {
		return 0;
	}
}

