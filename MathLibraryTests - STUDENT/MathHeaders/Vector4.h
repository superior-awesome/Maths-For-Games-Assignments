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

		float operator[](int dim);

		float Magnitude() const;

		void Normalise();
		Vector4 Normalised() const;

		float Dot(Vector4 rhs_) const;
		Vector4 Cross(const Vector4& rhs_);

		float AngleBetween(const Vector4& other) const;

		std::string ToString() const
		{
			return "Vector4 ToString incomplete";
		};

	};
};