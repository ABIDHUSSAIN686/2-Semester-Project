#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
////////////////////////////////////////////////class for the position 
class Axis{
protected:
int xaxis,x1axis;
int yaxis,y1axis;
public:

Axis()
{
xaxis=700;
yaxis=700;
x1axis=50;
y1axis=750;
}
Axis(int x,int x1,int y,int y1)
{
xaxis=x;
yaxis=y;
x1axis=x1;
y1axis=y1;
}
Axis(int x,int y)
{
xaxis=x;
yaxis=y;
}

void setxaxis(int x)
{
xaxis=x;
}
int getxaxis()
{
return xaxis;
}
void setx1axis(int x1)
{
x1axis=x1;
}
int getx1axis()
{
return x1axis;
}
void setyaxis(int y)
{
yaxis=y;
}
int getyaxis()
{
return yaxis;
}
void sety1axis(int y1)
{
y1axis=y1;
}
int gety1axis()
{
return y1axis;
}
~Axis()
{
}

};

//////////////////////////////////////////////////////class for drawing the arena
class Arena: public Axis
{
protected:
float *color;
int size;
public:
Arena():Axis()
{
size=3;
}

void DisplayArena()
	{	
        Torus2d(510,260,90,360,0,500,11,colors[TAN]);  //HARD CODE FOR MAKING AREANA BEAUTIFUL
        Torus2d(850,530,90,360,140,10,6,colors[RED]);
        Torus2d(850,530,90,360,0,140,6,colors[BLACK]);
        Torus2d(160,530,90,360,140,10,6,colors[RED]);
        Torus2d(160,530,90,360,0,140,6,colors[BLACK]);

        DrawRoundRect(298,600,402,45,colors[BLACK],5);
        DrawRoundRect(302,603,394,40,colors[ORANGE_RED],5);
        DrawRoundRect(298,98,402,100,colors[BLACK],5);       
        DrawRoundRect(302,100,394,100,colors[ORANGE_RED],5);
        
        Torus2d(510,260,90,360,500,100,11,colors[CHOCOLATE]);
        Torus2d(510,260,90,360,500,10,11,colors[SADDLE_BROWN]);
        Torus2d(510,260,90,360,525,10,11,colors[SADDLE_BROWN]);
        Torus2d(510,260,90,360,550,10,11,colors[SADDLE_BROWN]);
        Torus2d(510,260,90,360,575,10,11,colors[SADDLE_BROWN]);
        Torus2d(510,260,90,360,600,10,11,colors[SADDLE_BROWN]);
        
        for(int i=xaxis;i>=300;i-=50)
	{
	DrawLine(i,x1axis+150,i,y1axis-150,size, colors[BLACK] );
	}
	for(int i=y1axis-150;i>=200;i-=50)
	{ 
	DrawLine( xaxis-400,i ,yaxis , i  , size , colors[BLACK] );
	}
	DrawString( 400, 610, "BEJWELED GAME", colors[PURPLE]);
	
		DrawCircle(500,150,35,colors[BLACK]);
		DrawCircle(450,150,25,colors[BLACK]);
		DrawCircle(550,150,25,colors[BLACK]);
		DrawCircle(500,150,30,colors[OLD_LACE]);
		DrawCircle(450,150,20,colors[OLD_LACE]);
		DrawCircle(550,150,20,colors[OLD_LACE]);
	   DrawRoundRect(507,130,5,40,colors[ORCHID],5);
	   DrawRoundRect(487,130,5,40,colors[ORCHID],5);
	   DrawString( 300, 70, "Player Name", colors[DARK_BLUE]); 
	   DrawCircle(200,150,45,colors[PURPLE]);
	   DrawCircle(200,150,40,colors[DEEP_PINK]);
	   DrawCircle(200,150,35,colors[LIGHT_STEEL_BLUE]);
	   DrawCircle(200,150,30,colors[OLD_LACE]);
	   DrawString(190,140,"M", colors[BLACK]);    
	   
           
         
	}
~Arena()
{
//cout<<"Destructor of Arena called"<<endl;
}
};
///////////////////////////////////////////////////////////////abstract class for drawing the shapes 
class Shape:public  Axis
{
protected:
float color;

public:
Shape():Axis()
{
color=0;
}
Shape(float c):Axis(xaxis, yaxis)
{
color=c;
}

float getcolor()
{
return color;
}
virtual void Drw(int x,int y)const=0;
virtual ~Shape()
{
//cout<<"Destructor of shape called"<<endl;
}
};
//////////////////////////////////////////////////////clss of circle 
class Circle:public Shape
{
protected:
int radius;
public:
Circle():Shape()
{
radius=15;
}
Circle(int r)
{
radius=r;
}
void Drw(int x,int y)const
{
DrawSquare(x-2,y-2,45,colors[MAROON]);
x+=20;
y+=20;


DrawCircle(x,y,radius,colors[KHAKI]);

}
};
/////////////////////////////////////////////////clss of Square
class Square:public Shape
{
protected: 
int lenght;
public:
Square():Shape()
{
lenght=30;
}
Square(int l)
{
lenght=l;
}
void Drw(int x,int y)const
{
DrawSquare(x-2,y-2,45,colors[ORANGE]);
 x+=5;
 y+=5;
DrawSquare(x,y,lenght,colors[GREEN]); 

}
};
/////////////////////////////////////////////////clss of RoundRectangle
class RoundRectangle:public Shape
{
protected: 
int lenght;
int width;
int radius;
public:
RoundRectangle():Shape()
{
lenght=25;
width=40;
radius=20;
}
RoundRectangle(int l,int w,int r):Shape()
{
lenght=l;
width=w;
radius=r;
}
void Drw(int x,int y)const
{
DrawSquare(x-2,y-2,45,colors[BLUE]);
x+=5;
 DrawRoundRect(x,y,lenght,width,colors[VIOLET],radius);
}
};
/////////////////////////////////////////////////clss of tours2d

class Torus:public Shape
{
protected: 
float angle;
float lenght;
float radius;
float width;
unsigned int sample;
public:
Torus():Shape()
{
angle=90;
lenght=365;
radius=10;
width=5;
sample=25;
}

void Drw(int x,int y)const
{
DrawSquare(x-2,y-2,45,colors[THISTLE]);
x+=20;
y+=20;
Torus2d(x,y,angle,lenght,radius,width,sample,colors[RED]);
}
};

/////////////////////////////////////////////////class of rectangle
class Rectangle:public Shape
{
protected: 
int lenght;
int width;
int radius;
public:
Rectangle():Shape()
{
lenght=30;
width=30;
radius=5;
}
Rectangle(int l,int w,int r):Shape()
{
lenght=l;
width=w;
radius=r;
}
void Drw(int x,int y)const
{
DrawSquare(x-2,y-2,45,colors[CORAL]);
x+=5;
y+=5;
 DrawRoundRect(x,y,lenght,width,colors[MAROON],radius);
}
};
///////////////////////////////////////////////clss for destroy
class Destroy
{
public:
void Destro(int (&array)[64],int &scoreadd, int &moves)
{
//                          *************************************************************************
//                                                 code from up to down 
//                          *************************************************************************

//first column first box
int j;
int i=0;



for(j=0;j<8;j++)
{
if(array[j]==array[8+j]&&array[j]==array[16+j]&&array[j]==array[24+j]&&array[j]==array[32+j]&&array[j]==array[40+j]&&array[j]==array[48+j]&&array[j]==array[56+j])
{
for(i;i<=56+j;i+=8)
{
array[i]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[j]==array[8+j]&&array[j]==array[16+j]&&array[j]==array[24+j]&&array[j]==array[32+j]&&array[j]==array[40+j]&&array[j]==array[48+j])
{
for(i;i<=48+j;i+=8)
{
array[i]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[j]==array[8+j]&&array[j]==array[16+j]&&array[j]==array[24+j]&&array[j]==array[32+j]&&array[j]==array[40+j])
{
for(i;i<=40+j;i+=8)
{
array[i]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[j]==array[8+j]&&array[j]==array[16+j]&&array[j]==array[24+j]&&array[j]==array[32+j])
{
for(i;i<=32+j;i+=8)
{
array[i]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[j]==array[8+j]&&array[j]==array[16+j]&&array[j]==array[24+j])
{
for(i;i<=24+j;i+=8)
{
array[i]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[j]==array[8+j]&&array[j]==array[16+j])
{
for(i;i<=16+j;i+=8)
{
array[i]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
i+=1;
}


//second box of column
int m;
int n=8;
int o=8;
for(m=0;m<8;m++)
{

if(array[o+m]==array[16+m]&&array[o+m]==array[24+m]&&array[o+m]==array[32+m]&&array[o+m]==array[40+m]&&array[o+m]==array[48+m]&&array[o+m]==array[56+m])
{
for(n;n<=56+m;n+=8)
{
array[n]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[o+m]==array[16+m]&&array[o+m]==array[24+m]&&array[o+m]==array[32+m]&&array[o+m]==array[40+m]&&array[o+m]==array[48+m])
{
for(n;n<=48+m;n+=8)
{
array[n]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[o+m]==array[16+m]&&array[o+m]==array[24+m]&&array[o+m]==array[32+m]&&array[o+m]==array[40+m])
{
for(n;n<=40+m;n+=8)
{
array[n]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[o+m]==array[16+m]&&array[o+m]==array[24+m]&&array[o+m]==array[32+m])
{
for(n;n<=32+m;n+=8)
{
array[n]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[o+m]==array[16+m]&&array[o+m]==array[24+m])
{
for(n;n<=24+m;n+=8)
{
array[n]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
n+=1;
}

int p;
int q=16;
int r=16;

//first column third box
for(p=0;p<8;p++)
{
 if(array[p+q]==array[24+p]&&array[p+q]==array[32+p]&&array[p+q]==array[40+p]&&array[p+q]==array[48+p]&&array[p+q]==array[56+p])
{
for(r;r<=56+p;r+=8)
{
array[r]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[p+q]==array[24+p]&&array[p+q]==array[32+p]&&array[p+q]==array[40+p]&&array[p+q]==array[48+p])
{
for(r;r<=48+p;r+=8)
{
array[r]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[p+q]==array[24+p]&&array[p+q]==array[32+p]&&array[p+q]==array[40+p])
{
for(r;r<=40+p;r+=8)
{
array[r]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[p+q]==array[24+p]&&array[p+q]==array[32+p])
{
for(r;r<=32+p;r+=8)
{
array[r]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
r+=1;
}

//first column fourth box
int e;
int f=24;
int g=24;

for(e=0;e<8;e++)
{
if(array[e+f]==array[32+e]&&array[e+f]==array[40+e]&&array[e+f]==array[48+e]&&array[e+f]==array[56+e])
{
for(g;g<=56+e;g+=8)
{
array[g]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[e+f]==array[32+e]&&array[e+f]==array[40+e]&&array[e+f]==array[48+e])
{
for(g;g<=48+e;g+=8)
{
array[g]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[e+f]==array[32+e]&&array[e+f]==array[40+e])
{
for(g;g<=40+e;g+=8)
{
array[g]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
g+=1;
}
//first column five box
int s;
int t=32;
int u=32;
for(s=0;s<8;s++)
{
if(array[s+t]==array[40+s]&&array[s+t]==array[48+s]&&array[s+t]==array[56+s])
{
for(u;u<=56+s;u+=8)
{
array[u]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[s+t]==array[40+s]&&array[s+t]==array[48+s])
{
for(u;u<=48+s;u+=8)
{
array[u]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
u+=1;
}
//first column six box
int aa;
int bb=40;
int cc=40;
for(aa=0;aa<7;aa++)
{
if(array[aa+bb]==array[48+aa]&&array[aa+bb]==array[56+aa])
{
for(cc;cc<=56+aa;cc+=8)
{
array[cc]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
cc+=1;
};

//                          *************************************************************************
//                                                 code from left to right
//                          *************************************************************************


//---------first box

int r1;
int rr1=0;
for(r1=0;r1<=56;r1+=8)
{
if(array[r1]==array[1+r1]&&array[r1]==array[2+r1]&&array[r1]==array[3+r1]&&array[r1]==array[4+r1]&&array[r1]==array[5+r1]&&array[r1]==array[6+r1]&&array[r1]==array[7+r1])
{
for(rr1;rr1<8;rr1++)
{
array[rr1+r1]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[r1]==array[1+r1]&&array[r1]==array[2+r1]&&array[r1]==array[3+r1]&&array[r1]==array[4+r1]&&array[r1]==array[5+r1]&&array[r1]==array[6+r1])
{
for(rr1;rr1<7;rr1++)
{
array[rr1+r1]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[r1]==array[1+r1]&&array[r1]==array[2+r1]&&array[r1]==array[3+r1]&&array[r1]==array[4+r1]&&array[r1]==array[5+r1])
{
for(rr1;rr1<6;rr1++)
{
array[rr1+r1]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[r1]==array[1+r1]&&array[r1]==array[2+r1]&&array[r1]==array[3+r1]&&array[r1]==array[4+r1])
{
for(rr1;rr1<5;rr1++)
{
array[rr1+r1]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[r1]==array[1+r1]&&array[r1]==array[2+r1]&&array[r1]==array[3+r1])
{
for(rr1;rr1<4;rr1++)
{
array[rr1+r1]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[r1]==array[1+r1]&&array[r1]==array[2+r1])
{
for(rr1;rr1<3;rr1++)
{
array[rr1+r1]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
}
//---------second box

int r2;
int rr2=1;
for(r2=0;r2<=56;r2+=8)
{
if(array[r2+1]==array[2+r2]&&array[r2+1]==array[3+r2]&&array[r2+1]==array[4+r2]&&array[r2+1]==array[5+r2]&&array[r2+1]==array[6+r2]&&array[r2+1]==array[7+r2])
{
for(rr2;rr2<8;rr2++)
{
array[rr2+r2]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[r2+1]==array[2+r2]&&array[r2+1]==array[3+r2]&&array[r2+1]==array[4+r2]&&array[r2+1]==array[5+r2]&&array[r2+1]==array[6+r2])
{
for(rr2;rr2<7;rr2++)
{
array[rr2+r2]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[r2+1]==array[2+r2]&&array[r2+1]==array[3+r2]&&array[r2+1]==array[4+r2]&&array[r2+1]==array[5+r2])
{
for(rr2;rr2<6;rr2++)
{
array[rr2+r2]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[r2+1]==array[2+r2]&&array[r2+1]==array[3+r2]&&array[r2+1]==array[4+r2])
{
for(rr2;rr2<5;rr2++)
{
array[rr2+r2]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else 
if(array[r2+1]==array[2+r2]&&array[r2+1]==array[3+r2])
{
for(rr2;rr2<4;rr2++)
{
array[rr2+r2]=rand()%5;
}
scoreadd+=30;
moves+=1;
}

}

//---------third box


int r3;
int rr3=2;
for(r3=0;r3<=56;r3+=8)
{

if(array[r3+2]==array[3+r3]&&array[r3+2]==array[4+r3]&&array[r3+2]==array[5+r3]&&array[r3+2]==array[6+r3]&&array[r3+2]==array[7+r3])
{
for(rr3;rr3<8;rr3++)
{
array[rr3+r3]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[r3+2]==array[3+r3]&&array[r3+2]==array[4+r3]&&array[r3+2]==array[5+r3]&&array[r3+2]==array[6+r3])
{
for(rr3;rr3<7;rr3++)
{
array[rr3+r3]=rand()%5;
}
scoreadd+=30;
moves+=1;
}

else if(array[r3+2]==array[3+r3]&&array[r3+2]==array[4+r3]&&array[r3+2]==array[5+r3])
{
for(rr3;rr3<6;rr3++)
{
array[rr3+r3]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else 

if(array[r3+2]==array[3+r3]&&array[r3+2]==array[4+r3])
{
for(rr3;rr3<5;rr3++)
{
array[rr3+r3]=rand()%5;
}
scoreadd+=30;
moves+=1;
}

}


//---------fourth box


int r4;
int rr4=3;
for(r4=0;r4<=56;r4+=8)
{

if(array[r4+3]==array[4+r4]&&array[r4+3]==array[5+r4]&&array[r4+3]==array[6+r4]&&array[r4+3]==array[7+r4])
{
for(rr4;rr4<8;rr4++)
{
array[rr4+r4]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[r4+3]==array[4+r4]&&array[r4+3]==array[5+r4]&&array[r4+3]==array[6+r4])
{
for(rr4;rr4<7;rr4++)
{
array[rr4+r4]=rand()%5;
}
scoreadd+=30;
moves+=1;
}

else if(array[r4+3]==array[4+r4]&&array[r4+3]==array[5+r4])
{
for(rr4;rr4<6;rr4++)
{
array[rr4+r4]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
}

//---------five box
int r5;
int rr5=4;
for(r5=0;r5<=56;r5+=8)
{

if(array[r5+4]==array[5+r5]&&array[r5+4]==array[6+r5]&&array[r5+4]==array[7+r5])
{
for(rr5;rr5<8;rr5++)
{
array[rr5+r5]=rand()%5;
}
scoreadd+=30;
moves+=1;
}
else if(array[r5+4]==array[5+r5]&&array[r5+4]==array[6+r5])
{
for(rr5;rr5<7;rr5++)
{
array[rr5+r5]=rand()%5;
}
scoreadd+=30;
moves+=1;
}

}

//---------six box
int r6;
int rr6=5;
for(r6=0;r6<=56;r6+=8)
{

if(array[r6+5]==array[6+r6]&&array[r6+5]==array[7+r6])
{
for(rr6;rr6<8;rr6++)
{
array[rr6+r6]=rand()%5;
}
scoreadd+=30;
moves+=1;
}

}

}
};

////////////////////////////////////////////////clss for swaping gems
class Swap
{
protected:
public:
void swap(int (&array)[64],int &ind1, int &ind2,int &x1,int &y1,int &x2,int &y2)
{
int temp;
//---------------generic code from up to down 
if(array[ind1]==array[ind2+8]&&array[ind1]==array[ind2+16]&&array[ind1]==array[ind2+24]&&array[ind2]==array[ind1+32]&&array[ind1]==array[ind2+40]&&array[ind2]==array[ind1+48])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"upper se nechay called"<<endl;

}
else if(array[ind1]==array[ind2+8]&&array[ind1]==array[ind2+16]&&array[ind1]==array[ind2+24]&&array[ind1]==array[ind2+32]&&array[ind1]==array[ind2+40])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"upper se nechay called"<<endl;

}
else if(array[ind1]==array[ind2+8]&&array[ind1]==array[ind2+16]&&array[ind1]==array[ind2+24]&&array[ind1]==array[ind2+32])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"upper se nechay called"<<endl;

}
else if(array[ind1]==array[ind2+8]&&array[ind1]==array[ind2+16]&&array[ind1]==array[ind2+24])
{temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"upper se nechay called"<<endl;

}
else if(array[ind1]==array[ind2+8]&&array[ind1]==array[ind2+16])
{

temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"upper se nechay called"<<endl;

}
//-----------------generic code from down to upward
else if(array[ind1]==array[ind2-8]&&array[ind1]==array[ind2-16]&&array[ind1]==array[ind2-24]&&array[ind1]==array[ind2-32]&&array[ind1]==array[ind2-40]&&array[ind1]==array[ind2-48])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"down to up called"<<endl;

}
else if(array[ind1]==array[ind2-8]&&array[ind1]==array[ind2-16]&&array[ind1]==array[ind2-24]&&array[ind1]==array[ind2-32]&&array[ind2]==array[ind1-40])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"down to up called"<<endl;

}
else if(array[ind1]==array[ind2-8]&&array[ind1]==array[ind2-16]&&array[ind1]==array[ind2-24]&&array[ind1]==array[ind2-32])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"down to up called"<<endl;

}

else if(array[ind1]==array[ind2-8]&&array[ind1]==array[ind2-16]&&array[ind1]==array[ind2-24])
{temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"down to up called"<<endl;

}
else if(array[ind1]==array[ind2-8]&&array[ind1]==array[ind2-16])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"down to up called"<<endl;

}
//---------------Generic code from left to right 
else if(array[ind1]==array[ind2+1]&&array[ind1]==array[ind2+2]&&array[ind1]==array[ind2+3]&&array[ind1]==array[ind2+4]&&array[ind1]==array[ind2+5]&&array[ind1]==array[ind2+6])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"left to right called"<<endl;

}
else if(array[ind1]==array[ind2+1]&&array[ind1]==array[ind2+2]&&array[ind1]==array[ind2+3]&&array[ind1]==array[ind2+4]&&array[ind1]==array[ind2+5])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"left to right called"<<endl;

}
else if(array[ind1]==array[ind2+1]&&array[ind1]==array[ind2+2]&&array[ind1]==array[ind2+3]&&array[ind1]==array[ind2+4])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"left to right called"<<endl;

}
else if(array[ind1]==array[ind2+1]&&array[ind1]==array[ind2+2]&&array[ind1]==array[ind2+3])
{temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"left to right called"<<endl;

}
else if(array[ind1]==array[ind2+1]&&array[ind1]==array[ind2+2])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"left to right called"<<endl;

}


//--------------Generic code for right to left 
else if(array[ind1]==array[ind2-1]&&array[ind1]==array[ind2-2]&&array[ind1]==array[ind2-3]&&array[ind1]==array[ind2-4]&&array[ind1]==array[ind2-5]&&array[ind1]==array[ind2-6])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"right to left called"<<endl;

}
else if(array[ind1]==array[ind2-1]&&array[ind1]==array[ind2-2]&&array[ind1]==array[ind2-3]&&array[ind1]==array[ind2-4]&&array[ind1]==array[ind2-5])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"right to left called"<<endl;

}
else if(array[ind1]==array[ind2-1]&&array[ind1]==array[ind2-2]&&array[ind1]==array[ind2-3]&&array[ind1]==array[ind2-4])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"right to left called"<<endl;

}
else if(array[ind1]==array[ind2-1]&&array[ind1]==array[ind2-2]&&array[ind1]==array[ind2-3])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"right to left called"<<endl;

}
else if(array[ind1]==array[ind2-1]&&array[ind1]==array[ind2-2])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"right to left called"<<endl;

}


//Generic code implementation   down-right

else if(array[ind1+8]==array[ind1+1]&&array[ind1+8]==array[ind1+2])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"down-right called"<<endl;

}

//Generic code implementation   down-left
else if(array[ind1+8]==array[ind1-1]&&array[ind1+8]==array[ind1-2])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"down-left called"<<endl;

}
//Generic code implementation   up-RIGHT
else if(array[ind1-8]==array[ind1+1]&&array[ind1-8]==array[ind1+2])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"up-RIGHT called"<<endl;

}
//Generic code implementation   up-LEFT
else if(array[ind1-8]==array[ind1-1]&&array[ind1-8]==array[ind1-2])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"up-LEFT called"<<endl;

}
//Generic code for the right-down
else if(array[ind1-1]==array[ind1+8]&&array[ind1-1]==array[ind1+16])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"right-down called"<<endl;

}
//Generic code for the right-up
else if(array[ind1-1]==array[ind1-8]&&array[ind1-1]==array[ind1-16])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"right-up called"<<endl;

}
//Generic code for the left-down
else if(array[ind1+1]==array[ind1+8]&&array[ind1+1]==array[ind1+16])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"left-down called"<<endl;

}

//Generic code for the left-up
else if(array[ind1+1]==array[ind1-8]&&array[ind1+1]==array[ind1-16])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"left-up called"<<endl;

}

//Generic code for       up
//                       |
//Generic code for left----right
//                       |
//Generic code for     down
else if(array[ind1-1]==array[ind1+8]&&array[ind1-1]==array[ind1-8])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"left  'down and up' called"<<endl;

}
else if(array[ind1+1]==array[ind1+8]&&array[ind1+1]==array[ind1-8])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"right 'down and up' called"<<endl;

}
else if(array[ind1+8]==array[ind1-1]&&array[ind1+8]==array[ind1+1])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"down-left and right called"<<endl;

}
else if(array[ind1-8]==array[ind1-1]&&array[ind1-8]==array[ind1+1])
{
temp=array[ind1];
array[ind1]=array[ind2];
array[ind2]=temp;
cout<<"up left and right called"<<endl;
}

/*
cout<<"array[ind1]   "<<array[ind1]<<endl;
cout<<"array[ind2]   "<<array[ind2]<<endl;
cout<<"array[ind2+1] "<<array[ind2+1]<<endl;
cout<<"array[ind2+2] "<<array[ind2+2]<<endl;*/
temp=0;
x2=0;
y2=0;

}
};
class Timer
{
protected:

public:
void printtime(int count)
{
int add=count*6; 

if(count>0)
{
Torus2d(510,700,90,add,30,10,35,colors[PURPLE]);
Torus2d(510,700,90,add,32,10,35,colors[DEEP_PINK]);
}
Torus2d(510,700,90,360,0,30,35,colors[OLD_LACE]);
DrawString( 500, 690, Num2Str(count), colors[BLACK]);

DrawString( 730, 550, "C", colors[PLUM]);
DrawString( 750, 545, "O", colors[PLUM]);
DrawString( 770, 540, "M", colors[PLUM]);
DrawString( 790, 535, "M", colors[PLUM]);
DrawString( 810, 530, "E", colors[PLUM]);
DrawString( 830, 525, "N", colors[PLUM]);
DrawString( 850, 520, "T", colors[PLUM]);

if(count==0)
{
DrawString( 770, 450, "GAME OVER", colors[MOCCASIN]);
}


}

};
class Scored
{
public:
void printscore(int &scorestore)
{
string s;
s+=Num2Str(scorestore);
DrawString( 150, 530, "Score", colors[PLUM]);
DrawString( 165, 490, s, colors[PLUM]);
}
};
class ProgressBar
{protected: 
int num;

public:
ProgressBar()
{

num=0;
}
void printProgressBar(int &score_storedalready,int &clock,int &level,int &progress,int &moves,int &life)
{
       DrawRoundRect(110,20,800,10,colors[ORANGE_RED],5);
       DrawRoundRect(110,0,800,10,colors[ORANGE_RED],5);
       
        progress=score_storedalready;
       if(progress<=800)
       {     
       DrawRoundRect(110,10,progress,10,colors[BLUE],10); 
       }   
        if((progress==800&&clock!=0)||(progress>800&&clock!=0))
       {
       level++;
       score_storedalready=0;
       clock=60;    
       DrawString( 770, 450, "LEVEL DONE", colors[MOCCASIN]);    
       }
        if((progress!=800&&clock==0))
       {
       score_storedalready=0;
       clock=60;    
       life--;
       DrawString( 770, 450, "LEVEL DONE", colors[MOCCASIN]);    
       }
       if(life==0)
       {
       life=3;
       moves=0;
       score_storedalready=0;
       clock=60;   
        DrawString( 770, 450, "YOU LOSE", colors[MOCCASIN]); 
       }
       DrawString( 600, 170, "LEVEL", colors[MOCCASIN]);      
       DrawString( 680, 170, Num2Str(level), colors[BLUE]); 
       DrawString( 600, 120, "life", colors[MOCCASIN]);      
       DrawString( 680, 120, Num2Str(life), colors[BLUE]);       
       DrawString( 305, 170, "MOVES", colors[MOCCASIN]);
       DrawString( 393, 170,Num2Str(moves), colors[BLUE]);    
}
};
class Main
{

public:
void DrwMainMenu(int &loading,string s)
{

  bool check=true;
     if(loading<=300)
     {
     DrawRoundRect(365,250,loading,15,colors[DODGER_BLUE],2);     
     DrawRoundRect(365,253,loading,10,colors[BLUE],2);     
     }
     else
     {check=false;}
     
     if(check==false)
     {
     DrawRoundRect(0,0,340,840,colors[ORANGE_RED],5);
     DrawRoundRect(340,0,340,840,colors[DARK_RED],5);
     DrawRoundRect(680,0,340,840,colors[TOMATO],5);  
     DrawRoundRect(400,480,200,75,colors[LIGHT_CORAL],5);
     DrawRoundRect(400,480,200,37,colors[CORAL],5);  
     DrawString( 403, 700, "BEJWELED GAME", colors[BLUE]); 
     DrawString( 405, 520, "PLAYER NAME", colors[BLUE]);     
     DrawString( 405, 490, s, colors[MOCCASIN]);  
     DrawCircle(490,350,25,colors[PALE_GOLDEN_ROD]);
     DrawCircle(490,350,30,colors[OLIVE]);
     DrawCircle(490,350,20,colors[KHAKI]); 
  }
  }
 void DrwGameMenu()
 {
 Torus2d(850,260,90,360,220,100,11,colors[RED]);
 Torus2d(850,260,90,360,0,230,11,colors[BLACK]);
 Torus2d(850,260,90,360,220,10,11,colors[WHITE]);	
 Torus2d(850,260,90,360,250,10,11,colors[WHITE]);
 Torus2d(850,260,90,360,280,10,11,colors[WHITE]);
 Torus2d(850,260,90,360,320,10,11,colors[WHITE]);
 DrawRoundRect(790,370,120,40,colors[ORANGE_RED],5);
 for(int i=300;i>=100;i-=50)
  {
  DrawRoundRect(750,i,200,40,colors[ORANGE_RED],5);
  }
 DrawString( 798, 380, "OPTIONS", colors[BLUE]);
 DrawString( 760, 310, "NEW GAME", colors[BLUE]);
 DrawString( 760, 260, "RESUME", colors[BLUE]);
 DrawString( 760, 210, "SCORE", colors[BLUE]);
 DrawString( 760, 160, "CONTROLS", colors[BLUE]);
 DrawString( 760, 110, "BACK", colors[BLUE]); 
 }
 void DrawGameinstruction()
 {
  Torus2d(520,260,90,360,500,100,11,colors[RED]);
  Torus2d(520,260,90,360,0,400,11,colors[BLACK]);
  for(int i=390;i<=480;i+=30)
  {
  Torus2d(520,260,90,360,i,10,11,colors[WHITE]);
  }	
  Torus2d(520,260,90,360,600,10,11,colors[BLACK]);
  DrawRoundRect(440,530,190,60,colors[ORANGE_RED],5);
  for(int i=470;i>=60;i-=50)
  {
  DrawRoundRect(280,i,500,50,colors[ORANGE_RED],5);
  }
  DrawRoundRect(490,10,70,40,colors[ORANGE_RED],5);
  DrawString( 448, 550, "INSTRUCTIONS", colors[BLUE]);
  DrawString( 280, 475, "1-PRESS MOUSE BUTTON AND DRAG IT TO", colors[BLUE]);
  DrawString( 280, 425, "SWAP GEMS.", colors[BLUE]);
  DrawString( 280, 375, "2-ALWAYS MAKE THE PAIR OF THREE OR ", colors[GREEN]);
  DrawString( 280, 325, "MORE GEMS.", colors[GREEN]);
  DrawString( 280, 275, "3-PRESS 'P' TO PAUSE GAME AND 'ESC'TO", colors[INDIGO]);
  DrawString( 280, 225, "EXIT GAME", colors[INDIGO]);
  DrawString( 280, 175, "4-PRESS HINT BUTTON TO SHOW FORMED ", colors[CHART_REUSE]);
  DrawString( 280, 125, "PAIR", colors[CHART_REUSE]);
  DrawString( 495, 16, "BACK ", colors[SKY_BLUE]);
 }
 void DrawScore()
 {
 Torus2d(520,260,90,360,500,100,11,colors[SALMON]);
 Torus2d(520,260,90,360,0,400,11,colors[BLACK]);
 for(int i=390;i<=480;i+=30)
  {
   Torus2d(520,260,90,360,i,10,11,colors[FIREBRICK]);
  }	
 Torus2d(520,260,90,360,600,10,11,colors[BLACK]);
 DrawString( 495, 16, "BACK ", colors[SKY_BLUE]);
 } 
};

class Range
{

public:

void SetRange(int &x,int &y,int &wine1,int &wine2,int &wine3,int &wine4,int (&array1)[64],int (&array3)[64])
{
if((x>=300&&x<350)&&(y>=206&&y<246))
{
 wine1=array1[0];
 wine2=array3[0];
}
else if((x>=350&&x<400)&&(y>=206&&y<246))
{
 wine1=array1[1];
 wine2=array3[1];
}
else if((x>=400&&x<450)&&(y>=206&&y<246))
{
 wine1=array1[2];
 wine2=array3[2];
}     
else if((x>=450&&x<500)&&(y>=206&&y<246))
{
 wine1=array1[3];
 wine2=array3[3];
}
else if((x>=500&&x<550)&&(y>=206&&y<246))
{
 wine1=array1[4];
 wine2=array3[4];
}
else if((x>=550&&x<600)&&(y>=206&&y<246))
{
 wine1=array1[5];
 wine2=array3[5];
}
else if((x>=600&&x<650)&&(y>=206&&y<246))
{
 wine1=array1[6];
 wine2=array3[6];
}
else if((x>=650&&x<700)&&(y>=206&&y<246))
{
 wine1=array1[7];
 wine2=array3[7];
}

                        //-----------2row
else  if((x>=300&&x<350)&&(y>=246&&y<289))
{
 wine1=array1[8];
 wine2=array3[8];
}
else if((x>=350&&x<400)&&(y>=246&&y<289))
{
 wine1=array1[9];
 wine2=array3[9];
}
else if((x>=400&&x<450)&&(y>=246&&y<289))
{
 wine1=array1[10];
 wine2=array3[10];
}     
else if((x>=450&&x<500)&&(y>=246&&y<289))
{
 wine1=array1[11];
 wine2=array3[11];
}
else if((x>=500&&x<550)&&(y>=246&&y<289))
{
 wine1=array1[12];
 wine2=array3[12];
}
else if((x>=550&&x<600)&&(y>=246&&y<289))
{
 wine1=array1[13];
 wine2=array3[13];
}
else if((x>=600&&x<650)&&(y>=246&&y<289))
{
 wine1=array1[14];
 wine2=array3[14];
}
else if((x>=650&&x<700)&&(y>=246&&y<289))
{
 wine1=array1[15];
 wine2=array3[15];
}
                             //---------------row3
else if((x>=300&&x<350)&&(y>=289&&y<332))
{
 wine1=array1[16];
 wine2=array3[16];
}
else if((x>=350&&x<400)&&(y>=289&&y<332))
{
 wine1=array1[17];
 wine2=array3[17];
}
else if((x>=400&&x<450)&&(y>=289&&y<332))
{
 wine1=array1[18];
 wine2=array3[18];
}     
else if((x>=450&&x<500)&&(y>=289&&y<332))
{
 wine1=array1[19];
 wine2=array3[19];
}
else if((x>=500&&x<550)&&(y>=289&&y<332))
{
 wine1=array1[20];
 wine2=array3[20];
}
else if((x>=550&&x<600)&&(y>=289&&y<332))
{
 wine1=array1[21];
 wine2=array3[21];
}
else if((x>=600&&x<650)&&(y>=289&&y<332))
{
 wine1=array1[22];
 wine2=array3[22];
}
else if((x>=650&&x<700)&&(y>=289&&y<332))
{
 wine1=array1[23];
 wine2=array3[23];
}
                   //------------row4

else if((x>=300&&x<350)&&(y>=332&&y<373))
{
 wine1=array1[24];
 wine2=array3[24];
}
else if((x>=350&&x<400)&&(y>=332&&y<373))
{
 wine1=array1[25];
 wine2=array3[25];
}
else if((x>=400&&x<450)&&(y>=332&&y<373))
{
 wine1=array1[26];
 wine2=array3[26];
}     
else if((x>=450&&x<500)&&(y>=332&&y<373))
{
 wine1=array1[27];
 wine2=array3[27];
}
else if((x>=500&&x<550)&&(y>=332&&y<373))
{
 wine1=array1[28];
 wine2=array3[28];
}
else if((x>=550&&x<600)&&(y>=332&&y<373))
{
 wine1=array1[29];
 wine2=array3[29];
}
else if((x>=600&&x<650)&&(y>=332&&y<373))
{
 wine1=array1[30];
 wine2=array3[30];
}
else if((x>=650&&x<700)&&(y>=332&&y<373))
{
 wine1=array1[31];
 wine2=array3[31];
}         
                                     //----------row5
else if((x>=300&&x<350)&&(y>=373&&y<415))
{
 wine1=array1[32];
 wine2=array3[32];
}
else if((x>=350&&x<400)&&(y>=373&&y<415))
{
 wine1=array1[33];
 wine2=array3[33];
}
else if((x>=400&&x<450)&&(y>=373&&y<415))
{
 wine1=array1[34];
 wine2=array3[34];
}     
else if((x>=450&&x<500)&&(y>=373&&y<415))
{
 wine1=array1[35];
 wine2=array3[35];
}
else if((x>=500&&x<550)&&(y>=373&&y<415))
{
 wine1=array1[36];
 wine2=array3[36];
}
else if((x>=550&&x<600)&&(y>=373&&y<415))
{
 wine1=array1[37];
 wine2=array3[37];
}
else if((x>=600&&x<650)&&(y>=373&&y<415))
{
 wine1=array1[38];
 wine2=array3[38];
}
else if((x>=650&&x<700)&&(y>=373&&y<415))
{
 wine1=array1[39];
 wine2=array3[39];
}                                     

                         //----------------row6
else if((x>=30&&x<350)&&(y>=415&&y<458))
{
 wine1=array1[40];
 wine2=array3[40];
}
else if((x>=350&&x<400)&&(y>=415&&y<458))
{
 wine1=array1[41];
 wine2=array3[41];
}
else if((x>=400&&x<450)&&(y>=415&&y<458))
{
 wine1=array1[42];
 wine2=array3[42];
}     
else if((x>=450&&x<500)&&(y>=415&&y<458))
{
 wine1=array1[43];
 wine2=array3[43];
}
else if((x>=500&&x<550)&&(y>=415&&y<458))
{
 wine1=array1[44];
 wine2=array3[44];
}
else if((x>=550&&x<600)&&(y>=415&&y<458))
{
 wine1=array1[45];
 wine2=array3[45];
}
else if((x>=600&&x<650)&&(y>=415&&y<458))
{
 wine1=array1[46];
 wine2=array3[46];
}
else if((x>=650&&x<700)&&(y>=415&&y<458))
{
 wine1=array1[47];
 wine2=array3[47];
}                                     
                 //--------------row7
else if((x>=300&&x<350)&&(y>=458&&y<501))
{
 wine1=array1[48];
 wine2=array3[48];
}
else if((x>=350&&x<400)&&(y>=458&&y<501))
{
 wine1=array1[49];
 wine2=array3[49];
}
else if((x>=400&&x<450)&&(y>=458&&y<501))
{
 wine1=array1[50];
 wine2=array3[50];
}     
else if((x>=450&&x<500)&&(y>=458&&y<501))
{
 wine1=array1[51];
 wine2=array3[51];
}
else if((x>=500&&x<550)&&(y>=458&&y<501))
{
 wine1=array1[52];
 wine2=array3[52];
}
else if((x>=550&&x<600)&&(y>=458&&y<501))
{
 wine1=array1[53];
 wine2=array3[53];
}
else if((x>=600&&x<650)&&(y>=458&&y<501))
{
 wine1=array1[54];
 wine2=array3[54];
}
else if((x>=650&&x<700)&&(y>=458&&y<501))
{
 wine1=array1[55];
 wine2=array3[55];
}                 
                  //---------------row8

else if((x>=300&&x<350)&&(y>=501&&y<542))
{
 wine1=array1[56];
 wine2=array3[56];
}
else if((x>=350&&x<400)&&(y>=501&&y<542))
{
 wine1=array1[57];
 wine2=array3[57];
}
else if((x>=400&&x<450)&&(y>=501&&y<542))
{
 wine1=array1[58];
 wine2=array3[58];
}     
else if((x>=450&&x<500)&&(y>=501&&y<542))
{
 wine1=array1[59];
 wine2=array3[59];
}
else if((x>=500&&x<550)&&(y>=501&&y<542))
{
 wine1=array1[60];
 wine2=array3[60];
}
else if((x>=550&&x<600)&&(y>=501&&y<542))
{
 wine1=array1[61];
 wine2=array3[61];
}
else if((x>=600&&x<650)&&(y>=501&&y<542))
{
 wine1=array1[62];
 wine2=array3[62];
}
else if((x>=650&&x<700)&&(y>=501&&y<542))
{
 wine1=array1[63];
 wine2=array3[63];
}                                                   
 
                                              
if(wine3==0&&wine4==0)
{
wine3=wine1;
wine4=wine2;
}
}
};

//                               **************************************************************     
//                                                 Max Score
//                               **************************************************************  
class Scoring
{
public:

   void calculate(int &s)
   {
         	
	ofstream outputFile;	
	outputFile.open("maxacore.txt");
	outputFile<<s<<endl;	
	outputFile.close();
  
  
       
     
    }
    
    void read()
    {
        int in;
	ifstream inputFile;
	inputFile.open("maxacore.txt");
	cout<<"scorestored is "<<endl;
        inputFile>>in;
        DrawRoundRect(440,530,190,60,colors[ORANGE_RED],5);
        DrawRoundRect(300,400,190,60,colors[ORANGE_RED],5);
        DrawRoundRect(300,300,190,60,colors[ORANGE_RED],5);
        DrawRoundRect(300,200,190,60,colors[ORANGE_RED],5);
        DrawRoundRect(300,100,190,60,colors[ORANGE_RED],5);
        DrawString(460,550,"MAX_SCORE", colors[DARK_CYAN]);        
       
        DrawString( 305, 410,"1-", colors[DARK_CYAN]);
        DrawString( 305, 310,"2-", colors[DARK_CYAN]);
        DrawString( 305, 210,"3-", colors[DARK_CYAN]);
        DrawString( 305, 110,"4-", colors[DARK_CYAN]);
        
        DrawString( 340, 410,Num2Str(in), colors[CHART_REUSE]);
        int s=0;
        DrawString( 340, 310,Num2Str(s), colors[CHART_REUSE]);
        DrawString( 340, 210,Num2Str(s), colors[CHART_REUSE]);
        DrawString( 340, 110,Num2Str(s), colors[CHART_REUSE]);
        
        
        inputFile.close();
        
        }	
};


