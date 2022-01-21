#include <iomanip>
#include "PixelInfo.hpp"

using namespace std;

std::ostream& operator<<(std::ostream& out, const PixelInfo& pi)
{
	out << "(" << setw(3) << pi.x << "," << setw(3) << pi.y << "): " 
		<< pi.numIterations;

	return out;
}


