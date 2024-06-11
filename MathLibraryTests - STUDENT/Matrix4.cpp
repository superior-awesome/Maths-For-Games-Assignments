#include "../MathHeaders/Matrix4.h"
#include "../MathHeaders/Vector3.h"

#include <cmath>

namespace MathClasses
{
		//Default constructor. Sets all elements to zero.
		Matrix4::Matrix4()
		{
			for (int i = 0; i < 16; i++)
			{
				v[i] = 0;
			}

		}

		//Constructor sets all values to arg.
		Matrix4::Matrix4(float f_)
		{
			for (int i = 0; i < 16; i++)
			{
				v[i] = f_;
			};
		}

		//Constructor sets all values corresponding to sixteen arg (column then row).
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
		}

		//Constructor sets all values corresponding to a array arg (column then row).
		Matrix4::Matrix4(float f_[16])
		{

			for (int i = 0; i < 16; i++)
			{
				v[i] = f_[i];
			};
		}

		//Function creates and returns a identity matrix.
		Matrix4 Matrix4::MakeIdentity()
		{
			Matrix4 identity;

			identity.m1 = 1.0f;
			identity.m6 = 1.0f;
			identity.m11 = 1.0f;
			identity.m16 = 1.0f;


			return identity;
		}

		//Returns a mutable reference based on the subscript operator.
		float& Matrix4::operator[](int dim)
		{
			return v[dim];
		}

		//Returns a constant reference based on the subscript operator.
		const float& Matrix4::operator [](int dim) const
		{
			return v[dim];
		}
		
		//Returns the address of the first array data point.
		Matrix4::operator float* ()
		{
			return &v[0];
		}

		//Multiplies two Matrix4s and returns a new Matrix4.
		Matrix4 Matrix4::operator*(const Matrix4& rhs) const
		{
			Matrix4 temp;
			Matrix4 tempT;

			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					int targetArray = (x + (4 * y));
					temp[targetArray] =
						(mm[0][x] * rhs.mm[y][0]) +
						(mm[1][x] * rhs.mm[y][1]) +
						(mm[2][x] * rhs.mm[y][2]) +
						(mm[3][x] * rhs.mm[y][3]);
				};
			};
			return temp;
		}

		//Sets LHS to LHS Matrix4 times RHS Matrix4.
		Matrix4& Matrix4::operator*=(const Matrix4& rhs)
		{
			Matrix4 tempM42 = (*this) * rhs;

			for (int i = 0; i < 16; i++)
			{
				v[i] = tempM42[i];
			}
			return *this;
		}

		//Multiplies a Matrix4 and a Vector3 and returns a new Vector3.
		Vector4 Matrix4::operator*(Vector4 rhs) const
		{
			return Vector4(
				rhs.x * m1 + rhs.y * m5 + rhs.z * m9  + rhs.w * m13,
				rhs.x * m2 + rhs.y * m6 + rhs.z * m10 + rhs.w * m14,
				rhs.x * m3 + rhs.y * m7 + rhs.z * m11 +	rhs.w * m15,
				rhs.x * m4 + rhs.y * m8 + rhs.z * m12 + rhs.w * m16
			);
		}

		//Equality Matrix4 operator.
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
		}

		//Not equality Matrix4 operator.
		bool Matrix4::operator != (Matrix4 v_) const
		{
			return !((*this) == v_);
		}

		//Transposes affected Matrix4.
		Matrix4 Matrix4::Transposed() const
		{
			return Matrix4(m1, m5, m9, m13,
				m2, m6, m10, m14,
				m3, m7, m11, m15,
				m4, m8, m12, m16
			);
		}

		//Rotates Matrix4 by x (pitch).
		Matrix4 Matrix4::MakeRotateX(float a)
		{
			return Matrix4(	1.0f,	0.0f,		0.0f,		0.0f,
							0.0f,	cosf(a),	-sinf(a),	0.0f,
							0.0f,	sinf(a),	cosf(a),	0.0f,
							0.0f,	0.0f,		0.0f,		1.0f
			);
		}

		//Rotates Matrix4 by y (yaw).
		Matrix4 Matrix4::MakeRotateY(float a)
		{
			return Matrix4(	cosf(a),	0,		sinf(a),	0.0f,
							0.0f,		1,		0,			0.0f,
							-sinf(a),	0.0f,	cosf(a),	0,
							0,			0,		0,			1
			);
		}

		//Rotates Matrix4 by z (roll).
		Matrix4 Matrix4::MakeRotateZ(float a)
		{
			return Matrix4(cosf(a), sinf(a), 0, 0,
				-sinf(a), cosf(a), 0, 0,
				0.0f, 0.0f, 1, 0,
				0, 0, 0, 1
			);
		}

		//Recieves three arg as floats. Returns a Matrix4 which can be multiplied with a Matrix4 to rotate it in 3D space.
		Matrix4 Matrix4::MakeEuler(float pitch, float yaw, float roll)
		{
			Matrix4 x = MakeRotateX(pitch);
			Matrix4 y = MakeRotateY(yaw);
			Matrix4 z = MakeRotateZ(roll);

			return z * y * x;
		}

		//Recieves one arg as a Vector3. Returns a Matrix4 which can be multiplied with a Matrix4 to rotate it in 3 dimensions.
		Matrix4 Matrix4::MakeEuler(Vector3 v_)
		{
			return MakeEuler(v_.x, v_.y, v_.z);
		}

		//Recieves three arg as floats. Returns a Matrix4 which can be multiplied with a Matrix4 to scale it in 3 dimensions.
		Matrix4 Matrix4::MakeTranslation(float x_, float y_, float z_)
		{
			Matrix4 tempM43(1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				x_, y_, z_, 1);
			return tempM43;
		}

		//Recieves two arg as floats. Returns a Matrix4 which can be multiplied with a Matrix4 to scale it in 2 dimensions.
		Matrix4 Matrix4::MakeScale(float xScale, float yScale, float zScale)
		{
			return Matrix4(xScale, 0.0f, 0.0f, 0,
				0.0f, yScale, 0.0f, 0,
				0.0f, 0.0f, zScale, 0,
				0, 0, 0, 1
			);
		}

		//Recieves one arg as a Vector3. Returns a Matrix4 which can be multiplied with a Matrix4 to scale it in 3 dimensions.
		Matrix4 Matrix4::MakeScale(Vector3 v_)
		{
			return MakeScale(v_.x,v_.y,v_.z);
		}

		//Takes a Vector3 and sets location in space.
		Matrix4 Matrix4::MakeTranslation(Vector3 v_)
		{
			return MakeTranslation(v_.x, v_.y, v_.z);
		}

		//Formats the matrix for debugging purpouses.
		std::string Matrix4::ToString() const
		{
			std::string output;
					output.append( "\n");

			for (int i = 0; i < 16; i++)
			{
				if ((i) % 4 == 0 && i > 0)
				{
					output.append( "\n");
				};
				output.append(std::to_string(float(v[i])));
				output.append(" ,");
			};
			
			output.append( "\n");

			return output;
		}
};
