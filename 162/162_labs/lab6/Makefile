CC = g++ -Wall -g
exe_file = a.out 
$.out(exe_file): shape.o rectangle.o circle.o application.o
	$(CC) shape.o rectangle.o circle.o application.o -o $(exe_file)
shape.o: shape.cpp
	$(CC) -c shape.cpp
rectangle.o: rectangle.cpp	
	$(CC) -c rectangle.cpp
circle.o: circle.cpp
	$(CC) -c circle.cpp

application.o: application.cpp
	$(CC) -c application.cpp

clean:
	rm -f *.out *.o $(exe_file)
