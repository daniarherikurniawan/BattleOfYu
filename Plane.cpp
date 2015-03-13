#include "Plane.h"

Plane::Plane() {
	mLines.clear();
	this->x = 0;
	this->y = 0;
}

Plane::Plane(string inputFile) {
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
	this->x = 0;
	this->y = 0;
}

void Plane::readFromFile(string inputFile) {
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

void Plane::moveBy(int x, int y){
	this->x = this->x + x;
	this->y = this->y + y;

	for(int i = 0; i < mLines.size(); i++) {
		Point mNewBegin, mNewEnd;
		mNewBegin.x = mLines[i].getBeginPoint().x + x;
		mNewBegin.y = mLines[i].getBeginPoint().y + y;
		mNewEnd.x = mLines[i].getEndPoint().x + x;
		mNewEnd.y = mLines[i].getEndPoint().y + y;

		mLines[i].setBeginPoint(mNewBegin);
		mLines[i].setEndPoint(mNewEnd);
	}
}

vector<Line> Plane::getLines() const {
	return mLines;
}
