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
}

// DO ZOOM
/******************************************************************************/
pair<double, double> ZoomList::doZoom(int x, int y)
{
	return pair<double, double>(0,0);
}
