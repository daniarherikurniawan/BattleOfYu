build:
	g++ -o bin/PixelDemo demo/PixelDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp MatrixDrawable.cpp Drawable.cpp ClipDrawable.cpp Rectangle.cpp

run: BattleOfYu
	./BattleOfYu

roda: rodaDemos.cpp
	g++ -o roda rodaDemos.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp Peluru.cpp Bitmap.cpp MatrixDrawable.cpp Drawable.cpp Roda.cpp
	./roda
	rm roda

clean:
	rm -rf *.o
	rm -rf BattleOfYu
	rm -rf *~

test-build:
	g++ -o BattleOfYu PropellerDemo.cpp Pixel.cpp Screen.cpp Line.cpp CompositeDrawable.cpp Util.cpp Keyboard.cpp Peluru.cpp Bitmap.cpp MatrixDrawable.cpp Drawable.cpp -lrt

