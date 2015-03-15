#ifndef CROSSHAIR_MANAGER
#define CROSSHAIR_MANAGER
#include "Drawable.h"
#include "Pixel.h"
#include "Keyboard.h"
#include "Enemy.h"
#include <vector>
#define CROSSHAIR_SIZE 15
#define CROSSHAIR_DISPLACEMENT 1
#define CROSSHAIR_STATE_SHOOT 0
#define CROSSHAIR_STATE_IDLE 1
#define CROSSHAIR_STATE_MOVE 5
using namespace std;

class Crosshair: public Drawable {
	Point mPosition;
	Color mColor;
	vector<Point> mPoints; //crosshair points
	int state;
	
public:
	Crosshair();
	vector<Pixel> getPixels() const;
	int getLeftMostX() const;
	int getTopMostY() const;
	int getPointsSize() const;
	Point getPosition() const;
	
	void setPosition(Point p);
	void updateFromKeyboard();
	bool isShooting() const;
	void shoot(vector<Enemy> &enemies);
	bool intersect(const Enemy& enemy) const;

};
#endif
