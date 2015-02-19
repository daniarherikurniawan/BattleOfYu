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
	Bullet (const Bullet &obj) : bitmap(obj.bitmap), angle(obj.angle), trail_length(obj.trail_length) {} 
	Bullet (int x, int y) : bitmap(x,y){}
	virtual Bullet* clone() = 0;
	virtual ~Bullet() {} //buat manggil child destructor
	Bitmap bitmap;
	virtual vector<Pixel> getPixels() {return bitmap.getPixels();}
	virtual void rotate(int angle) {this->bitmap = this->bitmap.rotate(angle);this->angle += angle;}

	int angle;
	int trail_length;
	void setPoint (Point p) {this->p = p; bitmap.setBeginPoint(p);}
	Point getPoint() {return p;}
};

class LaserBullet : public Bullet {
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


Bullet* BulletFactory::create(int type){
	if (type == BulletFactory::LASER){
		return new LaserBullet();
	}
}

LaserBullet::LaserBullet() : Bullet(10,30){
	Color blue(51,204,255,0);
	Color darkBlue(36,143,178,0);
	W = 10; H = 30;
	//random resize
	
	for(int y = 0; y < H - 10; y++){
		for(int x = 0; x < W; x++){
			this->bitmap.setPixel(Point(x,y),blue);
		}
	}
	for(int y = H - 10; y < H; y++)
	for(int x = 0; x < W; x++){
		this->bitmap.setPixel(Point(x,y),darkBlue);
	}
}

void LaserBullet::rotate(int angle) {
	Bullet::rotate(angle);
	this->W = this->bitmap.getWidth();
	this->H = this->bitmap.getHeight();
}

LaserBullet::~LaserBullet(){

}

int main () {
	int angle;
	Screen s;
	BulletFactory bf;
	Bullet *b = bf.create(BulletFactory::LASER);
	Bullet *new_b = b->clone();
	int y = 100, x= 100, i=1;
	scanf("%d",&angle);
	while(i) {
		if (i % 100 == 0) {
			printf("n\n");
			float radians=(2*3.1416*angle)/360; 

			float cosine=(float)cos(radians); 
			float sine=(float)sin(radians); 
			y = y - (int)(sine*i/100);
			x = x - (int)(cosine*i/100);
			delete new_b;
			new_b = b->clone();
			new_b->rotate(angle-90);
			new_b->setPoint(Point(x,y));
		}
		else {
			s.beginBatch();
			s.draw(new_b);
			s.endBatch();
		}
		i++;
	}
	delete b;
	delete new_b;
}

