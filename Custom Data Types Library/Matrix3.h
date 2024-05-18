#pragma once

#include "Vector3.h"

class Matrix3
{
public:
	float m11,m12,m13, m21, m22, m23, m31, m32, m33;

	Matrix3();
	Matrix3(const Matrix3& other);
	Matrix3(float m11_, float  m12_, float  m13_, 
			float  m21_, float  m22_, float  m23_0,
			float m31_, float m32_ , float m33_);

	Matrix3& operator=(const Matrix3& other);

	Vector3 operator*(const Vector3& vec3_);
	Matrix3 operator*(const Matrix3& mat3_);
	
	Matrix3& operator*=(const Matrix3& mat3_);
	
	Matrix3& SetRotateX(float a);

};

