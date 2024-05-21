#define _USE_MATH_DEFINES

#ifndef M_Pi

#define M_Pi 3.1415f

#endif // !M_Pi


#include <cmath>
#include <iostream>

#include "Matrix3.h"

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

//	Multiplies two Matrix3 together.
Matrix3 Matrix3::operator*(const Matrix3& mat3_)
{
	Matrix3 temp;

	temp.m11 = (m11 * mat3_.m11) + (m12 * mat3_.m21) + (m13 * mat3_.m31);
	temp.m12 = (m11 * mat3_.m12) + (m12 * mat3_.m22) + (m13 * mat3_.m32);
	temp.m13 = (m11 * mat3_.m13) + (m12 * mat3_.m23) + (m13 * mat3_.m33);
	
	temp.m21 = (m21 * mat3_.m11) + (m22 * mat3_.m21) + (m23 * mat3_.m31);
	temp.m22 = (m21 * mat3_.m12) + (m22 * mat3_.m22) + (m23 * mat3_.m32);
	temp.m23 = (m21 * mat3_.m13) + (m22 * mat3_.m23) + (m23 * mat3_.m33);
	
	temp.m31 = (m31 * mat3_.m11) + (m32 * mat3_.m21) + (m33 * mat3_.m31);
	temp.m32 = (m31 * mat3_.m12) + (m32 * mat3_.m22) + (m33 * mat3_.m32);
	temp.m33 = (m31 * mat3_.m13) + (m32 * mat3_.m23) + (m33 * mat3_.m33);

	return temp;
}

Matrix3& Matrix3::operator*=(const Matrix3& mat3_)
{
	Matrix3 temp = (*this) * mat3_;

	m11 = temp.m11;
	m12 = temp.m12;
	m13 = temp.m13;
	m21 = temp.m21;
	m22 = temp.m22;
	m23 = temp.m23;
	m31 = temp.m31;
	m32 = temp.m32;
	m33 = temp.m33;

	return *this;
}


//	Rotates the Matrix around the X axis by "a" degrees.
Matrix3 Matrix3::SetRotateX(float a)
{

	a *= (M_Pi / 180.0f);
	std::cout << a << std::endl;

	Matrix3 RotMatrix(
		1,		0,		0,
		0,		cos(a),	-1 * sin(a),
		0,		sin(a),	cos(a)
		);
	
	return RotMatrix;
}

//	Rotates the Matrix around the Y axis by "a" degrees.
Matrix3 Matrix3::SetRotateY(float a)
{
	a *= (M_Pi / 180.0f);
	std::cout << a << std::endl;

	Matrix3 RotMatrix(
		cos(a),	0,		-1 * sin(a),
		0,		1,		0,
		sin(a), 0 ,		cos(a)
	);

	return RotMatrix;
}

//	Rotates the Matrix around the Z axis by "a" degrees.
Matrix3 Matrix3::SetRotateZ(float a)
{
	a *= (M_Pi / 180.0f);
	std::cout << a << std::endl;

	Matrix3 RotMatrix(
		cos(a),	-sin(a),	0,
		sin(a), cos(a),		0,
		0,		0,			1
	);


	return RotMatrix;
}

Matrix3 Matrix3::MakeEuler(float x, float y, float z)
{
	Matrix3 EMat = SetRotateX(x) * SetRotateY(y) * SetRotateZ(z);
	return EMat;
}

/*
Matrix3 Matrix3::MakeEuler(Vector3 Vec_)
{
	Matrix3 EMat = MakeEuler(Vec_.x, Vec_.y, Vec_.z);
	return EMat;
}
*/

//___________________________________________________________________
// Debug points


void Matrix3::PrintMat3()
{
	std::cout <<
		"[" << m11 << "," << m12 << "," << m13 << "]\n" <<
		"[" << m21 << "," << m22 << "," << m23 << "]\n" <<
		"[" << m31 << "," << m32 << "," << m33 << "]\n\n";
}
