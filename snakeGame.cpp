#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<cmaths>
using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x,y, fruitx,fruity,score;// x is the head of the snake, y is the tail of the snake
enum eDirection {
	STOP=0,LEFT,RIGHT,UP,DOWN 
	};
	int tailx[100],taily[100];
	int len;
eDirection dir;
void setup(){
	gameOver= false;
	dir = STOP;
	x=width/2;
	y=width/2;
	
	score=0;
}
void draw(){
	//draw map;
	system("cls");
	for(int i=0;i<width;i++){
		cout<<"#";
	}
	cout<< endl;
	for(int i=0;i<height;i++){
		
		for(int j=0;j<width;j++){
			
			if(j==0 || j==width-1) cout<<"#";
			
			else if( i== x && j==y ){
				cout<<0;
			}
			else if(i==fruitx || j==fruity){
				cout << "F";
			}
			else {
					bool print= false; 
				for(int k=0; k<len;k++){
					
				if(tailx[k]==j && taily[k]==i){
						cout<<"o";
						print =true;
					}
					
				}
				
				
			if(!print) cout<< " "; 
		}
		}
	}
	for(int i=0;i<width;i++){
		cout<<"#";
	}
	cout<< endl;
	cout<< "SCORE: "<< score<< endl;
}
void input(){
	if(_kbhit()){
		switch(_getch()){
			case'a': dir=LEFT;
			break;
			case 's': dir=DOWN;
			break;
			case 'd': dir=RIGHT;
			break;
			case 'w': dir=UP;
			break;
			case 'x': gameOver=true;
			break;
			
			
		}
	}
}
void logic(){
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x, prev2y;
	for(int i=1; i<len; i++){
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=pev2x;
		prevy=prev2y;
		tailx[0]=x;
		taily[0]=y;
	}
	switch(dir){
		case LEFT: x--;  
			break;
		case RIGHT: x++;
			break;
		case UP: y++;
			break;
		case DOWN: y--;
			break;	
			default:
			break;	
	}
	/*if(x>width || x<0 || y>height || y<0){
		gameOver=true;
		*/ 
	if(x>width) x=0;else if(x<0) x=width-1;
	if(y>height) y=0;else if(y<0) y=height-1;
	for(int i=0;i<len;i++){
		if(tailx[i]=x;taily[i]=y)
		gameOver=true;
	}
	if(x==fruitx && y==fruity){
		score=score+10;
		fruitx=rand() % width;
	    fruity=rand() % height;
	    len++;
	}
}
int main(){
	setup();
	while(!gameOver){
		draw();
		input();
		logic();
		Sleep(10);
		
		//Sleep(10);
	}
	return 0;
}
