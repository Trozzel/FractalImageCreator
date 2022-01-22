#ifndef __MANDELBROT_HPP__
#define __MANDELBROT_HPP__

class Mandelbrot
{
public:
	static const int MAX_ITERATIONS { 1000 };
public:
	static int getIterations(double x, double y);
};

#endif // __MANDELBROT_HPP__
