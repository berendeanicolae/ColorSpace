#include <ColorSpace.h>
#include <Comparison.h>
#include <gtest/gtest.h>

#include "TestFixture.h"
#include "utils.h"


TEST_F(TestFixture, ColorConversion) {
	ColorSpace::Rgb a(0, 0, 0);
	ColorSpace::Rgb b(255, 255, 255);

	PRINTF("%g\n", ColorSpace::Cie1976Comparison::Compare(&a, &b));
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

