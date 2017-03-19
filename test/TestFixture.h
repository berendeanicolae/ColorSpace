#ifndef TEST_FIXTURE_H
#define TEST_FIXTURE_H

#include <gtest/gtest.h>

class TestFixture : public ::testing::Test {
	public:
		TestFixture();
		~TestFixture();
};

#endif // TEST_FIXTURE_H

