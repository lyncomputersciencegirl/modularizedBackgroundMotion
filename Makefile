all: background

background: background.cpp myimage.cpp myimage.h
	g++ background.cpp myimage.cpp -Wall -lX11 -lGL -lGLU -lm -obackground

clean:
	rm -f background 


