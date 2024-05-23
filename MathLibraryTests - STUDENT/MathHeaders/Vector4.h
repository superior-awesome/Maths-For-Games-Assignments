#pragma once

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

		float Magnitude() const;

		void Normalise();
		Vector4 Normalised() const;

		float Dot(Vector4 rhs_) const;
		Vector4 Cross(const Vector4& rhs_);

		float AngleBetween(const Vector4& other) const;
	};
};