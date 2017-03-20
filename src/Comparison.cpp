#include "Comparison.h"
#include <cmath>

#define SQR(x) ((x)*(x))

namespace ColorSpace {
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

		double c1 = sqrt(lab_a.a*lab_a.a + lab_a.b*lab_a.b);
		double c2 = sqrt(lab_b.a*lab_b.a + lab_b.b*lab_b.b);
		double deltaC = c1 - c2;

		double deltaH = deltaA*deltaA + deltaB*deltaB - deltaC*deltaC;
		deltaH = (deltaH < 0 ? 0 : sqrt(deltaH)); // TODO: sqrt not required https://github.com/THEjoezack/ColorMine/issues/40

		double sl = 1.0;
		double sc = 1.0 + app.k1*c1;
		double sh = 1.0 + app.k2*c1;

		deltaL /= app.kl*sl;
		deltaC /= sc;
		deltaH /= sh;

		return sqrt(SQR(deltaL) + SQR(deltaC) + SQR(deltaH));
	}

	double Cie2000Comparison::Compare(IColorSpace *a, IColorSpace *b) {
		Lab lab_a;
		Lab lab_b;

		a->To<Lab>(&lab_a);
		b->To<Lab>(&lab_b);

		return 0;
	}

	double CmcComparison::Compare(IColorSpace *a, IColorSpace *b) {
		return 0;
	}
}

