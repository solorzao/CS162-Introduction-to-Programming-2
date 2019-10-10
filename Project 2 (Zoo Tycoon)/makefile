target: Project2

Project2: main.o zoo.o animal.o tiger.o penguin.o turtle.o
	g++ main.o zoo.o animal.o tiger.o penguin.o turtle.o -std=c++11 -o Project2

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

zoo.o: zoo.cpp
	g++ -std=c++11 -c zoo.cpp

animal.o: animal.cpp
	g++ -std=c++11 -c animal.cpp

tiger.o: tiger.cpp
	g++ -std=c++11 -c tiger.cpp

penguin.o: penguin.cpp
	g++ -std=c++11 -c penguin.cpp

turtle.o: turtle.cpp
	g++ -std=c++11 -c turtle.cpp

clean:
	rm *.o Project2 



