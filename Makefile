CXXFLAGS +=-std=c++11

main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o

tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o
	
main.o: main.cpp profile.h network.o

tests.o: tests.cpp doctest.h profile.h network.h

profile.o: profile.cpp profile.h 
	g++ -g -c profile.cpp

network.o: network.cpp network.h profile.h
	g++ -g -c network.cpp

clean:
	rm -f main.o tests.o profile.o network.o
