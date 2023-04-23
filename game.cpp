//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================
/*
Muhammad Ali Ahson
i21-2535
Section C

*/

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
# include <fstream>
#include<ctime>
#include<cstdlib>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 /////////////////////////////////////////
 char color;
 
 
 
 ///////////// Pixels our taxi moves/////////
 //Pixels are the axis which will be shifted in the game when you press any key//
int pixels = 10;
const int row = 77;
const int column = 95;

int xaxis=2; 
int yaxis=770; 
int arrayx = 0;
int arrayy = 0;
//Here , we declare the dynamic allocation memory to use in the fuction of the game....// 
int** indexarray = new int*[row];


//  We instialize all the coordinates with the zero to give them equal background after you make your car and intialize with 1 //

	void game_indexarray(){
	for(int q=0;q<row;q++){
	for(int z=0;z<column;z++){
	indexarray[q][z] = 0;
	}
	}
	}
////////////////////////////////
 ////////Score/////////////
 /*This is using to calculate the score of the game */
	 int score =0;
	 int Score=0;
	void gamescore(){
	string ss ="Score =" +to_string(Score);
	DrawString( 800, 750, ss, colors[RED]);
	glutPostRedisplay();
		}


///////////////////////////////////
/*This function will be use in calculating the time and to terminate it after 3:00 min 180 seconds*/  
int tiktok=0;
void pehlatimer(int m) {

tiktok++;
if(tiktok ==180){
exit(1);
}
glutTimerFunc(1000, pehlatimer, 0);


}


//////////////////////////
void SetCanvasSize(int width, int height) {
glMatrixMode (GL_PROJECTION);
glLoadIdentity();
glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
glMatrixMode (GL_MODELVIEW);
glLoadIdentity();
}


/////// Passengers///////////
/*here , I use different check value if they get true the other function will become true*/
	int checkpas=0;
	// use of the random function to generate the random number
	
	int ry=GetRandInRange(15,70);
	int cx=GetRandInRange(15,70);
	
	// function to make a passenger////
	void drawpassenger(){
	if((indexarray[ry][cx]==2)){
	ry=GetRandInRange(15,70);
	cx=GetRandInRange(15,70);
	
	}
	
	else if((indexarray[ry][cx]!=2)){
	indexarray[ry][cx]=3;
	if (checkpas==0){
	   
	DrawCircle((cx*10)+20, 780-(ry*10) ,5,colors[BLACK]);
	DrawLine( (cx*10)+20 , 780-(ry*10) ,  (cx*10)+20 , 780-(ry*10)-25, 3 , colors[BLACK] );
	DrawLine( (cx*10)+20 , 780-(ry*10)-25 ,  (cx*10)-8+20 , 780-(ry*10)-41 , 3 , colors[BLACK] );  
	DrawLine( (cx*10)+20 ,780- (ry*10)-25 ,  (cx*10)+8+20 , 780-(ry*10)-41 , 3 , colors[BLACK] );
	DrawLine( (cx*10)-13+20 , 780-(ry*10)-15 ,  (cx*10)+13+20 ,780- (ry*10)-15 , 3 , colors[BLACK] );
	}
	
	}
	
		glutPostRedisplay();
	}
// function to make a passenger////
	int checkpas1=0;
	int headx=GetRandInRange(12,70);
	int heady=GetRandInRange(12,90);
	void drawpassenger1(){
	if((indexarray[headx][heady]!=2) and (indexarray[headx][heady]!=3)){
	indexarray[headx][heady]=4;
	if (checkpas1==0){
	   
	DrawCircle((heady*10)+20, 770-(headx*10) ,5,colors[BLACK]);
	DrawLine( (heady*10)+20 , 770-(headx*10) ,  (heady*10)+20 , 770-(headx*10)-25, 3 , colors[BLACK] );
	DrawLine( (heady*10)+20 , 770-(headx*10)-25 ,  (heady*10)-8+20 , 770-(headx*10)-41 , 3 , colors[BLACK] );  
	DrawLine( (heady*10)+20 , 770-(headx*10)-25 ,  (heady*10)+8+20 , 770-(headx*10)-41 , 3 , colors[BLACK] );
	DrawLine( (heady*10)-13+20 , 770-(headx*10)-15 ,  (heady*10)+13+20 , 770-(headx*10)-15 , 3 , colors[BLACK] );
	}
	
	else{
	}
	}
	else{ 
	headx=GetRandInRange(12,70);
	heady=GetRandInRange(12,90);
	
	}
		glutPostRedisplay();

  	}
// function to make a passenger////
	int checkpas2=0;

	int headx1=GetRandInRange(10,60);
	int heady1=GetRandInRange(10,80);
	void drawpassenger2(){
	if((indexarray[headx1][heady1]!=2)){
	indexarray[headx1][heady1]=5;
	if (checkpas2==0){
	   
	DrawCircle( (heady1*10)+19, 780-(headx1*10) ,5,colors[BLACK]);
	DrawLine( (heady1*10)+20 , 780-(headx1*10) ,  (heady1*10)+20 , 780-(headx1*10)-25, 3 , colors[BLACK] );
	DrawLine( (heady1*10)+20 ,780- (headx1*10)-25 ,  (heady1*10)-8+20 , 780-(headx1*10)-41 , 3 , colors[BLACK] );  
	DrawLine( (heady1*10)+20 , 780-(headx1*10)-25 ,  (heady1*10)+8+20 ,780-(headx1*10)-41 , 3 , colors[BLACK] );
	DrawLine( (heady1*10)-13+20 , 780-(headx1*10)-15 ,  (heady1*10)+13+20 , 780-(headx1*10)-15 , 3 , colors[BLACK] );
	}
	
	else{
	}
	}
	else{ 
	headx1=GetRandInRange(2,70);
	heady1=GetRandInRange(2,90);
	
	}
		glutPostRedisplay();
	}
// Passengers//////////



//////////////////////////////



/////Destinations///////////////

// these are the functions which will be use to generate the random destrination when you pick the passenger
// for this I use the check conditions to get true...
// three different values ... Six different axes
	int ygp=GetRandInRange(12,60);
	int xgp=GetRandInRange(12,70);
	int agp=GetRandInRange(12,60);
	int bgp=GetRandInRange(12,70);
	int cgp=GetRandInRange(12,60);
	int dgp=GetRandInRange(12,70);
	int genpoint=0;
	//  Function to generate the random desrtination for the passenger//
	
	void genp()
	{
	cout<<genpoint;
	
	if(genpoint==1)
	{
		cout<<"my name is ali"<<endl;
		indexarray[ygp][xgp]=6;
		DrawCircle((xgp*10)+20,780-(ygp*10),5,colors[GREEN]);
		score +=10;
		
	}
	
	glutPostRedisplay();
	}
	//  Function to generate the random desrtination for the passenger//
	void genp1(){	
	
	if(genpoint==3)
	{
		cout<<"my name is ali"<<endl;
		indexarray[ygp][xgp]=6;
		DrawCircle((agp*10)+20,780-(bgp*10),5,colors[GREEN]);
		score +=10;
	
	DrawCircle((agp*10),780-(bgp*10),5,colors[GREEN]);
	}
	
	
	
	glutPostRedisplay();
	}
	//  Function to generate the random desrtination for the passenger//
	void genp2(){
	if((indexarray[dgp][cgp]!=2) and (indexarray[dgp][cgp]!=3) and (indexarray[dgp][cgp]!=4) and (indexarray[dgp][cgp]!=5)){

	if(genpoint==5){
	score +=10;
	genpoint++;
	
	indexarray[dgp][cgp]=8;	
	}
	else{
	
	}}
	
	glutPostRedisplay();
}

/////Destination//////////



/////////////////////////////////////


/////////Buildings////////////
// Here I use the for Loops to make my buildings and to fill the 2D dynamic memory allocations so that 
// It will hinders the car....
/*

This is helpful in the making random values



int blockx=GetRandInRange(12,67);
int blocky=GetRandInRange(12,80);
int block1x=GetRandInRange(12,65);
int block1y=GetRandInRange(12,79);
void blocks(){
	  for(int i=blockx;i<=blockx+2;i++){
	  for(int j=blocky;j<=blocky+10;j++){
	  indexarray[i][j]=2;
	  }
	  }
	for(int i=block1x;i<=block1x+7;i++){
	  for(int j=block1y;j<=block1y+4;j++){
	  indexarray[i][j]=2;
	  }
	  }
}







*/
	void blocks(){
	  for(int i=8;i<=11;i++){
	  for(int j=4;j<=13;j++){
	  indexarray[i][j]=2;
	  }
	  }
	for(int i=11;i<=17;i++){
	  for(int j=4;j<=7;j++){
	  indexarray[i][j]=2;
	  }
	  }

	for(int i=8;i<=11;i++){
	  for(int j=25;j<=35;j++){
	  indexarray[i][j]=2;
	  }
	  }


	for(int i=11;i<=17;i++){
	  for(int j=35;j>=31;j--){
	  indexarray[i][j]=2;
	  }
	  }


	for(int i=25;i<=27;i++){
	  for(int j=4;j<=35;j++){
	  indexarray[i][j]=2;
	  }
	  }


	for(int i=33;i<=36;i++){
	  for(int j=45;j<=55;j++){
	  indexarray[i][j]=2;
	  }
	  }

	for(int i=40;i<=42;i++){
	  for(int j=4;j<=30;j++){
	  indexarray[i][j]=2;
	  }
	  }

	for(int i=42;i<=50;i++){
	  for(int j=4;j<=7;j++){
	  indexarray[i][j]=2;
	  }
	  }

	for(int i=42;i<=50;i++){
	  for(int j=30;j>=27;j--){
	  indexarray[i][j]=2;
	  }
	  }

	for(int i=58;i<=70;i++){
	  for(int j=15;j<=21;j++){
	  indexarray[i][j]=2;
	  }
	  }
	  
	for(int i=70;i<=73;i++){
	  for(int j=15;j<=35;j++){
	  indexarray[i][j]=2;
	  }
	  }
// Loop to make the Triangle like Diamond in the gameplay
	for(int i=20,u=58;i<=38;i++,u++){
	  for(int j=70;j>=u;j--){
	  indexarray[i][j]=2;
	  }
	  cout<<endl;
	  }
	for(int i=20,u=82;i<=38;i++,u--){
	  for(int j=70;j<=u;j++){
	  indexarray[i][j]=2;
	  }
	  cout<<endl;
	  }

	for(int i=8,u=70;i<=20;i++,u--){
	  for(int j=70;j>=u;j--){
	  indexarray[i][j]=2;
	  }
	  cout<<endl;
	  }
	for(int i=8,u=70;i<=20;i++,u++){
	  for(int j=70;j<=u;j++){
	  indexarray[i][j]=2;
	  }
	  cout<<endl;
	  }

	for(int i=42;i<=52;i++){
	  for(int j=65;j<=70;j++){
	  indexarray[i][j]=2;
	  }
	  }
	  for(int i=47;i<=50;i++){
	  for(int j=80;j<=89;j++){
	  indexarray[i][j]=2;
	  }
	  }

	for(int i=62;i<=72;i++){
	  for(int j=65;j<=70;j++){
	  indexarray[i][j]=2;
	  }
	  }
	for(int i=70;i<=72;i++){
	  for(int j=65;j<=85;j++){
	  indexarray[i][j]=2;
	  }
	  }
	for(int i=62;i<=72;i++){
	  for(int j=80;j<=85;j++){
	  indexarray[i][j]=2;
	  }
	  }
	}
/////////////Buildings//////////
//////////////////////////////
////////Tree////
int treey=GetRandInRange(12,67);
int treex=GetRandInRange(12,69);
int tree1x=GetRandInRange(12,65);
int tree1y=GetRandInRange(12,70);
	void tree(){
	if( indexarray[treey][treex] ==2){
	treey=GetRandInRange(12,67);
	treex=GetRandInRange(12,69);
	for(int i =treey,u=0;u<2;u++,i++){
	for(int j=treex,h=0;h<2;h++,j++){
	indexarray[i][j]=2;
	}
	}

	for(int i=treey-4,q=0,u=treex;q<4;q++,i++,u++){
	  for(int j=treex;j<=u;j++){
	  indexarray[i][j]=2;
	  }
	  cout<<endl;
	  }
	  

	for(int i=treey-4,u=treex,q=0;q<4;q++,i++,u--){
	  for(int j=treex;j>=u;j--){
	  indexarray[i][j]=2;
	  }
	  cout<<endl;
	  }
	  }
	  else{
	  treey=GetRandInRange(12,67);
	treex=GetRandInRange(12,69);
	for(int i =treey,u=0;u<2;u++,i++){
	for(int j=treex,h=0;h<2;h++,j++){
	indexarray[i][j]=2;
	}
	}

	for(int i=treey-4,q=0,u=treex;q<4;q++,i++,u++){
	  for(int j=treex;j<=u;j++){
	  indexarray[i][j]=2;
	  }
	  cout<<endl;
	  }
	  

	for(int i=treey-4,u=treex,q=0;q<4;q++,i++,u--){
	  for(int j=treex;j>=u;j--){
	  indexarray[i][j]=2;
	  }
	  cout<<endl;
	  }
	  }
	  /////////////////////
	  if(indexarray[tree1y][tree1x]==2){
	  tree1x=GetRandInRange(12,65);
	  tree1y=GetRandInRange(12,70);
	  for (int i=tree1y,u=0; u<2  ;u++, i++){
	  for (int j=tree1x,h=0 ; h<2  ;h++, j++){
	  indexarray[i][j]=2;
	  
	  }}
	  for(int i=tree1y-4,q=0,u=tree1x;q<4;q++,i++,u++){
	  for(int j=tree1x;j<=u;j++){
	  indexarray[i][j]=2;
	  }
	  cout<<endl;
	  }
	  

	for(int i=tree1y-4,u=tree1x,q=0;q<4;q++,i++,u--){
	  for(int j=tree1x;j>=u;j--){
	  indexarray[i][j]=2;
	  }
	  cout<<endl;
	  }
	}
	else{
	
	}
	}
///////////////////////////////////blocks///////
//////////////////////
	int obsticley=GetRandInRange(12,60);
	int obsticlex=GetRandInRange(12,70);
	void obsticles(){

	for(int i=obsticlex,u=0;u<=2;i++,u++){
	for(int j=obsticley,h=0;h<=2;j++,h++){
	 indexarray[i][j]=2;

	}
	}

	DrawRectangle( (obsticley*10)+10   ,760- (obsticlex*10) ,  25 , 22, colors[BROWN] );
	}
	int obsticle1y=GetRandInRange(10,60);
	int obsticle1x=GetRandInRange(11,70);
	void obsticles1(){

	for(int i=obsticle1x,u=0;u<=2;i++,u++){
	for(int j=obsticle1y,h=0;h<=2;j++,h++){
	 indexarray[i][j]=2;

	}
	}

	DrawRectangle( (obsticle1y*10)+10   ,760- (obsticle1x*10) ,  25 , 22, colors[BROWN] );
	}
	int obsticle2y=GetRandInRange(9,60);
	int obsticle2x=GetRandInRange(13,70);


	void obsticles2(){

	for(int i=obsticle2x,u=0;u<=2;i++,u++){
	for(int j=obsticle2y,h=0;h<=2;j++,h++){
	 indexarray[i][j]=2;

	}
	}
	
	DrawRectangle( (obsticle2y*10)+10   ,760- (obsticle2x*10) ,  25 , 22, colors[BROWN] );
	}

	int obsticle3y=GetRandInRange(9,65);
	int obsticle3x=GetRandInRange(13,72);


	void obsticles3(){

	for(int i=obsticle3x,u=0;u<=2;i++,u++){
	for(int j=obsticle3y,h=0;h<=2;j++,h++){
	 indexarray[i][j]=2;

	}
	}
	
	
	DrawRectangle( (obsticle3y*10)+10   ,760- (obsticle3x*10) ,  25 , 22, colors[BROWN] );
	}


	//////////////////////////////
	//////Draw cars
	void drawCar() {
	if(color=='y'){
	DrawSquare(xaxis, yaxis, 20, colors[OLIVE]);
	glutPostRedisplay();
	}}
	void drawCar1() {
	if(color=='r'){
	DrawSquare(xaxis, yaxis, 20, colors[RED]);
	glutPostRedisplay();
	}}
	int secondcarx=20;
	int secondcary=550;
	void movingCar1() {
	DrawSquare(secondcarx,secondcary, 20, colors[RED]);
	glutPostRedisplay();
	}
	int thirdcarx=430;
	int thirdcary=610;
void movingCar2() {
if(checkpas2==1){
	DrawSquare(thirdcarx,thirdcary, 20, colors[RED]);
	}glutPostRedisplay();}

//it is a function to move the car in auto mode.
bool flag = true;
void moveCar() {
	
	/*if (secondcarx > 20 && flag) {
		secondcarx -= 5;
		//cout << "going left";
		if (secondcarx < 100)
			
			flag = false;

	}
	else if (secondcarx < 950 && !flag) {
		//cout << "go right";
		secondcary += 5;
		if (secondcarx > 500)
			flag = true;
	//}

}*/
{if (thirdcary > 10 && flag) {


		thirdcary -= 10;
		
		if(thirdcary < 200)
			
			flag = false;

	}
	else if (thirdcary < 700 && !flag) {
		
		thirdcary += 10;
		if (thirdcary > 670){
			
			flag = true;

}}
else if (thirdcary==220 && flag){

thirdcarx +=10;

if (thirdcarx <200)
flag = false;

}
else if (secondcarx <200 && !flag){
secondcarx -=10;
flag =true;

}
}















  {if (secondcary > 10 && flag) {


		secondcary -= 10;
		
		if(secondcary < 200)
			
			flag = false;

	}
	else if (secondcary < 700 && !flag) {
		
		secondcary += 10;
		if (secondcary > 670){
			
			flag = true;

}}
else if (secondcary==220 && flag){

secondcarx +=10;

if (secondcarx <200)
flag = false;

}
else if (secondcarx <200 && !flag){
secondcarx -=10;
flag =true;

}}}


////////////////////////////////
void menu(){
glClearColor(255/*Red Component*/, 255, //148.0/255/*Green Component*/,
255/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
glClear (GL_COLOR_BUFFER_BIT); //Update the colors
DrawRoundRect(400,500,350,50,colors[BLACK],0);
DrawRoundRect(400,400,350,50,colors[BLACK],0);
DrawRoundRect(400,300,350,50,colors[BLACK],0);
DrawRoundRect(400,600,350,50,colors[BLACK],0);
DrawString( 430, 620, "Start Game with Red Color ", colors[WHITE]);
DrawString( 430, 520, "Start Game with Yellow Color ", colors[WHITE]);
DrawString( 430, 420, "Leader Board", colors[WHITE]);
DrawString( 430, 320, "Exit Game", colors[RED]);
DrawString( 40, 700, "Enter Name ; ", colors[RED]);
glutSwapBuffers();
}
















//////////////////////////




void Displayindex(){
cout<<endl;
for(int i=0;i<row;i++){
for(int j =0;j<column;j++){
cout<<indexarray[i][j];
}
cout<<endl;
}
}

/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
//set the background color using function glClearColor.
//to change the background play with the red, green and blue values below.
//Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

glClearColor(255/*Red Component*/, 255, //148.0/255/*Green Component*/,
255/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
glClear (GL_COLOR_BUFFER_BIT); //Update the colors


 

 

//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)

	   ////////////////////////////////////////// LINES
		DrawLine( 1 , 30 , 1 , 720 , 5 , colors[BLACK] );
		DrawLine( 50 , 30 , 50 , 720 ,5 , colors[BLACK] );
		DrawLine( 150 , 30 , 150 , 720 ,5 , colors[BLACK] );
	        DrawLine( 250 , 30 , 250 , 720 ,5 , colors[BLACK] );
	        DrawLine( 350 , 30 , 350 , 720 ,5 , colors[BLACK] );
	        DrawLine( 450 , 30 , 450 , 720 ,5 , colors[BLACK] );
	        DrawLine( 550 , 30 , 550 , 720 ,5 , colors[BLACK] );
	        DrawLine( 650 , 30 , 650 , 720 ,5 , colors[BLACK] );
	        DrawLine( 750 , 30 , 750 , 720 ,5 , colors[BLACK] );
	        DrawLine( 850 , 30 , 850 , 720 ,5 , colors[BLACK] );
	        DrawLine( 950 , 30 , 950 , 720 ,5 , colors[BLACK] );
		  
	////////////////////////////
	/////////////// Buildings/////
	  DrawLine( 0 , 30 , 970 , 30 ,5 , colors[BLACK] );
	  DrawLine( 0 , 720 , 970 , 720 ,5 , colors[BLACK] );

	DrawRoundRect(32+20,670,112-20,30,colors[BLACK],0);
	DrawRoundRect(52,610,30,70,colors[BLACK],0);
	/////
	DrawRoundRect(262,670,100,30,colors[BLACK],0);
	DrawRoundRect(322,610,40,70,colors[BLACK],0);
	/////
	DrawRoundRect(52,510,310,20,colors[BLACK],0);

	/////
	DrawRoundRect(52,360,260,20,colors[BLACK],0);
	DrawRoundRect(52,280,30,100,colors[BLACK],0);
	DrawRoundRect(282,280,30,100,colors[BLACK],0);
	/////
	DrawRoundRect(162,50,60,150,colors[BLACK],0);
	DrawRoundRect(215,50,147,30,colors[BLACK],0);
	///////////////////////
	DrawTriangle( 592, 580 , 712, 695 , 832 , 580, colors[BLACK] );
	DrawTriangle( 592, 580 , 712, 465 , 832 , 580, colors[BLACK] );
	////////////////
	DrawRoundRect(662,260,50,100,colors[BLACK],0);
	/////////////
	DrawRoundRect(812,280,92,30,colors[BLACK],0);
	///////////////////////
	DrawRoundRect(662,60,50,100,colors[BLACK],0);
	DrawRoundRect(702,60,150,20,colors[BLACK],0);
	DrawRoundRect(812,60,50,100,colors[BLACK],0);
	//////////
	DrawRoundRect(462,420,100,30,colors[BLACK],0);
	//////////////////////////////////////////////////////////////////////////
	drawpassenger();
	drawpassenger1();
	drawpassenger2();

/////////////////////
   string pehla ="Time =" +to_string(tiktok);
   DrawString( 100, 750, pehla, colors[BLACK]);











	////////////////////////////////////////////////////////////////////////////
	drawCar();
	drawCar1(); 
	movingCar1();
	movingCar2();
	gamescore();
	///////////////////////////////
	/////Green Lights//////////
	genp();
	genp1();
	genp2();
	/////////Green Lights////////
	/////////////////////////////
	////tree///
	DrawRectangle( (treex*10) +10  , 770-(treey*10 ),  15 , 20 , colors[BROWN] );
	DrawTriangle( treex*10-20, 780-(treey*10)+10 , (treex*10)+10, (780-(treey*10))+40 , (treex*10)+40 , 780-(treey*10)+10, colors[GREEN] );
	//down wala tree
	DrawRectangle( (tree1x*10) +10  , 770-(tree1y*10 ),  15 , 20 , colors[BROWN] );
	DrawTriangle( tree1x*10-20, 780-(tree1y*10)+10 , (tree1x*10)+10, (780-(tree1y*10))+40 , (tree1x*10)+40 , 780-(tree1y*10)+10, colors[GREEN] );
	//////////
	obsticles();
	obsticles1();
	obsticles2();
	obsticles3();
	//movingCar1();
	//drawCar2();
	glutSwapBuffers(); // do not modify this line..

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {



	if (key
	== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
	// what to do when left key is pressed...
	cout<<"left x " << xaxis+20<<endl;

	if((indexarray[arrayx][arrayy-1]!=2) ){
	if((xaxis!=2)){
	xaxis -= (pixels);
	indexarray[arrayx][arrayy] = 0;
	arrayy-=1;
	indexarray[arrayx][arrayy] = 1;

	}
	}


	} else if (key
	== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	cout<<"right x " << xaxis+20<<endl;

	if((indexarray[arrayx][arrayy+1]!=2) ){
	if(indexarray[arrayx][arrayy]!=9){
	if(xaxis <= 940){
	xaxis += (pixels);
	indexarray[arrayx][arrayy] = 0;
	arrayy+=1;
	indexarray[arrayx][arrayy] = 1;
	}
	}
	}
	} else if (key
	== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {


	cout<<"down value is " <<yaxis+20<<endl;

	if((indexarray[arrayx-1][arrayy]!=2)){
	if (yaxis<700){
	yaxis+=(pixels);

	if (arrayx>=1){
	indexarray[arrayx][arrayy] = 0;
	arrayx-=1;
	indexarray[arrayx][arrayy] = 1;
	}
	}
	}
	}
	else if (key
	== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {


	cout<<"down value is " <<yaxis+20<<endl;

	if((indexarray[arrayx+1][arrayy]!=2) ){
	if (yaxis>30){
	yaxis-= (pixels);
	if (arrayx<row-1){
	indexarray[arrayx][arrayy] = 0;
	arrayx+=1;
	indexarray[arrayx][arrayy] = 1;
	}
	}
	//cout<<endl<<"row="<<row<<" CAR="<<arrayx<<endl;
	}

	}
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	* this function*/
	Displayindex();

	glutPostRedisplay();

	}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
	exit(1); // e0t the program when escape key is pressed.
	}

	if (key == ' ' || key == 32) //Key for placing the bomb
	{
	//cout<<"hEADX    "<<headx<<endl;
	//cout<<"hEADy    "<<heady<<endl;
	//cout<<"headx1   "<<headx1<<endl;
	//cout<<"heady1   "<<heady1<<endl;
	/*cout<<"headx2   "<<headx2<<endl;
	cout<<"heady2   "<<heady2<<endl;

	*/
	cout<<" 3rd green points "<<cgp<<endl;
	cout<<"3rd green point "<<dgp<<endl;
	//do something if b is pressed
	//cout << "b pressed" << endl;
	/////////////////Green Destinations///////////
	
	
	if((indexarray[arrayx-1][arrayy]==6) or (indexarray[arrayx+1][arrayy]==6) or (indexarray[arrayx][arrayy-1]==6) or (indexarray[arrayx][arrayy+1]==6)){
	genpoint++;
	}
	if((indexarray[arrayx-1][arrayy]==7) or (indexarray[arrayx+1][arrayy]==7) or (indexarray[arrayx][arrayy-1]==7) or (indexarray[arrayx][arrayy+1]==7)){
	genpoint++;
	}
	if((indexarray[arrayx-1][arrayy]==8) or (indexarray[arrayx+1][arrayy]==8) or (indexarray[arrayx][arrayy-1]==8) or (indexarray[arrayx][arrayy+1]==8)){
	genpoint++;
	}

///////////////Passengers///////////////////////////////////


	if((indexarray[arrayx-1][arrayy]==3) or (indexarray[arrayx-1][arrayy]==3) or (indexarray[arrayx][arrayy-1]==3) or (indexarray[arrayx][arrayy+1]==3)){
	checkpas++;
	genpoint++;
	Score+=10;
cout<<"1 wali "<<genpoint<<endl;
	}

	if((indexarray[arrayx-1][arrayy]==4) or (indexarray[arrayx+1][arrayy]==4) or (indexarray[arrayx][arrayy-1]==4) or (indexarray[arrayx][arrayy+1]==4)){
	checkpas1++;
	genpoint++;
		Score+=10;
cout<<"2 wali "<<genpoint<<endl;
	}
	if((indexarray[arrayx-1][arrayy]==5) or (indexarray[arrayx+1][arrayy]==5) or (indexarray[arrayx][arrayy-1]==5) or (indexarray[arrayx][arrayy+1]==5)){
	checkpas2++;
	genpoint++;
		Score+=10;
cout<<"3 wali "<<genpoint<<endl;
	}
	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

// implement your functionality here
moveCar();

// once again we tell the library to call our Timer function after next 1000/FPS
glutTimerFunc(100, Timer, 0);
}
void MouseClicked(int button, int state, int x, int y) {

if (button == GLUT_LEFT_BUTTON) // dealing only with left button
{
glutTimerFunc(1000.0, pehlatimer, 0);
cout << GLUT_DOWN << " " << GLUT_UP << endl;

} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
{
cout<<"Right Button Pressed"<<endl;

}
glutPostRedisplay();
}
/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */

void MouseMoved(int x, int y) {
cout << x << " " << y << endl;
glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */

//////////////////////
void Scoreboard(){
glClearColor(255/*Red Component*/, 255, //148.0/255/*Green Component*/,
255/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
glClear (GL_COLOR_BUFFER_BIT); //Update the colors
 string text[10]={"100"};
    	DrawString( 80, 600, "hi tu", colors[RED]);
    

   ifstream of("Score.txt");
    
   
    string sc;
    int i=0;
    
    while(of>>sc)
    {
        //cout<<2<<sc;
        text[i]=sc;
        i++;
    }

    for(int i=0; i<10;i++)
    {
        	DrawString( 400, 600, text[i], colors[RED]);
        	cout<<endl;
    }
    
glutSwapBuffers();
}




///////////////

void MousePressedAndMoved(int x, int y) {
if((x>=400 and x<=550) and (y>=160 and y<=180)){
//cout<<"g ........."<<endl;
glutDisplayFunc(GameDisplay);
glutMouseFunc(MouseClicked);
color='r';
}


if((x>=400 and x<=550) and (y>=260 and y<=280)){
cout << x << " " << y << endl;
color='y';
glutDisplayFunc(GameDisplay);
glutMouseFunc(MouseClicked);
}
if((x>=400 and x<=550) and (y>=340 and y<=380)){

glutDisplayFunc(Scoreboard);
glutMouseFunc(MouseClicked);
}
if((x>=400 and x<=550) and (y>=440 and y<=490)){
exit(1);
}
glutPostRedisplay();

}
/*
 * our gateway main function
 * */
 
 
 
 
 /////////////////////////////////Main ////////////////////////
int main(int argc, char*argv[]) {
// cout<<"please enter the color of the car"<<endl;
// cin>>global;

int width = 970;
int height = 790; // i have set my window size to be 800 x 600


game_indexarray();
indexarray[arrayx][arrayy] = 1;
////////////////////////// Buildings 
blocks();

/////////////////////////
///////Trees
tree();


///////////



for(int i=0;i<row;i++){
indexarray[i] = new int[column];
}




///////////////////////
InitRandomizer(); // seed the random number generator...
glutInit(&argc, argv); // initialize the graphics library...
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
glutInitWindowPosition(50, 50); // set the initial position of our window
glutInitWindowSize(width, height); // set the size of our window
glutCreateWindow("Rush Hour by Muhammad Ali Ahson"); // set the title of our game window
SetCanvasSize(width, height); // set the number of pixels...

// Register your functions to the library,
// you are telling the library names of function to call for different tasks.
//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

glutDisplayFunc(menu); // tell library which function to call for drawing Canvas.
glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
glutTimerFunc(1000.0, Timer, 0);
//glutTimerFunc(1000.0, pehlatimer, 0);
// glutMouseFunc(MouseClicked);
glutPassiveMotionFunc(MouseMoved); // Mouse
glutMotionFunc(MousePressedAndMoved); // Mouse

// now handle the control to library and it will call our registered functions when
// it deems necessary...
glutMainLoop();
return 1;
}
#endif /* RushHour_CPP_ */b
