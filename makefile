execute: main.o
	g++ -o execute main.cpp

main.o: main.cpp LinkedStack.h LinkedStack.h node.h Token.h
	g++ -c main.cpp

make clean:
	rm *o execute