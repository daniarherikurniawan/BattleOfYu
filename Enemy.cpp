#include "Enemy.h"

int jari_jari = 5;
int panjang_badan = 20;
int tinggi_kaki = 15;

Enemy::Enemy(Point center, Color color) {
	this->color = color;
	this->center = center;
	radius = jari_jari;
}

int Enemy::getLeftMostX() const {
	return center.x - radius;
}

int Enemy::getTopMostY() const {
	return center.y - radius;
}

vector<Pixel> Enemy::getPixels() const {
	vector<Pixel> pixels;

	//Gambar kepala
	int xm = center.x;
	int ym = center.y;
	int r = radius;

	int x = -r;
	int y = 0;
	int err = 2-2*r;

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

	//Gambar badan
	Point badan_atas(center.x, center.y + radius);
	Point badan_bawah(center.x, center.y + radius + panjang_badan);

	Line badan (badan_atas, badan_bawah, color);

	vector<Pixel> pixelBadan = badan.getPixels();
	pixels.insert(pixels.end(),pixelBadan.begin(),pixelBadan.end());

	//Gambar tangan
	Point tangan_kiri(center.x - radius, center.y + radius + panjang_badan / 2);
	Point tangan_kanan(center.x + radius, center.y + radius + panjang_badan / 2);

	Line tangan (tangan_kiri, tangan_kanan, color);

	vector<Pixel> pixelTangan = tangan.getPixels();
	pixels.insert(pixels.end(),pixelTangan.begin(),pixelTangan.end());

	//Gambar kaki kiri
	Point kaki_kiri_atas(center.x, center.y + radius + panjang_badan);
	Point kaki_kiri_bawah(center.x - radius, center.y + tinggi_kaki + panjang_badan);

	Line kakiKiri (kaki_kiri_atas, kaki_kiri_bawah, color);

	vector<Pixel> pixelKakiKiri = kakiKiri.getPixels();
	pixels.insert(pixels.end(),pixelKakiKiri.begin(),pixelKakiKiri.end());

	//Gambar kaki kanan
	Point kaki_kanan_atas(center.x, center.y + radius + panjang_badan);
	Point kaki_kanan_bawah(center.x + radius, center.y + tinggi_kaki + panjang_badan);

	Line kakiKanan (kaki_kanan_atas, kaki_kanan_bawah, color);

	vector<Pixel> pixelKakiKanan = kakiKanan.getPixels();
	pixels.insert(pixels.end(),pixelKakiKanan.begin(),pixelKakiKanan.end());

	return pixels;
}

void Enemy::rotate(int angle, int x0, int y0) {

}

void Enemy::setCenter(Point c) {
	this->center = c;
}

Point Enemy::getCenter() const {
	return center;
}

// #ifndef ENEMY_H
// #define ENEMY_H

// #include "Drawable.h"
// #include "Line.h"
// #include "Pixel.h"
// #include <vector>

// class Enemy : public Drawable {
// private:
// 	Color mColor;
// public:
// 	Enemy(Point start,int width,int height,Color color);
// 	int getLeftMostX() const;
// 	int getTopMostY() const;
// 	vector<Pixel> getPixels() const;
// 	void rotate(int angle,int x0,int y0);
// };

// #endif