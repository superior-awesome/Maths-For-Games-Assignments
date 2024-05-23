#pragma once
#include "../MathHeaders/Vector3.h"
#include "../MathHeaders/Matrix3.h"
#include <cmath>

namespace MathClasses
{

	Matrix3::Matrix3()
	{
		for (int i = 0; i < 9; i++)
		{
			v[i] = 0;
		}
	};

	Matrix3::Matrix3(float f_)
	{
		for (int i = 0; i < 9; i++)
		{
			v[i] = f_;
		}
	};

	Matrix3::Matrix3(float m1_, float m2_, float m3_,
		float m4_, float m5_, float m6_,
		float m7_, float m8_, float m9_)
	{
		m1 = m1_;
		m2 = m2_;
		m3 = m3_;
		m4 = m4_;
		m5 = m5_;
		m6 = m6_;
		m7 = m7_;
		m8 = m8_;
		m9 = m9_;
	};

	//static Matrix3 MathClasses::Matrix3::MakeIdentity()
	Matrix3 Matrix3::MakeIdentity()
	{
		Matrix3 identity;
		identity.m1 = 1;
		identity.m2 = 0;
		identity.m3 = 0;

		identity.m4 = 0;
		identity.m5 = 1;
		identity.m6 = 0;

		identity.m7 = 0;
		identity.m8 = 0;
		identity.m9 = 1;

		return identity;

	};


	float& Matrix3::operator[](int dim)
	{
		return v[dim];
	};

	const float& Matrix3::operator [](int dim) const
	{
		return v[dim];
	};




	Matrix3 Matrix3::operator*(const Matrix3& rhs) const
	{
		Matrix3 temp;

		temp.m1 = (m1 * rhs.m1) + (m4 * rhs.m2) + (m7 * rhs.m3);
		temp.m2 = (m2 * rhs.m1) + (m5 * rhs.m2) + (m8 * rhs.m3);
		temp.m3 = (m3 * rhs.m1) + (m6 * rhs.m2) + (m9 * rhs.m3);

		temp.m4 = (m1 * rhs.m4) + (m4 * rhs.m5) + (m7 * rhs.m6);
		temp.m5 = (m2 * rhs.m4) + (m5 * rhs.m5) + (m8 * rhs.m6);
		temp.m6 = (m3 * rhs.m4) + (m6 * rhs.m5) + (m9 * rhs.m6);

		temp.m7 = (m1 * rhs.m7) + (m4 * rhs.m8) + (m7 * rhs.m9);
		temp.m8 = (m2 * rhs.m7) + (m5 * rhs.m8) + (m8 * rhs.m9);
		temp.m9 = (m3 * rhs.m7) + (m6 * rhs.m8) + (m9 * rhs.m9);

		return temp;
	};



	Matrix3& Matrix3::operator*=(const Matrix3& rhs)
	{

		m1 = (m1 * rhs.m1) + (m4 * rhs.m2) + (m7 * rhs.m3);
		m2 = (m2 * rhs.m1) + (m5 * rhs.m2) + (m8 * rhs.m3);
		m3 = (m3 * rhs.m1) + (m6 * rhs.m2) + (m9 * rhs.m3);

		m4 = (m1 * rhs.m4) + (m4 * rhs.m5) + (m7 * rhs.m6);
		m5 = (m2 * rhs.m4) + (m5 * rhs.m5) + (m8 * rhs.m6);
		m6 = (m3 * rhs.m4) + (m6 * rhs.m5) + (m9 * rhs.m6);

		m7 = (m1 * rhs.m7) + (m4 * rhs.m8) + (m7 * rhs.m9);
		m8 = (m2 * rhs.m7) + (m5 * rhs.m8) + (m8 * rhs.m9);
		m9 = (m3 * rhs.m7) + (m6 * rhs.m8) + (m9 * rhs.m9);

		return *this;
	};

	Matrix3& Matrix3::operator*=(const Matrix3& rhs)
	{

		m1 = (m1 * rhs.m1) + (m4 * rhs.m2) + (m7 * rhs.m3);
		m2 = (m2 * rhs.m1) + (m5 * rhs.m2) + (m8 * rhs.m3);
		m3 = (m3 * rhs.m1) + (m6 * rhs.m2) + (m9 * rhs.m3);

		m4 = (m1 * rhs.m4) + (m4 * rhs.m5) + (m7 * rhs.m6);
		m5 = (m2 * rhs.m4) + (m5 * rhs.m5) + (m8 * rhs.m6);
		m6 = (m3 * rhs.m4) + (m6 * rhs.m5) + (m9 * rhs.m6);

		m7 = (m1 * rhs.m7) + (m4 * rhs.m8) + (m7 * rhs.m9);
		m8 = (m2 * rhs.m7) + (m5 * rhs.m8) + (m8 * rhs.m9);
		m9 = (m3 * rhs.m7) + (m6 * rhs.m8) + (m9 * rhs.m9);

		return *this;
	};

	Vector3 Matrix3::operator*(Vector3 rhs) const
	{

		return Vector3(
			rhs.x * m1 + rhs.y * m4 + rhs.z * m7,
			rhs.x * m2 + rhs.y * m5 + rhs.z * m8,
			rhs.x * m3 + rhs.y * m6 + rhs.z * m9
		);

	};

	bool Matrix3::operator == (Matrix3 v_) const
	{
		float tollerance = 0.00001f;
		for (int i = 0; i < 9; i++)
		{
			if ((v[i] - v_[i]) > tollerance)	//	Need to do ABS
			{
				return false;
			}
		};
		return true;
	};

	bool Matrix3::operator != (Matrix3 v_) const
	{
		return !((*this) == v_);
	};

	Matrix3 Matrix3::Transposed() const
	{
		return Matrix3(m1, m4, m7, m2, m5, m8, m3, m6, m9);
	};

	Matrix3 Matrix3::MakeRotateX(float a)
	{
		return(	1,		0,			0,
				0,		cosf(a),	-sinf(a),
				0,		sinf(a),	cosf(a)
				);
	};

	Matrix3 Matrix3::MakeRotateY(float a)
	{
		return(	cosf(a),	0,	-sinf(a),
				0,			1,	0,
				sinf(a),	0,	cosf(a)
				);
	};
	Matrix3 Matrix3::MakeRotateZ(float a)
	{
		return(	cosf(a),	sinf(a),	0 ,
				-sinf(a),	cosf(a) ,	0,
				0,			0,			1
			);
	};

	Matrix3 Matrix3::MakeEuler(float pitch, float yaw, float roll)
	{
		Matrix3 x = MakeRotateX(pitch);
		Matrix3 y = MakeRotateY(yaw);
		Matrix3 z = MakeRotateZ(roll);

		return z * y * x;

		
	};

	Matrix3 Matrix3::MakeScale(float xScale, float yScale, float zScale)
	{
		return Matrix3(	xScale, 0, 0,
						0, yScale, 0,
						0, 0, zScale
		);
	};
	
	Matrix3 Matrix3::MakeScale(Vector3 scale)
	{
		return MakeScale(scale.x, scale.y, scale.z);
	};
	


};
