#include "WorldManager.h"

int WorldManager::getWidth() const { return mWidth;}
int WorldManager::getHeight() const { return mHeight;}

WorldManager::WorldManager(){
		printf("konstruk worldmanager\n");
}
void WorldManager::setWidth(int _width){
	if (_width < MAX_WIDTH){
		mWidth = _width;
	} else {
		mWidth = MAX_WIDTH;
	}
}
void WorldManager::setHeight(int _height){
	if (_height < MAX_HEIGHT){
		mHeight = _height;
	} else {
		mHeight = MAX_HEIGHT;
	}
}

int WorldManager::getPolygonSize() const{
	return mPolygons.size();
}

void WorldManager::fillBuffer(){
	for(int i = 0; i < getPolygonSize(); i++){
		Polygon3D &p3d = mPolygons[i];
		Polygon p2d = p3d.convertToPolygon2D();
		vector<Pixel> pixels = p2d.getPixels();
	}
}

//TBD

vector<Pixel> WorldManager::getPixels() const{
	
	//create pixel based on buffer
	vector<Pixel> retval;
	for(int w = 0; w < getWidth(); ++w)
	for(int h = 0; h < getHeight(); ++h){
		Point p(w,h);
		Color c = mBuffer[w][h];
		Pixel pixel(p,c);
		retval.push_back(pixel);
	}
	return retval;
}

void WorldManager::readMap3D(const char* file_name){
	FILE* file = fopen (file_name, "r");
	vector<Line3D> edges;
	vector<Line3D>::iterator it;
	double array[6]; //simpan x1 y1 z1 x2 y2 z2
	int result;
	char *comment=NULL;
	const char* barrier="finish\n";
	size_t len=0;
	if(file!=NULL){
	  while (!feof (file))
		{  
		  for(int i=0;i<6;i++){//scan satu line 3D
			result=fscanf (file, "%lf", &array[i]);
			if (i==2){
				array[2] = 414 - array[2];
			}
			
			if (i==5){
				array[5] = 414 - array[5];
			}
			//printf("Result=%d",result);
			//printf("Array[%d]=%lf",i,array[i]);
		  }
		  if(result!=1){
			  getline(&comment,&len,file);
			  if(strcmp(comment,barrier)==0){//identik
				  //construct line jadi polygon
				  Polygon3D poly;
				  for(int it=0;it<edges.size();it++)
					poly.add(&edges[it]);
				  //push ke mPolygons
				  mPolygons.push_back(poly);
			  }
		  }  
		  else{
			  Line3D line(array[0],array[1],array[2],array[3],array[4],array[5]);
			  edges.push_back(line);
		  }
		}
	  fclose (file);
	}
	else printf("file not available\n");             	
}
