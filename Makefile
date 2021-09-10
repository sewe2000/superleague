all: clean build
clean:
	rm -f superliga
build:
	g++ -lncurses -std=c++20 src/* -o superliga
debug:
	g++ -g -lncurses -std=c++20 src/* -o superliga
