main: main.o
	g++ main.o src/glad.c -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

main.o:
