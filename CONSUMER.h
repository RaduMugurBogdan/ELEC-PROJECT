struct consumer_comp{
	
	int x_center;// data from file
	int y_center;//	data from file
	int orientation;//data from file (1=vertical_orientation,-1=horisontal orientation)
	int x_left_or_up_connector;//standard// coordonatele conectorului stang
	int y_left_or_up_connector;//stamdard
	int x_right_or_down_connector;//standard// coordonatele conectorului drept
	int y_right_or_down_connector;//stamdard
	int height;//stamdard
	int width;//stamdard
	int radius;//standard
	
};
// dimensiunea alocata maximal pentru orice componenta (x*x)
#define STANDARD_SIZE 0
//lungimea standard aunui conector 
#define size_const 10 
#define COMPONENT_COLOR RED
#define circuit_color GREEN
/*

dimensiunea unei conponenete este de 50 px;

*/
consumer_comp* create_consumer_comp(int x_center,int y_center,int orientation){
	//VARIABLE DATA	
	consumer_comp*consumer=new consumer_comp;
	consumer->x_center=x_center;
	consumer->y_center=y_center;
	consumer->orientation=orientation;
	//STANDARD DATA		
	consumer->radius=15;
	consumer->height=2*consumer->radius;
	consumer->width=2*consumer->radius;
		if(consumer->orientation==1){//COORDONATELE IN CAZUL ORIENTARII ORIZONTALE
				//COORDONATELE PRIMULUI CONECTOR(CEL STANG)
				consumer->x_left_or_up_connector=consumer->x_center-consumer->radius-size_const;
				consumer->y_left_or_up_connector=consumer->y_center;
				//COORDONATELE CELUI DE AL DOILEA CONECTOR(CEL DREPT)
				consumer->x_right_or_down_connector=consumer->x_center+consumer->radius+size_const;
				consumer->y_right_or_down_connector=consumer->y_center;
				
		}else{//COORDONATELE IN CAZUL ORIENTARII VERTICALE
				//COORDONATELE PRIMULUI CONECTOR (CEL DE SUS)
				consumer->x_left_or_up_connector=consumer->x_center;
				consumer->y_left_or_up_connector=consumer->y_center-consumer->radius-size_const;
				//COORDONATELE CELUI DE AL DOILEA CONECTOR (CEL DE JOS)
				consumer->x_right_or_down_connector=consumer->x_center;
				consumer->y_right_or_down_connector=consumer->y_center+consumer->radius+size_const;
			
			}

	return consumer;
}


void draw_consumer(consumer_comp* consumer){
	
	if(consumer->x_center>STANDARD_SIZE&&consumer->y_center>STANDARD_SIZE){
	
		for(int i=1;i<=360;i++){
			putpixel(consumer->x_center+cos(i)*consumer->radius,consumer->y_center+sin(i)*consumer->radius,COMPONENT_COLOR);
		}
		//DESENARE DREPTE INTERNE
			setcolor(COMPONENT_COLOR);
			line(consumer->x_center+consumer->radius*cos(45),consumer->y_center-consumer->radius*sin(45),consumer->x_center-consumer->radius*cos(45),consumer->y_center+consumer->radius*sin(45));
			line(consumer->x_center-consumer->radius*cos(45),consumer->y_center-consumer->radius*sin(45),consumer->x_center+consumer->radius*cos(45),consumer->y_center+consumer->radius*sin(45));
		
		//proiectare conectori
			setcolor(circuit_color);
		if(consumer->orientation==1){
				line(consumer->x_center+consumer->radius,consumer->y_center,consumer->x_center+consumer->radius+size_const,consumer->y_center);
				line(consumer->x_center-consumer->radius,consumer->y_center,consumer->x_center-consumer->radius-size_const,consumer->y_center);
				
		}else{
				line(consumer->x_center,consumer->y_center-consumer->radius,consumer->x_center,consumer->y_center-consumer->radius-size_const);	
				line(consumer->x_center,consumer->y_center+consumer->radius,consumer->x_center,consumer->y_center+consumer->radius+size_const);
	}
		
	}else{
		std::cout<<"LOCATIA ALEASA NU PERMITE DESENAREA COMPONENTEI\n";
	}	
}




























