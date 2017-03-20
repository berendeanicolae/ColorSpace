#ifndef COMPARISON_H
#define COMPARISON_H

#include "ColorSpace.h"

namespace ColorSpace {
	struct IComparison {
		static double Compare(IColorSpace *a, IColorSpace *b);
	};

	struct Cie1976Comparison : public IComparison {
		static double Compare(IColorSpace *a, IColorSpace *b);
	};

	struct Cie94Comparison : public IComparison {
		enum APPLICATION {
			GRAPHIC_ARTS = 0,
			TEXTILES
		};

		struct Application {
			double kl, k1, k2;

			Application(APPLICATION appType);
		};

		static double Compare(IColorSpace *a, IColorSpace *b, APPLICATION appType=GRAPHIC_ARTS);
	};

	struct Cie2000Comparison : public IComparison {
		static double Compare(IColorSpace *a, IColorSpace *b);
	};

	struct CmcComparison : public IComparison {
		static double Compare(IColorSpace *a, IColorSpace *b);
	};
}

#endif // COMPARISON_H

