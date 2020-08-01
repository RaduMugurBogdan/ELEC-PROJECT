extern list_type* list;
list_type* moved_element=NULL;
extern long long screen_width;
extern long long screen_height;






void redesenare(){
	setfillstyle(XHATCH_FILL,BLACK);
	bar(0,100,screen_width,screen_height);
	list_type* p=list;
	while(p!=NULL){
	switch (p->type_of_comp){
				case 1:{
					//rezistenta
					draw_resistance(p->resistance);
					break;
				}
				case 2:{
				//sursa
					draw_source(p->source);
					break;
				}
				case 3:{
					// comutator
					draw_breaker(p->breaker);				
					break;
				}
				case 4:{
					//consumator
					draw_consumer(p->consumer);
					break;
				}
												
		}	
	p=p->next;	
	}
	desenare_conectori();
}


bool test_mutare_element(int x,int y){
	list_type* p=list;
	while(p!=NULL){
		 switch(p->type_of_comp){
		 		case 1:{
					//rezistenta
					if(abs(x-p->resistance->x_center)<=25&&abs(y-p->resistance->x_center)){
						moved_element=p;
						return true;
					}
					break;
				}
				case 2:{
				//sursa
					if(abs(x-p->source->x_center)<=25&&abs(y-p->source->x_center)){
						moved_element=p;
						return true;
					}
					break;
				}
				case 3:{
					// comutator
					if(abs(x-p->breaker->x_center)<=25&&abs(y-p->breaker->x_center)){
						moved_element=p;
						return true;
					}				
					break;
				}
				case 4:{
					//consumator
					if(abs(x-p->consumer->x_center)<=25&&abs(y-p->consumer->x_center)){
						moved_element=p;
						return true;
					}
					break;
				}
				
		 }
		p=p->next;			
	
	}
	return false;
	
}
