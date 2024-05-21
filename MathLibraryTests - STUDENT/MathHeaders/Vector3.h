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
	};
}