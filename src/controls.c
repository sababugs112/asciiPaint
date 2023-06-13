#include <stdio.h>
#include <stdlib.h>

#define length 75
#define cellSize 10



extern char** art;
char brush = '@';



float roundUp(int numToRound, int multiple);
void PcordsToScords(int gpx , int gpy , int* gsx , int* gsy);


void keyInputHandler(unsigned char key , int x , int y){

	if(key == 's'){
		FILE* f = fopen("save.txt","w");
		for(int i = 0 ; i < length ; i ++){
			for(int j = 0 ; j < length; j++){
				fprintf(f,"%c",art[i][j]);
			};
			fprintf(f,"%c",'\n');
		}

	}

};

void handleMouseMove(int x , int y){

	int sx , sy;	
	PcordsToScords(x,y,&sx,&sy);
	art[sy][sx] = brush;
};


float roundUp(int numToRound, int multiple){    //rounds to the nearest multipe of a number
	if (multiple == 0) return numToRound;

	int remainder = abs(numToRound) % multiple;
	if (remainder == 0) return numToRound;

	if (numToRound < 0) return -(abs(numToRound) - remainder);
	else return numToRound + multiple - remainder;
};


void PcordsToScords(int gpx , int gpy , int* gsx , int* gsy){
	*gsx = (int)(roundUp(gpx,cellSize) - 10) / 10 + 1;
	*gsy = (int)(roundUp(gpy,cellSize) - 10) / 10 + 2;
};
