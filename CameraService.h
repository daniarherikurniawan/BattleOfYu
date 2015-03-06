#ifndef CAMERA_SERVICE_H
#define CAMERA_SERVICE_H

#include "Pixel.h"
#include "Keyboard.h"
#define DISPLACEMENT 0.01

class CameraService {
public:
	static Point3D position;
	static void handleInput();
	static void translate(double x0,double y0,double z0);
};
#endif

