#include <iostream>
#include "ZoomList.hpp"

using namespace std;

// CTOR
/******************************************************************************/
ZoomList::ZoomList(int w, int h) : 
	_width(w), _height(h)
{
}

// ADD
/******************************************************************************/
void ZoomList::add(const Zoom& zoom)
{
	zooms.push_back(zoom);
	_xCenter += (zoom.x - (double)_width  / 2) * _scale;
	_yCenter += (zoom.y - (double)_height / 2) * _scale;

	_scale *= zoom.scale;
}

// DO ZOOM
/******************************************************************************/
pair<double, double> ZoomList::doZoom(int x, int y)
{
	double xFractal {  (x - (double)_width  / 2) * _scale + _xCenter };
	double yFractal { -(y - (double)_height / 2) * _scale + _yCenter };

	return pair<double, double>(xFractal, yFractal);
}
