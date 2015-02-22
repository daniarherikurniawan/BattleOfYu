#include "Screen.h"
#include "Pesawat.h"
#include "Keyboard.h"
#include "Util.h"
Pesawat plane;

const long long SECONDS_PER_FRAME = 1000/60;

void handleInput() {
	if (Keyboard::isKeyDown()) {
		if (Keyboard::getKeyDownCode() == Keyboard::KEY_D){
			Point explosionCenter(plane.getWidth()/2,plane.getHeight()/2);

			//Ini harus dipanggil sebelum meledak
			plane.startExplode(explosionCenter);		
		}
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_A) {
			//Ini harus dipanggil setelah meledak selesai. Tidak boleh tidak
			plane.finishExplode();
		}
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_W) {
			exit(0);
		}
	}
}

int main() {

	long long previousTime = (long long)Util::getCurrentTimeInMiliseconds();
	long long accumulateTime = 0;

	Screen screen;
	plane.setPosition(50,50);
	Keyboard::startListening();
	float initialPercentage = 0;
	while(true){
		if (accumulateTime>SECONDS_PER_FRAME){
			handleInput();
			screen.beginBatch();
			if (plane.isExploded()) {
				initialPercentage += 0.01;
				//Persentasi dari 0 hingga 1
				plane.explode(initialPercentage);
			}
			screen.draw(&plane);;		
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
