#pragma once

#include "Lila/Utils/Memory.h"

namespace Lila {
	class UUID {
	public:
		UUID();

		operator unsigned long long() { return id; }

	private:
		unsigned long long id;

	};
}
