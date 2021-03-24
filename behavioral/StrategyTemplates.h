#pragma once

#include "Track.h"

namespace patterns {

class CoastStrategy {
	Track create(unsigned id) const {
		return Track{ id, TrackType::COAST };
	}
};

class HispeedStrategy {
	Track create(unsigned id) const {
		return Track{ id, TrackType::HISPEED };
	}
};

class ManualStrategy {
	Track create(unsigned id) const {
		return Track{ id, TrackType::MANUAL };
	}
};

template<typename Strategy>
class TemplateContext {
public:
	Track createTrack(unsigned id) const {
		return _behavior.create(id);
	}

private:
	Strategy _behavior;
};

}
