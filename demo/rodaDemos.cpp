#include "Roda.h"
#include "Screen.h"
#include <unistd.h>

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}

int main() {
	Roda roda;
	Screen screen;
	roda.setRadius(15);
	roda.setCenter(Point(150,300));
	bool bounce = true;
	
	do {
		screen.beginBatch();

		bounce = roda.bounce();
		screen.draw(&roda);
		
		screen.endBatch();
	} while (bounce);

	return 0;
}
