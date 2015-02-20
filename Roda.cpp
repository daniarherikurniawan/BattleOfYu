#include "Roda.h"

Roda::Roda() {
	radius = 0;
	center.x = 0;
	center.y = 0;
	color.red = 0;
	color.green = 133;
	color.blue = 244;
	color.alpha = 0;
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

void Roda::bounce() {
	Screen screen;
	bool finish = false;
	int velocity = -20;
	int speed_reducer = 2;
	int limit = -20;
	int x_counter = 0;
	int center_y = center.y;

	do {
		screen.beginBatch();

		if(!finish) {
			center.y += velocity;
			x_counter++;
			if(x_counter == 5) {
				x_counter = 0;
				center.x += 5;
			}
			velocity++;
		}

		screen.draw(this);
		
		if(velocity > limit * -1) {
			limit += speed_reducer;
			velocity = limit;
			center.y = center_y;
			if(limit == 0) {
				finish = true;
			}
		}

		usleep(10000);

		screen.endBatch();
	} while(!finish);
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
