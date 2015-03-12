
#include "../Pixel.h"
#include "../Screen.h"
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
	//kubus taruh tengah
	pcube.translate(length*3.5,length*3.5,0);
	for (int i = 0; i < 12; i++) {
		
		cube[i]->translate(length*3.5,length*3.5,0);
	}

	Screen screen;
	//kamera digeser terus ke kanan, ke bawah, terus di zoom
	//kubusnya bakal gerak ke kiri, ke atas, zoom
	
	//init posisi kamera
	CameraService::position.x = 0;
	CameraService::position.y = 0;
	CameraService::position.z = 0;
	Keyboard::startListening();
	while (1){
		screen.beginBatch();
		screen.draw(&pcube);
		CameraService::handleInput();
		screen.endBatch();
	}
	
	for (int i = 0; i < 12; i++) {
		delete cube[i];
	}
}


Line* transform (Line3D* ln) {
	Point first, last;
	first.x = (ln->getBeginPoint()).x / ((ln->getBeginPoint()).z*scale + 1);
	first.y = (ln->getBeginPoint()).y / ((ln->getBeginPoint()).z*scale + 1);
	last.x = (ln->getEndPoint()).x / ((ln->getEndPoint()).z*scale + 1);
	last.y = (ln->getEndPoint()).y / ((ln->getEndPoint()).z*scale + 1);
	Color white(255,255,255,0);
	Line* l = new Line(first,last,white);
	return l;
}

void translate (Line* ln, int x, int y) {
	Point p1 = ln->getBeginPoint();
	Point p2 = ln->getEndPoint();
	Color c = ln->getColor();
	p1.x = p1.x + x;
	p1.y = p1.y + y;
	p2.x = p2.x + x;
	p2.y = p2.y + y;
	ln->setBeginPoint(p1);
	ln->setEndPoint(p2);
}
