#pragma once

namespace MathClasses
{
    struct Colour
	{
	public:

		Colour();

		Colour(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_);

		bool operator==(Colour c_);

		bool operator!=(Colour c_);

		unsigned char GetRed() const;
		unsigned char GetGreen() const;
		unsigned char GetBlue() const;
		unsigned char GetAlpha() const;

		void SetRed(unsigned char input);
		void SetGreen(unsigned char input);
		void SetBlue(unsigned char input);
		void SetAlpha(unsigned char input);

		void printColour();

		unsigned int colour;
	private:

	};
}