#include "../Pixel.h"
#include "../Screen.h"
#include "../Line.h"
#include "../CompositeDrawable.h"
#include "../Keyboard.h"
#include "../ClipDrawable.h"
#include "../Util.h"
#include "../Mouse.h"

const long long SECONDS_PER_FRAME = 1000/60;

WorldMap worldMap("../pulau/peta.txt");
ClipDrawable clipDrawable(150,150,150,150);

void handleInput() {
	if (Keyboard::isKeyDown()) {
		if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_D)
			clipDrawable.panBy(3,0);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_A)
			clipDrawable.panBy(-3,0);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_S)
			clipDrawable.panBy(0,3);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_W)
			clipDrawable.panBy(0,-3);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_I)
			clipDrawable.zoomBy(1.2);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_K)
			clipDrawable.zoomBy(0.8);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_L)
			exit(0);
	}
	Mouse::update();
	if (Mouse::isMouseEvent()) {
		if (Mouse::getMouseEventCode() == Mouse::MOUSE_LEFT_PRESS) {

		} else if (Mouse::getMouseEventCode() == Mouse::MOUSE_LEFT_RELEASE) {

		} else if (Mouse::getMouseEventCode() == Mouse::MOUSE_RIGHT_PRESS) {

		} else if (Mouse::getMouseEventCode() == Mouse::MOUSE_RIGHT_RELEASE) {

		}
	}
}

int main() {

	Screen screen;

	long long previousTime = (long long)Util::getCurrentTimeInMiliseconds();
	long long accumulateTime = 0;

	bool isShipPositive = true;
	bool isPlanePositive = true;

	

	worldMap.ship.moveBy(0,70);
	worldMap.plane.moveBy(40,0);


	clipDrawable.setWorldMap(worldMap);
	clipDrawable.setPosition(135,160);
	Keyboard::startListening();
	Mouse::startListening("event3");

	CompositeDrawable mousePointer("../mousePointer.txt");

	while(true){
		if (accumulateTime>SECONDS_PER_FRAME){
			handleInput();
			worldMap.setWindowPort(clipDrawable.getWindowPort());

			if (isShipPositive){
				worldMap.ship.moveBy(1,0);
				if (worldMap.ship.x > 400){
					isShipPositive = false;
				}
			}else{
				worldMap.ship.moveBy(-1,0);
				if (worldMap.ship.x < 10){
					isShipPositive = true;
				}
			}

			if (isPlanePositive){
				worldMap.plane.moveBy(0,1);
				if (worldMap.plane.y > 400){
					isPlanePositive = false;
				}
			}else{
				worldMap.plane.moveBy(0,-1);
				if (worldMap.plane.y < 10){
					isPlanePositive = true;
				}
			}

			clipDrawable.setWorldMap(worldMap);
			mousePointer.setPosition(Mouse::getPositionX()-mousePointer.getWidth()/2,Mouse::getPositionY()-mousePointer.getHeight()/2);
			screen.beginBatch();
			screen.draw(&mousePointer);
			screen.draw(&worldMap);
			screen.draw(&clipDrawable);
			screen.endBatch();
			while (accumulateTime<(SECONDS_PER_FRAME))
					accumulateTime -= (SECONDS_PER_FRAME);
		}
		else {
			long long currentTime = (long long)Util::getCurrentTimeInMiliseconds();
			accumulateTime += (currentTime - previousTime);
			previousTime = currentTime;
		}
	}
	
	return 0;
}
