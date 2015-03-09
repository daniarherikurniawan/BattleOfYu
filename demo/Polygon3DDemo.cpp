
#include "../Pixel.h"
#include "../Line.h"
#include "../Line3D.h"
#include "../CameraService.h"
#include "../Polygon3D.h"
#include <iostream>

Line* transform (Line3D* ln);
void translate (Line* ln, int x, int y);

float scale = 0.001;

int main () {
	Line3D* cube [12];
	int length = 100;
	double speed = 0.01;
	//U R D L
	//face
	cube [0] = new Line3D(0,0,0,0,length,0);
	cube [1] = new Line3D(0,length,0,length,length,0);
	cube [2] = new Line3D(length,length,0,length,0,0);
	cube [3] = new Line3D(length,0,0,0,0,0);
	//left
	//cube[0]
	cube [4] = new Line3D(0,length,0,0,length,length);
	cube [5] = new Line3D(0,length,length,0,0,length);
	cube [6] = new Line3D(0,0,length,0,0,0);
	//right
	//cube[2]
	cube[7] = new Line3D(length,length,0,length,length,length);
	cube[8] = new Line3D(length,length,length,length,0,length);
	cube[9] = new Line3D(length,0,length,length,0,0);
	//back
	cube[10] = new Line3D(0,length,length,length,length,length);
	cube[11] = new Line3D(0,0,length,length,0,length);
	
	Polygon3D pcube;
	for(int i = 0; i < 12; i++){
		pcube.add(cube[i]);
	}
	CameraService::position.x = 0;
	CameraService::position.y = 0;
	CameraService::position.z = 0;
	
	Polygon p2d = pcube.getPolygon2D();
	printf("before translate\n");
	p2d.printLines();
	
	printf("after translate (-length,0,0)\n");
	pcube.translate(-length,0,0);
	p2d = pcube.getPolygon2D();
	p2d.printLines();
	
	printf("after translate again (0,-length,0)\n");
	pcube.translate(0,-length,0);
	p2d = pcube.getPolygon2D();
	p2d.printLines();
	for (int i = 0; i < 12; i++) {
		delete cube[i];
	}
}
