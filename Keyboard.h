#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <stdio.h>

class Keyboard {
public:
	static const char KEY_A = 97;
	static const char KEY_S = 115;
	static const char KEY_W = 119;
	static const char KEY_D = 100;
	static const char KEY_I = 105;
	static const char KEY_J = 106;
	static const char KEY_K = 107;
	static const char KEY_L = 108;
	static bool isKeyDown();
	static void startListening();
	static int getKeyDownCode();
private:
	static void reset_terminal_mode();

	static void set_conio_terminal_mode();

	static int kbhit();

	static int getch();
	
	static struct termios orig_termios;
	
	static int keyDownCode;
};

#endif
