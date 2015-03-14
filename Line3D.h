#ifndef LINE3D_H
#define LINE3D_H

struct Podouble3D {
	double x;
	double y;
	double z;
	Podouble3D(double x0, double y0, double z0) : x(x0), y(y0), z(z0) {} 
	void translate (double x0, double y0, double z0) {x += x0; y+=y0; z+=z0;}
};


struct Line3D {
	Podouble3D p1, p2;
	Line3D(double x0, double y0, double z0, double x1, double y1, double z1) : p1(x0,y0,z0) , p2(x1,y1,z1) {}
	void translate(double x0, double y0, double z0) {p1.translate(x0,y0,z0);p2.translate(x0,y0,z0);}
};
#endif
