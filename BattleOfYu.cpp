// THE BATTLE OF YU (1813 - 1890)

#include "Pixel.h"
#include "Screen.h"
#include "Line.h"
#include "MatrixDrawable.h"
#include "CompositeDrawable.h"
#include "Util.h"
#include "Keyboard.h"
#include "Peluru.h"
#include "Roda.h"
#include "Pesawat.h"
#include "Propeller.hpp"
#include <unistd.h>


const long long SECONDS_PER_FRAME = 1000/60; // yang ini speed looping gamenya
const int FRAMERATE = 25000; // yang ini speed buat efek pesawat jatoh dkk

Point position(5,5);
Color color(0,255,0,0);
Pixel pixel(position,color);

Point beginPosition(4,4);
Point endPosition(100,100);
Color lineColor(255,0,0,0);
Line line(beginPosition,endPosition,color);

CompositeDrawable c_ship("ship.txt");
MatrixDrawable ship(&c_ship);

CompositeDrawable meledak("explosion.txt");
CompositeDrawable bird("bird.txt");
CompositeDrawable fish("fish.txt");
CompositeDrawable parasut("parasut.txt");
//MatrixDrawable parasut(&c_parasut);

Pesawat plane;
Roda roda1;
Roda roda2;

Propeller propeller("propeller.txt");


bool isPlane = false;
bool isShip = false;

float planeEx = 0.0f;
float shipEx = 0.0f;

bool isFlipShip = false;
bool isFlipPlane = false;

// state di dalam game
bool isFinish = false;
bool isAftermath = false;

// state di aftermath
bool isPlaneGrounded = false;
bool isBanSelesai = false;

BulletFactory bf;
Bullet *b[100]; // = bf.create(BulletFactory::LASER);

int peluruKosong(){
// cari space kosong pada array peluru
	for (int i = 0; i < 100; i++){
		if (b[i] == NULL){
			return i;
		}
	}
	return -1;
}

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}

void handleInput() {
	if (Keyboard::isKeyDown()) {
		if (Keyboard::getKeyDownCode() == Keyboard::KEY_D && !isPlane && !isShip){
			isFlipShip = false;
			ship.moveBy(2,0);
		}else if (Keyboard::getKeyDownCode() == Keyboard::KEY_A && !isPlane && !isShip){
			isFlipShip = true;
			ship.moveBy(-2,0);
			
		}else if (Keyboard::getKeyDownCode() == Keyboard::KEY_L && !isPlane && !isShip){
			if (!isFlipPlane){
				propeller.moveBy(-90,0);
				roda1.moveBy(20,0);
				roda2.moveBy(20,0);
			}
			isFlipPlane = true;
			plane.moveBy(2,0);
			propeller.moveBy(2,0);
			roda1.moveBy(2,0);
			roda2.moveBy(2,0);
			parasut.moveBy(2,0);
			
		}else if (Keyboard::getKeyDownCode() == Keyboard::KEY_J && !isPlane && !isShip){
			if (isFlipPlane){
				propeller.moveBy(90,0);
				roda1.moveBy(-20,0);
				roda2.moveBy(-20,0);
			}			
			isFlipPlane = false;
			plane.moveBy(-2,0);
			propeller.moveBy(-2,0);
			roda1.moveBy(-2,0);
			roda2.moveBy(-2,0);
			parasut.moveBy(-2,0);
		}else if (Keyboard::getKeyDownCode() == Keyboard::KEY_W)
			exit(0);
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_S && !isPlane && !isShip){
			int pos = peluruKosong();
			if (pos != -1){
				b[pos] = bf.create(BulletFactory::LASER);
				b[pos]->arah = false;
				Point st = ship.getPosition();
				b[pos]->setPoint(Point(st.x + 115, st.y + 60));
			}
		}
		else if (Keyboard::getKeyDownCode() == Keyboard::KEY_K && !isPlane && !isShip){
			int pos = peluruKosong();
			if (pos != -1){
				b[pos] = bf.create(BulletFactory::LASER);
				b[pos]->arah = true;
				Point st = plane.getPosition();
				b[pos]->rotate(180);
				b[pos]->setPoint(Point(st.x + 65, st.y + 26));
			}
		}
	}
}

int main() {

	Screen screen;
	
	long long previousTime = (long long)Util::getCurrentTimeInMiliseconds();
	long long accumulateTime = 0;
	Keyboard::startListening();
	
	Point f_pos(50,20);
	Color  f_col(255,255,255,255);
	Pixel f_plane(f_pos, f_col);
	propeller.setDrawPosition(145,30);
	
	bird.setPosition(50,20);
	fish.setPosition(50,20);

	roda1.setRadius(10);
	roda1.setCenter(Point(40,50));

	roda2.setRadius(10);
	roda2.setCenter(Point(120,50));
	parasut.setPosition(50,10);
	//plane.setPosition(200,10);
	//plane.fillColor(f_plane);
	//plane.fillPattern(&bird);
	
	ship.setPosition(10,250);
	
	
	
	f_pos.x = 50; f_pos.y = 20;
	Pixel f_ship(f_pos, f_col);
	//ship.fillColor(f_ship);
	
	f_pos.x = ship.getWidth() / 2;
	f_pos.y = ship.getHeight() / 2;
	
	
	ship.fillWithFloodFill(f_pos,&fish);
	

	int ii = 0;

	float speed = 0;
	float initialPercentage = 0;

	
	/* Game Clock */
	while (true) {
		if (accumulateTime>(SECONDS_PER_FRAME)) {
			handleInput();
			
			
			screen.beginBatch();
			
			
			if (isPlane){
			  //planeEx += 0.05f;
			  //meledak.setPosition(meledak.getPosition().x - 2,meledak.getPosition().y - 2);

			
	
			    initialPercentage += 0.07;
			plane.explode(initialPercentage);
				speed += 0.1f;

			propeller.applyGravity((int)speed);

			parasut.applyGravity((int)speed);
			screen.draw(&parasut);

			if (!isPlaneGrounded){
				isPlaneGrounded = roda1.applyGravity((int)speed);
				roda2.applyGravity((int)speed);
			}else{
				propeller.setState(0);
				isBanSelesai = !roda1.bounce();
				roda2.bounce();
			}

			usleep(FRAMERATE/4);
			  //screen.draw(&meledak, planeEx);
			  
			  if (isBanSelesai){

			      //screen.beginBatch();
			      //screen.endBatch();

			  	  isPlane = false;
			      //isAftermath = true;

				gotoxy(1, 10);
			      printf("\t\tSHIP WIN!\n\n\n\n\n\n\n\n\n\n");
			      isFinish = true;

				  /* TODO:
			         - Animasi pesawat pecah
			         - Kasih Gravity tiap pecahan pesawat biar jatuh:
			           - baling-baling
			           - ban
			           - potongan badan pesawat
			           - pilot keluar dari pesawat pake parasut
			         - Bikin ban mantul-mantul di atas tanah -_-
			      */

			      // gotoxy(10, 10);
			      // printf("SHIP WIN!\n\n\n\n\n\n\n\n\n\n");

			      // exit(0);

			  }
			}

			screen.draw(&plane, isFlipPlane);
			screen.draw(&roda1);
			screen.draw(&roda2);
			

			propeller.draw(&screen);

			if (isShip){
			  shipEx += 0.05f;
			  
			  meledak.setPosition(meledak.getPosition().x - 2,meledak.getPosition().y - 2);
			  screen.draw(&meledak, shipEx);
			  
			  if (shipEx > 2){
			      screen.beginBatch();
			      screen.endBatch();
			      gotoxy(10, 10);
			      printf("PLANE WIN!\n\n\n\n\n\n\n\n\n\n");
			      isFinish = true;
			      isShip = false;
			  }
			}else if (!isPlane) screen.draw(&ship, isFlipShip);
			
			// handle peluru
			for (int i = 0; i < 100; i++){
				if (b[i] != NULL){
					Point st = b[i]->getPoint();
					bool arah = b[i]->arah;
					b[i] = bf.create(BulletFactory::LASER);
					
					if (arah == true){ //pesawat yang nembak, pelurunya kebawah
						b[i]->arah = true;
						b[i]->rotate(180);
						b[i]->setPoint(Point(st.x, st.y + 1));
						
						if (st.y > 330) b[i] = NULL;
						
						if (st.x > ship.getPosition().x  - 10 && st.x < ship.getPosition().x + 150 && st.y > 220){	// COLLISION
						    meledak.setPosition(ship.getPosition().x,ship.getPosition().y);
						    isShip = true;
						    b[i] = NULL;
						}
						
					}else{
						b[i]->arah = false;
						b[i]->setPoint(Point(st.x, st.y - 1));
						
						if (st.y < 0) b[i] = NULL;
						
						if (st.x > plane.getPosition().x - 5 && st.x < plane.getPosition().x + 180 && st.y < 40){	// COLLISION
						    meledak.setPosition(plane.getPosition().x,plane.getPosition().y);
						    isPlane = true;
						    b[i] = NULL;

							Point explosionCenter(plane.getWidth()/2,plane.getHeight()/2);

							//Ini harus dipanggil sebelum meledak
							plane.startExplode(explosionCenter);
						}
					}
					if (b[i] != NULL) screen.draw(b[i]);
				}
			}

			if (isAftermath) {
				
			//	speed += 1; // speed untuk gravity pull
			//	isPlaneGrounded = plane.applyGravity(speed); /* Kasih efek gravity, return valuenya bakal 1 kalo object nya udah sampe "tanah" */				
			//	screen.draw(&plane, isFlipPlane); /* Ini buat gambar objek2 yang udah mulai jatoh ke tanah */
			//	usleep(FRAMERATE); // ini buat ngedelay kecepetan refresh frame biar gak terlalu cepet
				initialPercentage += 0.01;
				plane.explode(initialPercentage);

				if(initialPercentage == 1) { // periksa kalo semua objek udah sampe tanah, berarti game nya pindah ke state finish
					isAftermath = false;
					isFinish = true;

					screen.beginBatch();
					screen.draw(&plane, isFlipPlane); // ini buat gambar object2 yang udah berserakan di tanah
					screen.endBatch();

					gotoxy(10,10);
					printf("Ship Wins!\n\n\n\n\n");
					gotoxy(40,40);
					printf("\n");
				}
			}

			if (isFinish) {
				exit(0);
			}

			screen.endBatch();
			
			while (accumulateTime<(SECONDS_PER_FRAME))
				accumulateTime -= (SECONDS_PER_FRAME);
				
		}
		else {
			long long currentTime = (long long)Util::getCurrentTimeInMiliseconds();
			accumulateTime += (currentTime - previousTime);
			previousTime = currentTime;
		}
	}

	return 0;	
}




// coretan
	//screen.drawPixel(pixel);
	//screen.draw(&line);
	//screen.draw(&triangle);
