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
	static const char KEYBOARD_A = 97;
	static const char KEYBOARD_S = 115;
	static const char KEYBOARD_W = 119;
	static const char KEYBOARD_D = 100;
	static const char KEYBOARD_I = 105;
	static const char KEYBOARD_J = 106;
	static const char KEYBOARD_K = 107;
	static const char KEYBOARD_L = 108;
	static const char KEYBOARD_Q = 113;
	static const char KEYBOARD_E = 101;
	static const char KEYBOARD_F = 102;
	
	//kalo ini dipencet huruf X, langsung gg.
	static const char KEYBOARD_EXIT = 120;
	static bool isKeyDown();
	static void startListening();
	static int getKeyDownCode();
	
	//buffercode buat nampung input keyboard
	static int bufferedCode;
	static void setBufferedCode(const char& keycode);
	static int getBufferedCode();
	static void updateBufferedCode();
	
private:
	static void reset_terminal_mode();

	static void set_conio_terminal_mode();

	static int kbhit();

	static int getch();
	
	static struct termios orig_termios;
	
	static int keyDownCode;
};

#endif
