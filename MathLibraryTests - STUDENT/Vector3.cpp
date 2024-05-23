#pragma once

#include "../MathHeaders/Vector3.h"
#include <cmath>

namespace MathClasses
{


	Vector3::Vector3()
	{
		for (int i = 0; i < 3; i++)
		{
			v[i] = 0.0f;
		}
	};

	Vector3::Vector3(float f_)
	{
		for (int i = 0; i < 3; i++)
		{
			v[i] = f_;
		}
	};
	Vector3::Vector3(float x_, float y_, float z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}

	float Vector3::Magnitude() const
	{
		return sqrtf(x * x + y * y + z * z);
	};

	void Vector3::Normalise()
	{
		float m = this->Magnitude();

		for (int i = 0; i < 3; i++)
		{
			v[i] /= m;
		}
	};

	Vector3 Vector3::Normalised() const
	{
		float m = this->Magnitude();
		Vector3 Output;

		for (int i = 0; i < 3; i++)
		{
			Output.v[i] /= m;
		}
		return Output;
	};

	float Vector3::Dot(Vector3 rhs_) const
	{
		float temp = 0;

		for (int i = 0; i < 3; i++)
		{
			temp += (v[i] * rhs_.v[i]);
		}
		return temp;
	};

	Vector3 Vector3::Cross(const Vector3& rhs_)
	{
		return Vector3(	y * rhs_.z - z * rhs_.y,
						z * rhs_.x - x * rhs_.z,
						x * rhs_.y - y * rhs_.x
		);
	};

	float Vector3::AngleBetween(const Vector3& other) const
	{
		Vector3 a = Normalised();
		Vector3 b = other.Normalised();

		float c = a.Dot(b);

		return acosf(c);
	};

}