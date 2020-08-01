/**
AICI SUNT INCLUSE COMENZILE DE CREARA ALE PANOURILOR,BUTOANELOR DE SELECTIE  
+COMENZILE DE ACTUALIZARE A BUTOANELOR
*/
#include"lista_elemente.h"
#include"connect_comp.h"
#include"redesenare.h"
struct coord_buttons{
	int x1,y1;
	int x2,y2;
};
extern long long screen_width;
extern long long screen_height;

extern int global_stage;
struct coord_buttons coord_rezistenta;
struct coord_buttons coord_sursa;
struct coord_buttons coord_consumator;
struct coord_buttons coord_comutator;
struct coord_buttons coord_h_orient;
struct coord_buttons coord_v_orient;
struct coord_buttons coord_box;
struct coord_buttons coord_stage_closed;
struct coord_buttons coord_stage_opened;
short orientation_button=1;
short current_comp=0;
short current_stage=0;
short curent_connection_orientation=0;
					

//functia pune textul in interiorul butonului sau label-ului
void fix_text(int x1,int y1,int x2,int y2,char*name){
	int x_center;
	int y_center;
	int width=x2-x1;
	int height=y2-y1;
	int text_width=textwidth(name);
	int text_height=textheight(name);
	x_center=(width-text_width)/2+x1;
	y_center=(height-text_height)/2+y1;	
	outtextxy(x_center,y_center,name);	
}



//butoane  componenete
void coord_buton_rezistenta(int x1,int y1,int x2,int y2){
		coord_rezistenta.x1=x1;
		coord_rezistenta.y1=y1;
		coord_rezistenta.x2=x2;
		coord_rezistenta.y2=y2;
}

void coord_buton_consumator(int x1,int y1,int x2,int y2){
		coord_consumator.x1=x1;
		coord_consumator.y1=y1;
		coord_consumator.x2=x2;
		coord_consumator.y2=y2;
}

void coord_buton_sursa(int x1,int y1,int x2,int y2){
		coord_sursa.x1=x1;
		coord_sursa.y1=y1;
		coord_sursa.x2=x2;
		coord_sursa.y2=y2;
}

void coord_buton_comutator(int x1,int y1,int x2,int y2){
		coord_comutator.x1=x1;
		coord_comutator.y1=y1;
		coord_comutator.x2=x2;
		coord_comutator.y2=y2;
}

//-----------------------------------------------------------------
//desenare componenete
void desenare_buton_rezistenta(){
	setfillstyle(INTERLEAVE_FILL,WHITE);
	setcolor(YELLOW);
	bar(coord_rezistenta.x1,coord_rezistenta.y1,coord_rezistenta.x2,coord_rezistenta.y2);
	fix_text(coord_rezistenta.x1,coord_rezistenta.y1,coord_rezistenta.x2,coord_rezistenta.y2,"RESISTANCE");
}
void buton_click_rezistenta(){
	setfillstyle(INTERLEAVE_FILL,BLUE);
	setcolor(WHITE);
	bar(coord_rezistenta.x1,coord_rezistenta.y1,coord_rezistenta.x2,coord_rezistenta.y2);
	fix_text(coord_rezistenta.x1,coord_rezistenta.y1,coord_rezistenta.x2,coord_rezistenta.y2,"RESISTANCE");
}
void desenare_buton_sursa(){
	setfillstyle(INTERLEAVE_FILL,WHITE);
	setcolor(YELLOW);
	bar(coord_sursa.x1,coord_sursa.y1,coord_sursa.x2,coord_sursa.y2);
	fix_text(coord_sursa.x1,coord_sursa.y1,coord_sursa.x2,coord_sursa.y2,"SOURCE");	
}
void buton_click_sursa(){
	setfillstyle(INTERLEAVE_FILL,BLUE);
	setcolor(WHITE);
	bar(coord_sursa.x1,coord_sursa.y1,coord_sursa.x2,coord_sursa.y2);
	fix_text(coord_sursa.x1,coord_sursa.y1,coord_sursa.x2,coord_sursa.y2,"SOURCE");	
}
void desenare_buton_consumator(){
	setfillstyle(INTERLEAVE_FILL,WHITE);
	setcolor(YELLOW);
	bar(coord_consumator.x1,coord_consumator.y1,coord_consumator.x2,coord_consumator.y2);
	fix_text(coord_consumator.x1,coord_consumator.y1,coord_consumator.x2,coord_consumator.y2,"CONSUMER");	
}
void buton_click_consumator(){
	setfillstyle(INTERLEAVE_FILL,BLUE);
	setcolor(WHITE);
	bar(coord_consumator.x1,coord_consumator.y1,coord_consumator.x2,coord_consumator.y2);
	fix_text(coord_consumator.x1,coord_consumator.y1,coord_consumator.x2,coord_consumator.y2,"CONSUMER");
}
void desenare_buton_comutator(){
	setfillstyle(INTERLEAVE_FILL,WHITE);
	setcolor(YELLOW);
	bar(coord_comutator.x1,coord_comutator.y1,coord_comutator.x2,coord_comutator.y2);
	fix_text(coord_comutator.x1,coord_comutator.y1,coord_comutator.x2,coord_comutator.y2,"BREAKER");
}
void buton_click_comutator(){
	setfillstyle(INTERLEAVE_FILL,BLUE);
	setcolor(WHITE);
	bar(coord_comutator.x1,coord_comutator.y1,coord_comutator.x2,coord_comutator.y2);
	fix_text(coord_comutator.x1,coord_comutator.y1,coord_comutator.x2,coord_comutator.y2,"BREAKER");
}
//---------------------------------------------------------------------------------------------------
//desenare butoan orinetare

void coord_buton_h_orient(int x1,int y1,int x2,int y2){
	coord_h_orient.x1=x1;
	coord_h_orient.y1=y1;
	coord_h_orient.x2=x2;
	coord_h_orient.y2=y2;	
}

void coord_buton_v_orient(int x1,int y1,int x2,int y2){
	coord_v_orient.x1=x1;
	coord_v_orient.y1=y1;
	coord_v_orient.x2=x2;
	coord_v_orient.y2=y2;
}

void desenare_buton_h_orient(){
		setfillstyle(INTERLEAVE_FILL,WHITE);
		setcolor(YELLOW);
		bar(coord_h_orient.x1,coord_h_orient.y1,coord_h_orient.x2,coord_h_orient.y2);
		fix_text(coord_h_orient.x1,coord_h_orient.y1,coord_h_orient.x2,coord_h_orient.y2,"H_ORIENT");
}
void buton_click_h_orient(){
		setfillstyle(INTERLEAVE_FILL,BLUE);
		setcolor(WHITE);
		bar(coord_h_orient.x1,coord_h_orient.y1,coord_h_orient.x2,coord_h_orient.y2);
		fix_text(coord_h_orient.x1,coord_h_orient.y1,coord_h_orient.x2,coord_h_orient.y2,"H_ORIENT");				
}

void desenare_buton_v_orient(){
		setfillstyle(INTERLEAVE_FILL,WHITE);
		setcolor(YELLOW);
		bar(coord_v_orient.x1,coord_v_orient.y1,coord_v_orient.x2,coord_v_orient.y2);
		fix_text(coord_v_orient.x1,coord_v_orient.y1,coord_v_orient.x2,coord_v_orient.y2,"V_ORIENT");
}
void buton_click_v_orient(){
		setfillstyle(INTERLEAVE_FILL,BLUE);
		setcolor(WHITE);
		bar(coord_v_orient.x1,coord_v_orient.y1,coord_v_orient.x2,coord_v_orient.y2);
		fix_text(coord_v_orient.x1,coord_v_orient.y1,coord_v_orient.x2,coord_v_orient.y2,"V_ORIENT");
}

//desenarea casetei de prezentare
int x_center_of_box;
int y_center_of_box;

void coord_caseta(int x1,int y1,int x2,int y2){
	coord_box.x1=x1;
	coord_box.y1=y1;
	coord_box.x2=x2;
	coord_box.y2=y2;
	x_center_of_box=x1+25;
	y_center_of_box=y1+25;
}
void desenare_caseta(int nr,short orient,short stage){
	switch(nr){
		case 0:{
			//empty box
			setfillstyle(XHATCH_FILL,BLACK);
			bar(coord_box.x1,coord_box.y1,coord_box.x2,coord_box.y2);
			break;
		}
		case 1:{
			//rezistenta
			setfillstyle(XHATCH_FILL,BLACK);
			bar(coord_box.x1,coord_box.y1,coord_box.x2,coord_box.y2);
			resistance_comp* resistance=new resistance_comp;
  			resistance=create_resistance_comp(x_center_of_box,y_center_of_box,orient);
			draw_resistance(resistance);
			delete resistance;
			break;
		}
		case 2:{
			//sursa
			setfillstyle(XHATCH_FILL,BLACK);
			bar(coord_box.x1,coord_box.y1,coord_box.x2,coord_box.y2);
			source_comp* source=new source_comp;
  			source=create_source_comp(x_center_of_box,y_center_of_box,orient);
  			draw_source(source);
			delete source;
			break;
		}
		case 3:{
			// comutator
			setfillstyle(XHATCH_FILL,BLACK);
			bar(coord_box.x1,coord_box.y1,coord_box.x2,coord_box.y2);
			breaker_comp* breaker=new breaker_comp;
			breaker=create_breaker_comp(x_center_of_box,y_center_of_box,orient,stage);
			draw_breaker(breaker);
			delete breaker;
			break;
		}
		case 4:{
			//consumator
			setfillstyle(XHATCH_FILL,BLACK);
			bar(coord_box.x1,coord_box.y1,coord_box.x2,coord_box.y2);
			consumer_comp* consumer=new consumer_comp;
			consumer=create_consumer_comp(x_center_of_box,y_center_of_box,orient);
			draw_consumer(consumer);
			delete consumer;						
			break;
		}
		case 5:{
			for(int i=1;i<=10;i++){
				setfillstyle(XHATCH_FILL,BLACK);
				bar(coord_box.x1,coord_box.y1,coord_box.x2,coord_box.y2);
				delay(5);
				setfillstyle(XHATCH_FILL,WHITE);
				bar(coord_box.x1,coord_box.y1,coord_box.x2,coord_box.y2);
				delay(5);
			}
			
			break;
		}
			
	}
	
}
//butonae 
void coord_buton_stage_closed(int x1,int y1,int x2,int y2){
	coord_stage_closed.x1=x1;
	coord_stage_closed.y1=y1;
	coord_stage_closed.x2=x2;
	coord_stage_closed.y2=y2;
}
void desenare_buton_stage_closed(){
	setfillstyle(INTERLEAVE_FILL,WHITE);
	setcolor(YELLOW);
	bar(coord_stage_closed.x1,coord_stage_closed.y1,coord_stage_closed.x2,coord_stage_closed.y2);
	fix_text(coord_stage_closed.x1,coord_stage_closed.y1,coord_stage_closed.x2,coord_stage_closed.y2,"CLOSED");
}
void buton_click_stage_closed(){
	setfillstyle(INTERLEAVE_FILL,BLUE);
	setcolor(WHITE);
	bar(coord_stage_closed.x1,coord_stage_closed.y1,coord_stage_closed.x2,coord_stage_closed.y2);
	fix_text(coord_stage_closed.x1,coord_stage_closed.y1,coord_stage_closed.x2,coord_stage_closed.y2,"CLOSED");
}
void coord_buton_stage_opened(int x1,int y1,int x2,int y2){
	coord_stage_opened.x1=x1;
	coord_stage_opened.y1=y1;
	coord_stage_opened.x2=x2;
	coord_stage_opened.y2=y2;
}
void desenare_buton_stage_opened(){
	setfillstyle(INTERLEAVE_FILL,WHITE);
	setcolor(YELLOW);
	bar(coord_stage_opened.x1,coord_stage_opened.y1,coord_stage_opened.x2,coord_stage_opened.y2);
	fix_text(coord_stage_opened.x1,coord_stage_opened.y1,coord_stage_opened.x2,coord_stage_opened.y2,"OPENED");
}
void buton_click_stage_opened(){
	setfillstyle(INTERLEAVE_FILL,BLUE);
	setcolor(WHITE);
	bar(coord_stage_opened.x1,coord_stage_opened.y1,coord_stage_opened.x2,coord_stage_opened.y2);
	fix_text(coord_stage_opened.x1,coord_stage_opened.y1,coord_stage_opened.x2,coord_stage_opened.y2,"OPENED");
}


//***************************************************************************

void warn(){
	desenare_caseta(5,0,0);
	desenare_caseta(current_comp,orientation_button,current_stage);
}




//-----------------------------------------------------------------------------

void test_button(int x,int y){
	if(x<=screen_width&&y<=100){
			if(x>=coord_sursa.x1&&x<=coord_sursa.x2&&y>=coord_sursa.y1&&y<=coord_sursa.y2){
						buton_click_sursa();
						delay(50);
						desenare_buton_sursa();
						current_comp=2;
						desenare_caseta(2,orientation_button,0);	
			}else if(x>=coord_comutator.x1&&x<=coord_comutator.x2&&y>=coord_comutator.y1&&y<=coord_comutator.y2){
						buton_click_comutator();
						delay(50);
						desenare_buton_comutator();
						current_comp=3;
						desenare_caseta(3,orientation_button,current_stage);
			}else if(x>=coord_rezistenta.x1&&x<=coord_rezistenta.x2&&y>=coord_rezistenta.y1&&y<=coord_rezistenta.y2){
						buton_click_rezistenta();
						delay(50);
						desenare_buton_rezistenta();
						current_comp=1;
						desenare_caseta(1,orientation_button,0);
			}else if(x>=coord_consumator.x1&&x<=coord_consumator.x2&&y>=coord_consumator.y1&&y<=coord_consumator.y2){
						buton_click_consumator();
						delay(50);
						desenare_buton_consumator();
						current_comp=4;
						desenare_caseta(4,orientation_button,0);
			}else if(x>=coord_h_orient.x1&&x<=coord_h_orient.x2&&y>=coord_h_orient.y1&&y<=coord_h_orient.y2){
						buton_click_h_orient();
						orientation_button=1;
						desenare_buton_v_orient();	
						desenare_caseta(current_comp,orientation_button,current_stage);
			}else if(x>=coord_v_orient.x1&&x<=coord_v_orient.x2&&y>=coord_v_orient.y1&&y<=coord_v_orient.y2){
						buton_click_v_orient();
						orientation_button=0;
						desenare_buton_h_orient();
						desenare_caseta(current_comp,orientation_button,current_stage);	
			}else if(x>=coord_stage_closed.x1&&x<=coord_stage_closed.x2&&y>=coord_stage_closed.y1&&y<=coord_stage_closed.y2&&current_comp==3){
						buton_click_stage_closed();
						current_stage=0;
						desenare_buton_stage_opened();
						desenare_caseta(current_comp,orientation_button,current_stage);
			}else if(x>=coord_stage_opened.x1&&x<=coord_stage_opened.x2&&y>=coord_stage_opened.y1&&y<=coord_stage_opened.y2&&current_comp==3){
						buton_click_stage_opened();
						current_stage=1;
						desenare_buton_stage_closed();
						desenare_caseta(current_comp,orientation_button,current_stage);
			}else{
			 eval_options(x,y);
			}
					
			
			
			}else{
				// aici incepe sectiunea care cuprinde  interactiunea cu tabela de desene
				
				if(x>=50&&x<=screen_width-50&&y>=100&&y<=screen_height-80){	
					if(current_comp!=0&& global_stage==1){// !! de optimizat , se poat folosi o singura data functia insert_componenta
								switch (current_comp){
									case 1:{
										// rezistenta
										
										if(inserare_componenta(current_comp,x,y,orientation_button,current_stage)){
										resistance_comp* resistance=new resistance_comp;//creare componenta
			  							resistance=create_resistance_comp(x,y,orientation_button);//setare coordonare orientare si stare
										draw_resistance(resistance);//desenare
										delete resistance;//stergerea din memorie ,dar pastrarea sa in contextul grafix
										}else{
											//warning
											warn();
										}
										
										break;
									}
									case 2:{
									//sursa
										if(inserare_componenta(current_comp,x,y,orientation_button,current_stage)){
											source_comp* source=new source_comp;
							  				source=create_source_comp(x,y,orientation_button);
							  				draw_source(source);
											delete source;
										}else{
											//warninng
											warn();
										}
										break;
									}
									case 3:{
										// comutator
										if(inserare_componenta(current_comp,x,y,orientation_button,current_stage)){
											breaker_comp* breaker=new breaker_comp;
											breaker=create_breaker_comp(x,y,orientation_button,current_stage);
											draw_breaker(breaker);
											delete breaker;
										}else{
											//warning
											warn();
										
										}
										break;
									}
									case 4:{
										//consumator
										if(inserare_componenta(current_comp,x,y,orientation_button,current_stage)){
											consumer_comp* consumer=new consumer_comp;
											consumer=create_consumer_comp(x,y,orientation_button);
											draw_consumer(consumer);
											delete consumer;						
										}else{
											//warning
											warn();
										}
										break;
									}
												
						}
					}else  if(global_stage==2){
									if(stergere_elemente(current_comp,x,y,orientation_button,current_stage)){
										setfillstyle(XHATCH_FILL,BLACK);
										bar(x-25,y-25,x+25,y+25);	
									}else{
										warn();
									}
						
					}else if(global_stage==3){
							
									if(test_conectare_element(x,y)){
											creare_conector(x,y);
									}else{
										warn();
									}
					}
					else if(global_stage==4){
								//redesenare();
							if(!search_in_list(x,y)){
										int sec_orient;
										int sec_stage;
									while(true){
										if(ismouseclick(WM_LBUTTONDBLCLK)){
											int x_mv,y_mv;
											getmouseclick(WM_LBUTTONDOWN,x_mv,y_mv);
											if(search_in_list(x_mv,y_mv)){
												inserare_componenta(element_selectat->type_of_comp,x_mv,y_mv,sec_orient,sec_stage);
												stergere_elemente(element_selectat->type_of_comp,x,y,sec_orient,sec_stage);		 
											}else{
												warn();
											}
											break;
										}else{
												int x_poz;
												int y_poz;
												getmouseclick(WM_MOUSEMOVE,x_poz,y_poz);
											if(x_poz>=50&&x_poz<=screen_width-50&&y_poz>=120&&y_poz<=screen_height-80){
											
													switch(element_selectat->type_of_comp){
															
															case 1:{
																//rezistenta
																	resistance_comp* resistance=new resistance_comp;
																	resistance=create_resistance_comp(x_poz,y_poz,element_selectat->resistance->orientation);
																	draw_resistance(resistance);
																	sec_orient=element_selectat->resistance->orientation;
																	delete resistance;
																
																break;
															}
															case 2:{
																//usrsa
																	source_comp* source=new source_comp;
																	source=create_source_comp(x_poz,y_poz,element_selectat->source->orientation);
																	draw_source(source);
																	sec_orient=element_selectat->source->orientation;
																	delete source;
																break;
															}
															case 3:{
																//comutator
																	breaker_comp* breaker=new breaker_comp;
																	breaker=create_breaker_comp(x_poz,y_poz,element_selectat->breaker->orientation,element_selectat->breaker->orientation);
																	draw_breaker(breaker);
																	sec_orient=element_selectat->breaker->orientation;
																	sec_stage=element_selectat->breaker->stage;
																	delete breaker;
																break;
															}
															case 4:{
																//consumator
																consumer_comp* consumer=new consumer_comp;
																consumer=create_consumer_comp(x_poz,y_poz,element_selectat->consumer->orientation);
																draw_consumer(consumer);
																sec_orient=element_selectat->consumer->orientation;
																delete consumer;
																break;
															}	
														
														
													}
												
											}
											
											
												delay(50);
										}
										
										redesenare();
										cout<<"inca in bucla\n";
										delay(10);
									}
									cout<<"iesire din bucla\n";
							}else{
								warn();
							}
							
						}
				}else{
					if(current_comp==0)
						warn();
				}
	}
	
}











