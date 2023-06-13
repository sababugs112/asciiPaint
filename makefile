CC = gcc
SOURCE_FILES = src/main.c src/renderSys.c src/controls.c


CFLAGS = -g
LFLAGS = -lglut -lGL

all:asciiPaint


asciiPaint: 
	$(CC) $(SOURCE_FILES) $(CFLAGS) $(LFLAGS) -o asciiPaint.out 


