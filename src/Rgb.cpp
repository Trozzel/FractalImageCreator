#include "Rgb.hpp"

using namespace std;

Rgb::Rgb(double red, double green, double blue) :
	_red(red), _green(green), _blue(blue)
{}

Rgb& Rgb::operator-=(const Rgb& other)
{
	_red   = ( _red - other._red > 0.0)     ? _red -   other._red   : 0;
	_green = ( _green - other._green > 0.0) ? _green - other._green : 0;
	_blue  = ( _blue - other._blue > 0.0)   ? _blue -  other._blue  : 0;
	return *this;
}


Rgb operator-  (const Rgb& rgb1, const Rgb& rgb2)
{
	//double red = (rgb1._red - rgb2._red > 0) ? 
	//	rgb1._red - rgb2._red :
	//	0.0;
	//double green = (rgb1._green - rgb2._green > 0) ?
	//	rgb1._green - rgb2._green :
	//	0.0;
	//double blue = (rgb1._blue - rgb2._blue > 0) ?
	//	rgb1._blue - rgb2._blue :
	//	0.0;

	//return Rgb( red, blue, green );
	return Rgb(
			rgb1._red - rgb2._red,
			rgb1._green - rgb2._green,
			rgb1._blue - rgb2._blue
			);
}

ostream& operator<<(ostream& out, const Rgb& rgb)
{
	out << "(" << rgb._red << "," << rgb._green << "," << rgb._blue << ")";
	return out;
}
