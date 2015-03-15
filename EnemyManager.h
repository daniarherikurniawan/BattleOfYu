#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include <vector>
#include "Enemy.h"
#include "Crosshair.h"
#include "Screen.h"
#include "Mouse.h"

class EnemyManager {
private:
	vector<Enemy> enemies;
	Crosshair crosshair;
	Screen *screenRef;
	
public:
	EnemyManager(Screen *screenRef);
	
	//dipanggil sekali
	void start();
	//dipanggil pas game loop
	void loop();
	//dipanggil pas mau ngedraw
	void draw();
	
	int getEnemiesSize() const;
	void setCrosshairPosition(Point p);
	Point getCrosshairPosition() const;

protected:
	void addEnemy(Enemy enemy);
	vector<Enemy> getEnemies() const;
	
	void intersect();
	
};

#endif
