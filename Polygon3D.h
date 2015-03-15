#ifndef POLYGON3D_H
#define POLYGON3D_H
#include <vector>
#include "Line3D.h"
#include "Drawable.h"
#include "Polygon.h"
#include <algorithm>
using namespace std;

class Polygon3D : public Drawable {
	vector<Line3D> lines;
	
public:
	Polygon3D();
	Polygon3D(string filename);
	Polygon3D(vector<Line3D>& lines);
	
	
	//dua line ini harus dipanggil sebelum dan sesudah draw
	void beforeDraw();
	void afterDraw();
	
	int getSize() const;
	
	Polygon convertToPolygon2D() const;
	void add(Line3D* line);
	void clear();
	vector<Pixel> getPixels() const;
	~Polygon3D();
	int getLeftMostX() const;
	int getTopMostY() const;
	
	void translate(double dx,double dy);
	void translate(double dx,double dy,double dz);
	
	vector<Line3D> getAllLine() const{return lines;}
};

#endif
