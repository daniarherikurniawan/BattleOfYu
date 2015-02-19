#include "Pixel.h"
#include "Screen.h"
#include "Drawable.h"
#include "Bitmap.h"
#include <cstdio>
#include <vector>

//peluru interface
class Bullet :public Drawable{
private:
	Point p;
public:
	Bullet (const Bullet &obj) : bitmap(obj.bitmap), angle(obj.angle) {} 
	Bullet (int x, int y) : bitmap(x,y){}
	virtual Bullet* clone() = 0;
	virtual ~Bullet() {} //buat manggil child destructor
	Bitmap bitmap;
	virtual vector<Pixel> getPixels() const {return bitmap.getPixels();}
	virtual void rotate(int angle) {this->bitmap = this->bitmap.rotate(angle);this->angle += angle;}

	int angle;
	void setPoint (Point p) {this->p = p; bitmap.setBeginPoint(p);}
	Point getPoint() {return p;}

	bool arah;
	int getLeftMostX() const;
	int getTopMostY() const;
};

class LaserBullet : public Bullet {
private:
	static const int trail_length = 40;

public:
	LaserBullet();
	LaserBullet (const LaserBullet &obj) : Bullet(obj) { W = obj.W; H=obj.H;}
	virtual LaserBullet* clone() {return new LaserBullet (*this);}
	virtual void rotate(int angle);
	virtual ~LaserBullet();
	int W,H;
};

//peluru factory
class BulletFactory {
public:
	const static int LASER = 0;
	const static int ROUND = 1;
	Bullet* create(int type);
};
