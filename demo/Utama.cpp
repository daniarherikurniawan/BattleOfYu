#include "../Pixel.h"
#include "../Screen.h"
#include "../Line.h"
#include "../MatrixDrawable.h"
#include "../CompositeDrawable.h"
#include "../Keyboard.h"
#include "../Util.h"
#include "../Story.h"
#include "../Pesawat.h"
#include <sys/types.h>
#include <sys/wait.h>

const long long SECONDS_PER_FRAME = 1000/60;


Story ampas(0);

int state = 0;
int progressStory = 0;

void handleInput() {
	if (Keyboard::isKeyDown()) {
		if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_D)
			return; //clipDrawable.panBy(3,0);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_A)
			return; //clipDrawable.panBy(-3,0);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_S)
			ampas.next();
			progressStory++;

			if (progressStory == 3) state = 1;
			if (progressStory == 6) state = 2;
			if (progressStory == 9) state = 3;
			if (progressStory == 13) state = 4;
			if (progressStory == 18) state = 5;
			if (progressStory == 23) state = 6;
				
			
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_W)
			return; //clipDrawable.panBy(0,-3);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_I)
			return; //clipDrawable.zoomBy(1.2);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_K)
			return; //clipDrawable.zoomBy(0.8);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEYBOARD_L)
			exit(0);
	}
}
long long previousTime = (long long)Util::getCurrentTimeInMiliseconds();
long long accumulateTime = 0;

CompositeDrawable fish("../fish.txt");
CompositeDrawable bird("../bird.txt");
//Pesawat plane;

void sceneCerita(int part){
	while(state == part){
		if (accumulateTime>SECONDS_PER_FRAME){
			handleInput();
			
			ampas.printStory();			
			while (accumulateTime<(SECONDS_PER_FRAME))
					accumulateTime -= (SECONDS_PER_FRAME);
		}
		else {
			long long currentTime = (long long)Util::getCurrentTimeInMiliseconds();
			accumulateTime += (currentTime - previousTime);
			previousTime = currentTime;
		}
	}
}

int main() {

	Screen screen;

	
	CompositeDrawable peta("../pulau/peta.txt");
	CompositeDrawable *c_ship = new CompositeDrawable("../ship.txt");
	MatrixDrawable *ship = new MatrixDrawable(c_ship);

	CompositeDrawable *c_plane = new CompositeDrawable("../plane.txt");
	MatrixDrawable *plane = new MatrixDrawable(c_plane);
	
	Keyboard::startListening();
	
	Point f_pos1(ship->getWidth() / 2, ship->getHeight() / 2);
	ship->fillWithFloodFill(f_pos1,&fish);

	Point f_pos2(plane->getWidth() / 2, plane->getHeight() / 2);
	plane->fillWithFloodFill(f_pos2,&bird);
	
	ship->setPosition(280,190);
	plane->setPosition(280,190);
	

	screen.beginBatch();
	screen.draw(&peta);
	screen.endBatch();

	sceneCerita(0);

	screen.beginBatch();
	screen.draw(ship);
	screen.endBatch();

	sceneCerita(1);

	screen.beginBatch();
	screen.draw(plane);
	screen.endBatch();

	sceneCerita(2);

	Keyboard::reset_terminal_mode();
	ampas.gotoxy(14,25);
	printf("Input nama anda: ");
	string nama;
	getline (cin,nama);

	ampas.nama = nama;
	int warna_pilihan;

	ampas.gotoxy(14,25);
	printf("                                                                     ");
	
	Keyboard::startListening();
	sceneCerita(3);
	
	int pid = 0;
	pid = fork();

	if (pid == 0) {
		execl("ColorPicker", "ColorPicker",  NULL);
		return 0;
		
	} else {
		waitpid(pid, &warna_pilihan, 0);
	}

	screen.beginBatch();
	screen.draw(&peta);
	screen.endBatch();
	
	Keyboard::startListening();
	sceneCerita(4);

	pid = 0;
	pid = fork();

	if (pid == 0) {
		execl("ClipDemo", "ClipDemo",  NULL);
		return 0;
		
	} else { // This is the parent process
		waitpid(pid, &warna_pilihan, 0);
	}

	screen.beginBatch();
	screen.draw(&peta);
	screen.endBatch();
	
	Keyboard::startListening();
	sceneCerita(5);

	pid = 0;
	pid = fork();

	if (pid == 0) {
		execl("BattleOfYu", "BattleOfYu",  NULL);
		return 0;
		
	} else { // This is the parent process
		waitpid(pid, &warna_pilihan, 0);
	}

	screen.beginBatch();
	screen.draw(&peta);
	screen.endBatch();
	
	Keyboard::startListening();
	sceneCerita(6);

	return 0;
}
