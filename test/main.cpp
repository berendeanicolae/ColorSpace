#include <gtest\gtest.h>
#include "TestFixture.h"
#include "utils.h"

TEST_F(TestFixture, ColorBuild) {
}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

