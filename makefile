execute: main.o
	g++ -o execute main.cpp

main.o: main.cpp Tokenizer.h LinkedStack.h LinkedQueue.h node.h Token.h
	g++ -c main.cpp

make clean:
	rm *o execute