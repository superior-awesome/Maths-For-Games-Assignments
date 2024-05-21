#pragma once

namespace MathClasses
{
    struct Vector3
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

		Vector3()
		{
			for (int i = 0; i < 3; i++)
			{
				v[i] = 0.0f;
			}
		};

		Vector3(float f_)
		{
			for (int i = 0; i < 3; i++)
			{
				v[i] = f_;
			}
		};
		Vector3(float x_, float y_, float z_)
		{
			x = x_;
			y = y_;
			z = z_;
		}

		/*
		Vector3 operator+ (const Vector3& input_);
		Vector3 operator- (const Vector3& input_);
		Vector3 operator*(const float& input_) const;
		Vector3 operator/(const float& input_) const;

		friend Vector3 operator* (float scale, const Vector3 V3_);

		Vector3& operator+= (const Vector3& input_);
		Vector3& operator*= (const float& input_);

		float Dot(const Vector3 V3_) const;
		Vector3 Cross(const Vector3& V3_) const;
		float Magnitude(const Vector3& V3_) const;
		Vector3 Normalize(const Vector3& V3_) const;

		Vector3 operator*(const Matrix3& Mat3_);
		Vector3& operator*=(const Matrix3& Mat3_);
		//	_________________________________________________________________
	//	Debuggining Functions Below This Point


		void PrintVec3();
		*/
	};
}