all: main

main: dep
	g++ -o main Tag.o Token.o Type.o Real.o Num.o Word.o Lexer.o main.cpp

dep:  Tag.o Token.o Type.o Real.o Num.o Word.o Lexer.o EndException.o

Tag.o:
	g++ -c src/Tag.cpp

Token.o:
	g++ -c src/Token.cpp

Type.o:
	g++ -c src/Type.cpp

Real.o:
	g++ -c src/Real.cpp

Num.o:
	g++ -c src/Num.cpp

Word.o:
	g++ -c src/Word.cpp

Lexer.o:
	g++ -c src/Lexer.cpp

EndException.o:
	g++ -c EndException.cpp

clean:
	rm -f *.o
	rm -f main
