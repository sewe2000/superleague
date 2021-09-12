all: clean build
clean:
	rm -f superliga
build:
	g++ -lncurses -std=c++20 src/* -o superleague
debug:
	g++ -g -lncurses -std=c++20 src/* -o superleague
install:
	mkdir -p /usr/bin
	cp superleague /usr/bin
	

