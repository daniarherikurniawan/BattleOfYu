#include "../Pixel.h"
#include "../Screen.h"
#include "../Line.h"
#include "../CompositeDrawable.h"
#include "../Keyboard.h"
#include "../ClipDrawable.h"
#include "../Util.h"

const long long SECONDS_PER_FRAME = 1000/60;

WorldMap worldMap("../pulau/pulau1.txt");
ClipDrawable clipDrawable(150,150,150,150);

void handleInput() {
	if (Keyboard::isKeyDown()) {
		if (Keyboard::getKeyDownCode() == Keyboard::KEY_D)
			clipDrawable.panBy(3,0);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_A)
			clipDrawable.panBy(-3,0);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_S)
			clipDrawable.panBy(0,3);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_W)
			clipDrawable.panBy(0,-3);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_I)
			clipDrawable.zoomBy(1.2);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_K)
			clipDrawable.zoomBy(0.8);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_L)
			exit(0);
	}
}

int main() {

	Screen screen;

	long long previousTime = (long long)Util::getCurrentTimeInMiliseconds();
	long long accumulateTime = 0;

	clipDrawable.setWorldMap(worldMap);
	clipDrawable.setPosition(600,200);
	Keyboard::startListening();

	while(true){
		if (accumulateTime>SECONDS_PER_FRAME){
			handleInput();
			worldMap.setWindowPort(clipDrawable.getWindowPort());
			screen.beginBatch();
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