#pragma once
#ifndef _VECTOR3_
#include "../MathHeaders/Vector3.h"
#define _VECTOR3_
#endif // !_VECTOR3_

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
	};

	bool Vector3::operator==(Vector3 rhs_)
	{
		for (int i = 0; i < 3; i++)
		{
			if (x != rhs_.x)
			{
				return false;
			};
		};

		return true;
	};

	bool Vector3::operator!=(Vector3 rhs_)
	{

		if ((*this) == rhs_)
		{
			return false;
		}
		else
		{
			return true;
		};

	};

	float& Vector3::operator[](int dim)
	{
		return v[dim];
	};

	float Vector3::operator[](int dim) const
	{
		return v[dim];
	}
	
	Vector3::operator float*() 
	{

		float* temp = NULL;
			//= &(v[0]);
			//x = (float)x;
			//y = (float)y;
			//z = (float)z;

			return temp;
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

	//Why does this not want to be scoped into the Vector3 scope?
	//void Vector3::ToString()
//	{
	//	std::string output("ToString not implemented");

		//return output;
	//};
	
	


};