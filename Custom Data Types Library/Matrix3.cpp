#include "Matrix3.h"
#include <cmath>

#ifndef __VECTOR3__

#define __VECTOR3__
#include "Vector3.h"

#endif // !__VECTOR3__

// Default constructor.
Matrix3::Matrix3()
{
	m11 = 0;
	m12 = 0;
	m13 = 0;
	m21 = 0;
	m22 = 0;
	m23 = 0;
	m31 = 0;
	m32 = 0;
	m33 = 0;
}

// Copy Donctructor, deep coppies one Matrix3 onto another.
Matrix3::Matrix3(const Matrix3& other)
{
	m11 = other.m11;
	m12 = other.m12;
	m13 = other.m13;
	m21 = other.m21;
	m22 = other.m22;
	m23 = other.m23;
	m31 = other.m31;
	m32 = other.m32;
	m33 = other.m33;

}

// Constructor which can be used to individually set all matrix elements uniquely.
Matrix3::Matrix3(float m11_, float  m12_, float  m13_,
	float  m21_, float  m22_, float  m23_,
	float m31_, float m32_, float m33_)
{
	m11 = m11_;
	m12 = m12_;
	m13 = m13_;
	m21 = m21_;
	m22 = m22_;
	m23 = m23_;
	m31 = m31_;
	m32 = m32_;
	m33 = m33_;
}


//Copy Assignment
Matrix3& Matrix3::operator=(const Matrix3& other)
{
	m11 = other.m11;
	m12 = other.m12;
	m13 = other.m13;
	m21 = other.m21;
	m22 = other.m22;
	m23 = other.m23;
	m31 = other.m31;
	m32 = other.m32;
	m33 = other.m33;


	return *this;
}

// Constructor which can be used to individually set all matrix elements to the same value.
Vector3 Matrix3::operator*(const Vector3& vec3_)
{
	Vector3 temp;

	temp.x = m11 * vec3_.x + m12 * vec3_.x + m13 * vec3_.x;
	temp.y = m21 * vec3_.y + m22 * vec3_.y + m23 * vec3_.y;
	temp.z = m31 * vec3_.z + m31 * vec3_.z + m33 * vec3_.z;

	return temp;
}

//	Multiplies two Matrix3 together.
Matrix3 Matrix3::operator*(const Matrix3& mat3_)
{
	Matrix3 temp;

	temp.m11 = (m11 * mat3_.m11) + (m12 + mat3_.m21) + (m13 + mat3_.m31);
	temp.m12 = (m11 * mat3_.m12) + (m12 + mat3_.m22) + (m13 + mat3_.m32);
	temp.m13 = (m11 * mat3_.m13) + (m12 + mat3_.m23) + (m13 + mat3_.m33);
	
	temp.m21 = (m21 * mat3_.m11) + (m22 + mat3_.m21) + (m23 + mat3_.m31);
	temp.m22 = (m21 * mat3_.m12) + (m22 + mat3_.m22) + (m23 + mat3_.m32);
	temp.m23 = (m21 * mat3_.m13) + (m22 + mat3_.m23) + (m23 + mat3_.m33);
	
	temp.m31 = (m31 * mat3_.m11) + (m32 + mat3_.m21) + (m33 + mat3_.m31);
	temp.m32 = (m31 * mat3_.m12) + (m32 + mat3_.m22) + (m33 + mat3_.m32);
	temp.m33 = (m31 * mat3_.m13) + (m32 + mat3_.m23) + (m33 + mat3_.m33);

	return temp;
}

Matrix3& Matrix3::operator*=(const Matrix3& mat3_)
{
	Matrix3 temp;

	temp.m11 = (m11 * mat3_.m11) + (m12 + mat3_.m21) + (m13 + mat3_.m31);
	temp.m12 = (m11 * mat3_.m12) + (m12 + mat3_.m22) + (m13 + mat3_.m32);
	temp.m13 = (m11 * mat3_.m13) + (m12 + mat3_.m23) + (m13 + mat3_.m33);

	temp.m21 = (m21 * mat3_.m11) + (m22 + mat3_.m21) + (m23 + mat3_.m31);
	temp.m22 = (m21 * mat3_.m12) + (m22 + mat3_.m22) + (m23 + mat3_.m32);
	temp.m23 = (m21 * mat3_.m13) + (m22 + mat3_.m23) + (m23 + mat3_.m33);

	temp.m31 = (m31 * mat3_.m11) + (m32 + mat3_.m21) + (m33 + mat3_.m31);
	temp.m32 = (m31 * mat3_.m12) + (m32 + mat3_.m22) + (m33 + mat3_.m32);
	temp.m33 = (m31 * mat3_.m13) + (m32 + mat3_.m23) + (m33 + mat3_.m33);

	return temp;
}




//	Rotates the Matrix around the X axis;
Matrix3& Matrix3::SetRotateX(float a)
{
	Matrix3 RotMatrix(
		1,			0,				0,
		0,			m22 * cos(a),	m23 * -1 * sin(a),
		0,			m32 * sin(a),	m33 * cos(a)
		);

	Matrix3 OrignalMatrix(*this);

	
	Matrix3 ResultantMatrix = OrignalMatrix * RotMatrix;

	m11 = ResultantMatrix.m11;
	m12 = ResultantMatrix.m12;
	m13 = ResultantMatrix.m13;
	m21 = ResultantMatrix.m21;
	m22 = ResultantMatrix.m22;
	m23 = ResultantMatrix.m23;
	m31 = ResultantMatrix.m31;
	m32 = ResultantMatrix.m32;
	m33 = ResultantMatrix.m33;

	
	return *this;
}

//Identify matrix contant.
