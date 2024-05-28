#pragma once

#ifndef _CMATH_
#define _CMATH_
#include <cmath>
#endif // _CMATH_

namespace MathClasses
{
	class Matrix3
	{
	public:
		union
		{
			struct
			{
				float m1, m2, m3, m4, m5, m6, m7, m8, m9;
			};
			float v[9];
			float mm[3][3];
			Vector3 axis[3];
		};

		Matrix3();

		Matrix3(float f_);

		Matrix3(float f_[9]);

		Matrix3(float m1_, float m2_, float m3_,
			float m4_, float m5_, float m6_,
			float m7_, float m8_, float m9_);

		static Matrix3 MakeIdentity();

		float& operator[](int dim);
		const float& operator [](int dim) const;



		Matrix3 operator*(const Matrix3& rhs) const;
		Matrix3& operator*=(Matrix3& rhs);

		Matrix3& operator*=(const Matrix3& rhs);
		Vector3 operator*(Vector3 rhs) const;


		bool operator == (Matrix3 v_) const;
		bool operator != (Matrix3 v_) const;

		friend bool Matrix3::operator==(Matrix3 lhs_, Matrix3 rhs_);
		friend bool Matrix3::operator!=(Matrix3 lhs_, Matrix3 rhs_);

		operator float* ();

		Matrix3 Transposed() const;

		static Matrix3 MakeRotateX(float a);
		static Matrix3 MakeRotateY(float a);
		static Matrix3 MakeRotateZ(float a);

		static Matrix3 MakeEuler(float pitch, float yaw, float roll);
		static Matrix3 MakeEuler(Vector3 v_);

		static Matrix3 MakeScale(Vector3 scale);
		static Matrix3 MakeScale(float xScale, float yScale, float zScale);
		static Matrix3 MakeScale(float xScale, float yScale);

		static Matrix3 MakeTranslation(float x_, float y_);
		static Matrix3 MakeTranslation(Vector3 v_);
		static Matrix3 MakeTranslation(float x_, float y_, float z_);

		Matrix3& Translate(float x_, float y_);
		Matrix3& Translate(float x_, float y_, float z_);
		//Matrix3& Translate(Vector3 offset_);


			
		std::string ToString() const;

	};
};
