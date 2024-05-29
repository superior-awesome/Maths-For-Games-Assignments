#pragma once
#include <string>

#ifndef _CMATH_
#define _CMATH_
#include <cmath>
#endif // _CMATH_

namespace MathClasses
{
	class Vector3
	{
	public:
		union
		{
			struct
			{
				float x, y, z;
			};
			float v[3];
		};

		Vector3();
		Vector3(float f_);
		Vector3(float x_, float y_, float z_);


		Vector3 operator+(Vector3 rhs_);
		Vector3& operator+=(Vector3 rhs_);

		Vector3 operator-(Vector3 rhs_);
		Vector3& operator-=(Vector3 rhs_);

		Vector3 operator*(float f_);
		Vector3& operator*=(float f_);

		Vector3 operator/(float f_);
		Vector3& operator/=(float f_);

		friend Vector3 operator* (float scale, const Vector3 V3_);
		friend Vector3 operator/ (float scale, const Vector3 V3_);

	//	friend bool operator==(const Vector3 lhs_, const Vector3 rhs_);
	//	friend bool operator!=(const Vector3 lhs_, const Vector3 rhs_);

		bool operator==(const Vector3 rhs_) const;
		bool operator!=(const Vector3 rhs_) const;


		float& operator[](int dim);
		float operator[](int dim) const;

		operator float*();

		float Magnitude() const;
		void Normalise();
		Vector3 Normalised() const;

		float Dot(Vector3 rhs_) const;
		Vector3 Cross(const Vector3& rhs_);

		float AngleBetween(const Vector3& other) const;

		std::string ToString() const;

	};
};