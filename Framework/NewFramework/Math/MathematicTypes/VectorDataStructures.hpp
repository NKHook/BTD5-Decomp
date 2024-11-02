#pragma once

#include <string>

class CVec2i;
class CVec2 {
public:
	constexpr CVec2() = default;
	constexpr CVec2(float x, float y);
	constexpr explicit CVec2(const CVec2i&);
	constexpr explicit CVec2(const CVec2i*);
	constexpr explicit CVec2(const std::string&);

	constexpr CVec2 operator+(const CVec2& other) const;
	constexpr CVec2 operator-(const CVec2& other) const;
	constexpr CVec2 operator*(float scalar) const;

	constexpr CVec2& operator=(const std::string& s) { set(s); return *this; }
	constexpr void set(const std::string&);

	[[nodiscard]] constexpr std::string ToString() const;

	float mX = 0.0f;
	float mY = 0.0f;
};

class CVec2i {
public:
	constexpr CVec2i() = default;
	constexpr explicit CVec2i(const CVec2&);
	constexpr explicit CVec2i(const CVec2*);
	constexpr explicit CVec2i(const std::string&);

	constexpr CVec2i& operator=(const std::string& s) { set(s); return *this; }
	constexpr void set(const std::string&);

	[[nodiscard]] constexpr std::string ToString() const;

	int mX = 0;
	int mY = 0;
};

class CVec3 {
public:
	constexpr CVec3() = default;
	constexpr CVec3(const CVec3&) = default;
	constexpr CVec3(float x, float y, float z);
	constexpr explicit CVec3(const std::string& s);

	constexpr CVec3 operator+(const CVec3& other) const;
	constexpr CVec3 operator-(const CVec3& other) const;
	constexpr CVec3 operator*(float scalar) const;
	constexpr CVec3& operator*=(float scalar);

	constexpr CVec3& operator=(const std::string& s) { set(s); return *this; }
	constexpr void set(const std::string&);

	[[nodiscard]] constexpr float Dot(const CVec3& other) const;
	[[nodiscard]] constexpr CVec3 Cross(const CVec3& other) const;
	[[nodiscard]] constexpr float Length() const;
	[[nodiscard]] constexpr CVec3 Normalize() const;

	[[nodiscard]] constexpr std::string ToString() const;

	float mX = 0.0f;
	float mY = 0.0f;
	float mZ = 0.0f;
};

class CVec4 {
public:
	constexpr CVec4() = default;
	constexpr CVec4(float x, float y, float z, float w);
	constexpr explicit CVec4(const std::string& s);

	constexpr CVec4 operator+(const CVec4& other) const;
	constexpr CVec4 operator-(const CVec4& other) const;
	constexpr CVec4 operator*(float scalar) const;

	constexpr CVec4& operator=(const std::string& s) { set(s); return *this; }
	constexpr void set(const std::string&);

	[[nodiscard]] constexpr std::string ToString() const;

	float mX = 0.0f;
	float mY = 0.0f;
	float mZ = 0.0f;
	float mW = 0.0f;
};