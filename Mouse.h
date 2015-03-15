#ifndef MOUSE_H
#define MOUSE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>
#include <fcntl.h>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Mouse {
public:
  static const int MOUSE_LEFT_PRESS = 0;
  static const int MOUSE_LEFT_RELEASE = 1;
  static const int MOUSE_RIGHT_PRESS = 2;
  static const int MOUSE_RIGHT_RELEASE = 3;

  static int ukuran;

  static void startListening();
  static int getPositionX();
  static int getPositionY();
  static bool isMouseEvent();
  static int getMouseEventCode();
  static void update();

private:
  static const string MOUSEFILE;
  static struct input_event mInputEvent;
  static int *mFd;
  static int mPositionX,mPositionY;
  static bool mIsMouseEvent;
  static bool mEventCode;
  static int getdirevent (string dir, vector<string> &files);
};

#endif
