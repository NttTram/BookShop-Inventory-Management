appname := BookStore

CXX = g++
CXX_FLAGS= -std=g++11 -Wall -g -Werror

srcfile := $(shell find . -maxdepth 1 -name "*.cpp")
objects := $(pathsubst %.cpp, %.o $(srcfiles))

all: $(appname)

$(appname): $(objects) 
	$(CXX) $(CXX_FLAGS) -o $(appname) $(objects)

