#include "Roda.h"

Roda::Roda() {
	radius = 0;
	center.x = 0;
	center.y = 0;
	color.red = 0;
	color.green = 133;
	color.blue = 244;
	color.alpha = 0;
	finish = false;
	rolling = false;
	velocity = -20;
	speed_reducer = 2;
	limit = -20;
	x_counter = 0;
}

int Roda::getRadius() const {
	return radius;
}

void Roda::setRadius(int r) {
	radius = r;
}

Point Roda::getCenter() const {
	return center;
}

void Roda::setCenter(Point mid) {
	center.x = mid.x;
	center.y = mid.y;
}

bool Roda::bounce() {

	if(!finish) {
		if(!rolling) {
			center.y += velocity;
			x_counter++;
			if(x_counter == 5) {
				x_counter = 0;
				center.x += 5;
			}
			velocity++;
		}
		
		if(velocity > limit * -1) {
			limit += speed_reducer;
			velocity = limit;
			if(limit == 0) {
				rolling = true;
				x_counter = 0;
			}
		}

		if(rolling) {
			x_counter++;
			center.x++;
			if(x_counter == 50) {
				rolling = false;
				finish = true;
				x_counter = 0;
			}
		}
		usleep(10000);
		return true;
	} else { // if (finish)
		return false;
	}
}

vector<Pixel> Roda::getPixels() const {
	int xm = center.x;
	int ym = center.y;
	int r = radius;

	int x = -r;
	int y = 0;
	int err = 2-2*r;

	vector<Pixel> pixels;
	do {
		pixels.push_back(Pixel(Point(xm-x,ym+y),color));
		pixels.push_back(Pixel(Point(xm-y,ym-x),color));
		pixels.push_back(Pixel(Point(xm+x,ym-y),color));
		pixels.push_back(Pixel(Point(xm+y,ym+x),color));
		r = err;
		if (r <= y) {
			err += ++y*2+1;
		}
		if (r > x || err > y) {
			err += ++x*2+1;
		}
	} while (x < 0);

	return pixels;
}

int Roda::getLeftMostX() const {
	return center.x - radius;
}

int Roda::getTopMostY() const {
	return center.y - radius;
}

void Roda::setColor(Color c) {
	color = c;
}

Color Roda::getColor() const {
	return color;
}

void Roda::translate(int dx, int dy) {
	center.x += dx;
	center.y += dy;
};

void Roda::rotate(int angle, int x0, int y0) {
	//gak usah ngapa-ngapain, roda diputer2 sama aja
}