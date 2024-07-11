.default: all

all: main

clean:
	rm -f main *.o

reload: clean all


main: Book.o  Inventory.o main.o
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^ 

%.o: %.cpp 
	g++ -Wall -Werror -std=c++17 -g -O -c $^