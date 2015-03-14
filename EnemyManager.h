#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include <vector>
#include "Enemy.h"
#include "Crosshair.h"

class EnemyManager {
private:
	vector<Enemy> enemies;
	Crosshair crosshair;
public:
	EnemyManager();
	void addEnemy(Enemy enemy);
	vector<Enemy> getEnemies() const;
	void setCrosshairPosition(Point p);
	Point getCrosshairPosition() const;
	void intersect();
};

#endif