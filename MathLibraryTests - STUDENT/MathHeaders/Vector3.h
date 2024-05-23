#pragma once

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

		float Magnitude() const;

		void Normalise();
		Vector3 Normalised() const;
		float Dot(Vector3 rhs_) const;
		Vector3 Cross(const Vector3& rhs_);
		float AngleBetween(const Vector3& other) const;

	};
}