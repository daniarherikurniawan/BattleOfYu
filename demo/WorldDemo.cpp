#include "../World.h"
#include "../Screen.h"
#include "../Pixel.h"
#include "../Util.h"
#include "../Keyboard.h"

const long long SECONDS_PER_FRAME = 1000/60;

World world;
void handleInput() {
	if (Keyboard::isKeyDown()) {
		if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_D)
			world.moveByX(1);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_A)
			world.moveByX(-1);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_S)
			world.moveByY(-1);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_W)
			world.moveByY(1);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_I)
			exit(0);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_K)
			exit(0);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_L) {
			world.rotateCameraBy(10);
		}
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_J)
			world.rotateCameraBy(-10);
	}
	
}

int main() {
	long long previousTime = (long long)Util::getCurrentTimeInMiliseconds();
	long long accumulateTime = 0;

	Screen screen;
	Keyboard::startListening();

	while(true){
		handleInput();
		if (accumulateTime>SECONDS_PER_FRAME){
			vector<Pixel> pixels = world.getPixels();
			screen.beginBatch();
			for (int i=0;i<pixels.size();i++) {
				screen.drawPixel(pixels[i]);
			}
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