#include "../MathHeaders/Matrix4.h"

#include <cmath>

namespace MathClasses
{

		Matrix4::Matrix4()
		{
			for (int i = 0; i < 16; i++)
			{
				v[i] = 0;
			}
		};

		Matrix4::Matrix4(float f_)
		{
			for (int i = 0; i < 9; i++)
			{
				v[i] = f_;
			}
		};

		Matrix4::Matrix4(	float m1_, float m2_,	float m3_,	float m4_, 
							float m5_, float m6_,	float m7_,	float m8_, 
							float m9_, float m10_,	float m11_, float m12_, 
							float m13_,float m14_,	float m15_, float m16_)
		{
			m1 = m1_;
			m2 = m2_;
			m3 = m3_;
			m4 = m4_;
			m5 = m5_;
			m6 = m6_;
			m7 = m7_;
			m8 = m8_;
			m9 = m9_;
			m10 = m10_;
			m11 = m11_;
			m12 = m12_;
			m13 = m13_;
			m14 = m14_;
			m15 = m15_;
			m16 = m16_;
		};

		Matrix4 Matrix4::MakeIdentity()
		{
			Matrix4 identity(0);
			identity.m1 = 1;
			identity.m6 = 1;
			identity.m11 = 1;
			identity.m16 = 1;


			return identity;
		};

		float& Matrix4::operator[](int dim)
		{
			return v[dim];
		};

		const float& Matrix4::operator [](int dim) const
		{
			return v[dim];
		};

		Matrix4 Matrix4::operator*(const Matrix4& rhs) const
		{
			Matrix4 temp;

			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					int targetArray = (1 + y + (4 * x));

					temp[targetArray] = (mm[x][0] * rhs.mm[0][y]) +
						(mm[x][1] * rhs.mm[1][y]) +
						(mm[x][2] * rhs.mm[2][y]) +
						(mm[x][3] * rhs.mm[3][y]);
				}
			}
			return temp;
		};


		Matrix4& Matrix4::operator*=(const Matrix4& rhs)
		{

			Matrix4 temp = (*this) * rhs;

			for (int i = 0; i < 16; i++)
			{
				v[i] = rhs[i];
			}
			return *this;
		};

		Vector4 Matrix4::operator*(Vector4 rhs) const
		{
			return Vector4(
				rhs.x * m1 + rhs.y * m5 + rhs.z * m9  + rhs.w * m13,
				rhs.x * m2 + rhs.y * m6 + rhs.z * m10 + rhs.w * m14,
				rhs.x * m3 + rhs.y * m7 + rhs.z * m11 +	rhs.w * m15,
				rhs.x * m4 + rhs.y * m8 + rhs.z * m12 + rhs.w * m16
			);

		};

		bool Matrix4::operator==(Matrix4 v_) const
		{
			float tollerance = 0.00001f;
			for (int i = 0; i < 16; i++)
			{
				if (abs(v[i] - v_[i]) > tollerance)
				{
					return false;
				}
			};
			return true;
		};

		bool Matrix4::operator != (Matrix4 v_) const
		{
			return !((*this) == v_);
		};

		Matrix4 Matrix4::Transposed() const
		{
			return Matrix4(m1, m5, m9, m13,
				m2, m6, m10, m14,
				m3, m7, m11, m15,
				m4, m8, m12, m16
			);
		};
};
