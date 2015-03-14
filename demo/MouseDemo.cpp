#include "../Util.h"
#include "../Mouse.h"
#include "../Pixel.h"
#include "../Screen.h"
#include "../Pesawat.h"
#include <vector>
#include "../Drawable.h"
using namespace std;

const long long SECONDS_PER_FRAME = 1000/60;

CompositeDrawable mousePointer("../mousePointer.txt");
vector<Drawable*> drawables;

void handleInput() {
  Mouse::update();
  if (Mouse::isMouseEvent()) {
    if (Mouse::getMouseEventCode() == Mouse::MOUSE_LEFT_PRESS) {

    } else if (Mouse::getMouseEventCode() == Mouse::MOUSE_LEFT_RELEASE) {
      Pesawat *plane = new Pesawat();
      plane->setPosition(Mouse::getPositionX(),Mouse::getPositionY());
      drawables.push_back(plane);
    } else if (Mouse::getMouseEventCode() == Mouse::MOUSE_RIGHT_PRESS) {

    } else if (Mouse::getMouseEventCode() == Mouse::MOUSE_RIGHT_RELEASE) {

    }
  }
}


int main()
{
  long long previousTime = (long long)Util::getCurrentTimeInMiliseconds();
  long long accumulateTime = 0;

  Screen screen;

  Point position(1000,100);
  Color color(0,255,0,0);
  Pixel pixel(position,color);

  mousePointer.setPosition(50,50);
  Mouse::startListening("event3");
  while(true){
    if (accumulateTime>SECONDS_PER_FRAME){
      handleInput();
      mousePointer.setPosition(Mouse::getPositionX()-mousePointer.getWidth()/2,Mouse::getPositionY()-mousePointer.getHeight()/2);
      screen.beginBatch();
      screen.draw(&mousePointer);
      for (int i=0;i<drawables.size();i++) {
        screen.draw(drawables[i]);
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