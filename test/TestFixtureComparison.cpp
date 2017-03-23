#include "TestFixtureComparison.h"

#include <ColorSpace.h>
#include <Conversion.h>
#include <Comparison.h>
#include "utils.h"


/*
	CieDe1976 tests
*/
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


/*
	CieDe94 tests
*/
TEST_F(TestFixtureComparison, CIE94_Test1) {
	ColorSpace::Lab a(70.1, 53, -3.2);
	ColorSpace::Lab b(67.4, 47.7, -5.34);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie94Comparison::Compare(&a, &b), 3.408967));
}

/*
	CieDe200 tests generated with genCieDe2000Test.py
*/
TEST_F(TestFixtureComparison, CIE00_Test1) {
	ColorSpace::Lab a(50.0000, 2.6772, -79.7751);
	ColorSpace::Lab b(50.0000, 0.0000, -82.7485);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 2.0425));
}

TEST_F(TestFixtureComparison, CIE00_Test2) {
	ColorSpace::Lab a(50.0000, 3.1571, -77.2803);
	ColorSpace::Lab b(50.0000, 0.0000, -82.7485);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 2.8615));
}

TEST_F(TestFixtureComparison, CIE00_Test3) {
	ColorSpace::Lab a(50.0000, 2.8361, -74.0200);
	ColorSpace::Lab b(50.0000, 0.0000, -82.7485);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 3.4412));
}

TEST_F(TestFixtureComparison, CIE00_Test4) {
	ColorSpace::Lab a(50.0000, -1.3802, -84.2814);
	ColorSpace::Lab b(50.0000, 0.0000, -82.7485);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.0000));
}

TEST_F(TestFixtureComparison, CIE00_Test5) {
	ColorSpace::Lab a(50.0000, -1.1848, -84.8006);
	ColorSpace::Lab b(50.0000, 0.0000, -82.7485);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.0000));
}

TEST_F(TestFixtureComparison, CIE00_Test6) {
	ColorSpace::Lab a(50.0000, -0.9009, -85.5211);
	ColorSpace::Lab b(50.0000, 0.0000, -82.7485);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.0000));
}

TEST_F(TestFixtureComparison, CIE00_Test7) {
	ColorSpace::Lab a(50.0000, 0.0000, 0.0000);
	ColorSpace::Lab b(50.0000, -1.0000, 2.0000);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 2.3669));
}

TEST_F(TestFixtureComparison, CIE00_Test8) {
	ColorSpace::Lab a(50.0000, -1.0000, 2.0000);
	ColorSpace::Lab b(50.0000, 0.0000, 0.0000);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 2.3669));
}

TEST_F(TestFixtureComparison, CIE00_Test9) {
	ColorSpace::Lab a(50.0000, 2.4900, -0.0010);
	ColorSpace::Lab b(50.0000, -2.4900, 0.0009);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 7.1792));
}

TEST_F(TestFixtureComparison, CIE00_Test10) {
	ColorSpace::Lab a(50.0000, 2.4900, -0.0010);
	ColorSpace::Lab b(50.0000, -2.4900, 0.0010);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 7.1792));
}

TEST_F(TestFixtureComparison, CIE00_Test11) {
	ColorSpace::Lab a(50.0000, 2.4900, -0.0010);
	ColorSpace::Lab b(50.0000, -2.4900, 0.0011);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 7.2195));
}

TEST_F(TestFixtureComparison, CIE00_Test12) {
	ColorSpace::Lab a(50.0000, 2.4900, -0.0010);
	ColorSpace::Lab b(50.0000, -2.4900, 0.0012);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 7.2195));
}

TEST_F(TestFixtureComparison, CIE00_Test13) {
	ColorSpace::Lab a(50.0000, -0.0010, 2.4900);
	ColorSpace::Lab b(50.0000, 0.0009, -2.4900);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 4.8045));
}

TEST_F(TestFixtureComparison, CIE00_Test14) {
	ColorSpace::Lab a(50.0000, -0.0010, 2.4900);
	ColorSpace::Lab b(50.0000, 0.0010, -2.4900);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 4.8045));
}

TEST_F(TestFixtureComparison, CIE00_Test15) {
	ColorSpace::Lab a(50.0000, -0.0010, 2.4900);
	ColorSpace::Lab b(50.0000, 0.0011, -2.4900);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 4.7461));
}

TEST_F(TestFixtureComparison, CIE00_Test16) {
	ColorSpace::Lab a(50.0000, 2.5000, 0.0000);
	ColorSpace::Lab b(50.0000, 0.0000, -2.5000);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 4.3065));
}

TEST_F(TestFixtureComparison, CIE00_Test17) {
	ColorSpace::Lab a(50.0000, 2.5000, 0.0000);
	ColorSpace::Lab b(73.0000, 25.0000, -18.0000);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 27.1492));
}

TEST_F(TestFixtureComparison, CIE00_Test18) {
	ColorSpace::Lab a(50.0000, 2.5000, 0.0000);
	ColorSpace::Lab b(61.0000, -5.0000, 29.0000);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 22.8977));
}

TEST_F(TestFixtureComparison, CIE00_Test19) {
	ColorSpace::Lab a(50.0000, 2.5000, 0.0000);
	ColorSpace::Lab b(56.0000, -27.0000, -3.0000);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 31.9030));
}

TEST_F(TestFixtureComparison, CIE00_Test20) {
	ColorSpace::Lab a(50.0000, 2.5000, 0.0000);
	ColorSpace::Lab b(58.0000, 24.0000, 15.0000);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 19.4535));
}

TEST_F(TestFixtureComparison, CIE00_Test21) {
	ColorSpace::Lab a(50.0000, 2.5000, 0.0000);
	ColorSpace::Lab b(50.0000, 3.1736, 0.5854);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.0000));
}

TEST_F(TestFixtureComparison, CIE00_Test22) {
	ColorSpace::Lab a(50.0000, 2.5000, 0.0000);
	ColorSpace::Lab b(50.0000, 3.2972, 0.0000);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.0000));
}

TEST_F(TestFixtureComparison, CIE00_Test23) {
	ColorSpace::Lab a(50.0000, 2.5000, 0.0000);
	ColorSpace::Lab b(50.0000, 1.8634, 0.5757);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.0000));
}

TEST_F(TestFixtureComparison, CIE00_Test24) {
	ColorSpace::Lab a(50.0000, 2.5000, 0.0000);
	ColorSpace::Lab b(50.0000, 3.2592, 0.3350);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.0000));
}

TEST_F(TestFixtureComparison, CIE00_Test25) {
	ColorSpace::Lab a(60.2574, -34.0099, 36.2677);
	ColorSpace::Lab b(60.4626, -34.1751, 39.4387);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.2644));
}

TEST_F(TestFixtureComparison, CIE00_Test26) {
	ColorSpace::Lab a(63.0109, -31.0961, -5.8663);
	ColorSpace::Lab b(62.8187, -29.7946, -4.0864);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.2630));
}

TEST_F(TestFixtureComparison, CIE00_Test27) {
	ColorSpace::Lab a(61.2901, 3.7196, -5.3901);
	ColorSpace::Lab b(61.4292, 2.2480, -4.9620);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.8731));
}

TEST_F(TestFixtureComparison, CIE00_Test28) {
	ColorSpace::Lab a(35.0831, -44.1164, 3.7933);
	ColorSpace::Lab b(35.0232, -40.0716, 1.5901);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.8645));
}

TEST_F(TestFixtureComparison, CIE00_Test29) {
	ColorSpace::Lab a(22.7233, 20.0904, -46.6940);
	ColorSpace::Lab b(23.0331, 14.9730, -42.5619);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 2.0373));
}

TEST_F(TestFixtureComparison, CIE00_Test30) {
	ColorSpace::Lab a(36.4612, 47.8580, 18.3852);
	ColorSpace::Lab b(36.2715, 50.5065, 21.2231);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.4146));
}

TEST_F(TestFixtureComparison, CIE00_Test31) {
	ColorSpace::Lab a(90.8027, -2.0831, 1.4410);
	ColorSpace::Lab b(91.1528, -1.6435, 0.0447);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.4441));
}

TEST_F(TestFixtureComparison, CIE00_Test32) {
	ColorSpace::Lab a(90.9257, -0.5406, -0.9208);
	ColorSpace::Lab b(88.6381, -0.8985, -0.7239);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 1.5381));
}

TEST_F(TestFixtureComparison, CIE00_Test33) {
	ColorSpace::Lab a(6.7747, -0.2908, -2.4247);
	ColorSpace::Lab b(5.8714, -0.0985, -2.2286);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 0.6377));
}

TEST_F(TestFixtureComparison, CIE00_Test34) {
	ColorSpace::Lab a(2.0776, 0.0795, -1.1350);
	ColorSpace::Lab b(0.9033, -0.0636, -0.5514);

	ASSERT_TRUE(nearlyEqual(ColorSpace::Cie2000Comparison::Compare(&a, &b), 0.9082));
}

