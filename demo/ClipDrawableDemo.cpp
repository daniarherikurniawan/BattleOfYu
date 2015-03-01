#include "../Pixel.h"
#include "../Screen.h"
#include "../Line.h"
#include "../CompositeDrawable.h"
#include "../Keyboard.h"
#include "../ClipDrawable.h"

const long long SECONDS_PER_FRAME = 1000/60;

WorldMap worldMap("../pulau/peta.txt");
ClipDrawable clipDrawable(200,200,400,400);

void handleInput() {
	if (Keyboard::isKeyDown()) {
		if (Keyboard::getKeyDownCode() == Keyboard::KEY_D)
			clipDrawable.panBy(1,0);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_A)
			clipDrawable.panBy(-1,0);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_S)
			clipDrawable.panBy(0,-1);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_W)
			clipDrawable.panBy(0,1);
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
	
	long long accumulateTime = 0;

	clipDrawable.setWorldMap(worldMap);
	clipDrawable.setPosition(10,10);
	Keyboard::startListening();

	while(true){
		handleInput();
		screen.beginBatch();
		screen.draw(&clipDrawable);
		screen.endBatch();
	}
	
	return 0;
}