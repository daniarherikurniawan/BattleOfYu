// #ifndef ENEMY_MANAGER_H
// #define ENEMY_MANAGER_H

// #include <vector>
// #include "Enemy.h"
// #include "Crosshair.h"

// class EnemyManager {
// private:
// 	vector<Enemy> enemies;
// 	Crosshair crosshair;
// public:
// 	EnemyManager();
// 	void addEnemy(Enemy enemy);
// 	vector<Enemy> getEnemies() const;
// 	void setCrosshairPosition();
// 	Point getCrosshairPosition();
// 	void intersect();
// }

// #endif

#include "EnemyManager.h"

EnemyManager::EnemyManager() {
	//do nothing gitu loh.
}

void EnemyManager::addEnemy(Enemy enemy) {
	enemies.push_back(enemy);
}

vector<Enemy> EnemyManager::getEnemies() const {
	return enemies;
}

void EnemyManager::setCrosshairPosition(Point p) {
	crosshair.setPosition(p);
}

Point EnemyManager::getCrosshairPosition() const {
	return crosshair.getPosition();
}

void EnemyManager::intersect() {
	for(int i=0; i<enemies.size(); i++) {
		Point crosshairPosition = crosshair.getPosition();
		if(crosshairPosition.x > enemies[i].getLeftMostX() && crosshairPosition.x < enemies[i].getRightMostX() && crosshairPosition.y > enemies[i].getTopMostY() && crosshairPosition.y < enemies[i].getBottomMostY()) {
			//intersection kan berarti
			enemies.erase(enemies.begin()+i);
			i--;
		}
	}
}