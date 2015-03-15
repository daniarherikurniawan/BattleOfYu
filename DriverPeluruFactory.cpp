#include "PeluruFactory.cpp"
#include "Screen.h"
int main () {
	int angle;
	Screen s;
	BulletFactory bf;
	Bullet *b = bf.create(BulletFactory::LASER);
	Bullet *new_b;
	int y = 100, x= 100, i=0;
	scanf("%d",&angle);
	while(i) {
		if (i % 100 == 0) {
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
