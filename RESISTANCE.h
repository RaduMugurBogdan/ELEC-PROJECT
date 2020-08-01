//MAX WIDTH=200PX;
//MAX HEIGHT=200PX;
#define STANDARD_SIZE 0	
struct resistance_comp{
	int x_center;//data from file
	int y_center;//data from file
	int orientation;//data from file
	int x_left_or_up_connector;//standard// coordonatele conectorului stang
	int y_left_or_up_connector;//stamdard
	int x_right_or_down_connector;//standard// coordonatele conectorului drept
	int y_right_or_down_connector;//stamdard
	int width;//standard
	int height;//standard
	char inner_text[30];//standard
};
#define comp_color BLUE
#define circuit_color GREEN
#define size_const 10 // lungimea conectorului integrat
resistance_comp* create_resistance_comp(int x_center,int y_center,int orientation){
	
	resistance_comp* resistance=new resistance_comp;
	//CENTRUL OBIECTULUI
	resistance->x_center=x_center;
	resistance->y_center=y_center;
	//ORIENTAREA OBIECTULUI
	resistance->orientation=orientation;
	//DIMENSIUNILE OBIECTULUI
	resistance->width=30;
	resistance->height=30;
	
	strcpy(resistance->inner_text,"R");
	//COORDONATELE CONECTORILOR
	if(resistance->orientation==1){
				//CONNECTARE ORIZONTALA
				resistance->x_left_or_up_connector=resistance->x_center-resistance->width/2-size_const;//CONECTOR STANG
				resistance->y_left_or_up_connector=resistance->y_center;
				resistance->x_right_or_down_connector=resistance->x_center+resistance->width/2+size_const;//CONECTOR DREPT
				resistance->y_right_or_down_connector=resistance->y_center;	
	}else{
		
				resistance->x_left_or_up_connector=resistance->x_center;
				resistance->y_left_or_up_connector=resistance->y_center-resistance->height/2-size_const;
				resistance->x_right_or_down_connector=resistance->x_center;
				resistance->y_right_or_down_connector=resistance->y_center+resistance->height/2+size_const;
	}
	
	return resistance;
}

void draw_resistance(resistance_comp* resistance){
	
	if(resistance->x_center>STANDARD_SIZE&&resistance->y_center>STANDARD_SIZE){
			setcolor(comp_color);
			//DESENARE MARGINI
			line(resistance->x_center-resistance->width/2,resistance->y_center-resistance->height/2,resistance->x_center+resistance->width/2,resistance->y_center-resistance->height/2);//LATURA DE SUS	
			line(resistance->x_center-resistance->width/2,resistance->y_center+resistance->height/2,resistance->x_center+resistance->width/2,resistance->y_center+resistance->height/2);//LATURA DE JOS	
			line(resistance->x_center-resistance->width/2,resistance->y_center-resistance->height/2,resistance->x_center-resistance->width/2,resistance->y_center+resistance->height/2);//LATURA DIN STANGA
			line(resistance->x_center+resistance->width/2,resistance->y_center-resistance->height/2,resistance->x_center+resistance->width/2,resistance->y_center+resistance->height/2);//LATURA DIN DREAPTA
			
			//DESENARE TEXT
			int x=(resistance->width-textwidth(resistance->inner_text))/2+resistance->x_center-resistance->width/2;
			int y=(resistance->height-textheight(resistance->inner_text))/2+resistance->y_center-resistance->height/2;
			outtextxy(x,y,resistance->inner_text);			
			
			//DESENARE CONECTORI
				setcolor(circuit_color);
				if(resistance->orientation==1){
				
						line(resistance->x_center+resistance->width/2,resistance->y_center,resistance->x_center+resistance->width/2+size_const,resistance->y_center);//CONECTORUL STANG
						line(resistance->x_center-resistance->width/2,resistance->y_center,resistance->x_center-resistance->width/2-size_const,resistance->y_center);//CONECTORUL DREPT
				
				}else{
						line(resistance->x_center,resistance->y_center-resistance->height/2-size_const,resistance->x_center,resistance->y_center-resistance->height/2);//CONECTORUL SUPERIOR
						line(resistance->x_center,resistance->y_center+resistance->height/2+size_const,resistance->x_center,resistance->y_center+resistance->height/2);//CONECTORUL INFERIOR
				}
			
			
	}else{
		std::cout<<"NU SE POATE EFECTUA POZITIONAREA COMPONENENTEI\n";
	}
	
	
	
	
}





























