//modified by: Yeana Bond 
//date of modification: Fall 2022
//Minimum includes for this source file 
//Example of modularization since MyImage is now put into 
//myimage.cpp separtely 
//program: myimage.cpp
//author:  Gordon Griesel
//date:    2017 - 2018
//note: suorce file for MyImage.h
//The position of the background QUAD does not change.
//Just the texture coordinates change.
//In this example, only the x coordinates change.
//
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
//#include <string.h>
#include <unistd.h>
//#include <math.h>
//#include <X11/Xlib.h>
//#include <X11/keysym.h>
//#include <GL/glx.h>
#include "myimage.h"
// source file for MyImage.h class definition 
// Calling the instant of the class so that it can be convereted 
extern class MyImage myimage;

MyImage::~MyImage() { delete [] data;}
MyImage::MyImage(const char *fname) {


   // if (fname[0] == '\0')
    if (strlen(fname) == 0)
        return;
    //If fine name is a sort of path, if could be longer than 40
    //  char name[FILENAME_MAX];
    // FILENAME_MAX is not working because of sprintf(ts, "convert
    // %s %s, fname, ppmname); where fname and ppmname are combined
    // Getting errors so, we will consider using later
    char name[40];

    strcpy(name, fname);
    int slen = strlen(name);
    name[slen-4] = '\0';
    char ppmname[80];
    // ppm does can be constructed with a text file 
    sprintf(ppmname,"%s.ppm", name);
    char ts[100];
    // ppm file gets converted into an image file
    sprintf(ts, "convert %s %s", fname, ppmname);
    system(ts);
    FILE *fpi = fopen(ppmname, "r");
    if (fpi) {
        char line[200];
        fgets(line, 200, fpi);
        fgets(line, 200, fpi);
        //skip comments and blank lines
        while (line[0] == '#' || strlen(line) < 2)
            fgets(line, 200, fpi);
        sscanf(line, "%i %i", &width, &height);
        fgets(line, 200, fpi);
        //get pixel data
        int n = width * height * 3;			
        data = new unsigned char[n];			
        for (int i=0; i<n; i++)
            data[i] = fgetc(fpi);
        fclose(fpi);
    } else {
        printf("ERROR opening image: %s\n", ppmname);
        exit(0);
    }
    // unlink is like rm (remove) 
    unlink(ppmname);

};


