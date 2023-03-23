main: main.o funcs.o imageio.o
	g++ -o main main.o funcs.o imageio.o

funcs.o: funcs.cpp funcs.h

imageio.o: imageio.cpp imageio.h

main.o: main.cpp funcs.h imageio.h

clean:
	rm -f main.o funcs.o