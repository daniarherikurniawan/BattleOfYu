#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <string>
#include <iostream>
#include <fstream>

#include "Line.h"
#include "Plane.h"
#include "Ship.h"

class WorldMap {
private:
	vector<Line> mLines; 
	Plane plane;
	Ship ship;
	vector<Line> allLines;
public:
	WorldMap();
	WorldMap(string inputFile);
	vector<Line> getLines() const;
};

#endif