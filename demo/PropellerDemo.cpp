#include "../Pixel.h"
#include "../Screen.h"
#include "../Line.h"
#include "../CompositeDrawable.h"
#include "../Keyboard.h"

#include "Propeller.hpp"
const long long SECONDS_PER_FRAME = 1000/60;
bool isflip=false;
Point position(5,5);
Color color(0,255,0,0);
Pixel pixel(position,color);

Point beginPosition(4,4);
Point endPosition(100,100);
Color lineColor(255,0,0,0);
Line line(beginPosition,endPosition,color);

Propeller propeller("propeller.txt");
CompositeDrawable explosion("explosion.txt");
CompositeDrawable plane("plane.txt");
CompositeDrawable ship("ship.txt");

void handleInput() {
	if (Keyboard::isKeyDown()) {
		if (Keyboard::getKeyDownCode() == Keyboard::KEY_W)
			exit(0);
	}
}

int main() {
	Screen screen;
	
	long long accumulateTime = 0;
	Keyboard::startListening();
	
	propeller.setDrawPosition(200,200);
	
	ship.rotate(90,100,100);
	ship.setPosition(300,300);
	
	plane.setPosition(200,200);
	
	Point center(0,0);
	propeller.setCenter(center);
	float i=0.0;
	while(true){
		handleInput();
		screen.beginBatch();
		propeller.draw(&screen);
		
		
		if (i > 0.1){
			i = 0.0;
			ship.rotate(45,100,100);
			plane.rotate(45,100,150);
		}
		screen.draw(&ship,false);
		screen.draw(&plane,false);
		screen.endBatch();
		i+=0.00001;
	}
	
	return 0;	
}


