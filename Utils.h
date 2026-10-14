#pragma once

#include <cmath>
namespace aie {
	const float MAX_FLOAT_DELTA = 0.0001f;

    inline bool ApproximatelyEquals(float A, float B, float Threshold = 0.0001f)
    {
        return std::abs(A - B) < Threshold;
    }
}