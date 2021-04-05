#pragma once

#include <gtest/gtest.h>

#include <creational/FactoryMethod.h>

namespace patterns {
namespace test {

TEST(FactoryMethodTests, ParametrizedStaticMethod) {

	auto initialTrack = fm::Track::create(fm::TrackState::INIT, 1u);
	EXPECT_EQ(initialTrack->id(), 1u);
	EXPECT_EQ(initialTrack->stateVectorDemention(), 3u);

	auto mainTrack = fm::Track::create(fm::TrackState::MAIN, 2u);
	EXPECT_EQ(mainTrack->id(), 2u);
	EXPECT_EQ(mainTrack->stateVectorDemention(), 4u);
}

}
}
