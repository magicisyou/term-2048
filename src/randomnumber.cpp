#include "randomnumber.hpp"
#include <random>
#include <chrono>

namespace Random {
	unsigned int seed{static_cast<unsigned int>
	(std::chrono::steady_clock::now().time_since_epoch().count())};
	std::mt19937 mt{seed};
}

// Get a random int between the min and max including both
int Random::get(int min, int max) {
	std::uniform_int_distribution rand{min, max};
	return rand(mt);
}
