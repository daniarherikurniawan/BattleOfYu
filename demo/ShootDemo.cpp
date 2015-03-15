
#include "../Pixel.h"
#include "../Screen.h"
#include "../Line.h"
#include "../Line3D.h"
#include "../CameraService.h"
#include "../Polygon3D.h"
#include <iostream>
#include "../EnemyManager.h"

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
	Polygon3D pcube2;
	for(int i = 0; i < 12; i++){
		pcube.add(cube[i]);
	}
	for(int i= 0; i < 12; i++){
		pcube2.add(cube[i]);
	}
	
	//kubus taruh tengah
	pcube.translate(-200,0,0);
	pcube2.translate(200,0,0);
	//pcube2.translate(-400.,0.,0.);
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
	EnemyManager enemyManager(&screen);
	enemyManager.start();
	
	while (1){
		Keyboard::updateBufferedCode();
		screen.beginBatch();
		CameraService::handleInput();
		enemyManager.loop();
		screen.draw(&pcube);
		screen.draw(&pcube2);
		enemyManager.draw();
		screen.endBatch();
	}
	
	for (int i = 0; i < 12; i++) {
		delete cube[i];
	}
}
