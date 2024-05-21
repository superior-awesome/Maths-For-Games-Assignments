#pragma once

#define _MATRIX3_

class Matrix3
{
public:

	float 
		m11,	m12,	m13, 
		m21,	m22,	m23, 
		m31,	m32,	m33;

	Matrix3();
	Matrix3(const Matrix3& other);
	Matrix3(float m11_, float  m12_, float  m13_, 
			float  m21_, float  m22_, float  m23_0,
			float m31_, float m32_ , float m33_);

	Matrix3& operator=(const Matrix3& other);

	Matrix3 operator*(const Matrix3& mat3_);
	Matrix3& operator*=(const Matrix3& mat3_);
	
	Matrix3 SetRotateX(float a);
	Matrix3 SetRotateY(float a);
	Matrix3 SetRotateZ(float a);

	Matrix3 MakeEuler(float x, float y, float z);
	Matrix3 MakeEuler(class Vector3 Vec_);

	void PrintMat3();

};

