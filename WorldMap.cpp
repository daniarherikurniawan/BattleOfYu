#include "WorldMap.h"

WorldMap::WorldMap() {
	Line line1(Point(-1,-1),Point(99,99),Color(255,0,0,0));
	Line line2 (Point(25,0),Point(25,100),Color(255,0,0,0));
	mLines.push_back(line1);
	mLines.push_back(line2);
}

WorldMap::WorldMap(string inputFile) {
	ifstream inputStream;
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

vector<Line> WorldMap::getLines() const{
	return mLines;
}