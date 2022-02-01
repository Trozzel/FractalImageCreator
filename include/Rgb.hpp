#ifndef __RGB_HPP__
#define __RGB_HPP__

#include <ostream>
class Rgb
{
private:
	double _red{};
	double _green{};
	double _blue{};
public:
	Rgb(double red, double green, double blue) ;

	Rgb& operator-=(const Rgb& other);

	inline double red()   { return _red; }
	inline double green() { return _green; }
	inline double blue()  { return _blue; }
	
	friend Rgb operator-  (const Rgb& rgb1, const Rgb& rgb2);
	friend std::ostream& operator<<(std::ostream&, const Rgb&);
};

#endif // __RGB_HPP__
