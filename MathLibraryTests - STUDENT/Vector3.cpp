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
	};

	Vector3 Vector3::operator+(Vector3 rhs_)
	{
		return Vector3(
			x + rhs_.x,
			y + rhs_.y,
			z + rhs_.z
		);
	}

	Vector3& Vector3::operator+=(Vector3 rhs_)
	{
		x += rhs_.x;
		y += rhs_.y;
		z += rhs_.z;

		return *this;
	};

	Vector3 Vector3::operator-(Vector3 rhs_)
	{
		return Vector3(
			x - rhs_.x,
			y - rhs_.y,
			z - rhs_.z
		);
	};

	Vector3& Vector3::operator-=(Vector3 rhs_)
	{
		x -= rhs_.x;
		y -= rhs_.y;
		z -= rhs_.z;

		return *this;
	};

	Vector3 Vector3::operator*(float f_)
	{
		return Vector3(
			x *= f_,
			y *= f_,
			z *= f_
		);
	};

	Vector3& Vector3::operator*=(float f_)
	{
		x *= f_;
		y *= f_;
		z *= f_;

		return *this;
	};

	Vector3 Vector3::operator/(float f_)
	{
		return Vector3(
			x /= f_,
			y /= f_,
			z /= f_
		);
	}

	Vector3& Vector3::operator/=(float f_)
	{
		x /= f_;
		y /= f_;
		z /= f_;
		return *this;
	};


	Vector3 operator*(float scale, const Vector3 V3_)
	{
		return Vector3(
			V3_.x * scale,
			V3_.y * scale,
			V3_.z * scale
		);
	};

	Vector3 operator/(float scale, const Vector3 V3_)
	{
		return Vector3(
			V3_.x / scale,
			V3_.y / scale,
			V3_.z / scale
		);
	}

	bool MathClasses::operator==(const Vector3 lhs_, const Vector3 rhs_)
	{
		return
			abs(lhs_.x - rhs_.x) < 0.00001f &&
			abs(lhs_.y - rhs_.y) < 0.00001f &&
			abs(lhs_.z - rhs_.z) < 0.00001f;
	}

	bool MathClasses::operator!=(const Vector3 lhs_, const Vector3 rhs_) // DONT TOUCH THIS.
	{
		return  !(
				abs(lhs_.x - rhs_.x) < 0.00001f &&
				abs(lhs_.y - rhs_.y) < 0.00001f &&
				abs(lhs_.z - rhs_.z) < 0.00001f
				);
	};

	bool Vector3::operator==(const Vector3 rhs_) const
	{
		return
			abs(x - rhs_.x) < 0.00001f &&
			abs(y - rhs_.y) < 0.00001f &&
			abs(z - rhs_.z) < 0.00001f;

	}
	bool Vector3::operator!=(const Vector3 rhs_) const
	{
		return !(
			abs(x - rhs_.x) < 0.00001f &&
			abs(y - rhs_.y) < 0.00001f &&
			abs(z - rhs_.z) < 0.00001f
		);
	};


	float& Vector3::operator[](int dim)
	{
		return v[dim];
	};

	float Vector3::operator[](int dim) const
	{
		return v[dim];
	}

	Vector3::operator float* ()
	{
		return &v[0];
	};


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
		return Vector3(y * rhs_.z - z * rhs_.y,
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


	std::string Vector3::ToString() const
	{
		std::string output;

		output.append("( ");
		output.append(std::to_string(float(x)));
		output.append(", ");
		output.append(std::to_string(float(y)));
		output.append(", ");
		output.append(std::to_string(float(z)));

		output.append(" )\n");
		return output;
	};




};