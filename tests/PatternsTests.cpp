﻿#include "FactoryMethodTests.h"
#include "SingletonTests.h"
#include "StrategyTests.h"

#include <gtest/gtest.h>

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
