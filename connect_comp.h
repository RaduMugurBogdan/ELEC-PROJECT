
struct connector{
	int x1,y1;//connector 1
	int x2,y2;//connector 2
	connector* next;
};
void warn();
void redesenare();
connector* connectors_list=NULL;
connector* last_connector=NULL;
void insert_connector(int x1,int y1,int x2,int y2){
	if(connectors_list==NULL){
			connectors_list=new connector;
			connectors_list->x1=x1;
			connectors_list->y1=y1;
			connectors_list->x2=x2;
			connectors_list->y2=y2;
			connectors_list->next=NULL;
			last_connector=connectors_list;
	}else{
			last_connector->next=new connector;
			last_connector=last_connector->next;
			last_connector->x1=x1;
			last_connector->y1=y1;
			last_connector->x2=x2;
			last_connector->y2=y2;
			last_connector->next=NULL;
	}
	
}
void desenare_conectori(){
	connector* p=connectors_list;
	while(p!=NULL){
		line(p->x1,p->y1,p->x1,p->y2);
		line(p->x1,p->y2,p->x2,p->y2);
		p=p->next;
	}
}

bool test_conectare_element(int x,int y){
	if(!search_in_list(x,y)){
		return true;
	}
}


void tst_2(int &x,int &y){
	
	int x_conector_comp;
	int y_conector_comp;
	
	
		switch(element_selectat_conectare->type_of_comp){
		
		
															case 1:{
																//rezistenta
																	if(element_selectat_conectare->resistance->orientation==1){
																		// horisontal orienation
																		if(x>=element_selectat_conectare->resistance->x_center){
																			x_conector_comp=element_selectat_conectare->resistance->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->resistance->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->resistance->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->resistance->y_left_or_up_connector;		
																		}
																	}else{
																		if(y>=element_selectat_conectare->resistance->y_center){
																			x_conector_comp=element_selectat_conectare->resistance->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->resistance->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->resistance->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->resistance->y_left_or_up_connector;		
																		}
																		
																	}
																
																											
																break;
															}
															case 2:{
																//usrsa.
																if(element_selectat_conectare->source->orientation==1){
																		// horisontal orienation
																		if(x>=element_selectat_conectare->source->x_center){
																			x_conector_comp=element_selectat_conectare->source->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->source->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->source->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->source->y_left_or_up_connector;		
																		}
																	}else{
																		if(y>=element_selectat_conectare->source->y_center){
																			x_conector_comp=element_selectat_conectare->source->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->source->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->source->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->source->y_left_or_up_connector;		
																		}
																		
																	}
																break;
															}
															case 3:{
																//comutator
																if(element_selectat_conectare->breaker->orientation==1){
																		// horisontal orienation
																		if(x>=element_selectat_conectare->breaker->x_center){
																			x_conector_comp=element_selectat_conectare->breaker->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->breaker->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->breaker->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->breaker->y_left_or_up_connector;		
																		}
																	}else{
																		if(y>=element_selectat_conectare->breaker->y_center){
																			x_conector_comp=element_selectat_conectare->breaker->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->breaker->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->breaker->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->breaker->y_left_or_up_connector;		
																		}
																		
																	}
																break;
															}
															case 4:{
																//consumator
																if(element_selectat_conectare->consumer->orientation==1){
																		// horisontal orienation
																		if(x>=element_selectat_conectare->consumer->x_center){
																			x_conector_comp=element_selectat_conectare->consumer->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->consumer->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->consumer->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->consumer->y_left_or_up_connector;		
																		}
																	}else{
																		if(y>=element_selectat_conectare->consumer->y_center){
																			x_conector_comp=element_selectat_conectare->consumer->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->consumer->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->consumer->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->consumer->y_left_or_up_connector;		
																		}
																		
																	}
																break;
															}	
														
	}
	
	x=x_conector_comp;
	y=y_conector_comp;
	
}


void creare_conector(int x,int y){
	
	int x_conector_comp;
	int y_conector_comp;
	int orientation_elem=0;
	int x_center;
	int y_center;
	int conector_stang=0;
	int conector_drept=0;
	int conector_sus=0;
	int conector_jos=0;
		switch(element_selectat_conectare->type_of_comp){
		
		
															case 1:{
																//rezistenta
																	if((orientation_elem=element_selectat_conectare->resistance->orientation)==1){
																		// horisontal orienation
																		if(x>=element_selectat_conectare->resistance->x_center){
																			x_conector_comp=element_selectat_conectare->resistance->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->resistance->y_right_or_down_connector;	
																			conector_stang=1;																		
																		}else{
																				x_conector_comp=element_selectat_conectare->resistance->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->resistance->y_left_or_up_connector;		
																				conector_drept=1;
																		}
																	}else{
																		if(y>=element_selectat_conectare->resistance->y_center){
																			x_conector_comp=element_selectat_conectare->resistance->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->resistance->y_right_or_down_connector;																			
																			conector_sus=1;
																		}else{
																				x_conector_comp=element_selectat_conectare->resistance->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->resistance->y_left_or_up_connector;		
																				conector_jos=1;
																		}
																		
																	}	
																	x_center=element_selectat_conectare->resistance->x_center;
																		y_center=element_selectat_conectare->resistance->y_center;
																											
																break;
															}
															case 2:{
																//usrsa.
																if((orientation_elem=element_selectat_conectare->source->orientation)==1){
																		// horisontal orienation
																		if(x>=element_selectat_conectare->source->x_center){
																			x_conector_comp=element_selectat_conectare->source->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->source->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->source->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->source->y_left_or_up_connector;		
																		}
																	}else{
																		if(y>=element_selectat_conectare->source->y_center){
																			x_conector_comp=element_selectat_conectare->source->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->source->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->source->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->source->y_left_or_up_connector;		
																		}
																		
																	}
																		x_center=element_selectat_conectare->source->x_center;
																		y_center=element_selectat_conectare->source->y_center;
																break;
															}
															case 3:{
																//comutator
																if((orientation_elem=element_selectat_conectare->breaker->orientation)==1){
																		// horisontal orienation
																		if(x>=element_selectat_conectare->breaker->x_center){
																			x_conector_comp=element_selectat_conectare->breaker->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->breaker->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->breaker->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->breaker->y_left_or_up_connector;		
																		}
																	}else{
																		if(y>=element_selectat_conectare->breaker->y_center){
																			x_conector_comp=element_selectat_conectare->breaker->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->breaker->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->breaker->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->breaker->y_left_or_up_connector;		
																		}
																		
																	}
																		x_center=element_selectat_conectare->breaker->x_center;
																		y_center=element_selectat_conectare->breaker->y_center;
																break;
															}
															case 4:{
																//consumator
																if((orientation_elem=element_selectat_conectare->consumer->orientation)==1){
																		// horisontal orienation
																		if(x>=element_selectat_conectare->consumer->x_center){
																			x_conector_comp=element_selectat_conectare->consumer->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->consumer->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->consumer->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->consumer->y_left_or_up_connector;		
																		}
																	}else{
																		if(y>=element_selectat_conectare->consumer->y_center){
																			x_conector_comp=element_selectat_conectare->consumer->x_right_or_down_connector;
																			y_conector_comp=element_selectat_conectare->consumer->y_right_or_down_connector;																			
																		}else{
																				x_conector_comp=element_selectat_conectare->consumer->x_left_or_up_connector;
																				y_conector_comp=element_selectat_conectare->consumer->y_left_or_up_connector;		
																		}
																		
																	}
																		x_center=element_selectat_conectare->consumer->x_center;
																		y_center=element_selectat_conectare->consumer->y_center;
																break;
															}	
														
	}
	bool flag=0;
	int x1=x_conector_comp;
	int y1=y_conector_comp;
	int x2=x1;
	int y2=y1;
	while(true){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x1,y1);
			while(!ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_MOUSEMOVE,x1,y1);
				while(!ismouseclick(WM_MOUSEMOVE)){
					if(y1>100&&y2>100){
						
						line(x1,y1,x1,y2);
						line(x1,y2,x2,y2);
					}	
					delay(10);
				}
									
				//determinare coordonatele punctului final de conexiune
				redesenare();
				delay(5);
					
			}
				if(!search_in_list(x1,y1)&&x1!=x2&&y1!=y2){
							tst_2(x1,y1);
							flag=1;
					}else{
						redesenare();
						warn();
					}
			break;
	
		}
		delay(5);
	}
	
	if(flag){
		line(x1,y1,x1,y2);
		line(x1,y2,x2,y2);
		insert_connector(x1,y1,x2,y2);
	
	}
	global_stage=1;
	buton_click_draw_option();
	desenare_connect_option();
}











