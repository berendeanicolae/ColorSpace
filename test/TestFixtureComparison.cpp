#include "TestFixtureComparison.h"

#include <ColorSpace.h>
#include <Conversion.h>
#include <Comparison.h>
#include <algorithm>

bool nearlyEqual(double a, double b) { //http://floating-point-gui.de/errors/comparison/
	const double eps = 1e-2;
	double absA = abs(a);
	double absB = abs(b);
	double diff = abs(a - b);

	if (a == b) {
		return true;
	}
	if (a == 0 || b == 0 || diff<std::numeric_limits<double>::epsilon()) {
		return diff < eps*std::numeric_limits<double>::epsilon();
	}
	return (diff / std::min(absA + absB, std::numeric_limits<double>::max())) < eps;
}

TEST_F(TestFixtureComparison, CIE1976_Test1) {
	ColorSpace::Rgb rgb(140, 130, 23);
	ColorSpace::Rgb a, b;

	a.Initialize(&rgb);
	b.Initialize(&rgb);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie1976Comparison::Compare(&a, &b), 0));
}
TEST_F(TestFixtureComparison, CIE1976_Test2) {
	ColorSpace::Lab a(50, 67, 88);
	ColorSpace::Lab b(50, 15, 22);
	
	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie1976Comparison::Compare(&a, &b), 84.0238));
}
TEST_F(TestFixtureComparison, CIE1976_Test3) {
	ColorSpace::Lab a(88.17, 67, 88);
	ColorSpace::Lab b(87.16, 65, 66);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie1976Comparison::Compare(&a, &b), 22.1138));
}


TEST_F(TestFixtureComparison, CIE94_Test1) {
	ColorSpace::Lab a(70.1, 53, -3.2);
	ColorSpace::Lab b(67.4, 47.7, -5.34);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie94Comparison::Compare(&a, &b), 3.408967));
}



TEST_F(TestFixtureComparison, CIE00_Test1) {
	ColorSpace::Lab a(50, 2.6772, -79.7751);
	ColorSpace::Lab b(50, 0, -82.7485);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 2.0425));
}



