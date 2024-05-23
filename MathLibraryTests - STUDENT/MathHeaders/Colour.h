#pragma once

namespace MathClasses
{
    struct Colour
	{
	public:

		Colour();

		unsigned char GetRed() const;
		unsigned char GetGreen() const;
		unsigned char GetBlue() const;
		unsigned char GetAlpha() const;

		void SetRed(unsigned char input);
		void SetGreen(unsigned char input);
		void SetBlue(unsigned char input);
		void SetAlpha(unsigned char input);

		void printColour();

	private:
		unsigned int colour;

	};
}