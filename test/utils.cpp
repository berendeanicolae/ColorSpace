#include "utils.h"
#include <limits>
#include <algorithm>

/*
Floating point comparison function adapted from
http://floating-point-gui.de/errors/comparison/
*/
bool nearlyEqual(double a, double b) {
	const double eps = 1e-2;
	double absA = abs(a);
	double absB = abs(b);
	double diff = abs(a - b);

	if (a == b) {
		return true;
	}
	if (a == 0 || b == 0 || absA+absB<std::numeric_limits<double>::epsilon()) {
		return diff < eps*std::numeric_limits<double>::epsilon();
	}
	return (diff / std::min(absA + absB, std::numeric_limits<double>::max())) < eps;
}

