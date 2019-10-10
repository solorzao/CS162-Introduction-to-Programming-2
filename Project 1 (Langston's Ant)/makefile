
target: Project1

Project1: main.o ant.o board.o
	g++ main.o ant.o board.o -std=c++11 -o Project1

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

ant.o: ant.cpp
	g++ -std=c++11 -c ant.cpp

board.o: board.cpp
	g++ -std=c++11 -c board.cpp

clean:
	rm *.o Project1 


