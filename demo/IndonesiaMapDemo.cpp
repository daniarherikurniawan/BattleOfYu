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

CompositeDrawable map ("../pulau/peta.txt");
void handleInput() {
	if (Keyboard::isKeyDown()) {
		if (Keyboard::getKeyDownCode() == Keyboard::KEY_D){
			map.moveBy(2,0);
			isflip=false;		
		}
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_A){
			map.moveBy(-2,0);
			isflip=true;		
		}
		if (Keyboard::getKeyDownCode() == Keyboard::KEY_L){
			map.moveBy(2,0);
			isflip=false;
		}
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_J){
			isflip=true;
			map.moveBy(-2,0);
		}
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_W)
			exit(0);
	}
}

int main() {

	Screen screen;
	
	long long accumulateTime = 0;
	Keyboard::startListening();
	
	map.setPosition(200,10);
	
	map.setPosition(10,200);
	while(true){
		handleInput();
		screen.beginBatch();
		screen.draw(&map,isflip);
		screen.endBatch();
	}
	
	return 0;	
}


