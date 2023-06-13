#include <GL/glut.h>
#include "renderSys.h"
#include "controls.h"


#define length 75

void resize();

char** art;
#define wheight 750
#define wwidth 750 



int main(int argc, char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(wwidth,wheight);
	glutCreateWindow("asciiPaint");
	glutDisplayFunc(display);


	glutReshapeFunc(resize);
	glutMotionFunc(handleMouseMove);
	glutKeyboardFunc(keyInputHandler);



	art = calloc(length,sizeof(char*));
	for(int i = 0 ; i < length ; i++){
		art[i] = calloc(length + 1,sizeof(char));
		for(int j = 0; j < length ; j++) art[i][j] = ' ';
	};



	glutMainLoop();

	return 0;

};


void resize(){
	glutReshapeWindow(wwidth,wheight);
};
