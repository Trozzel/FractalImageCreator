#ifndef __FRACTALCREATOR_HPP__
#define __FRACTALCREATOR_HPP__

#include <string>

#include "Zoom.hpp"

class FractalCreator
{
private:

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void drawFractal();
	void addZoom(const Zoom& zoom);
	void writeBitmap(const std::string& name);
};

#endif // __FRACTALCREATOR_HPP__
