#include <complex>
#include <cmath>

#include "Mandelbrot.hpp"

using namespace std;

int Mandelbrot::getIterations(double x, double y)
{
	int numIterations {0};
	
	complex<double> z {0};
	complex<double> c (x, y);

	while (numIterations < MAX_ITERATIONS) {
		z = z*z + c;

		if ( abs(z) > 2 ) {
			break;
		}
		++numIterations;
	}
	
	return numIterations;
}
