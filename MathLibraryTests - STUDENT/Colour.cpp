#include "..\MathHeaders\Colour.h"
#include <iostream>


namespace MathClasses
{
	Colour::Colour()
	{
		colour = 0x0;
	}

	unsigned char Colour::GetRed() const
	{
		return colour >> 24;
	}

	unsigned char Colour::GetGreen() const
	{
		return colour >> 16;
	}

	unsigned char Colour::GetBlue() const
	{
		return colour >> 8;
	}

	unsigned char Colour::GetAlpha() const
	{
		return colour;
	}

	void Colour::SetRed(unsigned char input)
	{
		unsigned int R = input << 24;

		colour = colour & 0xFFFFFF;

		colour = colour | R;
	}

	void Colour::SetGreen(unsigned char input)
	{
		unsigned int G = input << 16;

		colour = colour & 0xFF00FFFF;

		colour = colour | G;
	}

	void Colour::SetBlue(unsigned char input)
	{
		unsigned int B = input << 8;

		colour = colour & 0xFFFF00FF;

		colour = colour | B;
	}

	void Colour::SetAlpha(unsigned char input)
	{
		unsigned int A = input;

		colour = colour & 0xFFFFFF00;

		colour = colour | A;
	}

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
		}

		std::cout << std::endl;

	}
}