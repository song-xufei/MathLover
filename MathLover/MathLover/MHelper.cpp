#include "MHelper.h"

namespace MathLover {
	double doubleRound(double number, unsigned int bits) {
		std::stringstream ss;
		ss << std::fixed << std::setprecision(bits) << number;
		ss >> number;
		return number;
	}
}

