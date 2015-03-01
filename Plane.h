#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <iostream>
#include <fstream>

#include "Line.h"

class Plane {
private:
	vector<Line> mLines; 
public:
	Plane();
	Plane(string inputFile);
	vector<Line> getLines() const;
	void readFromFile(string inputFile);
};

#endif