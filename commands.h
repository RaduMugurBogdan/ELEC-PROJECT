#include<iostream>
using namespace std;
extern int global_x;
extern int global_y;

struct coord_options{
	int x1, y1;
	int x2, y2;
};
int global_stage=1;
struct coord_options draw_option;
struct coord_options connect_option;
struct coord_options delete_option;
struct coord_options move_option;
void fix_text(int x1,int y1,int x2,int y2,char*name);
struct coord_options coord_h_connect;
struct coord_options coord_v_connect;
extern short curent_connection_orientation; 
//------------------------------------------------------
//functii butoane optiuni
//functia buton draw
void coord_draw_option(int x1,int y1,int x2,int y2){
	draw_option.x1=x1;
	draw_option.y1=y1;
	draw_option.x2=x2;
	draw_option.y2=y2;
}
void desenare_draw_option(){
	setfillstyle(INTERLEAVE_FILL,WHITE);
	setcolor(YELLOW);
	bar(draw_option.x1,draw_option.y1,draw_option.x2,draw_option.y2);
	fix_text(draw_option.x1,draw_option.y1,draw_option.x2,draw_option.y2,"DRAW");
}
void buton_click_draw_option(){
	setfillstyle(INTERLEAVE_FILL,BLUE);
	setcolor(WHITE);
	bar(draw_option.x1,draw_option.y1,draw_option.x2,draw_option.y2);
	fix_text(draw_option.x1,draw_option.y1,draw_option.x2,draw_option.y2,"DRAW");
}

//functie buton conectare

void coord_connect_option(int x1,int y1,int x2,int y2){
	connect_option.x1=x1;
	connect_option.y1=y1;
	connect_option.x2=x2;
	connect_option.y2=y2;
} 
void desenare_connect_option(){
	setfillstyle(INTERLEAVE_FILL,WHITE);
	setcolor(YELLOW);
	bar(connect_option.x1,connect_option.y1,connect_option.x2,connect_option.y2);
	fix_text(connect_option.x1,connect_option.y1,connect_option.x2,connect_option.y2,"CONNECT");
}
void buton_click_connect_option(){
	setfillstyle(INTERLEAVE_FILL,BLUE);
	setcolor(WHITE);
	bar(connect_option.x1,connect_option.y1,connect_option.x2,connect_option.y2);
	fix_text(connect_option.x1,connect_option.y1,connect_option.x2,connect_option.y2,"CONNECT");
}
//functie desenare buton de stergere

void coord_delete_option(int x1,int y1,int x2,int y2){
	delete_option.x1=x1;
	delete_option.y1=y1;
	delete_option.x2=x2;
	delete_option.y2=y2;
} 
void desenare_delete_option(){
	setfillstyle(INTERLEAVE_FILL,WHITE);
	setcolor(YELLOW);
	bar(delete_option.x1,delete_option.y1,delete_option.x2,delete_option.y2);
	fix_text(delete_option.x1,delete_option.y1,delete_option.x2,delete_option.y2,"DELETE");
}
void buton_click_delete_option(){
	setfillstyle(INTERLEAVE_FILL,BLUE);
	setcolor(WHITE);
	bar(delete_option.x1,delete_option.y1,delete_option.x2,delete_option.y2);
	fix_text(delete_option.x1,delete_option.y1,delete_option.x2,delete_option.y2,"DELETE");
}

//functii buton de mutare

void coord_move_option(int x1,int y1,int x2,int y2){
	move_option.x1=x1;
	move_option.y1=y1;
	move_option.x2=x2;
	move_option.y2=y2;
} 
void desenare_move_option(){
	setfillstyle(INTERLEAVE_FILL,WHITE);
	setcolor(YELLOW);
	bar(move_option.x1,move_option.y1,move_option.x2,move_option.y2);
	fix_text(move_option.x1,move_option.y1,move_option.x2,move_option.y2,"MOVE");
}

void buton_click_move_option(){
	setfillstyle(INTERLEAVE_FILL,BLUE);
	setcolor(WHITE);
	bar(move_option.x1,move_option.y1,move_option.x2,move_option.y2);
	fix_text(move_option.x1,move_option.y1,move_option.x2,move_option.y2,"MOVE");
}

//functii buton conector vertical
void coord_buton_v_connector(int x1,int y1,int x2,int y2){
	coord_v_connect.x1=x1;
	coord_v_connect.y1=y1;
	coord_v_connect.x2=x2;
	coord_v_connect.y2=y2;
}
void desenare_buton_v_connector(){
		setfillstyle(INTERLEAVE_FILL,WHITE);
		setcolor(YELLOW);
		bar(coord_v_connect.x1,coord_v_connect.y1,coord_v_connect.x2,coord_v_connect.y2);
		fix_text(coord_v_connect.x1,coord_v_connect.y1,coord_v_connect.x2,coord_v_connect.y2,"H_CONNECTOR");
}
void buton_click_v_connector(){
		setfillstyle(INTERLEAVE_FILL,BLUE);
		setcolor(WHITE);
		bar(coord_v_connect.x1,coord_v_connect.y1,coord_v_connect.x2,coord_v_connect.y2);
		fix_text(coord_v_connect.x1,coord_v_connect.y1,coord_v_connect.x2,coord_v_connect.y2,"H_CONNECTOR");				
}

//h_connector;

void coord_buton_h_connector(int x1,int y1,int x2,int y2){
	coord_h_connect.x1=x1;
	coord_h_connect.y1=y1;
	coord_h_connect.x2=x2;
	coord_h_connect.y2=y2;
}

void desenare_buton_h_connector(){
		setfillstyle(INTERLEAVE_FILL,WHITE);
		setcolor(YELLOW);
		bar(coord_h_connect.x1,coord_h_connect.y1,coord_h_connect.x2,coord_h_connect.y2);
		fix_text(coord_h_connect.x1,coord_h_connect.y1,coord_h_connect.x2,coord_h_connect.y2,"V_CONNECTOR");
}

void buton_click_h_connector(){
		setfillstyle(INTERLEAVE_FILL,BLUE);
		setcolor(WHITE);
		bar(coord_h_connect.x1,coord_h_connect.y1,coord_h_connect.x2,coord_h_connect.y2);
		fix_text(coord_h_connect.x1,coord_h_connect.y1,coord_h_connect.x2,coord_h_connect.y2,"V_CONNECTOR");				

 
}

 //functie pricipala , aici se stabileste operatiunea dorita
 void eval_options(int x,int y){
 	
 	if(x>=draw_option.x1&&x<=draw_option.x2&&y>=draw_option.y1&&y<=draw_option.y2){
 		global_stage=1;
 		buton_click_draw_option();
 		desenare_connect_option();
		desenare_delete_option();
		desenare_move_option();
	 }else if(x>=connect_option.x1&&x<=connect_option.x2&&y>=connect_option.y1&&y<=connect_option.y2){
	 	 global_stage=3;
		 buton_click_connect_option();
	 	 desenare_draw_option();
	 	 desenare_delete_option();
	 	 desenare_move_option();
	 }else if(x>=delete_option.x1&&x<=delete_option.x2&&y>=delete_option.y1&&y<=delete_option.y2){
	 		global_stage=2;
			buton_click_delete_option();
	 		desenare_draw_option();
	 		desenare_connect_option();
	 		desenare_move_option();
	 }else if(x>=move_option.x1&&x<=move_option.x2&&y>=move_option.y1&&y<=move_option.y2){
	 		global_stage=4;
			buton_click_move_option();
	 		desenare_delete_option();
	 		desenare_draw_option();
	 		desenare_connect_option(); 
	 }else if(x>=coord_h_connect.x1&&x<=coord_h_connect.x2&&y>=coord_h_connect.y1&&coord_h_connect.y2&&global_stage==3){
	 		curent_connection_orientation=0;
		 	buton_click_h_connector();
	 		desenare_buton_v_connector();
	 }else if(x>=coord_v_connect.x1&&x<=coord_v_connect.x2&&y>=coord_v_connect.y1&&coord_v_connect.y2&&global_stage==3){
	 		curent_connection_orientation=1;
			 buton_click_v_connector();
	 		desenare_buton_h_connector();
		
	 }
 	 	
 }
 


void draw_commands(){
	int x1,x2,y1,y2;
	int width=200+200/3+15;
	int height=15;
	int dist_x=5;
	int dist_y_up_and_down=3;
	int dist_y_inter=4;
	//desenarre label optiuni
	x1=global_x;
	y1=global_y+dist_y_up_and_down;
	x2=x1+width;
	y2=y1+height;
	setcolor(WHITE);
	setfillstyle(CLOSE_DOT_FILL, RED);
	bar(x1,y1,x2,y2);
	fix_text(x1,y1,x2,y2,"OPTIONS");
	//desenare butoane
	//buton DRAW
	int width_2=200/3; 
	y1=y2+dist_y_inter;
	y2=y1+35;
	x2=x1+width_2;
	coord_draw_option(x1,y1,x2,y2);
	buton_click_draw_option();	
	//buton DELETE
	x1=x2+dist_x;
	x2=x1+width_2;
	coord_delete_option(x1,y1,x2,y2);
	desenare_delete_option();
	//desenare connect
	x1=x2+dist_x;
	x2=x1+width_2;
	coord_connect_option(x1,y1,x2,y2);
	desenare_connect_option();
	//muutare 
	x1=x2+dist_x;
	x2=x1+width_2;
	coord_move_option(x1,y1,x2,y2);
	desenare_move_option();
	// label conectori
	width=200+dist_x;
	x1=x2+dist_x*2;
	y1=dist_y_up_and_down;
	x2=x1+width;
	y2=y1+height;
	setcolor(WHITE);
	setfillstyle(CLOSE_DOT_FILL, RED);
	bar(x1,y1,x2,y2);
	fix_text(x1,y1,x2,y2,"CONNECTORS");
	
	//buton conector orizontal
	
	y1=y2+dist_y_inter;
	y2=y1+35;	
	x1=x2-width;
	x2=x1+width/2-dist_x/2;
	coord_buton_h_connector(x1,y1,x2,y2);
	buton_click_h_connector();
//	desenare_buton_h_connector();
	//buton conector vertical
	x1=x2+dist_x/2;
	x2=x1+width/2;
	
	coord_buton_v_connector(x1,y1,x2,y2);
	desenare_buton_v_connector();
			
}




	


