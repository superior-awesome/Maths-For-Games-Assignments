#pragma once

namespace MathClasses
{
    struct Vector4
    {
	public:
		union
		{
			struct
			{
				float x, y, z,w;
			};
			float v[4];
		};

		Vector4()
		{
			for (int i = 0; i < 4; i++)
			{
				v[i] = 0.0f;
			}
		};

		Vector4(float f_)
		{
			for (int i = 0; i < 4; i++)
			{
				v[i] = f_;
			}
		};
		Vector4(float x_, float y_, float z_, float w_)
		{
			x = x_;
			y = y_;
			z = z_;
			w = w_;
		}
	};
}
