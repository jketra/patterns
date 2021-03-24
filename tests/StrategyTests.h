#pragma once

#include <memory>

#include <gtest/gtest.h>

#include <behavioral/Strategy.h>

namespace patterns {
namespace test {

TEST(StrategyTests, Nasledovanie) {

	Context context;

	auto track = context.createTrack(0u);
	EXPECT_EQ(track.type, TrackType::HISPEED);

	context.setBehavior(std::unique_ptr<CoastTrackBehavior>(new CoastTrackBehavior()));
	track = context.createTrack(1u);
	EXPECT_EQ(track.type, TrackType::COAST);

	context.setBehavior(std::unique_ptr<ManualTrackBehavior>(new ManualTrackBehavior()));
	track = context.createTrack(2u);
	EXPECT_EQ(track.type, TrackType::MANUAL);

	context.setBehavior(std::unique_ptr<HispedTrackBehavior>(new HispedTrackBehavior()));
	track = context.createTrack(2u);
	EXPECT_EQ(track.type, TrackType::HISPEED);
}

}
}
