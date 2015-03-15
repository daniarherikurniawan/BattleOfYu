#ifndef WORLD_H
#define WORLD_H
#include "Line3D.h"
#include "Line.h"
#include "Drawable.h"
#include <cmath>
#include <iostream>

using namespace std;

class World {
private:
	vector<Line3D*> lines;
	int mCameraFar;
	int mCameraNear;
	float mCameraDegree;
	int mCameraPositionX;
	int mCameraPositionY;
	int mCameraPositionZ;

public:
	World() {
		createDummyBuilding(10,10,100,200,150);
		createDummyBuilding(-110,10,100,200,150);

		mCameraNear = 0;
		mCameraFar = 200;
		mCameraDegree = 0;

		mCameraPositionX = 0;
		mCameraPositionY = 50;
		mCameraPositionZ = -10;
	}

	void createDummyBuilding(int x,int z,int width,int height,int depth) {
		lines.push_back(new Line3D(x,0,z,x+width,0,z));
		lines.push_back(new Line3D(x,0,z,x,height,z));
		lines.push_back(new Line3D(x,0,z,x,0,z+depth));
		lines.push_back(new Line3D(x+width,0,z,x+width,height,z));
		lines.push_back(new Line3D(x+width,0,z,x+width,0,z+depth));
		lines.push_back(new Line3D(x,height,z,x,height,z+depth));
		lines.push_back(new Line3D(x,height,z,x+width,height,z));
		lines.push_back(new Line3D(x,0,z+depth,x,height,z+depth));
		lines.push_back(new Line3D(x,0,z+depth,x+width,0,z+depth));
		lines.push_back(new Line3D(x+width,height,z,x+width,height,z+depth));
		lines.push_back(new Line3D(x,height,z+depth,x+width,height,z+depth));
		lines.push_back(new Line3D(x+width,0,z+depth,x+width,height,z+depth));
	}

	void moveByX(int displacementX) {
		mCameraPositionX += displacementX;
	}

	void moveByY(int displacementY) {
		mCameraPositionY += displacementY;
	}

	void moveByZ(int displacementZ) {
		mCameraPositionZ += displacementZ;
	}

	void rotateCameraBy(int degree) {
		mCameraDegree += degree;
	}

	vector<Pixel> getPixels() {
		vector<Pixel> pixels;
		float PI = 3.14159265;
		for (int i=0;i<lines.size();i++) {
			
			//translate
			float x1 = ((lines[i]->p1).x-mCameraPositionX);
			float y1 = ((lines[i]->p1).y-mCameraPositionY);
			float z1 = ((lines[i]->p1).z-mCameraPositionZ);
			float x2 = ((lines[i]->p2).x-mCameraPositionX);
			float y2 = ((lines[i]->p2).y-mCameraPositionY);
			float z2 = ((lines[i]->p2).z-mCameraPositionZ);

			//rotate
			float tethaInRadian = mCameraDegree*PI/180;
			x1 = x1* cos(tethaInRadian) + (z1 * -1 * sin(tethaInRadian));
			z1 = x1* sin(tethaInRadian) + (z1 * cos(tethaInRadian));
			x2 = x2* cos(tethaInRadian) + (z2 * -1 * sin(tethaInRadian));
			z2 = x2* sin(tethaInRadian) + (z2 * cos(tethaInRadian));

			//projection
			float divider1 = ((float)tan(90/2*3.14159265/180) * -1. * (z1+60.));
			float divider2 = ((float)tan(90/2*3.14159265/180) * -1. * (z2+60.));
			x1 = -150 * x1 /divider1;
			y1 = -150 * y1 /divider1;
			x2 = -150 * x2 /divider2;
			y2 = -150 * y2 /divider2;
			
			x1 += 250;
			y1 *= -1;
			y1 += 250;

			x2 += 250;
			y2 *= -1;
			y2 += 250;

			/*cout<<i<<endl;
			cout<<lines[i]->p1.x<<" "<<lines[i]->p1.y<<" "<<lines[i]->p1.z<<endl;
			cout<<lines[i]->p2.x<<" "<<lines[i]->p2.y<<" "<<lines[i]->p2.z<<endl;
			cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;*/

			Line line(Point(x1,y1),Point(x2,y2),Color(255,0,0,0));
			vector<Pixel> newPixels = line.getPixels();
			pixels.insert(pixels.end(),newPixels.begin(),newPixels.end());
		}
		return pixels;
	}

};
#endif