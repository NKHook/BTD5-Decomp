#pragma once

#include <Math/MathematicTypes/VectorDataStructures.hpp>

#include <array>

class CMatrix {
public:
	void Identity();
    bool Inverse(CMatrix& result) const;
    void LoadLookAt(const CVec3& eye, const CVec3& center, const CVec3& up);
    void LoadOrthographic(float left, float right, float bottom, float top, float near, float far);
    void LoadPerspective(float fovy, float aspect, float near, float far, bool isRadians);
	void MultiplyPoint(const CVec2& point, CVec2& result) const;
	void MultiplyPoint2f(const float* point, float* result) const;

	bool operator!=(const CMatrix& other) const;
	CMatrix operator*(const CMatrix& other) const;
    CVec4 operator*(const CVec4& vec) const;
	CVec3 operator*(const CVec3& vec) const;
	CVec2 operator*(const CVec2& vec) const;
	CMatrix& operator*=(const CMatrix& other);
	CMatrix& operator*=(float scalar);
    CMatrix operator+(const CMatrix& other) const;
	CMatrix& operator+=(const CMatrix& other);
    CMatrix operator-() const;
    CMatrix operator-(const CMatrix& other) const;
    CMatrix& operator-=(const CMatrix& other);
    CMatrix& operator=(const CMatrix& other);
    bool operator==(const CMatrix& other) const;

    void PostMultiply(const CMatrix& other);
    void PreMultiply(const CMatrix& other);
    void Reset(const CVec3& vec, float angle);
    void Reset(const CVec2& vec, float angle);
    void Rotate(float angle, const CVec3& axis);
    void RotateZ(float angle);
    void RotX(float angle);
    void RotY(float angle);
    void RotZ(float angle);
    void Scale(const CVec3& scale);
    void Scale(const CVec2& scale);
	void Set(float m00, float m01, float m02, float m03,
	     float m10, float m11, float m12, float m13,
	     float m20, float m21, float m22, float m23,
	     float m30, float m31, float m32, float m33);
	void Skew(const CVec2& skew);
    [[nodiscard]] std::string ToString() const;
    void Translate(const CVec3& translation);
    void Translate(const CVec2& translation);
    [[nodiscard]] CMatrix Transpose() const;
    [[nodiscard]] CVec3 UnProject(const CVec2& screenPos, float depth, const CVec2& viewport, const CMatrix& projMatrix) const;
private:
	std::array<float, 16> mData{}; // Assuming the matrix is a 4x4 matrix stored in a 1D array
};
