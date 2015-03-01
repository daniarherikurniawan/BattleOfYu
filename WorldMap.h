#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <string>
#include <iostream>
#include <fstream>

#include "Line.h"

class WorldMap {
private:
	vector<Line> mLines; 
public:
	WorldMap();
	WorldMap(string inputFile);
	vector<Line> getLines() const;
};

#endif