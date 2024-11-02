#include "VectorDataStructures.hpp"

#include <Utilities/Logging.hpp>
#include <Utilities/StringHelper.hpp>

#include <cmath>

// some error messages contain line numbers, so I want to use them where I see them.
// that way I can have a more accurate decompilation
#define ENFORCE_LINE(expected) static_assert(__LINE__ == (expected), "This must be at line " #expected)

constexpr CVec2::CVec2(float x, float y) : mX{x}, mY{y} {}
constexpr CVec2::CVec2(const CVec2i& vec) : mX(static_cast<float>(vec.mX)), mY(static_cast<float>(vec.mY)) {}
constexpr CVec2::CVec2(const CVec2i* vec) : mX(static_cast<float>(vec->mX)), mY(static_cast<float>(vec->mY)) {}
constexpr CVec2::CVec2(const std::string& s) {
	set(s);
}

constexpr CVec2 CVec2::operator+(const CVec2& other) const {
	return { mX + other.mX, mY + other.mY };
}

constexpr CVec2 CVec2::operator-(const CVec2& other) const {
	return { mX - other.mX, mY - other.mY };
}

constexpr CVec2 CVec2::operator*(float scalar) const {
	return { mX * scalar, mY * scalar };
}

// Large empty space for other code.
// I know there should be other code here, just don't know what it is
















































constexpr void CVec2::set(const std::string& s) {
	std::vector<std::string> tokens;
	StringHelper::Explode(s, ",", &tokens);
	if (tokens.size() != 2) {
		// We know this needs to be on line 86 (thanks to error messages)
		LOG_ERROR("Incorrect number of components (%d) in string \'%s\'.", tokens.size(), s.c_str());
		ENFORCE_LINE(87);
		return;
	}
	mX = static_cast<float>(std::atof(tokens[0].c_str())); // NOLINT(*-err34-c)
	mY = static_cast<float>(std::atof(tokens[1].c_str())); // NOLINT(*-err34-c)
}

constexpr std::string CVec2::ToString() const {
	return StringHelper::Format("%f,%f", mX, mY);
}

constexpr CVec2i::CVec2i(const CVec2& vec) : mX(static_cast<int>(vec.mX)), mY(static_cast<int>(vec.mY)) {}
constexpr CVec2i::CVec2i(const CVec2* vec) : mX(static_cast<int>(vec->mX)), mY(static_cast<int>(vec->mY)) {}
constexpr CVec2i::CVec2i(const std::string& s) {
	set(s);
}

constexpr void CVec2i::set(const std::string& s) {
	std::vector<std::string> tokens;
	StringHelper::Explode(s, ",", &tokens);
	if (tokens.size() != 2) {
		LOG_ERROR("Incorrect number of components (%d) in string \'%s\'.", tokens.size(), s.c_str());
		return;
	}
	mX = std::atoi(tokens[0].c_str());
	mY = std::atoi(tokens[1].c_str());
}

constexpr std::string CVec2i::ToString() const {
	return StringHelper::Format("%d,%d", mX, mY);
}

constexpr CVec3::CVec3(float x, float y, float z) : mX{x}, mY{y}, mZ{z} {}
constexpr CVec3::CVec3(const std::string& s) {
	set(s);
}

constexpr CVec3 CVec3::operator+(const CVec3& other) const {
	return { mX + other.mX, mY + other.mY, mZ + other.mZ };
}

constexpr CVec3 CVec3::operator-(const CVec3& other) const {
	return { mX - other.mX, mY - other.mY, mZ - other.mZ };
}

constexpr CVec3 CVec3::operator*(float scalar) const {
	return { mX * scalar, mY * scalar, mZ * scalar };
}

constexpr CVec3& CVec3::operator*=(float scalar) {
	mX *= scalar;
	mY *= scalar;
	mZ *= scalar;
	return *this;
}

constexpr float CVec3::Dot(const CVec3& other) const {
	return mX * other.mX + mY * other.mY + mZ * other.mZ;
}

constexpr CVec3 CVec3::Cross(const CVec3& other) const {
	return { mY * other.mZ - mZ * other.mY, mZ * other.mX - mX * other.mZ, mX * other.mY - mY * other.mX };
}

constexpr CVec3 CVec3::Normalize() const {
	auto factor = 1.0f / Length();
	return *this * factor;
}

constexpr void CVec3::set(const std::string& s) {
	std::vector<std::string> tokens;
	StringHelper::Explode(s, ",", &tokens);
	if (tokens.size() != 3) {
		LOG_ERROR("Incorrect number of components (%d) in string \'%s\'.", tokens.size(), s); // We know this needs to be on line 145 (thanks to error messages)
		ENFORCE_LINE(146);
		return;
	}
	mX = static_cast<float>(std::atof(tokens[0].c_str())); // NOLINT(*-err34-c)
	mY = static_cast<float>(std::atof(tokens[1].c_str())); // NOLINT(*-err34-c)
	mZ = static_cast<float>(std::atof(tokens[2].c_str())); // NOLINT(*-err34-c)
}

constexpr float CVec3::Length() const {
	return std::sqrt(mX * mX + mY * mY + mZ * mZ);
}

constexpr std::string CVec3::ToString() const {
	return StringHelper::Format("%f,%f,%f", mX, mY, mZ);
}

constexpr CVec4::CVec4(const float x, const float y, const float z, const float w) : mX{x}, mY{y}, mZ{z}, mW{w} {}
constexpr CVec4::CVec4(const std::string& s) {
	set(s);
}

constexpr CVec4 CVec4::operator+(const CVec4& other) const {
	return { mX + other.mX, mY + other.mY, mZ + other.mZ, mW + other.mW };
}

constexpr CVec4 CVec4::operator-(const CVec4& other) const {
	return { mX - other.mX, mY - other.mY, mZ - other.mZ, mW - other.mW };
}

constexpr CVec4 CVec4::operator*(float scalar) const {
	return { mX * scalar, mY * scalar, mZ * scalar, mW * scalar };
}

constexpr void CVec4::set(const std::string& s) {
	std::vector<std::string> tokens;
	StringHelper::Explode(s, ",", &tokens);
	if (tokens.size() != 4) {
		LOG_ERROR("Incorrect number of components (%d) in string \'%s\'.", tokens.size(), s);
		return;
	}
	mX = static_cast<float>(std::atof(tokens[0].c_str())); // NOLINT(*-err34-c)
	mY = static_cast<float>(std::atof(tokens[1].c_str())); // NOLINT(*-err34-c)
	mZ = static_cast<float>(std::atof(tokens[2].c_str())); // NOLINT(*-err34-c)
	mW = static_cast<float>(std::atof(tokens[3].c_str())); // NOLINT(*-err34-c)
}

constexpr std::string CVec4::ToString() const {
	return StringHelper::Format("%f,%f,%f,%f", mX, mY, mZ, mW);
}

