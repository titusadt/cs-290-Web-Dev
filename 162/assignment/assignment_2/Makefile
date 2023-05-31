CC = g++ -g -std=c++11
exe_file = a.out 
$.out(exe_file): pizza.o menu.o restaurant.o driver.o
	$(CC) pizza.o menu.o driver.o restaurant.o -o $(exe_file)
pizza.o: pizza.cpp
	$(CC) -c pizza.cpp
menu.o: menu.cpp
	$(CC) -c menu.cpp
resaturant.o: restaurant.cpp
	$(CC) -c restaurant.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o $(exe_file)
