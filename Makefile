pixel:
	g++ -o bin/PixelDemo demo/PixelDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp -lrt

build:
	g++ -o bin/ClipDemo demo/ClipDrawableDemo.cpp Plane.cpp Ship.cpp WorldMap.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp ClipDrawable.cpp Rectangle.cpp -lrt

roda: rodaDemos.cpp
	g++ -o bin/roda demo/rodaDemos.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp Peluru.cpp Bitmap.cpp MatrixDrawable.cpp Drawable.cpp Roda.cpp

battleofyu:
	g++ -o bin/BattleOfYu demo/PropellerDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp Peluru.cpp Bitmap.cpp MatrixDrawable.cpp Drawable.cpp -lrt

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

polygon3d:
	g++ -o bin/polygon3d demo/Polygon3DDemo.cpp Pixel.cpp Screen.cpp Line.cpp Drawable.cpp CameraService.cpp Line3D.cpp Keyboard.cpp Polygon3D.cpp Polygon.cpp
	
cubedemo:
	g++ -o bin/cubedemo demo/CubeDemo.cpp Pixel.cpp Screen.cpp Line.cpp Drawable.cpp CameraService.cpp Line3D.cpp Keyboard.cpp Polygon3D.cpp Polygon.cpp WorldManager.cpp
	
line3ddemo:
	g++ -o bin/line3ddemo demo/Line3DDemo.cpp Pixel.cpp Screen.cpp Line.cpp Drawable.cpp Line3D.cpp

mapdemo:
	g++ -o bin/mapdemo demo/CubeDemo.cpp Pixel.cpp Screen.cpp Line.cpp Drawable.cpp CameraService.cpp Line3D.cpp Keyboard.cpp WorldManager.cpp Polygon3D.cpp Polygon.cpp

colorpicker:
	g++ colorpicker.cpp -o bin/colorpicker


