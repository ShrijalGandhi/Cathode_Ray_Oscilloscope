#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#define pi 3.142


	void main()
	{
/*----------------------------------------------------------------------------------------------------------*/
	void initialize();
	void draw(int,int);
	void draw2(int,double,double);
     //	void draw3(int);		/*....Why it is commented is explained in function draw2()....*/
	void amplifier(int,int,int);
	void amplitude(int,double,int,int);
	void frequency(int,double,int,int);
	void plotgraph(int);
/*---------------------------------------------------------------------------------------------------------*/
	clrscr();
	int gd=DETECT,gm,color;
	int option,A,noise,gain,vsat,f1,f2;

	double f,theta,m;

	initialize();


/*---------------------------------------------------------------------------------------------------------------*/

	restart:
	{
		clrscr();

	cout<<"-------------------------------------MENU----------------------------------"<<"\n";
	cout<<"1. y=Asin(theta)"<<"\n";
	cout<<"2. y=Asin(wt)"<<"\n";
	cout<<"3. y=Asin(wt+theta)"<<"\n";
	cout<<"4. Effects of noise on a sine wave"<<"\n";
	cout<<"5. Amplifier"<<"\n";
	cout<<"6. Amplitude Modulation"<<"\n";
	cout<<"7. Frequency Modulation"<<"\n";
	cout<<"Enter your option"<<"\n";
	cin>>option;





		switch(option)
		{
			case 1:cout<<"Enter the value of A"<<"\n";
				cin>>A;
				break;

			case 2:cout<<"Enter the value of A,f respectively"<<"\n";
				cin>>A>>f;
				theta=0.0;
				break;

			case 3:cout<<"Enter value of A,f,theta respectively"<<"\n";
				cin>>A>>f>>theta;
				break;

			case 4:cout<<"Enter the value of A,noise"<<"\n";
				cin>>A>>noise;
				break;

			case 5:cout<<"Enter the value of input voltage,supply voltage,gain"<<"\n";
				cin>>A>>vsat>>gain;
				break;

			case 6:cout<<"Enter A,modulation index,carrier frequency,modulating frequency"<<"\n";
				cin>>A>>m>>f1>>f2;		
				break;

			case 7:cout<<"Enter A,modulation index,carrier frequency,modulating frequency"<<"\n";
				cin>>A>>m>>f1>>f2;		
				break;

			default:cout<<"Invalid option"<<"\n";
				goto restart;
		}
	}
/*-----------------------------------------DRAWING-----------------------------------------------------------------*/
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	 plotgraph(A);


 /*---------------------------PLOTTING OF THE GRAPH----------------------------*/


 /*-----------------------INTERSECTION POINT------------------------------*/

      //setcolor(10);
      //line(100,275,100,275);

 /*-------------------------FUNCTION CALL------------------------------------*/

		switch(option)
		{
			case 1:draw(A,0);
				break;

			case 2:draw2(A,f,theta);
				break;

			case 3:draw2(A,f,theta);
				break;

			case 4:draw(A,noise);
				break;
			
			case 5:amplifier(A,vsat,gain);
				break;

			case 6:amplitude(A,m,f1,f2);
				break;

			case 7:frequency(A,m,f1,f2);
				break;
		}
/*------------------------------------ENDING-------------------------------------*/

	getch();
	closegraph();

	cout<<"Do you want to continue.....If yes Press Y"<<"\n";
	char c;
	cin>>c;
	if(c=='Y'||c=='y')
	goto restart;

	cout<<"THANK YOU.......HAVE A NICE DAY"<<"\n";
       //getch();  /*if you want exit to be user controlled*/
	delay(2000);
	}

/*------------------------------------------OUTSIDE MAIN--------------------------------------------------*/

	void draw(int A,int noise)
	{
		double x=100;
		double y=275;
		double theta=0;

		void draw3(int);

					if(noise!=0)
					{
						draw3(A);  		/* Since in c function prototype(declaration)
									must reside int the function that calls it */
					}


		 for(x=100;x<=600;x+=pi/5)
		 {
		  y=275;
		  y-=A*sin(theta)+noise;
		  delay(10);
		  theta+=pi/180;
		  putpixel(x,y,10);
		 }
	}
/*------------------------------------------to generate original sine wave----------------------------------------*/
	void draw3(int A)
	{
	double x,y;
	double theta=0;

		setcolor(8);
	rectangle(50,50,600,150);

			for(y=50;y<150;y+=30)
			line(50,y,600,y);

			for(x=50;x<=600;x+=30)
			line(x,50,x,150);

			setcolor(7);

		line(100,50,100,150);
		line(50,100,600,100);

		line(50,100-A,600,100-A);
		line(50,100+A,600,100+A);

			for(x=100;x<=600;x+=pi/5)
			{
			y=100;
			y-=A*sin(theta);
			delay(10);
			theta+=pi/180;
			putpixel(x,y,10);
			}
	}
/*------------------------------------------------------------------------------------------------------------------*/
	void draw2(int A,double f,double theta)
	{

		double x=100;
		double y=275;

		double w;

		w=2*pi*f;

		int sign;

		if(theta==0)
		sign=1;
		else
		sign=theta/theta;



		 for(x=0.0;x<=500;x+=0.1)
		 {
		  y=0;
		  y=A*sin(w*x*sign+(theta*pi/180));   /* since it is
							 sin(180+theta)
						      */
		  delay(3);
		  putpixel(x+100,275-y,10);
		 }


	}
/*-----------------------------------------INITIAL HOUSEKEEPING-----------------------------------------------*/
	void plotgraph(int A)
	{
	setcolor(8);

		int x,y;
			x=0;
			y=150;
/*-----------------X-AXIS-----------------*/

	for(y=150;y<=400;y+=30)
	line(50,y,600,y);

/*---------------Y-AXIS-------------------*/
	for(x=50;x<=600;x+=30)
	line(x,150,x,400);

	rectangle(50,150,600,400);

/*-----------REFERENCE AXES----------------*/

	/*
	   Includes the co ordinate axes
	   and the axes for marking the highest value of the wave ie Amplitude
	*/

	setcolor(7);
	line(100,150,100,400);
	line(50,275,600,275);


	line(50,275-A,600,275-A);
	line(50,275+A,600,275+A);

	}
/*------------------------------------------------------------------------------------------------------------*/
	void amplifier(int A,int vsat,int gain)
	{
		void draw3(int);

		double x,y,v;
		double theta=0;


		v=gain*A;

		draw3(A);

		for(x=100;x<=600;x+=pi/5)
		{
		y=0;
		y=v*sin(theta);

			if(y>vsat)
			{
			y=vsat;
			theta+=pi/180;
			putpixel(x,275-y,10);
			delay(3);
			continue;
			}
			else
				if(vsat*(-1)>y)
				{
					y=vsat;
					theta+=pi/180;
					putpixel(x,275+y,10);
					delay(3);
					continue;
				}
			else
			{
			delay(10);
			theta+=pi/180;
			putpixel(x,275-y,10);
			}


		}


	}
/*------------------------------------------Amplitude Modulation-------------------------------------------*/



	void amplitude(int A,double m,int f1,int f2)
	{
		double x,y,w1,w2,carrier,upper,lower,k;

		w1=2*pi*f1;
		w2=2*pi*f2;
		k=m*A/2;

		for(x=0.0;x<=500;x+=0.1)
		 {
		  y=0;
		  carrier=A*sin(w1*x);
		  lower=k*cos((w1-w2)*x);
		  upper=k*cos((w1+w2)*x);

		  y=carrier+lower-upper;
		  delay(3);
		  putpixel(x+100,275-y,10);
		 }




	}

	void frequency(int A,double m,int f1,int f2)
	{

		double x,y,w1,w2,term1,term2;

		w1=2*pi*f1;
		w2=2*pi*f2;

		for(x=0.0;x<=500;x+=0.1)
		 {
		  y=0;

		 term1=w1*x;
		 term2=m*sin(w2*x);

		y=A*sin(term1+term2);


		  delay(3);
		  putpixel(x+100,275-y,10);
		 }


	}

	void initialize()
	{
	 int gd=DETECT,gm;

		initgraph(&gd,&gm,"C:\\TC\\BGI");
		setcolor(WHITE);
		rectangle(50,50,600,450);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,0);
		outtextxy(300,50,"CRO");
		delay(1000);

		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		outtextxy(100,150,"Initializing");

			for(int i=1,x=200;i<=3;i++,x+=5)
			{
				outtextxy(x,150,".");
				delay(1000);
			}
	       outtextxy(100,175,"Loading graphics");

			for(i=1,x=275;i<=3;i++,x+=5)
			{
				outtextxy(x,175,".");
				delay(1500);
			}


		closegraph();
	}



