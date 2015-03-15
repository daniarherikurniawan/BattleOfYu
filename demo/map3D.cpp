
#include "../Pixel.h"
#include "../Screen.h"
#include "../Line.h"
#include "../Line3D.h"
#include "../CameraService.h"
#include "../Polygon3D.h"
#include <iostream>
#include <algorithm>
#include "../Crosshair.h"
#include "../MatrixDrawable.h"
#include "../WorldManager.h"

Line* transform (Line3D* ln);
void translate (Line* ln, int x, int y);
Crosshair crosshair;

float scale = 0.001;

//Mengembalikan barycenter dari sebuah polygon
Point3D getMeanPoint (Polygon3D a) {
	Point3D sum;
	vector<Line3D> allLine = a.getAllLine();
	for (int i = 0; i < allLine.size(); i++) {
		Point3D begin = allLine[i].getBeginPoint();
		Point3D end = allLine[i].getEndPoint();
		sum.z += begin.z + end.z;
		sum.y += begin.y + end.y;
		sum.x += begin.x + end.x;
	}
	sum.z = sum.z/(allLine.size()*2);
	sum.y = sum.y/(allLine.size()*2);
	sum.x = sum.x/(allLine.size()*2);
	return sum;
}

Point3D getExtremePoint (Polygon3D a,Point3D p) {
	vector<Line3D> allLine = a.getAllLine();
	Point3D extreme= allLine[0].getBeginPoint();
	extreme.translate(-p.x,-p.y,-p.z);
	for (int i = 0; i < allLine.size(); i++) {
		Point3D begin = allLine[i].getBeginPoint();
		Point3D end = allLine[i].getEndPoint();
		begin.translate(-p.x,-p.y,-p.z);
		end.translate(-p.x,-p.y,-p.z);
		double beginDistance = begin.x * begin.x + begin.y * begin.y + begin.z*begin.z;
		double endDistance = end.x*end.x + end.y*end.y + end.z*end.z;
		double extremeDistance = extreme.x*extreme.x + extreme.y*extreme.y + extreme.z*extreme.z;
		if (extremeDistance > beginDistance) {extreme = begin;extremeDistance = beginDistance;}
		if (extremeDistance > endDistance) {extreme = end;extremeDistance = endDistance;}
	}
	return extreme;
}

//Buat sorting vector polyline terhadap cameraservice
bool sortFunction(Polygon3D a, Polygon3D b) {
	Point3D campos = CameraService::position;
	a.beforeDraw(); b.beforeDraw();
	Point3D aPoint,bPoint;
	/*Extreme Based
	Point3D zero;
	aPoint = getExtremePoint(a,zero);
	bPoint = getExtremePoint(b,zero); */
	// Mean based
	aPoint = getMeanPoint(a);
	bPoint = getMeanPoint(b);

	//cout << campos.x << " " << campos.y << " " << campos.z << " ";
	//cout << aPoint.x << " " << aPoint.y << " " << aPoint.z << " " << bPoint.x << " " << bPoint.y << " " << bPoint.z << "\n";
	
	double aDistance = aPoint.x * aPoint.x + aPoint.y * aPoint.y + aPoint.z * aPoint.z;
	double bDistance = bPoint.x * bPoint.x + bPoint.y * bPoint.y + bPoint.z * bPoint.z;
	a.afterDraw(); b.afterDraw();
	return aDistance < bDistance; 
}

//Algoritma painter
void drawPainter(vector<Polygon3D> vpoly, Screen *screen);

int main () {
	WorldManager* mapITB = new WorldManager();
	mapITB->readMap3D("../mapitb.txt");
	vector<Polygon3D> vpoly;
	vpoly = mapITB->mPolygons;

	Screen screen;
	//kamera digeser terus ke kanan, ke bawah, terus di zoom
	//kubusnya bakal gerak ke kiri, ke atas, zoom
	
	//init posisi kamera
	CameraService::position.x = 80;
	CameraService::position.y = 0;
	CameraService::position.z = 300;
	CameraService::mCameraDegreeHorizontal = 0;
	Keyboard::startListening();
	crosshair.setPosition(Point(100,100));
	while (1){
		screen.beginBatch();

		drawPainter(vpoly,&screen);
		
		screen.draw(&crosshair);
		CameraService::handleInput();
		screen.endBatch();
	}
	
}


Line* transform (Line3D* ln) {
	Point first, last;
	first.x = (ln->getBeginPoint()).x / ((ln->getBeginPoint()).z*scale + 1);
	first.y = (ln->getBeginPoint()).y / ((ln->getBeginPoint()).z*scale + 1);
	last.x = (ln->getEndPoint()).x / ((ln->getEndPoint()).z*scale + 1);
	last.y = (ln->getEndPoint()).y / ((ln->getEndPoint()).z*scale + 1);
	Color white(255,255,255,0);
	Line* l = new Line(first,last,white);
	return l;
}

void translate (Line* ln, int x, int y) {
	Point p1 = ln->getBeginPoint();
	Point p2 = ln->getEndPoint();
	Color c = ln->getColor();
	p1.x = p1.x + x;
	p1.y = p1.y + y;
	p2.x = p2.x + x;
	p2.y = p2.y + y;
	ln->setBeginPoint(p1);
	ln->setEndPoint(p2);
}

void drawPainter(vector<Polygon3D> vpoly, Screen *screen) {
	std::sort (vpoly.begin(), vpoly.end(), sortFunction);
	for(int i = vpoly.size() - 1; i >= 0; i--) {
		//screen->draw(&vpoly[i]);
		vpoly[i].beforeDraw();
		Polygon p = vpoly[i].convertToPolygon2D();
		
		p.getWidth(); //Jangan di hapus, ada masalah dengan MatrixDrawable
		p.getHeight();
		
		Point fillPoint(p.getWidth()/2,p.getHeight()/2);		
		Color black(120,120,120,254);
		Pixel fillPixel(fillPoint,black);
		MatrixDrawable md(&p);
		md.fillColor(fillPixel);
		Point p1 = p.getTopLeft();
		md.setPosition(p1.x,p1.y);
		screen->draw(&md);
	}
}
