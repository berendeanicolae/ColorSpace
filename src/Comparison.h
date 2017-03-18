#ifndef COMPARISON_H
#define COMPARISON_H

#include "ColorSpace.h"

namespace ColorSpace {
	struct IComparison {
		static double Compare(IColorSpace *a, IColorSpace *b);
	};

}

#endif // COMPARISON_H

