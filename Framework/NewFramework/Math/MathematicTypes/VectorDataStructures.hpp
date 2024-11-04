#pragma once

#include <string>

class CVec2i;
class CVec2 {
public:
	constexpr CVec2() = default;
	CVec2(float x, float y);
	explicit CVec2(const CVec2i&);
	explicit CVec2(const CVec2i*);
	explicit CVec2(const std::string&);

	CVec2 operator+(const CVec2& other) const {
		return { mX + other.mX, mY + other.mY };
	}
	CVec2 operator-(const CVec2& other) const {
		return { mX - other.mX, mY - other.mY };
	}
	CVec2 operator*(float scalar) const {
		return { mX * scalar, mY * scalar };
	}

	CVec2& operator=(const std::string& s) { set(s); return *this; }
	void set(const std::string&);

	[[nodiscard]] std::string ToString() const;

	float mX = 0.0f;
	float mY = 0.0f;
};

class CVec2i {
public:
	constexpr CVec2i() = default;
	constexpr explicit CVec2i(const CVec2&);
	constexpr explicit CVec2i(const CVec2*);
	constexpr explicit CVec2i(const std::string&);

	CVec2i& operator=(const std::string& s) { set(s); return *this; }
	void set(const std::string&);

	[[nodiscard]] std::string ToString() const;

	int mX = 0;
	int mY = 0;
};

class CVec3 {
public:
	constexpr CVec3() = default;
	constexpr CVec3(const CVec3&) = default;
	CVec3(float x, float y, float z);
	explicit CVec3(const std::string& s);

	CVec3 operator+(const CVec3& other) const {
		return { mX + other.mX, mY + other.mY, mZ + other.mZ };
	}
	CVec3 operator-(const CVec3& other) const {
		return { mX - other.mX, mY - other.mY, mZ - other.mZ };
	}
	CVec3 operator*(float scalar) const {
		return { mX * scalar, mY * scalar, mZ * scalar };
	}
	CVec3& operator*=(float scalar) {
		mX *= scalar;
		mY *= scalar;
		mZ *= scalar;
		return *this;
	}

	CVec3& operator=(const std::string& s) { set(s); return *this; }
	void set(const std::string&);

	[[nodiscard]] float Dot(const CVec3& other) const;
	[[nodiscard]] CVec3 Cross(const CVec3& other) const;
	[[nodiscard]] float Length() const;
	[[nodiscard]] CVec3 Normalize() const;

	[[nodiscard]] std::string ToString() const;

	float mX = 0.0f;
	float mY = 0.0f;
	float mZ = 0.0f;
};

class CVec4 {
public:
	constexpr CVec4() = default;
	CVec4(float x, float y, float z, float w);
	explicit CVec4(const std::string& s);

	CVec4 operator+(const CVec4& other) const {
		return { mX + other.mX, mY + other.mY, mZ + other.mZ, mW + other.mW };
	}

	CVec4 operator-(const CVec4& other) const {
		return { mX - other.mX, mY - other.mY, mZ - other.mZ, mW - other.mW };
	}

	CVec4 operator*(float scalar) const {
		return { mX * scalar, mY * scalar, mZ * scalar, mW * scalar };
	}

	CVec4& operator=(const std::string& s) { set(s); return *this; }
	void set(const std::string&);

	[[nodiscard]] std::string ToString() const;

	float mX = 0.0f;
	float mY = 0.0f;
	float mZ = 0.0f;
	float mW = 0.0f;
};