FinalProject: main.o game.o player.o startRoom.o RoomA.o RoomB.o RoomC.o RoomD.o finalRoom.o
	g++ main.o game.o player.o startRoom.o RoomA.o RoomB.o RoomC.o RoomD.o finalRoom.o space.hpp -std=c++11 -o FinalProject

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

game.o: game.cpp
	g++ -std=c++11 -c game.cpp

player.o: player.cpp
	g++ -std=c++11 -c player.cpp

startRoom.o: startRoom.cpp
	g++ -std=c++11 -c startRoom.cpp

RoomA.o: RoomA.cpp
	g++ -std=c++11 -c RoomA.cpp

RoomB.o: RoomB.cpp
	g++ -std=c++11 -c RoomB.cpp

RoomC.o: RoomC.cpp
	g++ -std=c++11 -c RoomC.cpp

RoomD.o: RoomD.cpp
	g++ -std=c++11 -c RoomD.cpp

finalRoom.o: finalRoom.cpp
	g++ -std=c++11 -c finalRoom.cpp


clean:
	rm *.o FinalProject

