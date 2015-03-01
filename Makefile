pixel:
	g++ -o bin/PixelDemo demo/PixelDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt

build:
	g++ -o bin/ClipDemo demo/ClipDrawableDemo.cpp WorldMap.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp ClipDrawable.cpp Rectangle.cpp

roda: rodaDemos.cpp
	g++ -o bin/roda demo/rodaDemos.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp Peluru.cpp Bitmap.cpp MatrixDrawable.cpp Drawable.cpp Roda.cpp

battleofyu:
	g++ -o bin/BattleOfYu demo/PropellerDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp Peluru.cpp Bitmap.cpp MatrixDrawable.cpp Drawable.cpp -lrt

plane:
	g++ -o bin/PlaneDemo demo/Plane_topview_demo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt

scaller: Scaller.o
	g++ demo/Scaller.cpp -o bin/Scaller

battleship:
	g++ -o bin/BattleshipDemo demo/Battleship_topview_demo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt

indonesiamap:
	g++ -o bin/IndonesiaMapDemo demo/IndonesiaMapDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt
