#include "Matrix3.h"
#ifndef __VECTOR3__

#define __VECTOR3__
#include "Vector3.h"

#endif // !__VECTOR3__


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

Vector3 Matrix3::operator*(const Vector3& vec3_)
{
	Vector3 temp;

	temp.x = m11 * vec3_.x + m12 * vec3_.x + m13 * vec3_.x;
	temp.y = m21 * vec3_.y + m22 * vec3_.y + m23 * vec3_.y;
	temp.z = m31 * vec3_.z + m31 * vec3_.z + m33 * vec3_.z;

	return temp;
}

Matrix3 Matrix3::operator*(const Matrix3& m_)
{
	Matrix3 temp;

	temp.m11 = (m11 * m_.m11) + (m12 + m_.m21) + (m13 + m_.m31);
	temp.m12 = (m11 * m_.m12) + (m12 + m_.m22) + (m13 + m_.m32);
	temp.m13 = (m11 * m_.m13) + (m12 + m_.m23) + (m13 + m_.m33);
	
	temp.m21 = (m21 * m_.m11) + (m22 + m_.m21) + (m23 + m_.m31);
	temp.m22 = (m21 * m_.m12) + (m22 + m_.m22) + (m23 + m_.m32);
	temp.m23 = (m21 * m_.m13) + (m22 + m_.m23) + (m23 + m_.m33);
	
	temp.m31 = (m31 * m_.m11) + (m32 + m_.m21) + (m33 + m_.m31);
	temp.m32 = (m31 * m_.m12) + (m32 + m_.m22) + (m33 + m_.m32);
	temp.m33 = (m31 * m_.m13) + (m32 + m_.m23) + (m33 + m_.m33);

	return temp;
}

Matrix3 SetRotateX(float a)
{

}

//Identify matrix contant.