main: main.o funcs.o imagehelpers.o
	g++ -o main main.o funcs.o imagehelpers.o

main.o: main.cpp

funcs.o: funcs.cpp funcs.h

imagehelpers.o: imagehelpers.cpp imagehelpers.h

clean:
	rm -f main.o 
