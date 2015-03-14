
#include "../Pixel.h"
#include "../Screen.h"
#include "../Line.h"
#include "../Line3D.h"
#include <iostream>

Line* transform (Line3D* ln);
void translate (Line* ln, int x, int y);

float scale = 0.001;

int main () {
	Line3D* cube [12];
	int length = 100;
	double speed = 0.01;
	cube [0] = new Line3D(0,0,0,length,0,0);
	cube [1] = new Line3D(0,0,0,0,length,0);
	cube [2] = new Line3D(0,0,0,0,0,length);
	cube [3] = new Line3D(length,0,0,length,length,0);
	cube [4] = new Line3D(length,0,0,length,0,length);
	cube [5] = new Line3D(0,length,0,0,length,length);
	cube [6] = new Line3D(0,length,0,length,length,0);
	cube [7] = new Line3D(0,0,length,0,length,length);
	cube [8] = new Line3D(0,0,length,length,0,length);
	cube [9] = new Line3D(length,length,0,length,length,length);
	cube [10] = new Line3D(0,length,length,length,length,length);
	cube [11] = new Line3D(length,0,length,length,length,length);
	
	Point p(0,0);
	Point q(100,100);
	Color color(255,255,255,0);
	/*
	for(int i =0 ;i < 12; i++){
	 	Line line = cube[i]->getLine2D();
	 	Point bp = line.getBeginPoint();
	 	Point ep = line.getEndPoint();
		printf("%d %d %d %d\n",bp.x,bp.y,ep.x,ep.y);
	}*/
	
	Screen screen;
	for (int j = 0; j < 100000; j++) {
		screen.beginBatch();
		for(int i = 0; i < 12; i++){
			screen.draw(cube[i]);
		}
		screen.endBatch();
	}
	
	for (int i = 0; i < 12; i++) {
		delete cube[i];
	}
}
