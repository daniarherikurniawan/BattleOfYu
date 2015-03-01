#include "WorldMap.h"

WorldMap::WorldMap() {
	Line line1(Point(-1,-1),Point(99,99),Color(255,0,0,0));
	Line line2 (Point(25,0),Point(25,100),Color(255,0,0,0));
	mLines.push_back(line1);
	mLines.push_back(line2);
}

vector<Line> WorldMap::getLines() const{
	return mLines;
}