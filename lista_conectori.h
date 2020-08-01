


struct connector_list{
	int x1,y1;
	int x2,y2;
	connector_list* next;
};
connector_list* lista_conectori=NULL;
connector_list* last_connect=NULL;



void insert_connector(int x1,int y1,int x2,int y2){
	if(lista_conectori==NULL){
		lista_conectori=new connector_list;
		lista_conectori->x1=x1;
		lista_conectori->y1=y1;
		lista_conectori->x2=x2;
		lista_conectori->y2=y2;
		lista_conectori->next=NULL;
		last_connectori=lista_conectori;
	}else{
		last_connect=new connector_list;
		last_connect=last_connector->next;
		last_connect->x1=x1;
		last_connect->y1=y1;
		last_connect->x2=x2;
		last_connect->y2=y2;
		last_connect->next=NULL;
	}
}


void desenare_conectori(){
	connector_list* p=lista_conectori;
	while(p!=NULL){
		line(p->x1,p->y1,p->x1,p->y2);
		line(p->x1,p->y2,p->x2,p->y2);
		p=p->next;
	}
}




