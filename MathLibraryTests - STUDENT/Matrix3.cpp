#pragma once

#ifndef _VECTOR3_
#include "../MathHeaders/Vector3.h"
#define _VECTOR3_
#endif // !_VECTOR3_

#include "../MathHeaders/Matrix3.h"
#include <cmath>



namespace MathClasses
{

	//Default constructor. Sets all elements to zero.
	Matrix3::Matrix3()
	{
		for (int i = 0; i < 9; i++)
		{
			v[i] = 0.0f;
		};
	}

	//Constructor sets all values to arg.
	Matrix3::Matrix3(float f_)
	{
		for (int i = 0; i < 9; i++)
		{
			v[i] = f_;
		};
	}

	//Constructor sets all values corresponding to a array arg (column then row).
	Matrix3::Matrix3(float f_[9])
	{
		for (int i = 0; i < 9; i++)
		{
			v[i] = f_[i];
		}
	}

	//Constructor sets all values corresponding to nine arg (column then row).
	Matrix3::Matrix3(	float m1_, float m2_, float m3_,
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
	}

	//Function creates and returns a identity matrix.
	Matrix3 Matrix3::MakeIdentity()
	{
		Matrix3 identity;

		identity.m1 = 1.0f;
		identity.m5 = 1.0f;
		identity.m9 = 1.0f;

		return identity;

	}

	//Returns a mutable reference based on the subscript operator.
	float& Matrix3::operator[](int dim)
	{
		return v[dim];
	}

	//Returns a constant reference based on the subscript operator.
	const float& Matrix3::operator [](int dim) const
	{
		return v[dim];
	}

	//Multiplies two Matrix3s and returns a new Matrix3.
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
	}


	//Sets LHS to LHS Matrix3 times RHS Matrix3.
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
	}

	//Multiplies a Matrix3 and a Vector3 and returns a new Vector3.
	Vector3 Matrix3::operator*(Vector3 rhs) const
	{
		return Vector3(
			rhs.x * m1 + rhs.y * m4 + rhs.z * m7,
			rhs.x * m2 + rhs.y * m5 + rhs.z * m8,
			rhs.x * m3 + rhs.y * m6 + rhs.z * m9
		);
	}

	//Equality matrix3 operator.
	bool Matrix3::operator==(Matrix3 v_) const
	{
		float tollerance = 0.00001f;
		for (int i = 0; i < 9; i++)
		{
			if (abs(v[i] - v_[i]) > tollerance)
			{
				return false;
			}
		};
		return true;
	}

	//Not equality matrix3 operator.
	bool Matrix3::operator != (Matrix3 v_) const
	{
		float tollerance = 0.00001f;
		for (int i = 0; i < 9; i++)
		{
			if (abs(v[i] - v_[i]) > tollerance)
			{
				return true;
			}
		};
		return false;
	}

	//Returns the address of the first array data point.
	Matrix3::operator float* ()
	{
		return &v[0];
	}

	//Transposes affected Matrix3.
	Matrix3 Matrix3::Transposed() const
	{
		return Matrix3(m1, m4, m7, m2, m5, m8, m3, m6, m9);
	}

	//Rotates Matrix3 by x (pitch).
	Matrix3 Matrix3::MakeRotateX(float a)
	{
		return Matrix3(	1.0f,		0.0f,			0.0f,
						0.0f,		cosf(a),	-sinf(a),
						0.0f,		sinf(a),	cosf(a)
		);
	}

	//Rotates Matrix3 by y (yaw).
	Matrix3 Matrix3::MakeRotateY(float a)
	{
		return Matrix3(	cosf(a),	0.0f,	sinf(a),
						0.0f,		1.0f,	0.0f,
						-sinf(a),	0.0f,	cosf(a)
		);
	}

	//Rotates Matrix3 by z (roll).
	Matrix3 Matrix3::MakeRotateZ(float a)
	{
		return Matrix3(	cosf(a),	sinf(a),	0.0f ,
						-sinf(a),	cosf(a) ,	0.0f,
						0.0f,		0.0f,		1.0f
		);
	}

	//Recieves three arg as floats. Returns a Matrix3 which can be multiplied with a matrix 3 to rotate it in 3D space.
	Matrix3 Matrix3::MakeEuler(float pitch, float yaw, float roll)
	{
		Matrix3 x = MakeRotateX(pitch);
		Matrix3 y = MakeRotateY(yaw);
		Matrix3 z = MakeRotateZ(roll);

		return z * y * x;
		
	}


	//Recieves one arg as a Vector3. Returns a Matrix3 which can be multiplied with a matrix 3 to rotate it in 3 dimensions.
	Matrix3 Matrix3::MakeEuler(Vector3 v_)
	{
		return MakeEuler(v_.x,v_.y,v_.z);
	}

	//Recieves three arg as floats. Returns a Matrix3 which can be multiplied with a matrix 3 to scale it in 3 dimensions.
	Matrix3 Matrix3::MakeScale(float xScale, float yScale, float zScale)
	{
		return Matrix3(	xScale, 0.0f, 0.0f,
						0.0f, yScale, 0.0f,
						0.0f, 0.0f, zScale
		);
	}

	//Recieves two arg as floats. Returns a Matrix3 which can be multiplied with a Matrix3 to scale it in 2 dimensions.
	Matrix3 Matrix3::MakeScale(float xScale, float yScale)
	{
		return MakeScale(xScale,yScale,1);
	}
	
	//Recieves one arg as a Vector3. Returns a Matrix3 which can be multiplied with a matrix 3 to scale it in 3 dimensions.
	Matrix3 Matrix3::MakeScale(Vector3 scale)
	{
		return MakeScale(scale.x, scale.y, scale.z);
	}

	//Takes two floats and sets location in space.
	Matrix3 Matrix3::MakeTranslation(float x_, float y_)
	{
		return MakeTranslation(x_,y_,1);
	}

	//Takes a Vector3 and sets location in space.
	Matrix3 Matrix3::MakeTranslation(Vector3 v_)
	{
		return MakeTranslation(v_.x,v_.y,v_.z);
	}

	//Taked three floats and sets the translation.
	Matrix3 Matrix3::MakeTranslation(float x_, float y_, float z_)
	{
		return Matrix3(	1,0,0,
						0,1,0,
						x_,y_,z_
				);
	}

	//Takes two floats and offsets the translation in the x and y directions.
	Matrix3& Matrix3::Translate(float x_, float y_)
	{
		v[6] += x_;
		v[7] += y_;
		return *this;
	}

	//Takes three floats and offsets the translation in the x, y, and z directions.
	Matrix3& Matrix3::Translate(float x_, float y_, float z_)
	{
		
		v[6] += x_;
		v[7] += y_;
		v[8] += z_;
		return *this;
	}

	//Formats the matrix for debugging purpouses.
	std::string Matrix3::ToString() const
	{
		std::string output;

		for (int i = 0; i < 9; i++)
		{
			if ((i) % 3 == 0 && i > 0)
			{
				output.append("\n");
			};
			output.append(std::to_string(float(v[i])));
		};
		return output;
	}
};
