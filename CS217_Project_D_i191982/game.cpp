//================================================= ===========================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================
#ifndef CENTIPEDE_CPP_ 
#define CENTIPEDE_CPP_
#include "util.h"  
#include "Allcode.cpp"
#include<iostream>
#include<stdlib.h>
#include<string>   
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<fstream>
using namespace std;

static string s = "";
static int loading=0;
static int array1[64],array3[64],wine1=0,wine2=0,wine3=0,wine4=0,clocktime=60,pau=0,score=0;
bool timermode=true;

//                               **************************************************************     
//                                                 PrintableKeys  Function
//                               **************************************************************  
void PrintableKeys(unsigned char key, int x, int y) 
{ 
	
	if (key == 27/* Escape key ASCII*/) {
	
	Scoring a;
	a.calculate(score);
		exit(1); // exit the program when escape key is pressed.
	
	
	}
 
	if (key == 'b' || key == 'B') //Key for placing the bomb 
			{
		cout << "b pressed" << endl;		
	}
	if (key == 'p' || key == 'P')
	{
                    pau++;
		cout<<"b pressed"<< endl;
	}
	
    char a=key;                                          //used to convert the char into string 
    char array[] ={a};
    int arsize = sizeof(array)/sizeof(char);
    for(int i = 0;i<arsize;i++)
    {
        s = s + array[i];
    }       
	glutPostRedisplay();     
    }
 //                               **************************************************************     
//                                                FUNCTION FOR Main MENU
//                               **************************************************************  
   void MainMenu()
   {
     pau=1;
     glClearColor(0, 0, 0,0); 
     glClear (GL_COLOR_BUFFER_BIT);        
     Main a;
     a.DrwMainMenu(loading,s); 
     glutSwapBuffers();

   }
 //                               **************************************************************     
//                                                FUNCTION FOR GAME MENU
//                               **************************************************************  
 
 
  void GameMenu(){

glClearColor(   0.411764705882353,0.411764705882353, 0.411764705882353,0); 
glClear (GL_COLOR_BUFFER_BIT); 
     Main b;
     b.DrwGameMenu();    
     glutSwapBuffers();
}
 //                               **************************************************************     
//                                                FUNCTION FOR Control_Max 
//                               **************************************************************  

void Control_Max(){
glClearColor(   0.870588235294118, 0.721568627450980, 0.529411764705882,0); 
glClear (GL_COLOR_BUFFER_BIT); 
Main c;
c.DrawGameinstruction(); 
glutSwapBuffers();
}
 //                               **************************************************************     
//                                               FUNCTION FOR SCORE
//                               **************************************************************  

void Score(){
glClearColor( 0.803921568627451, 0.360784313725490,
				0.360784313725490,0); 
glClear (GL_COLOR_BUFFER_BIT);

Main d;
d.DrawScore();
Scoring s;
s.read(); 
glutSwapBuffers();
}

 //                               **************************************************************     
//                                               FUNCTION FOR SetCanvasSize
//                               **************************************************************  


void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width,0, height, -1, 1); //     set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);       
	glLoadIdentity();             
}

 //                               **************************************************************     
//                                               FUNCTION FOR MousePressedAndMoved
//                               **************************************************************  


void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl; 	
Range R;
R.SetRange(x,y,wine1,wine2,wine3,wine4,array1,array3);

  glutPostRedisplay();	       
}                   
//                               **************************************************************     
//                                               FUNCTION FOR Main Canvas drawing
//                               **************************************************************  

void GameDisplay(){
	

	glClearColor(  0.823529411764706, 0.411764705882353, 0.117647058823529,0);
	glClear (GL_COLOR_BUFFER_BIT); 
       
 static int move,progress=0,Level=0,index1=0,index2=0,xaxis,yaxis,array[64],lives=3;
 static bool flag=true;       
 int count=1; 
 xaxis=305;
 yaxis=555;

////////////////////////////////////////////////////condition for making one time true the condition 

 Arena copy;	     
 copy.DisplayArena();
 DrawString( 450, 70, s, colors[DARK_BLUE]); 
 Circle a;
 Square b;
 Rectangle c;
 RoundRectangle d;
 Torus e;
 Timer t;
 Scored s;
 ProgressBar p;


////////////////////////////////////////////////////condition for Drawing  

Shape *array2[4];
array2[0]=new Circle;
array2[1]=new Square;
array2[2]=new Rectangle;
array2[3]=new RoundRectangle;
array2[4]=new Torus; 
array2[0]=&a;
array2[1]=&b;               
array2[2]=&c;
array2[3]=&d;
array2[4]=&e;
   
   if(flag==true)
    {
     for(int i=0;i<64;i++)
    {
     array[i]=rand()%5;    
    }
    flag=false;
    }
   
   for(int j=0;j<64;j++)
   { 
   
     cout<<array[j]<<" ";
   }

for(int i=0;i<64;i++)
{     
array2[array[i]]->Drw(xaxis,yaxis); 

        // cout<<i<<" ";
           if (array[i]==0)                  
               { 
                
                   array1[i]=xaxis;
                   array3[i]=yaxis;
               }
          else if (array[i]==1)                  
                 {
                   array1[i]=xaxis;
                   array3[i]=yaxis;
                 }
          else if (array[i]==2)                  
                 {
                   array1[i]=xaxis;
                   array3[i]=yaxis;
                 } 
          else if (array[i]==3)                  
                 { 
                   
                   array1[i]=xaxis;
                   array3[i]=yaxis;
                 }
         else if  (array[i]==4)                  
                 {
                  
                   array1[i]=xaxis;
                   array3[i]=yaxis;
                 }         
        xaxis+=50; 
      if (count==8)
       {
        yaxis-=50;
        xaxis=305; 
        count=0;
       // cout<<endl;
       }       
      count++;     
}    

///////////////////////////////////////Swaping
for(int i=0;i<64;i++)
{
if((array1[i]==wine1)&&(array3[i]==wine2))
{
index1=i;
}
}

for(int i=0;i<64;i++)
{
if((array1[i]==wine3)&&(array3[i]==wine4))
{
index2=i;
}
}

Destroy des;
des.Destro(array,score,move);
  
Swap copy2;
copy2.swap(array,index1,index2,wine1,wine2,wine3,wine4);
t.printtime(clocktime);
s.printscore(score);
p.printProgressBar(score,clocktime,Level,progress,move,lives);
wine3=0;
wine4=0;



       


//cout<<"wine1   "<<wine1<<endl;
//cout<<endl;
//cout<<"wine2   "<<wine2<<endl;
//cout<<endl;
//cout<<"wine3   "<<wine3<<endl;
//cout<<endl;
//cout<<"wine4   "<<wine4<<endl;
//cout<<endl;
/////////////////////////////////////////////// 
                   
glutSwapBuffers(); 
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

                 
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
   
	}else if (key 
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();  

}   
  

 
 
//                               **************************************************************     
//                                               FUNCTION FOR Timer
//                               **************************************************************  

void Timer(int m) 
{     
      // glutPostRedisplay();  
      //glutSwapBuffers();    
    if(loading<=300)
     { 
     loading+=2;
     }
	glutTimerFunc(1000.0, Timer, 0);
}

 //                               **************************************************************     
//                                               FUNCTION FOR Clock
//                               **************************************************************  

void clock(int m) //------used for the animation and controling time 
{ 


   if (pau%2!=0)
   {
   clocktime=clocktime; 
   }            
  else 
   {
   if(clocktime>0)
        {
         clocktime--;               
        }       
    }
 
        glutPostRedisplay();
	
	glutTimerFunc(2000.0, clock, 0);

}  




//                               **************************************************************     
//                                               FUNCTION FOR MouseMoved
//                               **************************************************************  

void MouseMoved(int x, int y) 
{
       
	//cout << x << " " << y << endl;         
	glutPostRedisplay();
}  
 

//                               **************************************************************     
//                                               FUNCTION FOR MouseClicked
//                               **************************************************************  


void MouseClicked(int button, int state, int x, int y) {
            // cout<<"x "<<x<<"y "<<y<<endl;
	                        	
	
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
	      if ((x>=750&&x<=950)&&(y>=467&&y<=500))
                        {
                        pau=0;
                        cout<<"\a";  
                        glutDisplayFunc(GameDisplay);
                        
                        }   
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
		
		
	 
	}
	 else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
		cout<<"Right Button Pressed"<<endl;  
	  
	        if ((x>=749&&x<=950)&&(y>=420&&y<=459))//Range for the gamedisplay
                       {   cout<<"\a";                                        
                        glutDisplayFunc(GameDisplay); 
                         pau=0;
                       }	                                      
                if ((x>=749&&x<=950)&&(y>=508&&y<=542))//Range for the ControlMax
                       { cout<<"\a"; 
                        glutDisplayFunc(Score); 
                       }
                if ((x>=749&&x<=950)&&(y>=551&&y<=585))//Range for the ControlMax
                       { cout<<"\a"; 
                        glutDisplayFunc(Control_Max); 
                       }         
                if ((x>=750&&x<=950)&&(y>=595&&y<=626))//Range for the exit 
                        { cout<<"\a"; 
                        exit(1);} 
                if ((x>=489&&x<=561)&&(y>=608&&y<=703))
                        {
                         cout<<"\a"; 
                         glutDisplayFunc(GameMenu);}  
                if ((x>=472&&x<=527)&&(y>=560&&y<=610))
                        {
                        cout<<"\a";  
                        glutDisplayFunc(GameMenu);
                        pau=1;
                        } 
                      if(pau==1){
                      if ((x>=459&&x<=520)&&(y>=390&&y<=440))
                        {
                        cout<<"\a";  
                        glutDisplayFunc(GameMenu);
                        pau=1;
                       }
                       }         

	glutPostRedisplay();  
}

}


  
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020,height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode 
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window 
	SetCanvasSize(width, height); // set the number of pixels...+

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
    
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas       
        glutDisplayFunc(GameMenu);
        glutDisplayFunc(MainMenu); 
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(100.0, Timer, 0);
	glutTimerFunc(1000.0, clock, 0); 
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
 
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...   	
	glutMainLoop(); 
	return 1;
}
#endif /* AsteroidS_CPP_ */
