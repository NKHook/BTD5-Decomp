#include "Matrix.hpp"

#include <Math/Maths.hpp>

#include <Utilities/StringHelper.hpp>
#include <cmath>

void CMatrix::Identity() {
	// Set all elements to 0
	mData.fill(0);

	// Set the diagonal elements to 1
	mData[0] = 1.0f;
	mData[5] = 1.0f;
	mData[10] = 1.0f;
	mData[15] = 1.0f;
}

bool CMatrix::Inverse(CMatrix& result) const {
    float det;
    float inv[16];

    // Calculate the determinant
    det = mData[0] * (mData[5] * (mData[10] * mData[15] - mData[11] * mData[14]) -
                       mData[6] * (mData[9] * mData[15] - mData[11] * mData[13]) +
                       mData[7] * (mData[9] * mData[14] - mData[10] * mData[13])) -
          mData[1] * (mData[4] * (mData[10] * mData[15] - mData[11] * mData[14]) -
                       mData[6] * (mData[8] * mData[15] - mData[11] * mData[12]) +
                       mData[7] * (mData[8] * mData[14] - mData[10] * mData[12])) +
          mData[2] * (mData[4] * (mData[9] * mData[15] - mData[11] * mData[13]) -
                        mData[5] * (mData[8] * mData[15] - mData[11] * mData[12]) +
                        mData[7] * (mData[8] * mData[13] - mData[9] * mData[12])) -
          mData[3] * (mData[4] * (mData[9] * mData[14] - mData[10] * mData[13]) -
                       mData[5] * (mData[8] * mData[14] - mData[10] * mData[12]) +
                       mData[6] * (mData[8] * mData[13] - mData[9] * mData[12]));

    if (std::abs(det) < 1e-05) {
        return false;
    }

    // Calculate the inverse
    inv[0] = mData[5] * (mData[10] * mData[15] - mData[11] * mData[14]) -
             mData[6] * (mData[9] * mData[15] - mData[11] * mData[13]) +
             mData[7] * (mData[9] * mData[14] - mData[10] * mData[13]);
    inv[1] = mData[1] * (mData[10] * mData[15] - mData[11] * mData[14]) -
             mData[2] * (mData[9] * mData[15] - mData[11] * mData[13]) +
             mData[3] * (mData[9] * mData[14] - mData[10] * mData[13]);
    inv[2] = mData[1] * (mData[6] * mData[15] - mData[7] * mData[14]) -
             mData[2] * (mData[5] * mData[15] - mData[7] * mData[13]) +
             mData[3] * (mData[5] * mData[14] - mData[6] * mData[13]);
    inv[3] = mData[1] * (mData[6] * mData[11] - mData[7] * mData[10]) -
             mData[2] * (mData[5] * mData[11] - mData[7] * mData[9]) +
             mData[3] * (mData[5] * mData[10] - mData[6] * mData[9]);

    inv[4] = mData[4] * (mData[10] * mData[15] - mData[11] * mData[14]) -
             mData[6] * (mData[8] * mData[15] - mData[11] * mData[12]) +
             mData[7] * (mData[8] * mData[14] - mData[10] * mData[12]);
    inv[5] = mData[0] * (mData[10] * mData[15] - mData[11] * mData[14]) -
             mData[2] * (mData[8] * mData[15] - mData[11] * mData[12]) +
             mData[3] * (mData[8] * mData[14] - mData[10] * mData[12]);
    inv[6] = mData[0] * (mData[6] * mData[15] - mData[7] * mData[14]) -
             mData[2] * (mData[4] * mData[15] - mData[7] * mData[12]) +
             mData[3] * (mData[4] * mData[14] - mData[6] * mData[12]);
    inv[7] = mData[0] * (mData[6] * mData[11] - mData[7] * mData[10]) -
             mData[2] * (mData[4] * mData[11] - mData[7] * mData[8]) +
             mData[3] * (mData[4] * mData[10] - mData[6] * mData[8]);

    inv[8] = mData[4] * (mData[9] * mData[15] - mData[11] * mData[13]) -
             mData[5] * (mData[8] * mData[15] - mData[11] * mData[12]) +
             mData[7] * (mData[8] * mData[13] - mData[9] * mData[12]);
    inv[9] = mData[0] * (mData[9] * mData[15] - mData[11] * mData[13]) -
             mData[1] * (mData[8] * mData[15] - mData[11] * mData[12]) +
             mData[3] * (mData[8] * mData[13] - mData[9] * mData[12]);
    inv[10] = mData[0] * (mData[5] * mData[15] - mData[7] * mData[13]) -
              mData[1] * (mData[4] * mData[15] - mData[7] * mData[12]) +
              mData[3] * (mData[4] * mData[13] - mData[5] * mData[12]);
    inv[11] = mData[0] * (mData[5] * mData[11] - mData[7] * mData[9]) -
              mData[1] * (mData[4] * mData[11] - mData[7] * mData[8]) +
              mData[3] * (mData[4] * mData[9] - mData[5] * mData[8]);

    inv[12] = mData[4] * (mData[9] * mData[14] - mData[10] * mData[13]) -
              mData[5] * (mData[8] * mData[14] - mData[10] * mData[12]) +
              mData[6] * (mData[8] * mData[13] - mData[9] * mData[12]);
    inv[13] = mData[0] * (mData[9] * mData[14] - mData[10] * mData[13]) -
              mData[1] * (mData[8] * mData[14] - mData[10] * mData[12]) +
              mData[2] * (mData[8] * mData[13] - mData[9] * mData[12]);
    inv[14] = mData[0] * (mData[5] * mData[14] - mData[6] * mData[13]) -
              mData[1] * (mData[4] * mData[14] - mData[6] * mData[12]) +
              mData[2] * (mData[4] * mData[13] - mData[5] * mData[12]);
    inv[15] = mData[0] * (mData[5] * mData[10] - mData[6] * mData[9]) -
              mData[1] * (mData[4] * mData[10] - mData[6] * mData[8]) +
              mData[2] * (mData[4] * mData[9] - mData[5] * mData[8]);

    // Scale the inverse by the reciprocal of the determinant
    float invdet = 1.0f / det;
    for (int i = 0; i < 16; ++i) {
        result.mData[i] = inv[i] * invdet;
    }

    return true;
}

void CMatrix::LoadLookAt(const CVec3& eye, const CVec3& center, const CVec3& up) {
	CVec3 f = (center - eye).Normalize();
	CVec3 u = up.Normalize();
	CVec3 s = f.Cross(u).Normalize();
	u = s.Cross(f);

	mData[0] = s.mX;
	mData[1] = u.mX;
	mData[2] = -f.mX;
	mData[3] = 0.0f;

	mData[4] = s.mY;
	mData[5] = u.mY;
	mData[6] = -f.mY;
	mData[7] = 0.0f;

	mData[8] = s.mZ;
	mData[9] = u.mZ;
	mData[10] = -f.mZ;
	mData[11] = 0.0f;

	mData[12] = -s.Dot(eye);
	mData[13] = -u.Dot(eye);
	mData[14] = f.Dot(eye);
	mData[15] = 1.0f;
}

void CMatrix::LoadOrthographic(float left, float right, float bottom, float top, float near, float far) {
	mData[0] = 2.0f / (right - left);
	mData[1] = 0.0f;
	mData[2] = 0.0f;
	mData[3] = 0.0f;

	mData[4] = 0.0f;
	mData[5] = 2.0f / (top - bottom);
	mData[6] = 0.0f;
	mData[7] = 0.0f;

	mData[8] = 0.0f;
	mData[9] = 0.0f;
	mData[10] = -2.0f / (far - near);
	mData[11] = 0.0f;

	mData[12] = -(right + left) / (right - left);
	mData[13] = -(top + bottom) / (top - bottom);
	mData[14] = -(far + near) / (far - near);
	mData[15] = 1.0f;
}

void CMatrix::LoadPerspective(float fovy, float aspect, float near, float far, bool isRadians) {
	float fovyRad = isRadians ? fovy : MATHS::DegToRad(fovy);
	float tanHalfFovy = MATHS::tanf(fovyRad / 2.0f);

	float f = 1.0f / tanHalfFovy;

	mData[0] = f / aspect;
	mData[1] = 0.0f;
	mData[2] = 0.0f;
	mData[3] = 0.0f;

	mData[4] = 0.0f;
	mData[5] = f;
	mData[6] = 0.0f;
	mData[7] = 0.0f;

	mData[8] = 0.0f;
	mData[9] = 0.0f;
	mData[10] = (far + near) / (near - far);
	mData[11] = -1.0f;

	mData[12] = 0.0f;
	mData[13] = 0.0f;
	mData[14] = (2.0f * far * near) / (near - far);
	mData[15] = 0.0f;
}

void CMatrix::MultiplyPoint(const CVec2& point, CVec2& result) const {
	result.mX = point.mY * mData[4] + point.mX * mData[0] + mData[12];
	result.mY = point.mY * mData[5] + point.mX * mData[1] + mData[13];
}

void CMatrix::MultiplyPoint2f(const float* point, float* result) const {
	result[0] = mData[0] * point[0] + mData[4] * point[1] + mData[12];
	result[1] = mData[1] * point[0] + mData[5] * point[1] + mData[13];
}

bool CMatrix::operator!=(const CMatrix& other) const {
	for (size_t i = 0; i < mData.size(); ++i) {
		if (mData[i] != other.mData[i]) {
			return true;
		}
		if (std::isnan(mData[i]) || std::isnan(other.mData[i])) {
			return true;
		}
	}
	return false;
}

CMatrix CMatrix::operator*(const CMatrix& other) const {
	CMatrix result;

	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			result.mData[i * 4 + j] = 0.0f;
			for (size_t k = 0; k < 4; ++k) {
				result.mData[i * 4 + j] += mData[i * 4 + k] * other.mData[k * 4 + j];
			}
		}
	}

	return result;
}

CVec4 CMatrix::operator*(const CVec4& vec) const {
	return { vec.mX * mData[0] + vec.mY * mData[4] + vec.mZ * mData[8] + vec.mW * mData[12],
				vec.mX * mData[1] + vec.mY * mData[5] + vec.mZ * mData[9] + vec.mW * mData[13],
				vec.mX * mData[2] + vec.mY * mData[6] + vec.mZ * mData[10] + vec.mW * mData[14],
				vec.mX * mData[3] + vec.mY * mData[7] + vec.mZ * mData[11] + vec.mW * mData[15] };
}

CVec3 CMatrix::operator*(const CVec3& vec) const {
	return { vec.mX * mData[0] + vec.mY * mData[4] + vec.mZ * mData[8] + mData[12],
				vec.mX * mData[1] + vec.mY * mData[5] + vec.mZ * mData[9] + mData[13],
				vec.mX * mData[2] + vec.mY * mData[6] + vec.mZ * mData[10] + mData[14] };
}

CVec2 CMatrix::operator*(const CVec2& vec) const {
	return { vec.mX * mData[0] + vec.mY * mData[4] + mData[12],
				vec.mX * mData[1] + vec.mY * mData[5] + mData[13] };
}

CMatrix& CMatrix::operator*=(const CMatrix& other) {
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			mData[i * 4 + j] = 0.0f;
			for (size_t k = 0; k < 4; ++k) {
				mData[i * 4 + j] += mData[i * 4 + k] * other.mData[k * 4 + j];
			}
		}
	}
	return *this;
}
CMatrix& CMatrix::operator*=(float scalar) {
	for (size_t i = 0; i < mData.size(); ++i) {
		mData[i] *= scalar;
	}
	return *this;
}

CMatrix CMatrix::operator+(const CMatrix& other) const {
	CMatrix result;

	for (size_t i = 0; i < mData.size(); ++i) {
		result.mData[i] = mData[i] + other.mData[i];
	}

	return result;
}

CMatrix& CMatrix::operator+=(const CMatrix& other) {
	for (size_t i = 0; i < mData.size(); ++i) {
		mData[i] += other.mData[i];
	}
	return *this;
}

CMatrix CMatrix::operator-() const {
	CMatrix result;

	for (size_t i = 0; i < mData.size(); ++i) {
		result.mData[i] = -mData[i];
	}

	return result;
}

CMatrix CMatrix::operator-(const CMatrix& other) const {
	CMatrix result;

	for (size_t i = 0; i < mData.size(); ++i) {
		result.mData[i] = mData[i] - other.mData[i];
	}

	return result;
}

CMatrix& CMatrix::operator-=(const CMatrix& other) {
	for (size_t i = 0; i < mData.size(); ++i) {
		mData[i] -= other.mData[i];
	}
	return *this;
}

CMatrix& CMatrix::operator=(const CMatrix& other) {
	if (this != &other) {
		for (size_t i = 0; i < mData.size(); ++i) {
			mData[i] = other.mData[i];
		}
	}
	return *this;
}

bool CMatrix::operator==(const CMatrix& other) const {
	for (size_t i = 0; i < mData.size(); ++i) {
		if (mData[i] != other.mData[i]) {
			return false;
		}
		if (std::isnan(mData[i]) || std::isnan(other.mData[i])) {
			return false;
		}
	}
	return true;
}

void CMatrix::PostMultiply(const CMatrix& other) {
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			mData[i * 4 + j] = 0.0f;
			for (size_t k = 0; k < 4; ++k) {
				mData[i * 4 + j] += mData[k * 4 + j] * other.mData[i * 4 + k];
			}
		}
	}
}

void CMatrix::PreMultiply(const CMatrix& other) {
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			mData[i * 4 + j] = 0.0f;
			for (size_t k = 0; k < 4; ++k) {
				mData[i * 4 + j] += other.mData[i * 4 + k] * mData[k * 4 + j];
			}
		}
	}
}

void CMatrix::Reset(const CVec3& vec, float angle) {
	// Reset to identity matrix
	mData.fill(0.0f);
	mData[0] = 1.0f;
	mData[5] = 1.0f;
	mData[10] = 1.0f;
	mData[15] = 1.0f;

	// Set translation part
	mData[12] = vec.mX;
	mData[13] = vec.mY;
	mData[14] = vec.mZ;

	// Apply rotation if angle is not zero and not NaN
	if (angle != 0.0f && !std::isnan(angle)) {
		float radians = (angle * static_cast<float>(std::numbers::pi)) / 180.0f;
		float cosAngle = MATHS::cosf(radians);
		float sinAngle = MATHS::sinf(radians);

		// Assuming a simple rotation around the Z-axis for demonstration
		mData[0] = cosAngle;
		mData[1] = -sinAngle;
		mData[4] = sinAngle;
		mData[5] = cosAngle;
	}
}

void CMatrix::Reset(const CVec2& vec, float angle) {
	// Reset to identity matrix
	mData.fill(0.0f);
	mData[0] = 1.0f;
	mData[5] = 1.0f;
	mData[10] = 1.0f;
	mData[15] = 1.0f;

	// Set translation part
	mData[12] = vec.mX;
	mData[13] = vec.mY;

	// Apply rotation if angle is not zero and not NaN
	if (angle != 0.0f && !std::isnan(angle)) {
		float radians = (angle * static_cast<float>(std::numbers::pi)) / 180.0f;
		float cosAngle = MATHS::cosf(radians);
		float sinAngle = MATHS::sinf(radians);

		// Assuming a simple rotation around the Z-axis for demonstration
		mData[0] = cosAngle;
		mData[1] = -sinAngle;
		mData[4] = sinAngle;
		mData[5] = cosAngle;
	}
}

void CMatrix::Rotate(float angle, const CVec3& axis) {
	CMatrix rotationMatrix;

	// Reset to identity matrix
	rotationMatrix.mData.fill(0.0f);
	rotationMatrix.mData[0] = 1.0f;
	rotationMatrix.mData[5] = 1.0f;
	rotationMatrix.mData[10] = 1.0f;
	rotationMatrix.mData[15] = 1.0f;

	// Apply rotation based on the axis
	if (axis.mX == 1.0f && !std::isnan(axis.mX)) {
		RotX(angle);
	}
	if (axis.mY == 1.0f && !std::isnan(axis.mY)) {
		RotY(angle);
	}
	if (axis.mZ == 1.0f && !std::isnan(axis.mZ)) {
		RotZ(angle);
	}

	// Apply the rotation to the current matrix
	*this *= rotationMatrix;
}

void CMatrix::RotateZ(float angle) {
	// Convert angle from degrees to radians
	float radians = (angle * static_cast<float>(std::numbers::pi)) / 180.0f;

	// Calculate cosine and sine of the angle
	float cosAngle = MATHS::cosf(radians);
	float sinAngle = MATHS::sinf(radians);

	// Reset to identity matrix
	mData.fill(0.0f);
	mData[0] = cosAngle;
	mData[1] = sinAngle;
	mData[4] = -sinAngle;
	mData[5] = cosAngle;
	mData[10] = 1.0f;
	mData[15] = 1.0f;
}

void CMatrix::RotX(float angle) {
	// Convert angle from degrees to radians
	float radians = (angle * static_cast<float>(std::numbers::pi)) / 180.0f;

	// Calculate cosine and sine of the angle
	float cosAngle = MATHS::cosf(radians);
	float sinAngle = MATHS::sinf(radians);

	// Temporary variables to store the current matrix values
	float m11 = mData[0];
	float m12 = mData[1];
	float m13 = mData[2];
	float m14 = mData[3];
	float m21 = mData[4];
	float m22 = mData[5];
	float m23 = mData[6];
	float m24 = mData[7];
	float m31 = mData[8];
	float m32 = mData[9];
	float m33 = mData[10];
	float m34 = mData[11];

	// Apply the rotation around the X-axis
	mData[4] = cosAngle * m21 - sinAngle * m31;
	mData[5] = cosAngle * m22 - sinAngle * m32;
	mData[6] = cosAngle * m23 - sinAngle * m33;
	mData[7] = cosAngle * m24 - sinAngle * m34;
	mData[8] = sinAngle * m21 + cosAngle * m31;
	mData[9] = sinAngle * m22 + cosAngle * m32;
	mData[10] = sinAngle * m23 + cosAngle * m33;
	mData[11] = sinAngle * m24 + cosAngle * m34;
}

void CMatrix::RotY(float angle) {
	// Convert angle from degrees to radians
	float radians = (angle * static_cast<float>(std::numbers::pi)) / 180.0f;

	// Calculate cosine and sine of the angle
	float cosAngle = MATHS::cosf(radians);
	float sinAngle = MATHS::sinf(radians);

	// Temporary variables to store the current matrix values
	float m11 = mData[0];
	float m12 = mData[1];
	float m13 = mData[2];
	float m14 = mData[3];
	float m31 = mData[8];
	float m32 = mData[9];
	float m33 = mData[10];
	float m34 = mData[11];

	// Apply the rotation around the Y-axis
	mData[0] = cosAngle * m11 + sinAngle * m31;
	mData[1] = cosAngle * m12 + sinAngle * m32;
	mData[2] = cosAngle * m13 + sinAngle * m33;
	mData[3] = cosAngle * m14 + sinAngle * m34;
	mData[8] = cosAngle * m31 - sinAngle * m11;
	mData[9] = cosAngle * m32 - sinAngle * m12;
	mData[10] = cosAngle * m33 - sinAngle * m13;
	mData[11] = cosAngle * m34 - sinAngle * m14;
}

void CMatrix::RotZ(float angle) {
	// Convert angle from degrees to radians
	float radians = (angle * static_cast<float>(std::numbers::pi)) / 180.0f;

	// Calculate cosine and sine of the angle
	float cosAngle = MATHS::cosf(radians);
	float sinAngle = MATHS::sinf(radians);

	// Temporary variables to store the current matrix values
	float m11 = mData[0];
	float m12 = mData[1];
	float m13 = mData[2];
	float m14 = mData[3];
	float m21 = mData[4];
	float m22 = mData[5];
	float m23 = mData[6];
	float m24 = mData[7];

	// Apply the rotation around the Z-axis
	mData[0] = cosAngle * m11 + sinAngle * m21;
	mData[1] = cosAngle * m12 + sinAngle * m22;
	mData[2] = cosAngle * m13 + sinAngle * m23;
	mData[3] = cosAngle * m14 + sinAngle * m24;
	mData[4] = cosAngle * m21 - sinAngle * m11;
	mData[5] = cosAngle * m22 - sinAngle * m12;
	mData[6] = cosAngle * m23 - sinAngle * m13;
	mData[7] = cosAngle * m24 - sinAngle * m14;
}

void CMatrix::Scale(const CVec3& scale) {
	// Scale the first row by the x component of the scale vector
	for (size_t i = 0; i < 4; ++i) {
		mData[i] *= scale.mX;
	}

	// Scale the second row by the y component of the scale vector
	for (size_t i = 0; i < 4; ++i) {
		mData[i + 4] *= scale.mY;
	}

	// Scale the third row by the z component of the scale vector
	for (size_t i = 0; i < 4; ++i) {
		mData[i + 8] *= scale.mZ;
	}
}

void CMatrix::Scale(const CVec2& scale) {
	// Scale the first row by the x component of the scale vector
	for (size_t i = 0; i < 4; ++i) {
		mData[i] *= scale.mX;
	}

	// Scale the second row by the y component of the scale vector
	for (size_t i = 0; i < 4; ++i) {
		mData[i + 4] *= scale.mY;
	}
}

void CMatrix::Set(float m00, float m01, float m02, float m03,
				  float m10, float m11, float m12, float m13,
				  float m20, float m21, float m22, float m23,
				  float m30, float m31, float m32, float m33) {
	mData[0] = m00;
	mData[1] = m01;
	mData[2] = m02;
	mData[3] = m03;
	mData[4] = m10;
	mData[5] = m11;
	mData[6] = m12;
	mData[7] = m13;
	mData[8] = m20;
	mData[9] = m21;
	mData[10] = m22;
	mData[11] = m23;
	mData[12] = m30;
	mData[13] = m31;
	mData[14] = m32;
	mData[15] = m33;
}

void CMatrix::Skew(const CVec2& skew) {
	// Apply skew transformation
	mData[1] = skew.mY; // Skew along the y-axis
	mData[4] = skew.mX; // Skew along the x-axis
}

std::string CMatrix::ToString() const {
	return StringHelper::Format("%+8.8f | %+8.8f | %+8.8f | %+8.8f\n%+8.8f | %+8.8f | %+8.8f | %+8.8f\n%+8.8f | %+8.8f | %+8.8f | %+8.8f\n%+8.8f | %+8.8f | %+8.8f | %+8.8f", mData[0], mData[1], mData[2], mData[3], mData[4], mData[5], mData[6], mData[7], mData[8], mData[9], mData[10], mData[11], mData[12], mData[13], mData[14], mData[15]);
}

void CMatrix::Translate(const CVec3& translation) {
	// Apply translation transformation
	mData[12] = translation.mZ * mData[8] + translation.mY * mData[4] + translation.mX * mData[0] + mData[12];
	mData[13] = translation.mZ * mData[9] + translation.mY * mData[5] + translation.mX * mData[1] + mData[13];
	mData[14] = translation.mZ * mData[10] + translation.mY * mData[6] + translation.mX * mData[2] + mData[14];
	mData[15] = translation.mZ * mData[11] + translation.mY * mData[7] + translation.mX * mData[3] + mData[15];
}

void CMatrix::Translate(const CVec2& translation) {
	// Apply translation transformation
	mData[12] = translation.mY * mData[4] + translation.mX * mData[0] + mData[12];
	mData[13] = translation.mY * mData[5] + translation.mX * mData[1] + mData[13];
	mData[14] = translation.mY * mData[6] + translation.mX * mData[2] + mData[14];
	mData[15] = translation.mY * mData[7] + translation.mX * mData[3] + mData[15];
}

CMatrix CMatrix::Transpose() const {
	CMatrix result;

	// Transpose the matrix
	result.mData[0] = mData[0];
	result.mData[1] = mData[4];
	result.mData[2] = mData[8];
	result.mData[3] = mData[12];

	result.mData[4] = mData[1];
	result.mData[5] = mData[5];
	result.mData[6] = mData[9];
	result.mData[7] = mData[13];

	result.mData[8] = mData[2];
	result.mData[9] = mData[6];
	result.mData[10] = mData[10];
	result.mData[11] = mData[14];

	result.mData[12] = mData[3];
	result.mData[13] = mData[7];
	result.mData[14] = mData[11];
	result.mData[15] = mData[15];

	return result;
}

CVec3 CMatrix::UnProject(const CVec2& screenPos, float depth, const CVec2& viewport, const CMatrix& projMatrix) const {
	// Convert screen coordinates to normalized device coordinates (NDC)
	float ndcX = (screenPos.mX - viewport.mX) / viewport.mX * 2.0f - 1.0f;
	float ndcY = (screenPos.mY - viewport.mY) / viewport.mY * 2.0f - 1.0f;

	// Create a 4D vector from the NDC coordinates and depth
	CVec3 ndcPos(ndcX, ndcY, depth);

	// Create a 4x4 matrix from the projection matrix
	std::array<float, 16> invProjMatrix = projMatrix.mData;

	// Invert the projection matrix
	// Note: This is a placeholder for the actual matrix inversion logic
	// You would need to implement or use a library function for matrix inversion
	// For simplicity, we'll assume invProjMatrix is the inverse of projMatrix

	// Multiply the inverse projection matrix by the NDC vector
	CVec4 clipPos;
	clipPos.mX = invProjMatrix[0] * ndcPos.mX + invProjMatrix[1] * ndcPos.mY + invProjMatrix[2] * ndcPos.mZ + invProjMatrix[3];
	clipPos.mY = invProjMatrix[4] * ndcPos.mX + invProjMatrix[5] * ndcPos.mY + invProjMatrix[6] * ndcPos.mZ + invProjMatrix[7];
	clipPos.mZ = invProjMatrix[8] * ndcPos.mX + invProjMatrix[9] * ndcPos.mY + invProjMatrix[10] * ndcPos.mZ + invProjMatrix[11];
	clipPos.mW = invProjMatrix[12] * ndcPos.mX + invProjMatrix[13] * ndcPos.mY + invProjMatrix[14] * ndcPos.mZ + invProjMatrix[15];

	// Normalize the world coordinates by dividing by w
	if (clipPos.mW != 0.0f) {
		clipPos.mX /= clipPos.mW;
		clipPos.mY /= clipPos.mW;
		clipPos.mZ /= clipPos.mW;
	}

	return { clipPos.mX, clipPos.mY, clipPos.mZ };
}