main: *.o
	g++ -std=c++11 -o main *.o

*.o: *.cpp
	g++ -c *.cpp


run: main
	./main

coverage:
	g++ -std=c++98 -fprofile-arcs -ftest-coverage -c *.cpp
	g++ -std=c++98 -fprofile-arcs -ftest-coverage -o main *.o
	./main
	gcov *.cpp

valgrind:
	valgrind --leak-check=yes --track-origins=yes ./main
    
clean:
	rm *.o *.gcno *.gcda *.gcov main
