CXXFLAGS = -O2 -std=c++20 -Wall
LIBS = -lncurses
OBJS = obj/engine.o obj/footballer.o obj/main.o obj/menu.o obj/person.o obj/save.o

superleague: $(OBJS) 
	$(CXX) $(LIBS) -o superleague $(OBJS) 
obj/engine.o: include/engine.hpp include/menu.hpp
	$(CXX) $(CXXFLAGS) -c src/engine.cpp -o obj/engine.o
obj/footballer.o: include/footballer.hpp 
	$(CXX) $(CXXFLAGS) -c src/footballer.cpp -o obj/footballer.o
obj/main.o: include/engine.hpp 
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o
obj/menu.o: include/menu.hpp 
	$(CXX) $(CXXFLAGS) -c src/menu.cpp -o obj/menu.o
obj/person.o: include/person.hpp 
	$(CXX) $(CXXFLAGS) -c src/person.cpp -o obj/person.o
obj/save.o: include/save.hpp 
	$(CXX) $(CXXFLAGS) -c src/save.cpp -o obj/save.o
clean:
	rm -f superleague
	rm -f obj/*
install:
	mkdir -p /usr/bin
	cp superleague /usr/bin
	

