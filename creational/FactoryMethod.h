#pragma once

#include <cassert>
#include <cstddef>

#include <array>
#include <memory>

namespace patterns {
namespace fm {

enum class TrackState { INIT, MAIN };

class Track {
public:
	static std::unique_ptr<Track> create(TrackState trackState, unsigned id);

	unsigned id() const {
		return _id;
	}

	virtual size_t stateVectorDemention() const = 0;

	virtual ~Track() = default;

protected:
	Track(unsigned id) :
		_id{ id } {
	}

	unsigned _id;
};

class MainTrack : public Track {
public:
	MainTrack(unsigned id) :
		Track{ id },
		_stateVector{ 0, 0, 0, 0 } {
	}

	virtual size_t stateVectorDemention() const override {
		return _stateVector.size();
	}

private:
	std::array<int, 4u> _stateVector;
};

class InitialTrack : public Track {
public:
	InitialTrack(unsigned id) :
		Track{ id },
		_stateVector{ 0, 0, 0 } {
	}

	virtual size_t stateVectorDemention() const override {
		return _stateVector.size();
	}

private:
	std::array<int, 3u> _stateVector;
};

std::unique_ptr<Track> Track::create(TrackState trackState, unsigned id) {
	switch (trackState) {
	case TrackState::INIT:
		return std::make_unique<InitialTrack>(id);
	case TrackState::MAIN:
		return std::make_unique<MainTrack>(id);
	default:
		assert(false);
	}

	return std::unique_ptr<Track>(nullptr);
}

}
}
