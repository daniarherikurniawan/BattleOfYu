#include "CameraService.h"



Point3D CameraService::position(0.,0.,10.);
float CameraService::mCameraDegreeHorizontal = 0;
float CameraService::mCameraDegreeVertical = 0;

void CameraService::handleInput(){
	Point3D &campos = CameraService::position;
	
	if (Keyboard::getBufferedCode() != 0){
		if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_A){
			campos.translate(-DISPLACEMENT,0.,0.);
		} else if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_D){
			campos.translate(+DISPLACEMENT,0.,0.);
		} else if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_W){
			campos.translate(0.,+DISPLACEMENT,0.);
		} else if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_S){
			campos.translate(0.,-DISPLACEMENT,0.);
		} else if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_Q){
			campos.translate(0.,0.,+DISPLACEMENT);
		} else if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_E){
			campos.translate(0.,0.,-DISPLACEMENT);
		} else if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_EXIT){
			exit(EXIT_SUCCESS);
		}
	}
}

void CameraService::translate(double x0,double y0,double z0){
	Point3D &campos = CameraService::position;
	campos.x += x0; campos.y += y0; campos.z += z0;
}
