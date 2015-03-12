#include "CameraService.h"



Point3D CameraService::position(0.,0.,10.);

void CameraService::handleInput(){
	Point3D &campos = CameraService::position;
	
	if (Keyboard::isKeyDown()){
		if (Keyboard::getKeyDownCode() == Keyboard::KEY_A){
			campos.translate(-DISPLACEMENT,0.,0.);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEY_D){
			campos.translate(+DISPLACEMENT,0.,0.);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEY_W){
			campos.translate(0.,+DISPLACEMENT,0.);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEY_S){
			campos.translate(0.,-DISPLACEMENT,0.);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEY_Q){
			campos.translate(0.,0.,+DISPLACEMENT);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEY_E){
			campos.translate(0.,0.,-DISPLACEMENT);
		} else if (Keyboard::getKeyDownCode() == Keyboard::KEY_L){
			exit(EXIT_SUCCESS);
		}
	}
}

void CameraService::translate(double x0,double y0,double z0){
	Point3D &campos = CameraService::position;
	campos.x += x0; campos.y += y0; campos.z += z0;
}
