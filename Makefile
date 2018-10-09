myspeller: myspeller.o search.o 
	g++ myspeller.o search.o -o myspeller
speller.o: myspeller.cpp
	g++ -c myspeller.cpp
search.o: search.cpp search.h
	g++ -c search.cpp
clean:
	rm *.o myspeller

