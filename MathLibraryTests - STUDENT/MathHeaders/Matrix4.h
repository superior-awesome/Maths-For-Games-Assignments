#pragma once
#include "Vector4.h"

#ifndef _CMATH_
#define _CMATH_
#include <cmath>
#endif // _CMATH_

namespace MathClasses
{
	class Matrix4
	{
	public:
		union
		{
			struct
			{
				float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;
			};
			float v[16];
			float mm[4][4];
			Vector4 axis[4];
		};

		Matrix4();
		Matrix4(float f_);
		Matrix4(float m1_, float m2_, float m3_, float m4_,
			float m5_, float m6_, float m7_, float m8_,
			float m9_, float m10_, float m11_, float m12_,
			float m13_, float m14_, float m15_, float m16_);
		Matrix4(float f_[16]);

		static Matrix4 MakeIdentity();

		float& operator[](int dim);
		const float& operator[](int dim) const;

		operator float* ();

		Matrix4 operator*(const Matrix4& rhs) const;
		Matrix4& operator*=(const Matrix4& rhs);

		Vector4 operator*(Vector4 rhs) const;

		bool operator==(Matrix4 v_) const;

		//bool operator==(Matrix4 v_);
		bool operator != (Matrix4 v_) const;

		Matrix4 Transposed() const;

		static Matrix4 MakeRotateX(float a);
		static Matrix4 MakeRotateY(float a);
		static Matrix4 MakeRotateZ(float a);

		static Matrix4 MakeEuler(float pitch, float yaw, float roll);

		static Matrix4 MakeEuler(class Vector3 v_);

		static Matrix4 MakeTranslation(float x_, float y_, float z_);
		static Matrix4 MakeTranslation(class Vector3 v_);

		static Matrix4 MakeScale(float xScale, float yScale, float zScale);
		static Matrix4 MakeScale(Vector3 v_);

		std::string ToString() const;
	};
};