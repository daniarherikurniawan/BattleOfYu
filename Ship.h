#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>
#include <fstream>

#include "Line.h"

class Ship {
private:
	vector<Line> mLines; 
public:
	int x;
	int y;
	Ship();
	Ship(string inputFile);
	vector<Line> getLines() const;
	void readFromFile(string inputFile);
	void moveBy(int x, int y);
};

#endif
