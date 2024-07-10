.default: all

all: main

clean:
	rm -f main *.o

reload: clean all


mazeRunner: Book.o Main.o 
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^ -lmcpp 

%.o: %.cpp 
	g++ -Wall -Werror -std=c++17 -g -O -c $^