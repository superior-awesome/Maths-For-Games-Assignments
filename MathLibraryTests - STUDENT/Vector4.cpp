#pragma once
#include "..\MathHeaders\Vector4.h"
#include <cmath>

namespace MathClasses
{
	

	Vector4::Vector4()
	{
		for (int i = 0; i < 4; i++)
		{
			v[i] = 0.0f;
		}
	};

	Vector4::Vector4(float f_)
	{
		for (int i = 0; i < 4; i++)
		{
			v[i] = f_;
		}
	};
	
	Vector4::Vector4(float f_[4])
	{
		for (int i = 0; i < 4; i++)
		{
			v[i] = f_[i];
		}
	};

	Vector4::Vector4(float x_, float y_, float z_, float w_)
	{
		x = x_;
		y = y_;
		z = z_;
		w = w_;
	}


	Vector4 Vector4::operator+(Vector4 rhs_)
	{
		return Vector4( x+rhs_.x,
						y + rhs_.y,
						z + rhs_.z,
						w + rhs_.w
			);
	}
	Vector4& Vector4::operator+=(Vector4 rhs_)
	{
		x += rhs_.x;
		y += rhs_.y;
		z += rhs_.z;
		w += rhs_.w;

		return *this;
	};

	Vector4 Vector4::operator-(Vector4 rhs_)
	{
		return Vector4(x - rhs_.x,
			y - rhs_.y,
			z - rhs_.z,
			w - rhs_.w
		);
	};
	Vector4& Vector4::operator-=(Vector4 rhs_)
	{
		x -= rhs_.x;
		y -= rhs_.y;
		z -= rhs_.z;
		w -= rhs_.w;

		return *this;
	};

	Vector4 Vector4::operator*(float rhs_)
	{
		return Vector4(x * rhs_,
			y * rhs_,
			z * rhs_,
			w * rhs_
		);
	};
	Vector4& Vector4::operator*=(float rhs_)
	{
		x *= rhs_;
		y *= rhs_;
		z *= rhs_;
		w *= rhs_;

		return *this;
	};

	Vector4 Vector4::operator/(float rhs_)
	{
		return Vector4(
			x / rhs_,
			y / rhs_,
			z / rhs_,
			w / rhs_
		);
	}
	Vector4& Vector4::operator/=(float rhs_)
	{
		x /= rhs_;
		y /= rhs_;
		z /= rhs_;
		w /= rhs_;

		return *this;
	}

	Vector4 operator*(float scale, const Vector4 V4_)
	{
		return Vector4(	V4_.x * scale,
						V4_.y * scale,
						V4_.z * scale,
						V4_.w * scale
		);
	}

	Vector4 operator/(float scale, const Vector4 V4_)
	{
		return Vector4(	V4_.x / scale,
						V4_.y / scale,
						V4_.z / scale,
						V4_.w / scale
		);
	}

	bool Vector4::operator==(Vector4 rhs_) const
	{
		return
			abs(x - rhs_.x) < 0.00001f &&
			abs(y - rhs_.y) < 0.00001f &&
			abs(z - rhs_.z) < 0.00001f &&
			abs(w - rhs_.w) < 0.00001f;

	}
	bool Vector4::operator!=(Vector4 rhs_) const
	{
		return !(
			abs(x - rhs_.x) < 0.00001f &&
			abs(y - rhs_.y) < 0.00001f &&
			abs(z - rhs_.z) < 0.00001f &&
			abs(w- rhs_.w) < 0.00001f
			);
	};

	float Vector4::operator[](int dim) const
	{
		return v[dim];
	};

	float& Vector4::operator[](int dim)
	{
		return v[dim];
	};

	Vector4::operator float* ()
	{
		return &v[0];
	};



	float Vector4::Magnitude() const
	{
		return sqrtf(x * x + y * y + z * z + w * w);
	};

	void Vector4::Normalise()
	{

		if (Magnitude() > 0.00001f)
		{
			float m = this->Magnitude();

			for (int i = 0; i < 4; i++)
			{
				v[i] /= m;
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				v[i] = 0;
			}
		}
	};

	Vector4 Vector4::Normalised() const
	{
		float m = Magnitude();
		
		Vector4 Output(0.0f);

		if (m > 0.00001f)
		{
			for (int i = 0; i < 4; i++)
			{
				Output[i] = v[i] / m;
			};
		};

		return Output;
	};

	float Vector4::Dot(Vector4 rhs_) const
	{
		float temp = 0;

		for (int i = 0; i < 4; i++)
		{
			temp += (v[i] * rhs_.v[i]);
		}
		return temp;
	};

	Vector4 Vector4::Cross(const Vector4& rhs_)
	{
		return Vector4(y * rhs_.z - z * rhs_.y,
			z * rhs_.x - x * rhs_.z,
			x * rhs_.y - y * rhs_.x,
			0
		);
	}
	float Vector4::AngleBetween(const Vector4& other) const
	{

		return 0.0f;
	}

	std::string Vector4::ToString() const
	{
		std::string output;

		output.append("( ");
		output.append(std::to_string(float(x)));
		output.append(", ");
		output.append(std::to_string(float(y)));
		output.append(", ");
		output.append(std::to_string(float(z)));
		output.append(", ");
		output.append(std::to_string(float(w)));
		output.append(" )\n");
		return output;
	};


};
