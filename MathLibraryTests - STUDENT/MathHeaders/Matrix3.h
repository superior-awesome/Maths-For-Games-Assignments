namespace MathClasses
{
	class Matrix3
	{
		union
		{
			struct
			{
				float m1, m2, m3, m4, m5, m6, m7, m8, m9;
			};
			float v[9];
			float mm[3][3];
			class Vector3 axis[3];
		};


	public:

		Matrix3();

		Matrix3(float f_);

		Matrix3(float m1_, float m2_, float m3_,
			float m4_, float m5_, float m6_,
			float m7_, float m8_, float m9_);

		static Matrix3 MakeIdentity();


		float& operator[](int dim);

		const float& operator [](int dim) const;

		Matrix3 operator*(const Matrix3& rhs) const;

		Matrix3& operator*=(Matrix3& rhs);
		Matrix3& operator*=(const Matrix3& rhs);

		class Vector3 operator*(Vector3 rhs) const;

		bool operator == (class Matrix3 v_) const;

		bool operator != (class Matrix3 v_) const;

		Matrix3 Transposed() const;

		Matrix3 MakeRotateX(float a);
		Matrix3 MakeRotateY(float a);
		Matrix3 MakeRotateZ(float a);

		Matrix3 MakeEuler(float pitch, float yaw, float roll);

		Matrix3 MakeScale(Vector3 scale);
		Matrix3 MakeScale(float xScale, float yScale, float zScale);



	};
}
