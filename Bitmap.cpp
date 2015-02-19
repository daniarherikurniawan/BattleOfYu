#include "Bitmap.h"
#include <math.h>
#define min(a, b)  (((a) < (b)) ? (a) : (b)) 
#define max(a, b)  (((a) > (b)) ? (a) : (b))

void Bitmap::pixelate() {
	/*pixels.clear();
	for (int i = 0; i < getWidth(); i ++) 
	for (int j = 0; j < getHeight(); j++) 
		pixels.push_back(Pixel(Point(i+beginPoint.x,j+beginPoint.y),bitmap[i][j]));
	isPixelated = true;*/
}

Bitmap::Bitmap(int width,int height) {
	vector<Color> row;
	Color c (0,0,0,255);
	for (int i = 0; i < height; i++) {
		row.push_back(c);
	}
	for (int j = 0; j < width; j++)
		bitmap.push_back(row);
	isPixelated = false;
	beginPoint = Point(0,0);
}

Bitmap::~Bitmap() {
	
}

Bitmap::Bitmap (const Bitmap &obj) {
	this->bitmap = obj.bitmap;
	isPixelated = false;
	beginPoint = obj.beginPoint;
}

Bitmap* Bitmap::clone () {
	return new Bitmap(*this);
}

void Bitmap::setPixel(Pixel pixel) {
	setPixel(pixel.getPosition(),pixel.getColor());
	isPixelated = false;
}

void Bitmap::setPixel(Point point,Color color) {
	bitmap[point.x][point.y] = color;
	isPixelated = false;
}

void Bitmap::setBeginPoint(Point p) {
	beginPoint = p;
}

Color Bitmap::getColor(Point point) const {
	return bitmap[point.x][point.y];
}

int Bitmap::getWidth() const{
	return bitmap.size();
}

int Bitmap::getHeight() const{
	return bitmap[0].size();
}

Point Bitmap::getBeginPoint(){
	return beginPoint;
}

int Bitmap::getLeftMostX() const{
  return beginPoint.x;
}

int Bitmap::getTopMostY() const{
  return beginPoint.y;
}



vector<Pixel> Bitmap::getPixels() const{
	vector<Pixel> pixels;
	pixels.clear();
	for (int i = 0; i < getWidth(); i ++) 
	for (int j = 0; j < getHeight(); j++) 
		pixels.push_back(Pixel(Point(i+beginPoint.x,j+beginPoint.y),bitmap[i][j]));
	return pixels;
}

Bitmap Bitmap::rotate(int angle) {
	float radians=(2*3.1416*angle)/360; 

	float cosine=(float)cos(radians); 
	float sine=(float)sin(radians); 

	float Point1x=(-getHeight()*sine); 
	float Point1y=(getHeight()*cosine); 
	float Point2x=(getWidth()*cosine-getHeight()*sine); 
	float Point2y=(getHeight()*cosine+getWidth()*sine); 
	float Point3x=(getWidth()*cosine); 
	float Point3y=(getWidth()*sine); 

	float minx=min(0,min(Point1x,min(Point2x,Point3x))); 
	float miny=min(0,min(Point1y,min(Point2y,Point3y))); 
	float maxx=max(Point1x,max(Point2x,Point3x)); 
	float maxy=max(Point1y,max(Point2y,Point3y)); 

	int RotationWidth=(int)ceil(fabs(maxx)-minx); 
	int RotationHeight=(int)ceil(fabs(maxy)-miny); 

	Bitmap new_bitmap = Bitmap(RotationWidth,RotationHeight);

	for(int x=0;x<RotationWidth;x++) 
	{ 
	  for(int y=0;y<RotationHeight;y++) 
	  { 
	    int SrcBitmapx=(int)((x+minx)*cosine+(y+miny)*sine); 
	    int SrcBitmapy=(int)((y+miny)*cosine-(x+minx)*sine); 
	    if(SrcBitmapx>=0&&SrcBitmapx<getWidth()&&SrcBitmapy>=0&& 
		 SrcBitmapy<getHeight()) 
	    { 
	      new_bitmap.setPixel(Point(x,y),getColor(Point(SrcBitmapx,SrcBitmapy))); 
	    } 
	    else new_bitmap.setPixel(Point(x,y),Color(0,0,0,255));
	  } 
	} 
	/*
	for (int i = 0; i < RotationWidth; ) {
		bool deleteable = true;
		for (int j = 0; j < RotationHeight; j++) {
			if (new_bitmap.bitmap[0][j].alpha != 255) deleteable = false;
		}
		if (deleteable) new_bitmap.bitmap.erase(new_bitmap.bitmap.begin());
		else {i = RotationWidth;}
	}

	for (int i = 0; i >= 0; ) {
		bool deleteable = true;
		for (int j = 0; j < RotationHeight; j++) {
			if (new_bitmap.bitmap[new_bitmap.bitmap.size()-1][j].alpha != 255) deleteable = false;
		}
		if (deleteable) new_bitmap.bitmap.erase(new_bitmap.bitmap.begin());
		else {i = -1;}
	}
	RotationWidth = new_bitmap.bitmap.size();
	for (int j = 0; j < RotationHeight; j++) {
		bool deleteable = true;
		for (int i = 0; i < RotationWidth; i++) {
			if (new_bitmap.bitmap[i][j].alpha != 255) deleteable = false;
		}
		if (deleteable) 
		for (int i = 0; i < RotationWidth; i++) {
			new_bitmap.bitmap[i].erase(new_bitmap.bitmap[i].begin()+j);
		}
		else j = RotationHeight;
		if (deleteable) j--;
		RotationHeight = new_bitmap.bitmap[0].size();
	}

	for (int j = RotationHeight-1; j >= 0; j--) {
		bool deleteable = true;
		for (int i = 0; i < RotationWidth; i++) {
			if (new_bitmap.bitmap[i][j].alpha != 255) deleteable = false;
		}
		if (deleteable) 
		for (int i = 0; i < RotationWidth; i++) {
			new_bitmap.bitmap[i].erase(new_bitmap.bitmap[i].begin()+j);
		}
		else j = -1;
		if (deleteable) j--;
		RotationHeight = new_bitmap.bitmap[0].size();
	} */

	return new_bitmap;
}
