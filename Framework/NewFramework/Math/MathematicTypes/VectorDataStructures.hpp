#pragma once

#include <string>

class CVec2i;
class CVec2 {
public:
	CVec2() = default;
	explicit CVec2(const CVec2i&);
	explicit CVec2(const std::string&);

	CVec2& operator=(const std::string& s) { set(s); return *this; }
	void set(const std::string&);

	[[nodiscard]] std::string ToString() const;

	float mX = 0.0f;
	float mY = 0.0f;
};

class CVec2i {
public:
	int mX = 0;
	int mY = 0;
};

class CVec3 {
public:
	float mX = 0.0f;
	float mY = 0.0f;
	float mZ = 0.0f;
};