#include "../Pixel.h"
#include "../Screen.h"
#include "../Line.h"
#include "../CompositeDrawable.h"
#include "../Keyboard.h"


const long long SECONDS_PER_FRAME = 1000/60;
bool isflip=false;
Point position(5,5);
Color color(0,255,0,0);
Pixel pixel(position,color);

Point beginPosition(4,4);
Point endPosition(100,100);
Color lineColor(255,0,0,0);
Line line(beginPosition,endPosition,color);

CompositeDrawable triangle("../triangle.txt");
CompositeDrawable plane("../plane.txt");
CompositeDrawable ship("../ship.txt");
CompositeDrawable explosion("../explosion.txt");
void handleInput() {
	if (Keyboard::isKeyDown()) {
		if (Keyboard::getKeyDownCode() == Keyboard::KEY_D){
			ship.moveBy(2,0);
			isflip=false;		
		}
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_A){
			ship.moveBy(-2,0);
			isflip=true;		
		}
		if (Keyboard::getKeyDownCode() == Keyboard::KEY_L){
			plane.moveBy(2,0);
			isflip=false;
		}
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_J){
			isflip=true;
			plane.moveBy(-2,0);
		}
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_W)
			exit(0);
	}
}

int main() {

	Screen screen;
	
	long long accumulateTime = 0;
	Keyboard::startListening();
	
	plane.setPosition(200,10);
	
	ship.setPosition(10,200);
	float i=0.5;
	while(true){
		handleInput();
		screen.beginBatch();
		screen.draw(&ship,isflip);
		screen.draw(&explosion,i);		
		screen.endBatch();
		i+=0.001;
	}
	
	return 0;	
}


