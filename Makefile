pixel:
	g++ -o bin/PixelDemo demo/PixelDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt

build:
	g++ -o bin/ClipDemo demo/ClipDrawableDemo.cpp Plane.cpp Ship.cpp WorldMap.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp ClipDrawable.cpp Rectangle.cpp

roda: rodaDemos.cpp
	g++ -o bin/roda demo/rodaDemos.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp Peluru.cpp Bitmap.cpp MatrixDrawable.cpp Drawable.cpp Roda.cpp

battleofyu:
	g++ -o bin/BattleOfYu demo/BattleOfYu.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp Peluru.cpp Bitmap.cpp MatrixDrawable.cpp Drawable.cpp Roda.cpp Pesawat.cpp -lrt

plane:
	g++ -o bin/PlaneDemo demo/Plane_topview_demo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt

scaller: Scaller.o
	g++ Scaller.cpp -o Scaller
	./Scaller
	rm Scaller

battleship:
	g++ -o bin/BattleshipDemo demo/Battleship_topview_demo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt

indonesiamap:
	g++ -o bin/IndonesiaMapDemo demo/IndonesiaMapDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt

testplane:
	g++ Plane.cpp WorldMap.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp ClipDrawable.cpp Rectangle.cpp

testship:
	g++ Ship.cpp WorldMap.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp ClipDrawable.cpp Rectangle.cpp

cubedemo:
	g++ -o bin/cubedemo demo/CubeDemo.c Pixel.cpp Screen.cpp Line.cpp Drawable.cpp

colorpicker:
	g++ colorpicker.cpp -o bin/colorpicker

enemy:
	g++ -o bin/enemy demo/EnemyDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp Peluru.cpp Bitmap.cpp MatrixDrawable.cpp Drawable.cpp Enemy.cpp

mouse:
	g++ -o bin/MouseDemo demo/MouseDemo.cpp Util.cpp Mouse.cpp Keyboard.cpp Screen.cpp Pixel.cpp Pesawat.cpp MatrixDrawable.cpp Drawable.cpp CompositeDrawable.cpp Line.cpp ClipDrawable.cpp WorldMap.cpp Rectangle.cpp Plane.cpp Ship.cpp -lrt
