pixel:
	g++ -o PixelDemo PixelDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt

build:
	g++ -o bin/ClipDemo demo/ClipDrawableDemo.cpp WorldMap.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp ClipDrawable.cpp Rectangle.cpp

roda: rodaDemos.cpp
	g++ -o roda rodaDemos.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp Peluru.cpp Bitmap.cpp MatrixDrawable.cpp Drawable.cpp Roda.cpp
	./roda
	rm roda

clean:
	rm -rf *.o
	rm -rf BattleOfYu
	rm -rf *~

battleofyu:
	g++ -o BattleOfYu PropellerDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp Peluru.cpp Bitmap.cpp MatrixDrawable.cpp Drawable.cpp -lrt

plane:
	g++ -o PlaneDemo Plane_topview_demo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt
	./PlaneDemo

scaller: Scaller.o
	g++ Scaller.cpp -o Scaller
	./Scaller

battleship:
	g++ -o BattleshipDemo Battleship_topview_demo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt
	./BattleshipDemo
