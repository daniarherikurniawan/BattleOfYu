#include "Bitmap.h"
#include "Screen.h"
#include "Pixel.h"
#include <cstdio>

int main () {
	Color warna_peluru = Color(255,255,255,0);

	Screen s;
	int angle=0;        //45° for example 
	int width = 1;
	int width_limit = 3;
	int trail_length = 40;
	int y = 100;
	int length = 8;
	int x = 100;
	int bitmap_peluru_width = 2*width_limit+1;
	int bitmap_peluru_height = length + trail_length;
	scanf("%d",&angle);
	//Gambar bitmap peluru
	Bitmap bitmap_peluru (bitmap_peluru_width, bitmap_peluru_height);
	for (int j = 0; j < length; j++) {
	for (int i = 0; i < bitmap_peluru_width; i++) {
		if (i < width_limit-width || i > width_limit+width)
			bitmap_peluru.setPixel(Point(i,j),Color(0,0,0,255));
		else 
			bitmap_peluru.setPixel(Point(i,j),warna_peluru);
        }
	 	if (width < width_limit) width++;
	}
	for (int j = 3; j < trail_length;j++) 
	for (int i = 0; i < bitmap_peluru_width; i++){
		Color warna_trailing = Color(warna_peluru.red *(trail_length-j-1)/trail_length,
						warna_peluru.green *(trail_length-j-1)/trail_length,
						warna_peluru.red *(trail_length-j-1)/trail_length,
						warna_peluru.alpha);

		bitmap_peluru.setPixel(Point(i,j+length),warna_trailing);
	}
	bitmap_peluru.setBeginPoint(Point(100,100));
	int i = 1;
	Bitmap new_b = bitmap_peluru.rotate(angle);
	while(i) {
		if (i % 100 == 0) {
			float radians=(2*3.1416*angle)/360; 

			float cosine=(float)cos(radians); 
			float sine=(float)sin(radians); 
			y = y - (int)(sine*i/100);
			x = x - (int)(cosine*i/100);
			new_b = bitmap_peluru.rotate(angle-90);
			new_b.setBeginPoint(Point(x,y));
		}
		else {
			s.beginBatch();
			s.draw(&new_b);
			s.endBatch();
		}
		i++;
	}
}
