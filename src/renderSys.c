#include <GL/glut.h>
#include <string.h>
#include <stdio.h>

#define length 75
#define drawCellSize 10 
#define windowW 750 
#define windowH 750


extern char** art;

void drawText(char* str,int x, int y, float r, float g, float b,void* font);


void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	for(int i = 0; i < length; i++){
		drawText(art[i], 15 , 15 + 10*i, 1.0, 1.0 , 1.0 , GLUT_BITMAP_8_BY_13);
	};
	glFlush();
	glutSwapBuffers();
};




void drawText(char* str,int x, int y, float r, float g, float b,void* font){

	glColor3f(r,g,b);

	float cx = x - windowW/2;
	float cy = windowH/2 - y;

	cx = 2*cx/windowW;
	cy = 2*cy/windowH;  // translate x and y position

	glRasterPos2f(cx,cy);  // set text postion

	int len = strlen(str);

	for(int i = 0; i < len; i++) glutBitmapCharacter(font,str[i]);     // print on screen
};
