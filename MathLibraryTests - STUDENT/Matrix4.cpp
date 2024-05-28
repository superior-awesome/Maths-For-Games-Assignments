#include "../MathHeaders/Matrix4.h"
#include "../MathHeaders/Vector3.h"

#include <cmath>

namespace MathClasses
{

		Matrix4::Matrix4()
		{
			for (int i = 0; i < 16; i++)
			{
				v[i] = 0;
			}

			m1, m6, m11, m16 = 0;
		};

		Matrix4::Matrix4(float f_)
		{
			for (int i = 0; i < 16; i++)
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

		Matrix4::Matrix4(float f_[16])
		{
			m1 = f_[1];
			m2 = f_[2];
			m3 = f_[3];
			m4 = f_[4];
			m5 = f_[5];
			m6 = f_[6];
			m7 = f_[7];
			m8 = f_[8];
			m9 = f_[9];
			m10 = f_[10];
			m11 = f_[11];
			m12 = f_[12];
			m13 = f_[13];
			m14 = f_[14];
			m15 = f_[15];
			m16 = f_[16];
		};

		Matrix4 Matrix4::MakeIdentity()
		{
			Matrix4 identity;

			identity.m1 = 1.0f;
			identity.m6 = 1.0f;
			identity.m11 = 1.0f;
			identity.m16 = 1.0f;


			return identity;
		};

		float& Matrix4::operator[](int dim)
		{
			return v[dim];
		};

		const float& Matrix4::operator [](int dim) const
		{
			return v[dim];
		}
		
		Matrix4::operator float* ()
		{
			return &v[0];
		};

		Matrix4 Matrix4::operator*(const Matrix4& rhs) const
		{
			Matrix4 temp;

			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					int targetArray = (1 + y + (4 * x));

					temp[targetArray] = 
						(mm[x][0] * rhs.mm[0][y]) +
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
				};
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
		}
		Matrix4 Matrix4::MakeRotateX(float a)
		{
			return Matrix4(	1.0f,	0.0f,		0.0f,		0.0f,
							0.0f,	cosf(a),	-sinf(a),	0.0f,
							0.0f,	sinf(a),	cosf(a),	0.0f,
							0.0f,	0.0f,		0.0f,		1.0f
			);
		}
		Matrix4 Matrix4::MakeRotateY(float a)
		{
			return Matrix4(cosf(a), 0, -sinf(a), 0.0f,
				0.0f, 1, 0, 0.0f,
				sinf(a), 0.0f, cosf(a), 1.0f,
				0, 0, 0, 1
			);
		};

		Matrix4 Matrix4::MakeRotateZ(float a)
		{
			return Matrix4(cosf(a), -sinf(a), 0, 0,
				sinf(a), cosf(a), 0, 0,
				0.0f, 0.0f, 1, 0,
				0, 0, 0, 1
			);
		};

		Matrix4 Matrix4::MakeEuler(float pitch, float yaw, float roll)
		{
			Matrix4 x = MakeRotateX(pitch);
			Matrix4 y = MakeRotateY(yaw);
			Matrix4 z = MakeRotateZ(roll);

			return z * y * x;
		};

		Matrix4 Matrix4::MakeEuler(Vector3 v_)
		{

			return MakeEuler(v_.x, v_.y, v_.z);

		};

		Matrix4 Matrix4::MakeTranslation(float x_, float y_, float z_)
		{
			Matrix4 temp(1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				x_, y_, z_, 1);
			return temp;

		};

		Matrix4 Matrix4::MakeScale(float xScale, float yScale, float zScale)
		{
			return Matrix4(xScale, 0.0f, 0.0f, 0,
				0.0f, yScale, 0.0f, 0,
				0.0f, 0.0f, zScale, 0,
				0, 0, 0, 1
			);
		};


		Matrix4 Matrix4::MakeScale(Vector3 v_)
		{
			return MakeScale(v_.x,v_.y,v_.z);
		};

		Matrix4 Matrix4::MakeTranslation(Vector3 v_)
		{
			return MakeTranslation(v_.x, v_.y, v_.z);
		};

		std::string Matrix4::ToString() const
		{
			std::string output;

			for (int i = 0; i < 16; i++)
			{
				if ((i) % 4 == 0 && i > 0)
				{
					output.append( "\n");
				};
				output.append(std::to_string(float(v[i])));
			};
			

			return output;
		};
};
