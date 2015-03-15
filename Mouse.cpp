#include "Mouse.h"

int Mouse::mFd;
struct input_event Mouse::mInputEvent;
int Mouse::mPositionX;
int Mouse::mPositionY;
bool Mouse::mIsMouseEvent;
bool Mouse::mEventCode;

const string Mouse::MOUSEFILE = "/dev/input/";

void Mouse::startListening(string eventFile) {
	if((mFd = open((MOUSEFILE+eventFile).c_str(), O_RDONLY|O_NONBLOCK)) == -1) {
	    perror("opening device");
	    exit(EXIT_FAILURE);
	}
	mPositionY = 0;
	mPositionX = 0;
}

void Mouse::update() {
	
	int result = read(mFd, &mInputEvent, sizeof(struct input_event));
	while (mInputEvent.type!=0) {
		if (mInputEvent.type == 2) {
			if (mInputEvent.code == 0) { mPositionX += mInputEvent.value; }
			else if (mInputEvent.code == 1) { mPositionY += mInputEvent.value; }
		} else if (mInputEvent.type == 1) {
			if (mInputEvent.code == 272 ) { 
				mIsMouseEvent = true;
				if (mInputEvent.value == 0)  
					mEventCode = MOUSE_LEFT_PRESS;
				if (mInputEvent.value == 1)  
					mEventCode = MOUSE_LEFT_RELEASE;
			}
		} else if (mInputEvent.code == 273) {
			if (mInputEvent.code == 273 ) { 
				mIsMouseEvent = true;
				if (mInputEvent.value == 0)  
					mEventCode = MOUSE_RIGHT_PRESS;
				if (mInputEvent.value == 1)  
					mEventCode = MOUSE_RIGHT_RELEASE;
			}
		}
		result = read(mFd, &mInputEvent, sizeof(struct input_event));
	}
	
}

bool Mouse::isMouseEvent() {
	bool tmp = mIsMouseEvent;
	mIsMouseEvent = false;
	return tmp;
}

int Mouse::getMouseEventCode() {
	return mEventCode;
}

int Mouse::getPositionX() {
	return mPositionX;
}

int Mouse::getPositionY() {
	return mPositionY;
}