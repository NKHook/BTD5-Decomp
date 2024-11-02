#pragma once

#include <Math/MathematicTypes/VectorDataStructures.hpp>

#include <algorithm>
#include <cmath>

namespace MATHS {
	constexpr double abs(double value) {
		return std::abs(value);
	}
	constexpr double acos(double value) {
		return std::acos(value);
	}
	constexpr float acosf(float value) {
		return std::acos(value);
	}
	constexpr double asin(double value) {
		return std::asin(value);
	}
	constexpr float asinf(float value) {
		return std::asin(value);
	}
	constexpr double atan(double value) {
		return std::atan(value);
	}
	constexpr float atanf(float value) {
		return std::atan(value);
	}
	constexpr double atan2(double y, double x) {
		return std::atan2(y, x);
	}
	constexpr double ceil(double value) {
		return std::ceil(value);
	}
	constexpr float ceilf(float value) {
		return std::ceil(value);
	}
	constexpr double clamp(double value, double min, double max) {
		return std::clamp(value, min, max);
	}
	constexpr float clampf(float value, float min, float max) {
		return std::clamp(value, min, max);
	}
	constexpr int clampi(int value, int min, int max) {
		return std::clamp(value, min, max);
	}
	constexpr double cos(double value) {
		return std::cos(value);
	}
	constexpr float cosf(float value) {
		return std::cos(value);
	}
	constexpr float DegToRad(float deg) {
		return deg * static_cast<float>(std::numbers::pi) / 180.0f;
	}
	constexpr double exp(double value) {
		return std::exp(value);
	}
	constexpr float expf(float value) {
		return std::exp(value);
	}
	constexpr float fabs(float value) {
		return std::fabs(value);
	}
	constexpr int FindNearestPowerOf2(int value) {
		if (value == 0) {
			return 1;
		}

		uint32_t result = value - 1;
		result |= result >> 1;
		result |= result >> 2;
		result |= result >> 4;
		result |= result >> 8;
		result |= result >> 16;
		result += 1;

		return static_cast<int>(result);
	}
	constexpr double floor(double value) {
		return std::floor(value);
	}
	constexpr float floorf(float value) {
		return std::floor(value);
	}
	constexpr float fmax(float a, float b) {
		return std::fmax(a, b);
	}
	constexpr float fmod(float a, float b) {
		return std::fmod(a, b);
	}
	inline float frand() {
		return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	}
	inline float invsqrt(float x) {
		float xhalf = 0.5f * x;
		int i = *(int*)&x; // Treat the float as an integer
		i = 0x5f3759df - (i >> 1); // Perform the magic number operation
		x = *(float*)&i; // Treat the integer as a float
		x = x * (1.5f - (xhalf * x * x)); // Perform the first iteration of Newton's method
		return x;
	}
	constexpr float lerp(float a, float b, float t) {
		return std::lerp(a, b, t);
	}
	inline CVec2 lerp(CVec2 a, CVec2 b, float t) {
		return a + (b - a) * t;
	}
	inline CVec3 lerp(CVec3 b, CVec3 a, float t) {
		return a + (b - a) * t;
	}
	inline CVec4 lerp(CVec4 b, CVec4 a, float t) {
		return a + (b - a) * t;
	}
	constexpr double log(double value) {
		return std::log(value);
	}
	constexpr double log10(double value) {
		return std::log10(value);
	}
	constexpr float log10f(float value) {
		return std::log10(value);
	}
	constexpr double log2(double value) {
		return std::log(value);
	}
	constexpr int log2i(int value) {
		return std::log(value);
	}
	constexpr float logf(float value) {
		return std::log(value);
	}
	constexpr double pow(double x, double y) {
		return std::pow(x, y);
	}
	constexpr float powf(float x, float y) {
		return std::pow(x, y);
	}
	constexpr float RadToDeg(float rad) {
		return rad * 180.0f / static_cast<float>(std::numbers::pi);
	}
	constexpr double round(double value) {
		return std::round(value);
	}
	constexpr float roundf(float value) {
		return std::round(value);
	}
	constexpr double sign(double value) {
		if (value > 0.0) {
			return 1.0;
		}
		if (value < 0.0) {
			return -1.0;
		}
		return 0.0;
	}
	constexpr float signf(float value) {
		if (value > 0.0f) {
			return 1.0f;
		}
		if (value < 0.0f) {
			return -1.0f;
		}
		return 0.0f;
	}
	constexpr double sin(double value) {
		return std::sin(value);
	}
	constexpr float sinf(float value) {
		return std::sin(value);
	}
	constexpr double sqrt(double value) {
		return std::sqrt(value);
	}
	constexpr float sqrtf(float value) {
		return std::sqrt(value);
	}
	constexpr double tan(double value) {
		return std::tan(value);
	}
	constexpr float tanf(float value) {
		return std::tan(value);
	}
};