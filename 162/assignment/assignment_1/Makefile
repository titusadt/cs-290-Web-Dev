CC = g++ -g -std=c++11
exe_file = a.out 
$.out(exe_file): wizard.o prog.o
	$(CC) wizard.o prog.o -o $(exe_file)
wizard.o: wizard.cpp
	$(CC) -c wizard.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)
