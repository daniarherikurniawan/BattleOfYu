#ifndef LINE3D_H
#define LINE3D_H

#include "Pixel.h"
#include "Drawable.h"
#include "Line.h"



class Line3D: public Drawable {
private:
	Point3D mBeginPoint,mEndPoint;
	Color mColor;
	
public:
	Point3D getBeginPoint();
	Point3D getEndPoint();
	Color getColor() const;
	void setBeginPoint(Point3D value);
	void setEndPoint(Point3D value);
	
	Line getLine2D();
	//kedua fungsi ini harus dipanggil sebelum dan sesudah draw
	void beforeDraw();
	void afterDraw();
	
	Line3D(Point3D beginPoint,Point3D endPoint,Color color);
	Line3D(double x0, double y0, double z0, double x1, double y1, double z1);
	void translate(double x0, double y0, double z0);
	vector<Pixel> getPixels() const;
	void rotate(int angle,int x,int y);
	int getLeftMostX() const;
	int getTopMostY() const;
	
};
#endif
