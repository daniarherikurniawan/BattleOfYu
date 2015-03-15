#ifndef SCREEN_H
#define SCREEN_H

#include "Drawable.h"
#include "Pixel.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <math.h>
#include <errno.h>
#include <cstring>
#include "CompositeDrawable.h"
class Screen {
private :
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	int frameBufferFileDescriptor; 
	char* frameBuffer;
	char* pseudoFrame;
	long int screenSize;
	int width;
	int height;
	void initializeScreenInfo();

public :
	Screen();
	void drawPixel(Pixel pixel);
	void draw(Drawable *drawable);
	~Screen();
	void endBatch();
	void beginBatch();
	void draw(Drawable *drawable,bool isflip);
	void draw(Drawable *drawable,float scale);
};

#endif
