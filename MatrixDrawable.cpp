#include "MatrixDrawable.h"

MatrixDrawable::MatrixDrawable(Drawable *drawable) {
  mWidth = drawable->getWidth();
  mHeight = drawable->getHeight();
  mPixelMatrix = new Color*[mHeight];
  for (int i=0;i<mHeight;i++)
    mPixelMatrix[i] = new Color[mWidth];
  
  mPositionX = 0;
  mPositionY = 0;
  
  vector<Pixel> pixels = drawable->getPixels();
  for (int i=0;i<pixels.size();i++) {
    int x = pixels[i].getPosition().x - drawable->getLeftMostX();
    int y = pixels[i].getPosition().y - drawable->getTopMostY();
    if (x>=0 && y>=0) {
      mPixelMatrix[y][x] = pixels[i].getColor();
    }
  }
}

MatrixDrawable::MatrixDrawable(const MatrixDrawable& other) {
  mWidth = other.getWidth();
  mHeight = other.getHeight();
  mPixelMatrix = new Color*[mHeight];
  for (int i=0;i<mHeight;i++)
    mPixelMatrix[i] = new Color[mWidth];
  
  mPositionX = other.getPosition().x;
  mPositionY = other.getPosition().y;
  
  for (int i=0;i<mHeight;i++){
    for (int j=0;j<mWidth;j++){
      Point position(j,i);
      mPixelMatrix[i][j] = other.getColor(position);
    }
  }
  
}

vector<Pixel> MatrixDrawable::getPixels() const{
  vector<Pixel> pixels;
  for (int i=0;i<mHeight;i++) {
    for (int j=0;j<mWidth;j++) {
      int red = mPixelMatrix[i][j].red;
      int green = mPixelMatrix[i][j].green;
      int blue = mPixelMatrix[i][j].blue;
      int alpha = mPixelMatrix[i][j].alpha;
      if (red!=0 || green !=0 || blue != 0) {
	Point position(j+mPositionX,i+mPositionY);
	Color color (red,green,blue,alpha);
	Pixel pixel(position,color);
	pixels.push_back(pixel);
      }
    }
  }
  return pixels;
}

int MatrixDrawable::getLeftMostX() const{
  return mPositionX;
}

int MatrixDrawable::getTopMostY() const{
  return mPositionY;
}

void MatrixDrawable::fillWithFloodFill(Point position,MatrixDrawable pattern) {
  int x = position.x;
  int y = position.y;
  queue<Point> destPointQueue;
  queue<Point> sourcePointQueue;
  destPointQueue.push(position);
  Point initialSourcePoint(0,0);
  sourcePointQueue.push(initialSourcePoint);
  
  bool **isVisited;
  isVisited = new bool*[mHeight];
  for (int i=0;i<mHeight;i++)
    isVisited[i] = new bool[mWidth];
  
  for (int i=0;i<mHeight;i++)
    for (int j=0;j<mWidth;j++)
      isVisited[i][j] = false;
  
  int xHelper[4] = { 0, 0, -1 ,1};
  int yHelper[4] = { 1, -1, 0 , 0};
  
  while (!destPointQueue.empty()) {
    Point destPoint = destPointQueue.front();
    Point sourcePoint = sourcePointQueue.front();
    if (destPoint.y<mHeight && destPoint.x<mWidth && destPoint.y>=0 && destPoint.x>=0){
      if (!isVisited[destPoint.y][destPoint.x] && isEmpty(destPoint)){
	mPixelMatrix[destPoint.y][destPoint.x] = pattern.getColor(sourcePoint);
	for (int i=0;i<4;i++) {
	  Point nextDestPoint(destPoint.x+xHelper[i],destPoint.y+yHelper[i]);
	  Point nextSourcePoint(sourcePoint.x+xHelper[i],destPoint.y+yHelper[i]);
	  sourcePointQueue.push(nextSourcePoint);
	  destPointQueue.push(nextDestPoint);
	}
	isVisited[destPoint.y][destPoint.x] = true;
      }
    }
    
    sourcePointQueue.pop();
    destPointQueue.pop();
  }
  for (int i=0;i<mHeight;i++){
    delete[] isVisited[i];
  }
  delete[] isVisited;
}

bool MatrixDrawable::isEmpty(Point position) const{
  int x = position.x;
  int y = position.y;
  return !(mPixelMatrix[y][x].red || mPixelMatrix[y][x].green ||mPixelMatrix[y][x].blue);
}

Color MatrixDrawable::getColor(Point position) const{
  int x = position.x % mWidth;
  int y = position.y % mHeight;
  if (x < 0) x += mWidth;
  if (y < 0) y += mHeight;
  return mPixelMatrix[y][x];
}


MatrixDrawable::~MatrixDrawable(){
  for (int i=0;i<mHeight;i++)
    delete[] mPixelMatrix[i];
  delete[] mPixelMatrix;
}


void MatrixDrawable::fillPattern(Drawable *drawable){
	int pWidth = drawable->getWidth();
	int pHeight = drawable->getHeight();
	
	vector<Pixel> pixels = drawable->getPixels();
	for (int i=0;i<pixels.size();i++) {
		int x = pixels[i].getPosition().x;
		int y = pixels[i].getPosition().y;
		if (x>=0 && y>=0 && x < mWidth && y < mHeight) {
			  mPixelMatrix[y][x].red = pixels[i].getColor().red;
			  mPixelMatrix[y][x].green = pixels[i].getColor().green;
			  mPixelMatrix[y][x].blue = pixels[i].getColor().blue;
			  mPixelMatrix[y][x].alpha = pixels[i].getColor().alpha;
		}
	}
}

bool MatrixDrawable::isBlank(int x, int y){
	int red = mPixelMatrix[y][x].red;
	int green = mPixelMatrix[y][x].green;
	int blue = mPixelMatrix[y][x].blue;
	int alpha = mPixelMatrix[y][x].alpha;

	if (red == 0 && green == 0 && blue == 0)
		return true;
	else
		return false;
}

void MatrixDrawable::fillColor(Pixel pixel) {
	Point position = (pixel.getPosition());
	Color color = (pixel.getColor());
	
	int x = position.x;
	int y = position.y;
	
	if (x>= mWidth || x <= 0 || y >= mHeight || y <= 0 )
		return;
	
	
	mPixelMatrix[y][x].red = color.red;
	mPixelMatrix[y][x].green = color.green;
	mPixelMatrix[y][x].blue = color.blue;
	mPixelMatrix[y][x].alpha = color.alpha;
	
	
	if (isBlank(x , y - 1)){
		Point pos(x, y - 1);
		Pixel tmp(pos, color);
		fillColor(tmp);
	}
	if (isBlank(x - 1, y)){
		Point pos(x - 1, y );
		Pixel tmp(pos, color);
		fillColor(tmp);
	}
	if (isBlank(x + 1, y )){
		Point pos(x + 1, y);
		Pixel tmp(pos, color);
		fillColor(tmp);
	}
	if (isBlank(x , y + 1)){
		Point pos(x , y + 1);
		Pixel tmp(pos, color);
		fillColor(tmp);
	}
}
