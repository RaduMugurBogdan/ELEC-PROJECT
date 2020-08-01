#include"commands.h"
#include"butoane.h"
//aici se calculeaza cordonatele butoanelor si celorlalte compone

int global_x;
int global_y;
extern long long screen_width;

void desenare_meniu(){
	//inaltimea casetei este de 25 px;
	int width=100;
	int height=25;
	setcolor(YELLOW);
	//main container
	setfillstyle(XHATCH_FILL, RED);
	bar(0,0,screen_width,60);
	// stilul si dimensiunile butoanelor
	setfillstyle(INTERLEAVE_FILL,WHITE);
	int dist_x=5;
	int dist_y_up_and_down=3;
	int dist_y_inter=4;
	int x1,x2;
	int y1,y2;
	
	x1=dist_x;
	y1=dist_y_up_and_down;
	x2=width+dist_x;// intre componenete pe y sunt 2 px distanta
	y2=dist_y_up_and_down+height;//RATIA DE DISTANTIERE E DE 5 PX
	//buton rezistenta
	coord_buton_rezistenta(x1,y1,x2,y2);
	desenare_buton_rezistenta();
	//bar(x1,y1,x2,y2);
	//fix_text(x1,y1,x2,y2,"RESISTANCE");
	y1=y1+height+dist_y_inter;
	y2=y2+height+dist_y_inter;
	coord_buton_sursa(x1,y1,x2,y2);
	desenare_buton_sursa();	
  	//buton consumator
  	x1=x2+dist_x;
  	x2=x1+width;
  	y1=dist_y_up_and_down;
  	y2=y1+height;
  	coord_buton_consumator(x1,y1,x2,y2);
  	desenare_buton_consumator();
	//buton comutator
	y1=y1+height+dist_y_inter;
	y2=y2+height+dist_y_inter;
	coord_buton_comutator(x1,y1,x2,y2);
	desenare_buton_comutator();	
	//delimitataor 1
	setcolor(BLACK);
	for(int i=0;i<=5;i++){
		line(x2+5+i,0,x2+5+i,60);
	}
	
	
	//Label ORIENTATION
	setcolor(WHITE);
	x1=x2+10+dist_x;;
	y1=dist_y_up_and_down;;
	x2=x1+width*2;
	int height_2=15;
	y2=y1+height_2;
	setfillstyle( CLOSE_DOT_FILL, RED);
	bar(x1,y1,x2,y2);
	fix_text(x1,y1,x2,y2,"ORIENTATION");

	//buton_orientare orizontala
	int height_orient=35;
	y1=y2+dist_y_inter;
	y2=y1+height_orient;
	x2=x1+width-2;
	coord_buton_h_orient(x1,y1,x2,y2);
															//desenare_buton_h_orient();																								
	buton_click_h_orient();
	//button orientare _orizontala
	x1=x2+4;
	x2=x1+width-2;
	coord_buton_v_orient(x1,y1,x2,y2);		
	desenare_buton_v_orient();
	//presentation box
	x1=x2+5;
	y1=5;
	x2=50+x1;
	y2=y1+50;
	coord_caseta(x1,y1,x2,y2);
	desenare_caseta(0,0,0); 
	//desenare label stage
	x1=x2+5;
	y1=3;
	x2=x1+width*2;
	y2=y1+height_2;
	setcolor(WHITE);
	setfillstyle( CLOSE_DOT_FILL, RED);
	bar(x1,y1,x2,y2);
	fix_text(x1,y1,x2,y2,"BREAKER STAGE");
	//desenare buton inchidere
	height_orient=35;
	y1=y2+dist_y_inter;
	y2=y1+height_orient;
	x2=x1+width-2;	
	coord_buton_stage_closed(x1,y1,x2,y2);
	//desenare_buton_stage_closed();
	buton_click_stage_closed();
	//desenare buton deschidere
	x1=x2+4;
	x2=x1+width-2;
	coord_buton_stage_opened(x1,y1,x2,y2);
	desenare_buton_stage_opened();


	x1=x2;
	x1=x1+5;
	for(int i=0;i<5;i++){
		setcolor(BLACK);
		line(x1+i,0,x1+i,60);
	}
	global_x=x1+10;
	global_y=0;	
	draw_commands();	
}
//functia care coordoneaza operatiile facute de mouse
void mouse_listener(){
	while (true){
		int x;int y;
        getmouseclick(WM_LBUTTONDOWN, x, y);
		test_button(x,y);
		while(global_stage==4){
			if(ismouseclick(WM_LBUTTONDBLCLK)){
				getmouseclick(WM_LBUTTONDBLCLK, x, y);
				test_button(x,y);
			}else{
				getmouseclick(WM_LBUTTONDOWN, x, y);
				test_button(x,y);
				}
				delay(10);
		}
        delay(10);
    }
}






void style_bg(){
 	desenare_meniu();
	mouse_listener();


}
