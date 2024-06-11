#pragma once
#include "../MathHeaders/Vector3.h"

#include <cmath>

namespace MathClasses
{
	//Default Constructor, all values set to zero.
	Vector3::Vector3()
	{
		for (int i = 0; i < 3; i++)
		{
			v[i] = 0.0f;
		}
	};

	//Default Constructor, all values set to the argument float.
	Vector3::Vector3(float f_)
	{
		for (int i = 0; i < 3; i++)
		{
			v[i] = f_;
		}
	};


	//Default Constructor, each avlue in vecotr set individually.
	Vector3::Vector3(float x_, float y_, float z_)
	{
		x = x_;
		y = y_;
		z = z_;
	};

	//Operator overload+. returns a Vector3.
	Vector3 Vector3::operator+(Vector3 rhs_)
	{
		return Vector3(
			x + rhs_.x,
			y + rhs_.y,
			z + rhs_.z
		);
	}

	//Operator overload+=.
	Vector3& Vector3::operator+=(Vector3 rhs_)
	{
		x += rhs_.x;
		y += rhs_.y;
		z += rhs_.z;

		return *this;
	};

	//Operator overload-. Returns a Vector3.
	Vector3 Vector3::operator-(Vector3 rhs_)
	{
		return Vector3(
			x - rhs_.x,
			y - rhs_.y,
			z - rhs_.z
		);
	};

	//Operator overload-=.
	Vector3& Vector3::operator-=(Vector3 rhs_)
	{
		x -= rhs_.x;
		y -= rhs_.y;
		z -= rhs_.z;

		return *this;
	};

	//Operator overload*. Returns a Vector3.
	Vector3 Vector3::operator*(float f_)
	{
		return Vector3(
			x *= f_,
			y *= f_,
			z *= f_
		);
	};

	//Operator overload*=. Returns a Vector3.
	Vector3& Vector3::operator*=(float f_)
	{
		x *= f_;
		y *= f_;
		z *= f_;

		return *this;
	};

	//Operator overload/. Returns a Vector3.
	Vector3 Vector3::operator/(float f_)
	{
		return Vector3(
			x /= f_,
			y /= f_,
			z /= f_
		);
	}

	//Operator overload/=. Returns a Vector3.
	Vector3& Vector3::operator/=(float f_)
	{
		x /= f_;
		y /= f_;
		z /= f_;
		return *this;
	};

	//Operator overload*. Returns a Vector3.
	Vector3 operator*(float scale, const Vector3 V3_)
	{
		return Vector3(
			V3_.x * scale,
			V3_.y * scale,
			V3_.z * scale
		);
	};

	//Operator overload/. Returns a Vector3.
	Vector3 operator/(float scale, const Vector3 V3_)
	{
		return Vector3(
			V3_.x / scale,
			V3_.y / scale,
			V3_.z / scale
		);
	}

	//Operator overload==. Returns a bool.
	bool Vector3::operator==(const Vector3 rhs_) const
	{
		bool test = abs(x - rhs_.x) < 0.00001f &&
					abs(y - rhs_.y) < 0.00001f &&
					abs(z - rhs_.z) < 0.00001f;

		return test;
	};

	//Operator overload!=. Returns a bool.
	bool Vector3::operator!=(const Vector3 rhs_) const
	{
		bool test =
			abs(x - rhs_.x) < 0.00001f &&
			abs(y - rhs_.y) < 0.00001f &&
			abs(z - rhs_.z) < 0.00001f;

		return !test;
	};

	//Subscript operator. editable reference.
	float& Vector3::operator[](int dim)
	{
		return v[dim];
	};

	//Subscript operator. const reference.
	float Vector3::operator[](int dim) const
	{
		return v[dim];
	}

	//Casts Vector3 to a Pointer of the first element (x).
	Vector3::operator float* ()
	{
		return &v[0];
	};

	//Returns the magnitude of the Vector.
	float Vector3::Magnitude() const
	{
		return sqrtf(x * x + y * y + z * z);
	};

	//Sets the calling vector length to 1.
	void Vector3::Normalise()
	{
		float m = this->Magnitude();

		if (m > 0.00001)
		{

			for (int i = 0; i < 3; i++)
			{
				v[i] /= m;
			};

		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				v[i] = 0;
			};
		}
	};

	//Returns a unit vector of the calling function.
	Vector3 Vector3::Normalised() const
	{

		Vector3 Output(0);

		float m = Magnitude();

		if (m > 0.00001)
		{
			for (int i = 0; i < 3; i++)
			{
				Output[i] = v[i] / m;
			};
		}
		return Output;
	};

	//Returns a dot product of two Vector3s.
	float Vector3::Dot(Vector3 rhs_) const
	{
		float temp = 0;

		for (int i = 0; i < 3; i++)
		{
			temp += (v[i] * rhs_.v[i]);
		}
		return temp;
	};

	//Returns a cross product of two Vector3s.
	Vector3 Vector3::Cross(const Vector3& rhs_)
	{
		return Vector3(y * rhs_.z - z * rhs_.y,
			z * rhs_.x - x * rhs_.z,
			x * rhs_.y - y * rhs_.x
		);
	};

	//Returns the angle between two Vector3s.
	float Vector3::AngleBetween(const Vector3& other) const
	{
		Vector3 a = Normalised();
		Vector3 b = other.Normalised();

		float c = a.Dot(b);

		return acosf(c);
	};

	//Returns a std::string that represents the Vector3.
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