main: *.o
	g++ -std=c++98 -o main *.o

*.o: *.cpp
	g++ -c *.cpp


run: main
	./main

coverage:
	g++ -std=c++98 -fprofile-arcs -ftest-coverage -c *.cpp
	g++ -std=c++98 -fprofile-arcs -ftest-coverage -o main *.o
	./main
	gcov *.cpp

    
clean:
	rm *.o *.gcno *.gcda *.gcov main