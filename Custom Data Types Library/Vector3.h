#pragma once
class Vector3
{
public:
	float x, y, z;

	Vector3();
	Vector3(float f);
	Vector3(float x_, float y_, float z_);

	Vector3 operator+ (const Vector3& input_);
	Vector3 operator- (const Vector3& input_);
	Vector3 operator*(const float& input_) const;
	Vector3 operator/(const float& input_) const;

	friend Vector3 operator* (float scale, const Vector3 V3_);

	Vector3& operator+= (const Vector3& input_);
	Vector3& operator*= (const float& input_);

	float Dot(const Vector3 V3_);
	Vector3 Cross(const Vector3 V3_);
	float Magnitude(const Vector3 V3_);
};



