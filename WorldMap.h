#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include "Line.h"

class WorldMap {
private:
	vector<Line> mLines; 
public:
	WorldMap();
	vector<Line> getLines() const;
};

#endif