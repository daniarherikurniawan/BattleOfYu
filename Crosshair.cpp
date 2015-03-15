#include "Crosshair.h"

Crosshair::Crosshair(){
	for(int i = -CROSSHAIR_SIZE; i <= CROSSHAIR_SIZE; ++i){
		Point p(i,0);
		Point q(0,i);
		mPoints.push_back(p);
		mPoints.push_back(q);
	}
	Color color(66,242,144,0);
	mColor = color;
	state = CROSSHAIR_STATE_IDLE;
}

int Crosshair::getLeftMostX() const {
	return mPosition.x - CROSSHAIR_SIZE;
}

int Crosshair::getTopMostY() const {
	return mPosition.y - CROSSHAIR_SIZE;
}
vector<Pixel> Crosshair::getPixels() const{
	vector<Pixel> retval;
	for(int i = 0; i < getPointsSize(); ++i){
		Point p = mPoints[i];
		p.translate(getPosition().x,getPosition().y);
		
		Pixel pixel(p,mColor);
		retval.push_back(pixel);
	}
	return retval;
}

Point Crosshair::getPosition() const {
	return mPosition;
}

void Crosshair::setPosition(Point p) {
	mPosition = p;
}

int Crosshair::getPointsSize() const {
	return mPoints.size();
}

//I atas
//J kiri
//L Kanan
//K bawah
//F tembak
void Crosshair::updateFromKeyboard(){
	if (Keyboard::getBufferedCode() != 0){
		if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_EXIT){
			exit(EXIT_SUCCESS);
		} else if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_I){
			mPosition.y -= CROSSHAIR_DISPLACEMENT;
			state = CROSSHAIR_STATE_MOVE;
			
		} else if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_J){
			mPosition.x -= CROSSHAIR_DISPLACEMENT;
			state = CROSSHAIR_STATE_MOVE;
			
		} else if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_L){
			mPosition.x += CROSSHAIR_DISPLACEMENT;
			state = CROSSHAIR_STATE_MOVE; 
			
		} else if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_K){
			mPosition.y += CROSSHAIR_DISPLACEMENT;
			state = CROSSHAIR_STATE_MOVE;
			
		} else if (Keyboard::getBufferedCode() == Keyboard::KEYBOARD_F){
			state = CROSSHAIR_STATE_SHOOT;
		}
		
	} else {
		state = CROSSHAIR_STATE_IDLE;
	}
}

bool Crosshair::isShooting() const {
	return state == CROSSHAIR_STATE_SHOOT;
}

void Crosshair::shoot(vector<Enemy> &enemies){
	vector<Enemy> ret_enemies;
	
	//yang intersect gak masuk lagi
	for(int i = 0; i < (int) enemies.size(); i++){
		if (!intersect(enemies[i])){
			ret_enemies.push_back(enemies[i]);
		}
	}
	
	enemies = ret_enemies;
}

bool Crosshair::intersect(const Enemy& enemy) const {
	Point crosshairPosition = getPosition();
	if(crosshairPosition.x > enemy.getLeftMostX() && crosshairPosition.x < enemy.getRightMostX() && crosshairPosition.y > enemy.getTopMostY() && crosshairPosition.y < enemy.getBottomMostY()) {
		return true;
	} else {
		return false;
	}
}
