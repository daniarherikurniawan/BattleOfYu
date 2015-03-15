#include "Keyboard.h"

struct termios Keyboard::orig_termios;
int Keyboard::keyDownCode;
int Keyboard::bufferedCode = 0;

void Keyboard::setBufferedCode(const char& keycode){
	Keyboard::bufferedCode = keycode;
}

int Keyboard::getBufferedCode(){
	return Keyboard::bufferedCode;
}	

void Keyboard::updateBufferedCode(){
	if (Keyboard::isKeyDown()){
		Keyboard::setBufferedCode(Keyboard::getKeyDownCode());
	} else {
		Keyboard::setBufferedCode(0);
	}
}

void Keyboard::reset_terminal_mode()
{
    tcsetattr(0, TCSANOW, &orig_termios);
}

void Keyboard::set_conio_terminal_mode()
{
    struct termios new_termios;

    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    /* register cleanup handler, and set the new terminal mode */
    atexit(reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}

int Keyboard::kbhit()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int Keyboard::getch()
{
    int r;
    unsigned char c;
    if ((r = read(0, &c, sizeof(c))) < 0) {
        return r;
    } else {
        return c;
    }
}

bool Keyboard::isKeyDown() {
	if (kbhit()) {
		keyDownCode = getch();
		return true;
	}
	else
		return false;
}

int Keyboard::getKeyDownCode() {
	return keyDownCode;
}

void Keyboard::startListening() {
	set_conio_terminal_mode();
}
