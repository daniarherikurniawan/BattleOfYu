#include "../Crosshair.h"
#include "../Screen.h"
#include <unistd.h>

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}

int main() {
	Crosshair crosshair;
	Screen screen;

	screen.beginBatch();
	screen.draw(&crosshair);
	screen.endBatch();
	return 0;
}
