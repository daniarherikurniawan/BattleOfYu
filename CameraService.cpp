#include "CameraService.h"



Point3D CameraService::position(0.,0.,10.);
float CameraService::mCameraDegreeHorizontal = 0;
float CameraService::mCameraDegreeVertical = 0;

void CameraService::handleInput(){
	Point3D &campos = CameraService::position;
	
	if (Keyboard::isKeyDown()){
		if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_A){
			campos.translate(+DISPLACEMENT,0.,0.);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_D){
			campos.translate(-DISPLACEMENT,0.,0.);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_W){
			campos.translate(0.,+DISPLACEMENT,0.);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_S){
			campos.translate(0.,-DISPLACEMENT,0.);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_Q){
			campos.translate(0.,0.,+DISPLACEMENT);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_E){
			campos.translate(0.,0.,-DISPLACEMENT);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_L){
			exit(EXIT_SUCCESS);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_J){
			CameraService::mCameraDegreeHorizontal += 1;		
		}
	}
}

void CameraService::translate(double x0,double y0,double z0){
	Point3D &campos = CameraService::position;
	campos.x += x0; campos.y += y0; campos.z += z0;
}
