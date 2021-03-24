#pragma once

namespace patterns {

enum class TrackType { COAST, HISPEED, MANUAL };

struct Track {
	unsigned id;
	TrackType type;
};

}
