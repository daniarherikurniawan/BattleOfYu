#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

class Story{
	private:
		int current;
		float progress;
		string story;	
		string selectStory(int type);	

	public:
		void printStory();
		bool isDone;
		Story(int type);
		void next();
		void gotoxy(int x,int y);
		
		string nama;
};
