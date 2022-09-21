// Name: Yeana Bond
//new file name: myimage.h is a header file 
//program: background.cpp
//author:  Gordon Griesel
//date:    2017 - 2018
//
//The position of the background QUAD does not change.
//Just the texture coordinates change.
//In this example, only the x coordinates change.
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <math.h>
//#include <X11/Xlib.h>
//#include <X11/keysym.h>
//#include <GL/glx.h>

// if not defined, (if does not exist, define it right now
#ifndef _MYIMAGE_H_
#define _MYIMAGE_H_

class MyImage {
public:
	int width, height;
	unsigned char *data;
	// destructor : just a prototype now
	~MyImage();
	// constructor
	MyImage(const char *fname); 
};

#endif
