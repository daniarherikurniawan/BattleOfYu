#include "Screen.h"

Screen::Screen() {
	system("reset");
	frameBufferFileDescriptor = open("/dev/fb0",O_RDWR);
	if (frameBufferFileDescriptor == -1){
		perror("Error :");
		printf("Error opening dev/fb");	
		exit(1);	
	}
	initializeScreenInfo();	
	frameBuffer = (char*)mmap(0, finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, frameBufferFileDescriptor, 0);
	screenSize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
	width = vinfo.xres;
	height = vinfo.yres;
	pseudoFrame = new char[screenSize];
	memset(pseudoFrame,0,screenSize);
}

void Screen::initializeScreenInfo() {
	if (ioctl (frameBufferFileDescriptor, FBIOGET_VSCREENINFO, &vinfo)) {
		perror("Error ");
		exit(3);
	}
	
	if (ioctl (frameBufferFileDescriptor, FBIOGET_FSCREENINFO, &finfo)) {
		perror("Error ");
		exit(2);
	}

}

void Screen::drawPixel(Pixel pixel) {
	Point position = (pixel.getPosition());
	if (position.x>= width || position.x < 0 || position.y >=height || position.y <0 )
		return;
	int location = (position.x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) 
	+ (position.y+vinfo.yoffset) * finfo.line_length;
	
	Color color = (pixel.getColor());
	*(pseudoFrame+location) = color.blue;
	*(pseudoFrame+location+1) = color.green;
	*(pseudoFrame+location+2) = color.red;
	*(pseudoFrame+location+3) = color.alpha;
}

void Screen::draw(Drawable *drawable) {
	vector<Pixel> pixels = drawable->getPixels();
	for (int i=0;i<pixels.size();i++) {
		drawPixel(pixels[i]);
	}
}

Screen::~Screen() {
	munmap(frameBuffer,screenSize);
	delete pseudoFrame;
	close(frameBufferFileDescriptor);
}

void Screen::endBatch() {
	memcpy ( frameBuffer, pseudoFrame, screenSize );
}

void Screen::draw(Drawable *drawable,bool isflip){
	if(!isflip){
		draw(drawable);
	}
	else{
		vector<Pixel> result;
		//Hitung sumbu vertikal
		vector<Pixel> group_of_point=drawable->getPixels();
		vector<Pixel>::iterator it;
		int vertical_axis=0;
		int numb=0;
		for(it=group_of_point.begin();it!=group_of_point.end();it++){
			vertical_axis+=(it->getPosition()).x;numb++;
		}
		vertical_axis/=numb;

		//transformasi
		for(it=group_of_point.begin();it!=group_of_point.end();it++){
			int temp=(it->getPosition()).x;
			temp=2*vertical_axis-temp;
			Point pt(temp,(it->getPosition()).y);
			Pixel px(pt,it->getColor());
			result.push_back(px);
		}
		for(it=result.begin();it!=result.end();it++)
			drawPixel(*it); 
	}
}

void Screen::draw(Drawable *drawable,float scale){
	vector<Pixel> explosion_coordinate=drawable->getPixels();
	vector<Pixel>::iterator it;
	vector<Pixel> result;
	int x_center=0,ycenter=0;
	int numb_of_pixels=0;
	for(it=explosion_coordinate.begin();it!=explosion_coordinate.end();it++){
		Point point((int)(scale*(it->getPosition().x)),(int)(scale*(it->getPosition().y)));
		Pixel pixel(point,it->getColor());		
		result.push_back(pixel);
	}
	for(it=result.begin();it!=result.end();it++) drawPixel(*it); 
}

void Screen::beginBatch() {
	memset(pseudoFrame,0,screenSize);
}






