#include "Polygon3D.h"

Polygon3D::Polygon3D(){
}

Polygon3D::~Polygon3D(){
	lines.clear();
}

Polygon3D::Polygon3D(vector<Line3D>& __lines){
	lines.clear();
	for(unsigned int i = 0; i < __lines.size(); ++i){
		lines.push_back(__lines[i]);
	}
}

Polygon3D::Polygon3D(string filename){
/*
	ifstream inputStream;
	inputStream.open(fileName.c_str());
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
		} else {
			printf("Unknown type of component in file %s: %c\n",fileName.c_str(),typeOfComponent);
		}
		numberOfComponent--;
	}
	inputStream.close();*/
}

void Polygon3D::add(Line3D* line){
	Line3D _line = *line;
	lines.push_back(_line);	
}

void Polygon3D::clear(){
	(lines).clear();
}

void Polygon3D::beforeDraw(){
	for(int i = 0; i < getSize(); i++){
		lines[i].beforeDraw();
	}
}

void Polygon3D::afterDraw(){
	for(int i = 0; i < getSize(); i++){
		lines[i].afterDraw();
	}
}

Polygon Polygon3D::convertToPolygon2D() const {
	Polygon p;
	for(int i = 0; i < getSize(); i++){
		p.add(lines[i].getLine2D());
	}
	return p;
}


vector<Pixel> Polygon3D::getPixels() const{
	Polygon p2d = convertToPolygon2D();
	return p2d.getPixels();
}

int Polygon3D::getSize() const {
	return lines.size();
}
int Polygon3D::getLeftMostX() const {
	int left_most_x = lines[0].getBeginPoint().x;
	for(unsigned int i = 0; i < lines.size(); i++){
		int x = min(lines[i].getBeginPoint().x,lines[i].getEndPoint().x);	
		left_most_x = min(left_most_x,x);
	}
	return left_most_x;	
}

int Polygon3D::getTopMostY() const{
	int lmy = lines[0].getBeginPoint().x;
	for(unsigned int i = 0; i < lines.size(); i++){
		int y = min(lines[i].getBeginPoint().y,lines[i].getEndPoint().y);
		lmy = min(lmy,y);
	}
	return lmy;
}

void Polygon3D::translate(double dx,double dy,double dz){
	for(int i = 0; i < getSize(); i++){
		lines[i].translate(dx,dy,dz);
	}
}

void Polygon3D::translate(double dx,double dy){
	double dz = 0;
	translate(dx,dy,dz);
}

