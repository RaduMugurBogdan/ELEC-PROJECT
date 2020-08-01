#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<windows.h>
#include<string.h>
#include<iostream>
#include"RESISTANCE.h"
#include"SOURCE.h"
#include"CONSUMER.h"
#include"BREAKER.h"
#include"style_bg.h"

using namespace std;

long long screen_width;
long long screen_height;

//---------------------------------------------------------------------
/*
void lansare_sursa(){
  source_comp* source=new source_comp;
  source=create_source_comp(600,600,0);//pozitiile x,y si orientarea
  draw_source(source);
}

void lansare_rezistenta(){  	
  	resistance_comp*resistance=new resistance_comp;
  	resistance=create_resistance_comp(500,500,0);
	draw_resistance(resistance);
}

void lansare_consumator(){
	consumer_comp* consumer=new consumer_comp;
	consumer=create_consumer_comp(300,300,0);
	draw_consumer(consumer);
}
void lansare_comutator(){
	breaker_comp* breaker=new breaker_comp;
	breaker=create_breaker_comp(700,700,0,0);
	draw_breaker(breaker);
}
*/
int main(){
	int gd = DETECT, gm;
   	initgraph(&gd, &gm, "C:\\TC\\BGI");
   	screen_width = GetSystemMetrics(SM_CXSCREEN);//determinare lungime ecran
	screen_height = GetSystemMetrics(SM_CYSCREEN);//deterinare inaltime ecran 

	style_bg();	
  	getch();
   	closegraph();
	 return 0;
}

/*dimensiunea  obligatorie a unei componenete este 100X100 pixeli (impreuna cu conctorii atasati)*/




