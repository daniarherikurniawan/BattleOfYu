#include "Ship.h"

Ship::Ship() {
	mLines.clear();
}



Ship::Ship(string inputFile) {
	fstream inputStream;
	inputStream.open(inputFile.c_str());
	int numberOfComponent;
	inputStream >> numberOfComponent;
	while(numberOfComponent) {
		char typeOfComponent;
		inputStream >> typeOfComponent;
		if (typeOfComponent == '/') {
			string dummy;
			getline(inputStream,dummy);
			continue;
		}
		else if (typeOfComponent == 'L') {
			int x1,y1,x2,y2,red,green,blue;
			inputStream>>x1>>y1>>x2>>y2>>red>>green>>blue;
			Point beginPoint(x1,y1),endPoint(x2,y2);
			Color color(red,green,blue,0);
			mLines.push_back(Line(beginPoint,endPoint,color));
		}
		numberOfComponent--;
	}
	inputStream.close();
}

void Ship::readFromFile(string inputFile) {
	mLines.clear();
	fstream inputStream;
	inputStream.open(inputFile.c_str());
	int numberOfComponent;
	inputStream >> numberOfComponent;
	while(numberOfComponent) {
		char typeOfComponent;
		inputStream >> typeOfComponent;
		if (typeOfComponent == '/') {
			string dummy;
			getline(inputStream,dummy);
			continue;
		}
		else if (typeOfComponent == 'L') {
			int x1,y1,x2,y2,red,green,blue;
			inputStream>>x1>>y1>>x2>>y2>>red>>green>>blue;
			Point beginPoint(x1,y1),endPoint(x2,y2);
			Color color(red,green,blue,0);
			mLines.push_back(Line(beginPoint,endPoint,color));
		}
		numberOfComponent--;
	}
	inputStream.close();
}

vector<Line> Ship::getLines() const {
	return mLines;
}