#ifndef MATRIX_DRAWABLE_H
#define MATRIX_DRAWABLE_H
#include "Pixel.h"
#include <vector>
#include <cstdio>
#include "Drawable.h"
#include "CompositeDrawable.h"
#include <string>
#include <queue>

class MatrixDrawable : public Drawable{
private: 
  Color **mPixelMatrix;
  bool isEmpty(Point position) const;
  bool isBlank(int x, int y);
  void loadFromDrawable(Drawable *drawable);
public:
  MatrixDrawable(Drawable *drawable);
  MatrixDrawable(string inputFile);
  MatrixDrawable(MatrixDrawable matrix,Point startPoint,Point endPoint);
  MatrixDrawable(const MatrixDrawable& other);
  MatrixDrawable();
  ~MatrixDrawable();
  vector<Pixel> getPixels() const;
  int getLeftMostX() const;
  int getTopMostY() const;
  void fillWithFloodFill(Point position,MatrixDrawable pattern);
  Color getColor(Point position) const;
  
  vector<MatrixDrawable> split(int horizontal,int vertical)const;

  void fillColor(Pixel pixel);
  void fillPattern(Drawable *drawable);
	
  int applyGravity(int velocity); // return = 1 jika objek sudah sampai "tanah"
	void translate(int dx,int dy);
  void rotate(int angle,int x0,int y0);
};

#endif
