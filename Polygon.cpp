#include "Polygon.h"

Polygon::Polygon(){}
Polygon::~Polygon(){}


//nanti ini diganti
vector<Pixel> Polygon::getPixels() const{
	vector<Pixel> retval;
	for(int i = 0; i < getSize(); i++){
		vector<Pixel> linePixel = lines[i].getPixels();
		for(int j = 0; j < (int) linePixel.size(); ++j){
			retval.push_back(linePixel[j]);
		}
	}
	return retval;
}
/*
vector<Pixel> Polygon::getPixels() const {
	vector<Point> points = getPointsInside();
	
	vector<Pixel> pixels;
	for(int i = 0; i < (int) points.size(); i++){
		Pixel pixel(points[i],mColor);
		pixels.push_back(pixel);
	}
	return pixels;
}*/

Point Polygon::getTopLeft() const {
	Point ret;
	for(int i = 0; i < getSize(); ++i){
		if (i == 0){
			ret = lines[i].getBeginPoint();
		}
		Point bp = lines[i].getBeginPoint();
		Point ep = lines[i].getEndPoint();
		ret.x = min(ret.x,min(bp.x,ep.x));
		ret.y = min(ret.y,min(bp.y,ep.y));
	}
	return ret;
}

Point Polygon::getBottomRight() const{
	Point ret;
	for(int i = 0; i < getSize(); ++i){
		if (i == 0){
			ret = lines[i].getBeginPoint();
		}
		Point bp = lines[i].getBeginPoint();
		Point ep = lines[i].getEndPoint();
		ret.x = max(ret.x,max(bp.x,ep.x));
		ret.y = max(ret.y,max(bp.y,ep.y));
	}
	return ret;
}
	
vector<Point> Polygon::getPointsInside() const {
	//buat persegi panjang
	Point topLeft = getTopLeft();
	Point bottomRight = getBottomRight();
	vector<Point> retval;
	
	//untuk setiap titik
	for(int x = topLeft.x; x <= bottomRight.x; x++){
		for(int y = topLeft.y; y <= bottomRight.y; y++){		
			Point p(x,y);
			//jika didalam polygon
			if (pointInPolygon(p)){
				retval.push_back(p);
			}
		}
	}
	return retval;
}

void Polygon::add(Line line){
	lines.push_back(line);
}


int Polygon::getLeftMostX() const {
	int left_most_x = lines[0].getBeginPoint().x;
	for(unsigned int i = 0; i < lines.size(); i++){
		int x = min(lines[i].getBeginPoint().x,lines[i].getEndPoint().x);	
		left_most_x = min(left_most_x,x);
	}
	return left_most_x;	
}

int Polygon::getTopMostY() const{
	int lmy = lines[0].getBeginPoint().x;
	for(unsigned int i = 0; i < lines.size(); i++){
		int y = min(lines[i].getBeginPoint().y,lines[i].getEndPoint().y);
		lmy = min(lmy,y);
	}
	return lmy;
}

bool Polygon::pointInPolygon(Point p) const{
	const double PI = 3.14159265;
	const double EPS = 0.00001;
	if ((int) lines.size() == 0) return false;
	double sum = 0;
	for(int i = 0; i < (int) lines.size(); i++){
		Point q = lines[i].getBeginPoint();
		Point r = lines[i].getEndPoint();
		if (Point::crossProduct(p,q,r) < 0.){
			sum -= Point::angle(p,q,r);
		} else {
			sum += Point::angle(p,q,r);
		}
	}
	return (fabs(sum - 2 * PI) < EPS || fabs(sum + 2 * PI) < EPS);
}

int Polygon::getSize() const{
	return (int) lines.size();
}

void Polygon::translate(int dx,int dy){
	for(int i = 0; i < getSize(); ++i){
		lines[i].translate(dx,dy);
	}
}

void Polygon::printLines() const{
	for(int i = 0; i < getSize(); ++i){
		Point bp = lines[i].getBeginPoint();
		Point ep = lines[i].getEndPoint();
		printf("%d %d %d %d\n",bp.x,bp.y,ep.x,ep.y);
	}
}
