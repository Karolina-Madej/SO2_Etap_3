main: Screen.o Mountain.o Lift.o People.o main.cpp
	g++ -std=c++11 Screen.o Mountain.o Lift.o People.o  main.cpp -lncurses -pthread -fpermissive

Screen.o: Screen.cpp Screen.h
	g++  -c Screen.cpp -std=c++11 -lncurses -fpermissive

Mountain.o: Mountain.cpp Mountain.h
	g++  -c Mountain.cpp -std=c++11 -lncurses -fpermissive

Lift.o:Lift.cpp Lift.h
	g++  -c Lift.cpp -std=c++11 -lncurses -fpermissive

People.o:People.cpp People.h
	g++  -c People.cpp -std=c++11 -lncurses -fpermissive

SafeQueue.o: SafeQueue.cpp
	g++ -c SafeQueue.cpp -std=c++11 -lncurses -fpermissive
clean:
	rm -f *.o test
