/*
strcuturile de date necesare mentinerii componentelor si conectorilor
*/
#include<math.h>
struct list_type{
	int type_of_comp;
	source_comp* source;
	resistance_comp* resistance;
	consumer_comp* consumer;
	breaker_comp* breaker;
	list_type* next;	
	static int num_of_comp;
};
int list_type::num_of_comp=0;
list_type* list=NULL;
list_type* last_comp=NULL;
list_type* element_selectat_conectare=NULL;
// variabilele necesare desenarii elemenutului deplasat
list_type* element_selectat;
bool search_in_list(int x,int y){
	list_type* p=list;
	int x2;
	int y2;
	while(p!=NULL){
			switch (p->type_of_comp){
						case 1:{
							//rezistenta
							x2=p->resistance->x_center;
							y2=p->resistance->y_center;
							break;
						}
						case 2:{
						//sursa
							x2=p->source->x_center;
							y2=p->source->y_center;
							break;
						}
						case 3:{
							// comutator
							x2=p->breaker->x_center;
							y2=p->breaker->y_center;
							break;
						}
						case 4:{
							//consumator
							x2=p->consumer->x_center;
							y2=p->consumer->y_center;
							break;
						}
	
					}
		if(abs(x-x2)<=50&&abs(y-y2)<=50){
			element_selectat=p;
			element_selectat_conectare=p;
			return false;
		}
		p=p->next;
	}
	return true;	
}

bool inserare_componenta(int componenta,int x,int y,int orient,int stage){
	if(list==NULL){
		list=new list_type;
		list->next=NULL;
		list->type_of_comp=componenta;
		list->num_of_comp=1;
		list->breaker=NULL;
		list->source=NULL;
		list->resistance=NULL;
		list->consumer=NULL;
			switch (componenta){
				case 1:{
					//rezistenta
					list->resistance=new resistance_comp;
  					list->resistance=create_resistance_comp(x,y,orient);
					break;
				}
				case 2:{
				//sursa
					list->source=new source_comp;
					list->source=create_source_comp(x,y,orient);
					break;
				}
				case 3:{
					// comutator
					list->breaker=new breaker_comp;
					list->breaker=create_breaker_comp(x,y,orient,stage);
					break;
				}
				case 4:{
					//consumator
					list->consumer=new consumer_comp;
					list->consumer=create_consumer_comp(x,y,orient);
					break;
				}
												
		}
		
		//************************
		last_comp=list;	
		return true;	
	}else{
			if(search_in_list(x,y)){		
				last_comp->next=new list_type;
				last_comp=last_comp->next;
				last_comp->next=NULL;
				last_comp->type_of_comp=componenta;
					last_comp->breaker=NULL;
					last_comp->source=NULL;
					last_comp->resistance=NULL;
					last_comp->consumer=NULL;	
					switch (componenta){
								case 1:{
									//rezistenta
									last_comp->resistance=new resistance_comp;
				  					last_comp->resistance=create_resistance_comp(x,y,orient);
									break;
								}
								case 2:{
								//sursa
									last_comp->source=new source_comp;
									last_comp->source=create_source_comp(x,y,orient);
									break;
								}
								case 3:{
									// comutator
									last_comp->breaker=new breaker_comp;
									last_comp->breaker=create_breaker_comp(x,y,orient,stage);
									break;
								}
								case 4:{
									//consumator
									last_comp->consumer=new consumer_comp;
									last_comp->consumer=create_consumer_comp(x,y,orient);
									break;
								}
																
						}
				list->num_of_comp++;
				return true;
			}else{
				return false;
				//warning
			}
	}
	
}


bool stergere_elemente(int componenta,int &x,int &y,int orient,int stage){
	list_type* p=list;
	list_type* s=p;
	int x2,y2;
	bool sec=1;
	for(int i=1;i<=list->num_of_comp;i++){
			switch (p->type_of_comp){
						case 1:{
							//rezistenta
							x2=p->resistance->x_center;
							y2=p->resistance->y_center;
											
							break;
						}
						case 2:{
						//sursa
							x2=p->source->x_center;
							y2=p->source->y_center;
							break;
						}
						case 3:{
							// comutator
							x2=p->breaker->x_center;
							y2=p->breaker->y_center;
							
							break;
						}
						case 4:{
							//consumator
							x2=p->consumer->x_center;
							y2=p->consumer->y_center;
							
							break;
						}
	
					}	
		if(abs(x-x2)<=25&&abs(y-y2)<=25){
			x=x2;
			y=y2;
			list->num_of_comp--;
			if(i==1){
				list_type*q=list;
				delete q;
				list=list->next;
				return true;
			}else{
				list_type*q=p;
				s->next=p->next;
				delete q;
				return true;
			}
		}
		s=p;
		p=p->next;	
	}	
	return false;// nu se poate sterge
}



/***********************************************/


/************************************/









