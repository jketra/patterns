#pragma once

#include <iostream>
#include <memory>

#include "Track.h"

namespace patterns {

class ITrackBehavior {
public:
	virtual Track create(unsigned id) const = 0;
	virtual ~ITrackBehavior() = default;
};

class ManualTrackBehavior : public ITrackBehavior {
public:
	Track create(unsigned id) const override {
		return Track{id, TrackType::MANUAL};
	}

	~ManualTrackBehavior() {
		std::cout << "Del ManualTrackBehavior" << std::endl;
	}
};

class CoastTrackBehavior : public ITrackBehavior {
public:
	Track create(unsigned id) const override {
		return Track{ id, TrackType::COAST };
	}

	~CoastTrackBehavior() {
		std::cout << "Del CoastTrackBehavior" << std::endl;
	}
};

class HispedTrackBehavior : public ITrackBehavior {
public:
	Track create(unsigned id) const override {
		return Track{ id, TrackType::HISPEED };
	}

	~HispedTrackBehavior() {
		std::cout << "Del HispedTrackBehavior" << std::endl;
	}
};

class Context {
public:
	Context() :
		_behavior(new HispedTrackBehavior()) {
	}

	void setBehavior(std::unique_ptr<ITrackBehavior> behavior) {
		_behavior.swap(behavior);
	}

	Track createTrack(unsigned id) const {
		return _behavior->create(id);
	}

private:
	std::unique_ptr<ITrackBehavior> _behavior;
};

}
