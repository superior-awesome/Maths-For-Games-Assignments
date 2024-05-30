#include "..\MathHeaders\Colour.h"
#include <iostream>


namespace MathClasses
{
	//Default constructor. Defaults to "0,0,0,255".
	Colour::Colour()
	{
		colour = 0x0;
		SetAlpha(255);
	}
	
	//Constructor takes numbers 0<=1<256 or returns default constructor.
	Colour::Colour(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_)
	{
		if (
			r_ <= 255 && r_ >= 0 &&
			g_ <= 255 && g_ >= 0 &&
			b_ <= 255 && b_ >= 0 &&
			a_ <= 255 && a_ >= 0
			)
		{
			colour = 0x0;
			SetRed(r_);
			SetGreen(g_);
			SetBlue(b_);
			SetAlpha(a_);
		}
		else
		{
			colour = 0x0;
			SetAlpha(255);
		}
	};

	//Equality operator.
	bool Colour::operator==(Colour c_)
	{
		if (
			GetRed() == c_.GetRed() &&
			GetBlue() == c_.GetBlue() &&
			GetGreen() == c_.GetGreen() &&
			GetAlpha() == c_.GetAlpha()
			)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	//Not Equality operator.
	bool Colour::operator!=(Colour c_)
	{
		return !((*this) == c_);
	}

	//Returns the Red value 0<=n<256.
	unsigned char Colour::GetRed() const
	{
		return colour >> 24;
	}

	//Returns the Green value 0<=n<256.
	unsigned char Colour::GetGreen() const
	{
		return colour >> 16;
	}

	//Returns the Blue value 0<=n<256.
	unsigned char Colour::GetBlue() const
	{
		return colour >> 8;
	}

	//Returns the Alpha value 0<=n<256.
	unsigned char Colour::GetAlpha() const
	{
		return colour;
	}

	//Sets the Alpha value 0<=n<256.
	void Colour::SetRed(unsigned char input)
	{

		unsigned int R = input << 24;

		colour = colour & 0xFFFFFF;

		colour = colour | R;
	}

	//Sets the Green value 0<=n<256.
	void Colour::SetGreen(unsigned char input)
	{
		unsigned int G = input << 16;

		colour = colour & 0xFF00FFFF;

		colour = colour | G;
	}

	//Sets the Blue value 0<=n<256.
	void Colour::SetBlue(unsigned char input)
	{
		unsigned int B = input << 8;

		colour = colour & 0xFFFF00FF;

		colour = colour | B;
	}

	//Sets the Alpha value 0<=n<256.
	void Colour::SetAlpha(unsigned char input)
	{
		unsigned int A = input;

		colour = colour & 0xFFFFFF00;

		colour = colour | A;
	}

	//Prints the colour to cout as a Binary.
	void Colour::printColour()
	{

		unsigned int bitTest = 0X80000000;

		for (int i = 0; i < 32; i++)
		{
			if (i % 8 == 0 && i > 0)
			{
				std::cout << " ";
			}

			if (colour & bitTest)
			{
				std::cout << "1";
			}
			else
			{
				std::cout << "0";
			}
			bitTest /= 2;
		};
		std::cout << std::endl;
	};
};