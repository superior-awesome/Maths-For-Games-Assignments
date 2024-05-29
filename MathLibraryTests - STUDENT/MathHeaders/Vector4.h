#pragma once
#include <string>

#ifndef _CMATH_
#define _CMATH_
#include <cmath>
#endif // _CMATH_

namespace MathClasses
{
	class Vector4
	{
	public:
		union
		{
			struct
			{
				float x, y, z, w;
			};
			float v[4];
		};

		Vector4();
		Vector4(float f_);
		Vector4(float x_, float y_, float z_, float w_);


		Vector4 operator+(Vector4 rhs_);
		Vector4& operator+=(Vector4 rhs_);

		Vector4 operator-(Vector4 rhs_);
		Vector4& operator-=(Vector4 rhs_);

		Vector4 operator*(float rhs_);
		Vector4& operator*=(float rhs_);

		Vector4 operator/(float rhs_);
		Vector4& operator/=(float rhs_);

		friend Vector4 operator* (float scale, const Vector4 V4_);
		friend Vector4 operator/ (float scale, const Vector4 V4_);
		
		//friend bool Vector4::operator==(Vector4 lhs_, Vector4 rhs_);
		//friend bool Vector4::operator!=(Vector4 lhs_, Vector4 rhs_);

		bool operator==(Vector4 rhs_) const;
		bool operator!=(Vector4 rhs_) const;
		
		

		float operator[](int dim) const;
		float& operator[](int dim);

		operator float* ();


		float Magnitude() const;

		void Normalise();
		Vector4 Normalised() const;



		float Dot(Vector4 rhs_) const;
		Vector4 Cross(const Vector4& rhs_);

		float AngleBetween(const Vector4& other) const;

		std::string ToString() const;

	};
};