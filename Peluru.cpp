#include "Peluru.h"

Bullet* BulletFactory::create(int type){
	if (type == BulletFactory::LASER){
		return new LaserBullet();
	}
}

LaserBullet::LaserBullet() : Bullet(10,30+trail_length){
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
	for(int y = 2; y < trail_length; y++)
	for(int x = 0; x < W; x++){
		Color trail ((darkBlue.red * (trail_length - y)) / trail_length,
				(darkBlue.blue * (trail_length - y)) / trail_length,
				(darkBlue.green * (trail_length - y)) / trail_length,
				0
				);
		this->bitmap.setPixel(Point(x,y+H),trail);
	}
}

void LaserBullet::rotate(int angle) {
	Bullet::rotate(angle);
	this->W = this->bitmap.getWidth();
	this->H = this->bitmap.getHeight();
}


int Bullet::getLeftMostX() const{
	return this->bitmap.getLeftMostX();
}

int Bullet::getTopMostY() const{
	return this->bitmap.getTopMostY();
}

void Bullet::translate(int dx,int dy){
	printf("Bullet::translate not supported\n");
}
void LaserBullet::rotate(int angle,int x0,int y0){
	printf("Laserbullet::rotate not supported\n");
}

LaserBullet::~LaserBullet(){

}
