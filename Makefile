c lab3: main.o Stack.o Queue.o exec.o 
	g++ -std=c++11 -g -Wall main.o Stack.o Queue.o exec.o -o lab3

main.o: main.cpp Stack.h Queue.h Node.h  exec.h
	g++ -std=c++11 -g -Wall -c main.cpp

exec.o: exec.h Stack.h Queue.h Node.h exec.cpp
	g++ -std=c++11 -g -Wall -c exec.cpp

Queue.o: exec.h Stack.h Queue.h Node.h Queue.cpp
	g++ -std=c++11 -g -Wall -c Queue.cpp

Stack.o: Stack.h Node.h Queue.h exec.h Stack.cpp
	g++ -std=c++11 -g -Wall -c Stack.cpp

clean: 
	rm *.o lab3