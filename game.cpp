//============================================================================
// Name        : Muti Ur Rehman
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<fstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

//Variables for moving mars nitial positions
int xI = 400, yI = 383;			//CAR 1
int x2 = 50, y2 = 690;			//OWN CAR
int x3 = 946, y3 = 383;			//CAR 2
int x4 = 495, y4 = 680;			//CAR 3
int x5 = 495, y5 = 275;			//CAR 4

//Variable for displaying time on game screen
int ti=0;

//Variable used as counter to display cars after 2 dropoffs
int tii=0;
//int tiii=0;


// BOOL Variable for leaderboard
bool lede=true;

//BOOL Variable for passengers and their drop off locations
bool p1=true;
bool l1=false;

bool p2=true;
bool l2=false;

bool p3=true;
bool l3=false;

bool p4=true;
bool l4=false;

bool p5=true;
bool l5=false;

bool p6=true;
bool l6=false;

bool p7=true;
bool l7=false;

bool p8=true;
bool l8=false;


//BOOL Variables for Screens
bool men1=true;
bool gs=false;
bool lb=false;
bool red=false;
bool cs=false;
bool yellow=false;



//BOOL Variables for Collision System and Scoring System
bool c1=true;
bool c2=true;
bool c3=true;
bool c4=true;

bool t1=true;
bool t2=true;
bool t3=true;
bool t4=true;
bool t5=true;

bool pp1=true;
bool pp2=true;
bool pp3=true;
bool pp4=true;
bool pp5=true;
bool pp6=true;
bool pp7=true;
bool pp8=true;

//Variable for score
int scoregame=0;

//Funtion for Displaying car 1
void drawCar() {
	DrawSquare(xI, yI, 40, colors[DARK_RED]);
	glutPostRedisplay();
}

//Funtion for Displaying OWN car
void drawCar1() 
{
	if(yellow == true)
	{
	DrawSquare(x2, y2, 40, colors[YELLOW]);
	glutPostRedisplay();
	}
	if(red  == true)
	{
	DrawSquare(x2, y2, 40, colors[RED]);
	glutPostRedisplay();
	}
}

//Funtion for Displaying car 2
void drawCar2() {
	DrawSquare(x3, y3, 40, colors[DARK_RED]);
	glutPostRedisplay();
}

//Funtion for Displaying car 3
void drawCar3() {
	DrawSquare(x4, y4, 40, colors[DARK_RED]);
	glutPostRedisplay();
}

//Funtion for Displaying car 4
void drawCar4() {
	DrawSquare(x5, y5, 40, colors[DARK_RED]);
	glutPostRedisplay();
}

//Function for movement of Car 1
bool flag = true;
void moveCar() {
	
	if (xI > 55 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 55)
			
			flag = false;

	}
	else if (xI < 400 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 385)
			flag = true;
	}
}


//Function for movement of Car 2
bool flag1 = true;
void moveCar1() {
	
	if (x3 > 620 && flag1) {
		x3 -= 10;
		cout << "going left";
		if(x3 < 620)
			
			flag1 = false;

	}
	else if (x3 < 945 && !flag1) {
		cout << "go right";
		x3 += 10;
		if (x3 > 930)
			flag1 = true;
	}
}


//Function for movement of Car 3
bool flag2 = true;
void moveCar2() {
	
	if (y4 > 500 && flag2) {
		y4 -= 10;
		cout << "going down";
		if(y4 < 510)
			
			flag2 = false;

	}
	else if (y4 < 695 && !flag2) {
		cout << "go up";
		y4 += 10;
		if (y4 > 680)
			flag2 = true;
	}
}


//Function for movement of Car 4
bool flag3 = true;
void moveCar3() {
	
	if (y5 > 40 && flag3) {
		y5 -= 10;
		cout << "going down";
		if(y5 < 50)
			
			flag3 = false;

	}
	else if (y5 < 275 && !flag3) {
		cout << "go up";
		y5 += 10;
		if (y5 > 260)
			flag3 = true;
	}
}

/*
 * Main Canvas drawing function.
 * */
 
 
 //Functions for displaying Passengers
 //Function for passenger 8
 void person8()
 {
 	if (p8== true)
 	{
 	DrawCircle(470,200,5,colors[RED]);
	DrawLine( 470 , 195 ,  470 , 180 , 4 , colors[BROWN] );
	DrawLine( 470 , 181 ,  465 , 165 , 2 , colors[BROWN] );
	DrawLine( 470 , 181 ,  475 , 165 , 2 , colors[BROWN] );
	DrawLine( 470 , 200 ,  465 , 185 , 2 , colors[BROWN] );
	DrawLine( 470 , 200 ,  475 , 185 , 2 , colors[BROWN] );
 	}
 }
 
 
 //Function for passenger 7
 void person7()
 {
 	if (p7==true)
 	{
 	DrawCircle(800,70,5,colors[RED]);
	DrawLine( 800 , 65 ,  800 , 50 , 4 , colors[BROWN] );
	DrawLine( 800 , 51 ,  795 , 35 , 2 , colors[BROWN] );
	DrawLine( 800 , 51 ,  805 , 35 , 2 , colors[BROWN] );
	DrawLine( 800 , 70 ,  795 , 55 , 2 , colors[BROWN] );
	DrawLine( 800 , 70 ,  805 , 55 , 2 , colors[BROWN] );
	}
 }
 
 
  //Function for passenger 6
 void person6()
 {

 	if(p6==true)
 	{
 	DrawCircle(100,70,5,colors[RED]);
	DrawLine( 100 , 65 ,  100 , 50 , 4 , colors[BROWN] );
	DrawLine( 100 , 51 ,  95 , 35 , 2 , colors[BROWN] );
	DrawLine( 100 , 51 ,  105 , 35 , 2 , colors[BROWN] );
	DrawLine( 100 , 70 ,  95 , 55 , 2 , colors[BROWN] );
	DrawLine( 100 , 70 ,  105 , 55 , 2 , colors[BROWN] );
	}
 }
 
 
  //Function for passenger 5
 void person5()
 {
 if(p5==true)
 {
 	DrawCircle(200,655,5,colors[RED]);
	DrawLine( 200 , 650 ,  200 , 635 , 4 , colors[BROWN] );
	DrawLine( 200 , 636 ,  195 , 620 , 2 , colors[BROWN] );
	DrawLine( 200 , 636 ,  205 , 620 , 2 , colors[BROWN] );
	DrawLine( 200 , 650 ,  195 , 640 , 2 , colors[BROWN] );
	DrawLine( 200 , 650 ,  205 , 640 , 2 , colors[BROWN] );
	}
 }
 
 
  //Function for passenger 1
 void person1()
 {
 	if(p1==true)
 	{
 	DrawCircle(800,655,5,colors[RED]);
	DrawLine( 800 , 650 ,  800 , 635 , 4 , colors[BROWN] );
	DrawLine( 800 , 636 ,  795 , 620 , 2 , colors[BROWN] );
	DrawLine( 800 , 636 ,  805 , 620 , 2 , colors[BROWN] );
	DrawLine( 800 , 650 ,  795 , 640 , 2 , colors[BROWN] );
	DrawLine( 800 , 650 ,  805 , 640 , 2 , colors[BROWN] );
	}
 }
 
 
  //Function for passenger 2
 void person2()
 {
 	if(p2==true)
 	{
 	DrawCircle(800,550,5,colors[RED]);
	DrawLine( 800 , 545 ,  800 , 530 , 4 , colors[BROWN] );
	DrawLine( 800 , 531 ,  795 , 515 , 2 , colors[BROWN] );
	DrawLine( 800 , 531 ,  805 , 515 , 2 , colors[BROWN] );
	DrawLine( 800 , 550 ,  795 , 535 , 2 , colors[BROWN] );
	DrawLine( 800 , 550 ,  805 , 535 , 2 , colors[BROWN] );
	}
 }
 
 
  //Function for passenger 3
 void person3()
 {
 	if(p3==true)
 	{
 	DrawCircle(800,270,5,colors[RED]);
	DrawLine( 800 , 265 ,  800 , 250 , 4 , colors[BROWN] );
	DrawLine( 800 , 251 ,  795 , 235 , 2 , colors[BROWN] );
	DrawLine( 800 , 251 ,  805 , 235 , 2 , colors[BROWN] );
	DrawLine( 800 , 270 ,  795 , 255 , 2 , colors[BROWN] );
	DrawLine( 800 , 270 ,  805 , 255 , 2 , colors[BROWN] );
	}
 }
 
 
  //Function for passenger 4
 void person4()
 {
 	if(p4==true)
 	{
 	DrawCircle(100,270,5,colors[RED]);
	DrawLine( 100 , 265 ,  100 , 250 , 4 , colors[BROWN] );
	DrawLine( 100 , 251 ,  95 , 235 , 2 , colors[BROWN] );
	DrawLine( 100 , 251 ,  105 , 235 , 2 , colors[BROWN] );
	DrawLine( 100 , 270 ,  95 , 255 , 2 , colors[BROWN] );
	DrawLine( 100 , 270 ,  105 , 255 , 2 , colors[BROWN] );
	}
 }


//Funtions for displaying drop off location of passengers
void drawp1()
{
if(l1==true)
{
DrawSquare(270, 50, 40, colors[RED]);

}
}

void drawp2()
{
if(l2==true)
{
DrawSquare(600, 50, 40, colors[RED]);

}
}

void drawp3()
{
if(l3==true)
{
DrawSquare(270, 510, 40, colors[RED]);

}
}

void drawp4()
{
if(l4==true)
{
DrawSquare(600, 510, 40, colors[RED]);

}
}

void drawp5()
{
if(l5==true)
{
DrawSquare(120, 50, 40, colors[RED]);

}
}

void drawp6()
{
if(l6==true)
{
DrawSquare(900, 50, 40, colors[RED]);

}
}

void drawp7()
{
if(l7==true)
{
DrawSquare(120, 510, 40, colors[RED]);

}
}

void drawp8()
{
if(l8==true)
{
DrawSquare(900, 510, 40, colors[RED]);

}
}


//Funtion for displaying the result of the game (win or lose)
void outcome()
{

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT);
	
		if(scoregame<100)
		{
			DrawString( 400, 400, "YOU LOSE ", colors[BLACK]);
		}
		if(scoregame>=100)
		{
			DrawString( 400, 400, "YOU WIN", colors[BLACK]);
		}
	
}

//Funtion for storing scores in txt file to display on leaderboard
void led()
{

	string par=Num2Str(scoregame);
	fstream myfile;
	myfile.open("MUTI.txt",ios::out|ios::app);
	if(myfile.is_open())
	{
		myfile<<par<<endl;
		myfile.close();
	}
}

//Main Funtion of Whole Game 
void GameStart()
	{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	//DrawSquare(400, 20, 40, colors[RED]);
	
	//Green Square
	//DrawSquare( 250 , 250 ,30,colors[GREEN]); 
	
	
	//Display Score
	DrawString( 50, 800, "Score = ", colors[BLACK]);
	DrawString( 140, 800, Num2Str(scoregame), colors[BLACK]);
	
	DrawString( 400, 800, "TIME = ", colors[BLACK]);
	DrawString( 490, 800, Num2Str(ti), colors[BLACK]);
	
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	

	

	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine( 990 , 19 ,  990 , 746 , 10 , colors[BLACK] );	
	DrawLine( 35 , 19 ,  35 , 746 , 10 , colors[BLACK] );
	DrawLine( 35 , 25 ,  990 , 25 , 10 , colors[BLACK] );
	DrawLine( 35 , 740 ,  990 , 740 , 10 , colors[BLACK] );
	
	
	DrawLine( 600 , 600 ,  990 , 600 , 35 , colors[BLACK] );
	DrawLine( 167 , 600 ,  350 , 600 , 35 , colors[BLACK] );
	DrawLine( 35 , 200 ,  300 , 200 , 35 , colors[BLACK] );
	DrawLine( 650 , 200 ,  990 , 200 , 35 , colors[BLACK] );
	DrawLine( 440 , 400 ,  600 , 400 , 35 , colors[BLACK] );
	DrawLine( 520 , 320 ,  520 , 480 , 35 , colors[BLACK] );
	
	DrawLine( 185 , 600 ,  185 , 450 , 35 , colors[BLACK] );
	DrawLine( 770 , 600 ,  770 , 450 , 35 , colors[BLACK] );
	
	DrawLine( 185 , 350 ,  185 , 200 , 35 , colors[BLACK] );
	DrawLine( 770 , 350 ,  770 , 200 , 35 , colors[BLACK] );
	
	DrawLine( 475 , 735 ,  475 , 625 , 35 , colors[BLACK] );
	DrawLine( 475 , 140 ,  475 , 25 , 35 , colors[BLACK] );
	
	
	int xxx=40;
	int yyy=30;
	//Displaying grid lines
	DrawLine( xxx+30 , 745 ,  xxx+30 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+70 , 745 ,  xxx+70 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+110 , 745 ,  xxx+110 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+150 , 745 ,  xxx+150 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+190 , 745 ,  xxx+190 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+230 , 745 ,  xxx+230 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+270 , 745 ,  xxx+270 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+310 , 745 ,  xxx+310 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+350 , 745 ,  xxx+350 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+390 , 745 ,  xxx+390 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+430 , 745 ,  xxx+430 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+470 , 745 ,  xxx+470 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+510 , 745 ,  xxx+510 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+550 , 745 ,  xxx+550 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+590 , 745 ,  xxx+590 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+630 , 745 ,  xxx+630 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+670 , 745 ,  xxx+670 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+710 , 745 ,  xxx+710 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+750 , 745 ,  xxx+750 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+790 , 745 ,  xxx+790 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+830 , 745 ,  xxx+830 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+870 , 745 ,  xxx+870 , 25 , 1 , colors[BLACK] );
	DrawLine( xxx+910 , 745 ,  xxx+910 , 25 , 1 , colors[BLACK] );
	
	//Displaying grid lines
	DrawLine( 35 , yyy+30 ,  990 , yyy+30 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+70 ,  990 , yyy+70 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+110 ,  990 , yyy+110 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+150 ,  990 , yyy+150 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+190 ,  990 , yyy+190 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+230 ,  990 , yyy+230 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+270 ,  990 , yyy+270 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+310 ,  990 , yyy+310 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+350 ,  990 , yyy+350 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+390 ,  990 , yyy+390 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+430 ,  990 , yyy+430 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+470 ,  990 , yyy+470 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+510 ,  990 , yyy+510 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+550 ,  990 , yyy+550 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+590 ,  990 , yyy+590 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+630 ,  990 , yyy+630 , 1 , colors[BLACK] );
	DrawLine( 35 , yyy+670 ,  990 , yyy+670 , 1 , colors[BLACK] );
	
	
	//Displaying trees
	DrawCircle(680,655,15,colors[GREEN]);
	DrawLine( 680 , 640 ,  680 , 620 , 5 , colors[BROWN] );
	
	DrawCircle(280,655,15,colors[GREEN]);
	DrawLine( 280 , 640 ,  280 , 620 , 5 , colors[BROWN] );
	
	DrawCircle(475,455,15,colors[GREEN]);
	DrawLine( 475 , 440 ,  475 , 420 , 5 , colors[BROWN] );
	
	DrawCircle(280,255,15,colors[GREEN]);
	DrawLine( 280 , 240 ,  280 , 220 , 5 , colors[BROWN] );
	
	DrawCircle(850,255,15,colors[GREEN]);
	DrawLine( 850 , 240 ,  850 , 220 , 5 , colors[BROWN] );
	
	//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	//DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	//DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	//DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	//DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	
	drawCar1();
	//Condition for calling cars after 2 drop offs
	if(tii>=2)
	{
	drawCar();
	}
	if(tii>=4)
	{
	drawCar2();
	}
	if(tii>=6)
	{
	drawCar3();
	}
	if(tii>=8)
	{
	drawCar4();
	}
	
	
	//Calling passenger functions
	person1();
	person2();
	person3();
	person4();
	person5();
	person6();
	person7();
	person8();
	
	
	//Calling drop off locations
	drawp1();
	drawp2();
	drawp3();
	drawp4();
	drawp5();
	drawp6();
	drawp7();
	drawp8();
	
	//Condition for displaying final result
	if(ti>180)
	{
	outcome();
	}
	
	//Condition for calling filing function
	if(ti==180 && lede==true)
	{
		led();
		lede=false;
	}
	
}

//Function for displaying menu
void men()
{
glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT);
	
	DrawLine( 430 , 580 ,  630 , 580 , 60 , colors[BLACK] );
	DrawLine( 400 , 465 ,  520 , 465 , 60 , colors[BLACK] );
	DrawLine( 540 , 465 ,  640 , 465 , 60 , colors[BLACK] );
	DrawLine( 430 , 340 ,  630 , 340 , 60 , colors[BLACK] );
	DrawLine( 430 , 210 ,  630 , 210 , 60 , colors[BLACK] );
	
	DrawString( 450, 800, "RUSH HOUR", colors[BLACK]);
	
	DrawString( 410, 450, "YELLOW        RED", colors[RED]);
	
	DrawString( 490, 575, "START", colors[RED]);
	
	DrawString( 440, 325, "LEADERBOARD", colors[RED]);
	
	DrawString( 495, 205, "EXIT", colors[RED]);
}


//Function for displaying leaderboard
void LeaderBoard()
{
	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT);
	
	/*DrawLine( 430 , 465 ,  630 , 465 , 60 , colors[BLACK] );
	DrawLine( 430 , 340 ,  630 , 340 , 60 , colors[BLACK] );
	DrawLine( 430 , 210 ,  630 , 210 , 60 , colors[BLACK] );
	
	
	
	DrawString( 490, 450, "YELLOW CAR", colors[RED]);
	
	DrawString( 440, 325, "RED CAR", colors[RED]);
	
	DrawString( 495, 205, "BACK", colors[RED]);*/
	
	DrawLine( 325 , 795 ,  665 , 795 , 60 , colors[BROWN] );
	DrawString( 400, 795, "LEADERBOARD", colors[BLACK] );
	
	
	//FILING CONDITIONS
	int ll=400;
	int ww=690;
	int no=1;
	
	fstream myfile;
	myfile.open("MUTI.txt",ios::in);
	if(myfile.is_open())
	{
	
		string tu1;
		
		
		while(getline(myfile,tu1) && no<=10)
		{
			string num22 = Num2Str(no);
			DrawString( 340, ww, num22, colors[BLACK] );
			DrawString( 380, ww, ":", colors[BLACK] );
			DrawString( ll, ww, tu1, colors[BLACK] );
			
			ww=ww-50;
			no++;
		
		}
		myfile.close();
	}
	
}

//Function for choosing the Car Choices 
void carchoice()
{
	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT);
	
	DrawLine( 430 , 465 ,  630 , 465 , 60 , colors[BLACK] );
	DrawLine( 430 , 340 ,  630 , 340 , 60 , colors[BLACK] );
	DrawLine( 430 , 210 ,  630 , 210 , 60 , colors[BLACK] );
	
	
	
	DrawString( 490, 450, "YELLOW CAR", colors[YELLOW]);
	
	DrawString( 440, 325, "RED CAR", colors[RED]);
	
	DrawString( 495, 205, "BACK", colors[RED]);
}


//Function for calculating score
void score()
{
//Scores for Yellow car
	if(yellow==true)
	{
	if(((x2>xI-40 && x2<xI+40) && (y2>yI-40 && y2<yI+40))&& c1)
	{
	scoregame -= 3;
	c1=false;
	}
	else if(!((x2>xI-40 && x2<xI+40) || (y2>yI-40 && y2<yI+40))&& !c1)
	{
	c1=true;
	}
	if(((x2>x3-40 && x2<x3+40) && (y2>y3-40 && y2<y3+40))&& c2)
	{
	scoregame -= 3;
	c2=false;
	}
	else if(!((x2>x3-40 && x2<x3+40) || (y2>y3-40 && y2<y3+40))&& !c2)
	{
	c2=true;
	}
	if(((x2>x4-40 && x2<x4+40) && (y2>y4-40 && y2<y4+40))&& c3)
	{
	scoregame -= 3;
	c3=false;
	}
	else if(!((x2>x4-40 && x2<x4+40) || (y2>y4-40 && y2<y4+40))&& !c3)
	{
	c3=true;
	}
	if(((x2>x5-40 && x2<x5+40) && (y2>y5-40 && y2<y5+40))&& c4)
	{
	scoregame -= 3;
	c4=false;
	}
	else if(!((x2>x5-40 && x2<x5+40) || (y2>y5-40 && y2<y5+40))&& !c4)
	{
	c4=true;
	}
	
	if(((x2>620 && x2<700)&&(y2>585 && y2<665))&& t1)//
	{
	scoregame -= 2;
	t1=false;
	}
	else if(!((x2>620 && x2<700)||(y2>585 && y2<665))&& !t1)//
	{
	t1=true;
	}
	if(((x2>220 && x2<300)&&(y2>585 && y2<665))&& t2)//
	{
	scoregame -= 2;
	t2=false;
	}
	else if(!((x2>220 && x2<300)||(y2>585 && y2<665))&& !t2)//
	{
	t2=true;
	}
	if(((x2>420 && x2<480)&&(y2>410 && y2<470))&& t3)
	{
	scoregame -= 2;
	t3=false;
	}
	else if(!((x2>420 && x2<480)||(y2>410 && y2<470))&& !t3)
	{
	t3=true;
	}
	if(((x2>220 && x2<300)&&(y2>225 && y2<265))&& t4)//
	{
	scoregame -= 2;
	t4=false;
	}
	else if(!((x2>220 && x2<300)||(y2>225 && y2<265))&& !t4)//
	{
	t4=true;
	}
	if(((x2>790 && x2<870)&&(y2>225 && y2<265))&& t5)//
	{
	scoregame -= 2;
	t5=false;
	}
	else if(!((x2>790 && x2<870)||(y2>225 && y2<265))&& !t5)//
	{
	t5 = true ;
	}
	}

//Scores for red car
	if(red==true)
	{
	if(((x2>xI-40 && x2<xI+40) && (y2>yI-40 && y2<yI+40))&& c1)
	{
	scoregame -= 2;
	c1=false;
	
	}
	else if(!((x2>xI-40 && x2<xI+40) || (y2>yI-40 && y2<yI+40))&& !c1)
	{
	c1=true;
	}
	if(((x2>x3-40 && x2<x3+40) && (y2>y3-40 && y2<y3+40))&& c2)
	{
	scoregame -= 2;
	c2=false;
	}
	else if(!((x2>x3-40 && x2<x3+40) || (y2>y3-40 && y2<y3+40))&& !c2)
	{
	c2=true;
	}
	if(((x2>x4-40 && x2<x4+40) && (y2>y4-40 && y2<y4+40))&& c3)
	{
	scoregame -= 2;
	c3=false;
	}
	else if(!((x2>x4-40 && x2<x4+40) || (y2>y4-40 && y2<y4+40))&& !c3)
	{
	c3=true;
	}
	if(((x2>x5-40 && x2<x5+40) && (y2>y5-40 && y2<y5+40))&& c4)
	{
	scoregame -= 2;
	c4=false;
	}
	else if(!((x2>x5-40 && x2<x5+40) || (y2>y5-40 && y2<y5+40))&& !c4)
	{
	c4=true;
	}
	
	if(((x2>620 && x2<700)&&(y2>585 && y2<665))&& t1)//
	{
	scoregame -= 4;
	t1=false;
	}
	else if(!((x2>620 && x2<700)||(y2>585 && y2<665))&& !t1)//
	{
	t1=true;
	}
	if(((x2>220 && x2<300)&&(y2>585 && y2<665))&& t2)//
	{
	scoregame -= 4;
	t2=false;
	}
	else if(!((x2>220 && x2<300)||(y2>585 && y2<665))&& !t2)//
	{
	t2=true;
	}
	if(((x2>420 && x2<480)&&(y2>410 && y2<470))&& t3)
	{
	scoregame -= 4;
	t3=false;
	}
	else if(!((x2>420 && x2<480)||(y2>410 && y2<470))&& !t3)
	{
	t3=true;
	}
	if(((x2>220 && x2<300)&&(y2>225 && y2<265))&& t4)//
	{
	scoregame -= 4;
	t4=false;
	}
	else if(!((x2>220 && x2<300)||(y2>225 && y2<265))&& !t4)//
	{
	t4=true;
	}
	if(((x2>790 && x2<870)&&(y2>225 && y2<265))&& t5)//
	{
	scoregame -= 4;
	t5=false;
	}
	else if(!((x2>790 && x2<870)||(y2>225 && y2<265))&& !t5)//
	{
	t5 = true ;
	}
	}

//Scores for passengers
	if(p1==true)
	{
	  if(((x2>750 && x2<810)&&(y2>585 && y2<665))&& pp1)	
	  {
	  	scoregame -= 5;
	  	pp1=false;
	  }
	  else if(!((x2>750 && x2<810)||(y2>585 && y2<665))&& !pp1)	
	  {
	  	pp1=true;
	  }
	}
	
	if(p4==true)
	{
	  if(((x2>50 && x2<110)&&(y2>200 && y2<280))&& pp4)	
	  {
	  	scoregame -= 5;
	  	pp4=false;
	  }
	  else if(!((x2>50 && x2<110)||(y2>200 && y2<280))&& !pp4)	
	  {
	  	pp4=true;
	  }
	}
	
	if(p5==true)
	{
	  if(((x2>150 && x2<210)&&(y2>585 && y2<665))&& pp5)	
	  {
	  	scoregame -= 5;
	  	pp5=false;
	  }
	  else if(!((x2>150 && x2<210)||(y2>585 && y2<665))&& !pp5)	
	  {
	  	pp5=true;
	  }
	}
	
	if(p8==true)
	{
	  if(((x2>420 && x2<480)&&(y2>120 && y2<200))&& pp8)	
	  {
	  	scoregame -= 5;
	  	pp8=false;
	  }
	  else if(!((x2>420 && x2<480)||(y2>120 && y2<200))&& !pp8)	
	  {
	  	pp8=true;
	  }
	}
	if(p2==true)
	{
	  if(((x2>750 && x2<810)&&(y2>470 && y2<550))&& pp2)	
	  {
	  	scoregame -= 5;
	  	pp2=false;
	  }
	  else if(!((x2>750 && x2<810)||(y2>470 && y2<550))&& !pp2)	
	  {
	  	pp2=true;
	  }
	}
	
	if(p3==true)
	{
	  if(((x2>750 && x2<810)&&(y2>190 && y2<270))&& pp3)	
	  {
	  	scoregame -= 5;
	  	pp3=false;
	  }
	  else if(!((x2>750 && x2<810)||(y2>190 && y2<270))&& !pp3)	
	  {
	  	pp3=true;
	  }
	}
	
	if(p6==true)
	{
	  if(((x2>50 && x2<110)&&(y2>10 && y2<70))&& pp6)	
	  {
	  	scoregame -= 5;
	  	pp6=false;
	  }
	  else if(!((x2>50 && x2<110)||(y2>10 && y2<70))&& !pp6)	
	  {
	  	pp6=true;
	  }
	}
	
	if(p7==true)
	{
	  if(((x2>750 && x2<810)&&(y2>10 && y2<70))&& pp7)	
	  {
	  	scoregame -= 5;
	  	pp7=false;
	  }
	  else if(!((x2>750 && x2<810)||(y2>10 && y2<70))&& !pp7)	
	  {
	  	pp7=true;
	  }
	}
	
}

//Function for Condition function calling
void GameDisplay()/**/
	
{
	if(men1==true)
	{
	men();
	}
	if(gs==true)
	{
	GameStart();
	}
	if(lb==true)
	{
	LeaderBoard();
	}
	if(cs==true)
	{
	carchoice();
	}
	
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
			== GLUT_KEY_LEFT && (x2>49) && 
			! ((x2 == 200 && y2 > 410 ) && (x2 == 200  && y2 < 620 )) && 
			! ((x2 == 200 && y2 > 200 ) && (x2 == 200  && y2 < 350 )) && 
			
			! ((x2 == 790 && y2 > 410 ) && (x2 == 790  && y2 < 620 )) && 
			! ((x2 == 790 && y2 > 200 ) && (x2 == 790  && y2 < 350 )) && 
			! ((x2 == 490 && y2 > 580 ) && (x2 == 490  && y2 < 745 )) && 
			! ((x2 == 490 && y2 > 25 ) && (x2 == 490  && y2 < 140 )) && 
			! ((x2 == 540 && y2 > 280 ) && (x2 == 540  && y2 < 480 )) && 
			! ((x2 == 350 && y2 > 540 ) && (x2 == 350  && y2 < 620 )) && 
			! ((x2 == 300 && y2 > 140 ) && (x2 == 300  && y2 < 220 )) && 
			! ((x2 == 600 && y2 > 340 ) && (x2 == 600  && y2 < 420 ))
			
			/*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		x2 -= 10;

	} else if (key
			== GLUT_KEY_RIGHT &&(x2<946) && 
			! ((x2 == 130 && y2 > 410 ) && (x2 == 130  && y2 < 620 )) && 
			! ((x2 == 130 && y2 > 200 ) && (x2 == 130  && y2 < 350 )) && 
			
			! ((x2 == 710 && y2 > 410 ) && (x2 == 710  && y2 < 620 )) && 
			! ((x2 == 710 && y2 > 200 ) && (x2 == 710  && y2 < 350 )) && 
			! ((x2 == 420 && y2 > 580 ) && (x2 == 420  && y2 < 745 )) && 
			! ((x2 == 420 && y2 > 25 ) && (x2 == 420  && y2 < 140 )) && 
			! ((x2 == 460 && y2 > 280 ) && (x2 == 460  && y2 < 480 )) && 
			! ((x2 == 610 && y2 > 140 ) && (x2 == 610  && y2 < 220 )) && 
			! ((x2 == 400 && y2 > 340 ) && (x2 == 400  && y2 < 420 ))
			/*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		x2 += 10;
	} else if (key
			== GLUT_KEY_UP &&(y2<685) && 
			! ((x2 > 35 && y2 == 140 ) && (x2 < 300  && y2 == 140 )) && 
			! ((x2 > 620 && y2 == 140 ) && (x2 < 990  && y2 == 140 )) && 
			! ((x2 > 135  && y2 == 540 ) && (x2 < 340 && y2 == 540 )) && 
			! ((x2 > 560  && y2 == 540 ) && (x2 < 990 && y2 == 540 )) && 
			! ((x2 > 135  && y2 == 410 ) && (x2 < 210 && y2 == 410 )) && 
			! ((x2 > 425  && y2 == 580 ) && (x2 < 485 && y2 == 580 )) && 
			! ((x2 > 400  && y2 == 340 ) && (x2 < 600 && y2 == 340 )) && 
			! ((x2 > 460  && y2 == 280 ) && (x2 < 540 && y2 == 280 )) && 
			! ((x2 > 715  && y2 == 410 ) && (x2 < 790 && y2 == 410 ))
			
			/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		y2 += 10;
	}

	else if (key
			== GLUT_KEY_DOWN &&(y2>39) && 
			! ((x2 > 35  && y2 == 220 ) && (x2 < 300 && y2 == 220 ))  && 
			! ((x2 > 620  && y2 == 220 ) && (x2 < 990 && y2 == 220 )) && 
			! ((x2 > 135  && y2 == 620 ) && (x2 < 340 && y2 == 620 )) && 
			! ((x2 > 560  && y2 == 620 ) && (x2 < 990 && y2 == 620 )) && 
			! ((x2 > 425  && y2 == 140 ) && (x2 < 485 && y2 == 140 )) && 
			! ((x2 > 135  && y2 == 350 ) && (x2 < 210 && y2 == 350 )) && 
			! ((x2 > 400  && y2 == 420 ) && (x2 < 600 && y2 == 420 )) && 
			! ((x2 > 460  && y2 == 480 ) && (x2 < 540 && y2 == 480 )) && 
			! ((x2 > 715  && y2 == 350 ) && (x2 < 790 && y2 == 350 ))
			
			/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		y2 -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	

	//Person 1
	if (key == 32 && p1==true 
	&&(((x2>730 && x2<850)
	&&(y2>600 && y2<720)))) //Key for placing the bomb
			{
		
		cout << "space pressed" << endl;
		scoregame +=10;
		l1=true;
		p1=false;
		}
		
	if (key == 32 && (x2==270 && y2==50))	
	{
		l1=false;
		p1=true;
		tii++;
		scoregame +=10;
	}
	//Person 2
	if (key == 32 && p2==true 
	&&(((x2>730 && x2<850)
	&&(y2>450 && y2<600)))) //Key for placing the bomb
			{
		
		cout << "space pressed" << endl;
		scoregame +=10;
		l2=true;
		p2=false;
		}
		
	if (key == 32 && (x2==600 && y2==50))	
	{
		l2=false;
		p2=true;
		tii++;
		scoregame +=10;
	}
	
	//Person 3
	if (key == 32 && p3==true 
	&&(((x2>730 && x2<850)
	&&(y2>230 && y2<310)))) //Key for placing the bomb
			{
		
		cout << "space pressed" << endl;
		scoregame +=10;
		l3=true;
		p3=false;
		}
		
	if (key == 32 && (x2==270 && y2==510))	
	{
		l3=false;
		tii++;
		p3=true;
		scoregame +=10;
	}
	
	//Person 4
	if (key == 32 && p4==true 
	&&(((x2>40 && x2<220)
	&&(y2>230 && y2<310)))) //Key for placing the bomb
			{
		
		cout << "space pressed" << endl;
		scoregame +=10;
		l4=true;
		p4=false;
		}
		
	if (key == 32 && (x2==600 && y2==510))	
	{
		l4=false;
		p4=true;
		tii++;
		scoregame +=10;
	}
	
	//Person 5
	if (key == 32 && p5==true 
	&&(((x2>120 && x2<190)
	&&(y2>575 && y2<680)))) //Key for placing the bomb
			{
		
		cout << "space pressed" << endl;
		scoregame +=10;
		l5=true;
		p5=false;
		}
		
	if (key == 32 && (x2==120 && y2==50))	
	{
		l5=false;
		p5=true;
		tii++;
		scoregame +=10;
	}
	
	//Person 6
	if (key == 32 && p6==true 
	&&(((x2>70 && x2<200)
	&&(y2>20 && y2<140)))) //Key for placing the bomb
			{
		
		cout << "space pressed" << endl;
		l6=true;
		p6=false;
		scoregame +=10;
		}
		
	if (key == 32 && (x2==900 && y2==50))	
	{
		l6=false;
		tii++;
		p6=true;
		scoregame +=10;
	}
	
	//Person 7
	if (key == 32 && p7==true 
	&&(((x2>750 && x2<850)
	&&(y2>20 && y2<140)))) //Key for placing the bomb
			{
		
		cout << "space pressed" << endl;
		scoregame +=10;
		l7=true;
		p7=false;
		}
		
	if (key == 32 && (x2==120 && y2==510))	
	{
		l7=false;
		tii++;
		p7=true;
		scoregame +=10;
	}
	
	//Person 8
	if (key == 32 && p8==true 
	&&(((x2>380 && x2<470)
	&&(y2>140 && y2<240)))) //Key for placing the bomb
			{
		
		cout << "space pressed" << endl;
		scoregame +=10;
		l8=true;
		p8=false;
		}
		
	if (key == 32 && (x2==900 && y2==510))	
	{
		l8=false;
		p8=true;
		tii++;
		scoregame +=10;
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
 void Timer1(int mm) {

	ti++;
	glutTimerFunc(1000, Timer1, 0);
}
 
void Timer(int m) {

	// implement your functionality here
	moveCar();
	moveCar1();
	moveCar2();
	moveCar3();
	score();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(50, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
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
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON &&
	state &&
	men1 &&
	(x>400 && x<520) &&
	(y>240 && y<300)) // dealing only with left button
			{
			men1=false;
			gs=true;
			yellow=true;
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} 
	
	if (button == GLUT_LEFT_BUTTON &&
	state &&
	men1 &&
	(x>540 && x<640) &&
	(y>240 && y<300)) // dealing only with left button
			{
			men1=false;
			gs=true;
			red=true;
			
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} 
	
	
	if (button == GLUT_LEFT_BUTTON &&
	state &&
	men1 &&
	(x>430 && x<630) &&
	(y>330 && y<395)) // dealing only with left button
			{
			men1=false;
			lb=true;
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} 
	
	if (button == GLUT_LEFT_BUTTON &&
	state &&
	men1 &&
	(x>430 && x<630) &&
	(y>420 && y<485)) // dealing only with left button
			{
			exit(1);
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} 
	
	
	
	
	
	
	
	
	
	
	
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Muti Ur Rehman"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);
	glutTimerFunc(1000.0, Timer1, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
