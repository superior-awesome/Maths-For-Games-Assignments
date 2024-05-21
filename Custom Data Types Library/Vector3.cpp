#include "Vector3.h"
#include <cmath>
#include <iostream>



//	Default constructor.
Vector3::Vector3() 
{
	x = 0;
	y = 0;
	z = 0;
}

//	Constructor, sets all three floats to the argument.
Vector3::Vector3(float f)
{
	x = f;
	y = f;
	z = f;
}
//	Constructor, sets all three floats to the three arguments.
Vector3::Vector3(float x_, float y_, float z_)
{
	x = x_;
	y = y_;
	z = z_;
}

//	Operator overload, adds two vectors and returns a new Vector3.
Vector3 Vector3::operator+(const Vector3& input_) 
{
	Vector3 output;
	output.x = x + input_.x;
	output.y = y + input_.y;
	output.z = z + input_.z;
	return output;
}

//Operator overload, adds a Vector3 to the LHS Vector3.
Vector3& Vector3::operator+=(const Vector3& input_)
{
	x += input_.x;
	y += input_.y;
	z += input_.z;
	return *this;
}

//	Operator overload, subtracs RHS from LHS and returns a new Vector3.
Vector3 Vector3::operator-(const Vector3& input_)
{
	Vector3 output;

	output.x = x - input_.x;
	output.y = y - input_.y;
	output.z = z - input_.z;
	return output;
}

//Operator overload, multiplies a Vector3 with the LHS float.
Vector3& Vector3::operator*=(const float& input_)
{
	x *= input_;
	y *= input_;
	z *= input_;
	return *this;
}

//Operator overload, multiplies a Vector 3 with a float and returns a new Vector3.
Vector3 Vector3::operator*(const float& input_) const
{
	Vector3 temp(x * input_, y * input_, z * input_);
	return temp;
}

//Operator overload, multiplies a Vector3 with the LHS float.
Vector3 operator*(float scale, const Vector3 V3_)
{
	Vector3 temp = V3_ * scale;
	return temp;
}

//Operatotr overload, divides a Vector3 by a float.
Vector3 Vector3::operator/(const float& input_) const
{
	Vector3 temp(x / input_, y / input_, z / input_);

	return temp;
}

// Performs Dot-Product on Vector3, returning a new float.

float Vector3::Dot(const Vector3 V3_) const
{
	return (x * V3_.x + y * V3_.y + z * V3_.z);
}
// Performs Cross Product on Vector3, returning a new Vector3.
Vector3 Vector3::Cross(const Vector3& V3_) const
{
	Vector3 temp(
		y*V3_.z - z*V3_.y,
		z*V3_.x - x*V3_.z,
		x*V3_.y - y*V3_.x
	);
	return temp;
}

// Returns the magnitude of a Vector3 in a new float.
float Vector3::Magnitude(const Vector3& V3_) const
{
	float temp = sqrtf(pow(V3_.x,2.0f) + pow(V3_.y,2.0f) + pow(V3_.z,2.0f));
	return temp;
}

// Returns the unit vector of a Vector3 as a new float.
Vector3 Vector3::Normalize(const Vector3& V3_) const
{
	return V3_ / Magnitude(V3_);
}


// Multiplies a Vector3 by a Matrix3 to return a new Vector3.
Vector3 Vector3::operator*(const Matrix3& Mat3_)
{
	Vector3 temp;
	
	temp.x = Mat3_.m11 * x + Mat3_.m12 * y + Mat3_.m13 * z;
	temp.y = Mat3_.m21 * x + Mat3_.m22 * y + Mat3_.m23 * z;
	temp.z = Mat3_.m31 * x + Mat3_.m32 * y + Mat3_.m33 * z;

	return temp;
}

Vector3& Vector3::operator*=(const Matrix3& Mat3_)
{
	std::cout << "PING" << std::endl;
	
	Vector3 temp = (*this) * Mat3_;

	x = temp.x;
	y = temp.y;
	z = temp.z;

	return *this;
}



//	_________________________________________________________________
//	Debuggining Functions Below This Point

void Vector3::PrintVec3()
{
	std::cout <<"[" << x << "]" <<
		"\n[" << y << "]" <<
		"\n[" << z << "]" <<
		"\n\n" << std::endl;
}
/*
*/