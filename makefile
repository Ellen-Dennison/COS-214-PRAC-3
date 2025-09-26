run: main
	./main


main: main.o ChatRoom.o CtrlCat.o Dogorithm.o Users.o Name1.o Name2.o Name3.o
	g++ -std=c++98 main.o ChatRoom.o CtrlCat.o Dogorithm.o Users.o Name1.o Name2.o Name3.o -o main

main.o: main.cpp ChatRoom.h CtrlCat.h Dogorithm.h Users.h
	g++ -c main.cpp

Name1.o: Name1.cpp Name1.h Users.h
	g++ -c Name1.cpp


Name2.o: Name2.cpp Name2.h Users.h
	g++ -c Name2.cpp

Name3.o: Name3.cpp Name3.h Users.h
	g++ -c Name3.cpp

ChatRoom.o: ChatRoom.cpp ChatRoom.h Users.h
	g++ -c ChatRoom.cpp

CtrlCat.o: CtrlCat.cpp CtrlCat.h ChatRoom.h
	g++ -c CtrlCat.cpp

Dogorithm.o: Dogorithm.cpp Dogorithm.h ChatRoom.h
	g++ -c Dogorithm.cpp

Users.o: Users.cpp Users.h ChatRoom.h
	g++ -c Users.cpp

clean:
	rm *.o main