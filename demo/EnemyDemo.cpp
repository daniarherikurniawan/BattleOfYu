#include "../Enemy.h"
#include "../Screen.h"
#include <unistd.h>

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}

int main() {
	Enemy enemy (Point(20,50), Color(255,0,0,0));
	Screen screen;

	screen.beginBatch();
	screen.draw(&enemy);
	screen.endBatch();
	return 0;
}
