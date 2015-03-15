#include "Mouse.h"

using namespace std;

//int Mouse::mFd[];
struct input_event Mouse::mInputEvent;
int Mouse::mPositionX;
int Mouse::mPositionY;
bool Mouse::mIsMouseEvent;
bool Mouse::mEventCode;
int Mouse::ukuran;
int *Mouse::mFd;

const string Mouse::MOUSEFILE = "/dev/input/";

void Mouse::startListening() {
	string dir = string("/dev/input");
	vector<string> files = vector<string>();

	getdirevent(dir,files);
	ukuran = files.size();
	mFd = new int[files.size()];

	for (unsigned int i = 0;i < files.size();i++) {
		//cout << files[i] << endl;
		mFd[i] = open((MOUSEFILE+files[i]).c_str(), O_RDONLY|O_NONBLOCK);
	    }

	
	/*if((mFd = open((MOUSEFILE+eventFile).c_str(), O_RDONLY|O_NONBLOCK)) == -1) {
	    perror("opening device");
	    exit(EXIT_FAILURE);
	}*/
	mPositionY = 0;
	mPositionX = 0;
}

int Mouse::getdirevent (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    
    while ((dirp = readdir(dp)) != NULL) {
	size_t found = string(dirp->d_name).find("event");
	if (found!=string::npos)
        	files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

void Mouse::update() {
	for (unsigned int i = 0;i < ukuran;i++) {
		if (mFd[i] != -1){
			int result = read(mFd[i], &mInputEvent, sizeof(struct input_event));
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
				result = read(mFd[i], &mInputEvent, sizeof(struct input_event));
			}
		}
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
