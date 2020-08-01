struct source_comp{
	
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
	char inner_text[30];//stamdard
	
};
// dimensiunea alocata maximal pentru orice componenta (x*x)
#define STANDARD_SIZE 0
//lungimea standard aunui conector 
#define size_const 10 
#define SOURCE_COMPONENT_COLOR YELLOW
#define circuit_color GREEN

source_comp* create_source_comp(int x_center,int y_center,int orientation){
	//VARIABLE DATA	
	source_comp*source=new source_comp;
	source->x_center=x_center;
	source->y_center=y_center;
	source->orientation=orientation;
	//STANDARD DATA		
	source->radius=15;
	source->height=2*source->radius;//80 pixels
	source->width=2*source->radius;
	strcpy(source->inner_text,"S");
	
		if(source->orientation==1){//COORDONATELE IN CAZUL ORIENTARII ORIZONTALE
				//COORDONATELE PRIMULUI CONECTOR(CEL STANG)
				source->x_left_or_up_connector=source->x_center-source->radius-size_const;
				source->y_left_or_up_connector=source->y_center;
				//COORDONATELE CELUI DE AL DOILEA CONECTOR(CEL DREPT)
				source->x_right_or_down_connector=source->x_center+source->radius+size_const;
				source->y_right_or_down_connector=source->y_center;
				
		}else{//COORDONATELE IN CAZUL ORIENTARII VERTICALE
				//COORDONATELE PRIMULUI CONECTOR (CEL DE SUS)
				source->x_left_or_up_connector=source->x_center;
				source->y_left_or_up_connector=source->y_center-source->radius-size_const;
				//COORDONATELE CELUI DE AL DOILEA CONECTOR (CEL DE JOS)
				source->x_right_or_down_connector=source->x_center;
				source->y_right_or_down_connector=source->y_center+source->radius+size_const;
			
			}

	return source;
}


void draw_source(source_comp* source){
	
	if(source->x_center>STANDARD_SIZE&&source->y_center>STANDARD_SIZE){
	
		for(int i=1;i<=360;i++){
			putpixel(source->x_center+cos(i)*source->radius,source->y_center+sin(i)*source->radius,SOURCE_COMPONENT_COLOR);
		}
		
			//pozitionare text
			setcolor(SOURCE_COMPONENT_COLOR);
			int x=(2*source->radius-textwidth("S"))/2;
			int y=(2*source->radius-textheight("S"))/2;
		
			outtextxy(source->x_center-source->radius+x , source->y_center-source->radius+y,source->inner_text);	
		//proiectare conectori
			setcolor(circuit_color);
		if(source->orientation==1){
				line(source->x_center+source->radius,source->y_center,source->x_center+source->radius+size_const,source->y_center);
				line(source->x_center-source->radius,source->y_center,source->x_center-source->radius-size_const,source->y_center);
				
		}else{
				line(source->x_center,source->y_center-source->radius,source->x_center,source->y_center-source->radius-size_const);	
				line(source->x_center,source->y_center+source->radius,source->x_center,source->y_center+source->radius+size_const);
	}
		
	}else{
		std::cout<<"LOCATIA ALEASA NU PERMITE DESENAREA COMPONENTEI\n";
	}	
}

