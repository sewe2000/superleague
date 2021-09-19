CXXFLAGS = -O2 -std=c++20 -Wall
LIBS = -lncurses
OBJS = obj/engine.o obj/footballer.o obj/main.o obj/menu.o obj/person.o obj/save.o

superleague: $(OBJS) 
	$(CXX) $(LIBS) -o superleague $(OBJS) 
obj/engine.o: src/engine.cpp include/engine.hpp include/menu.hpp
	$(CXX) $(CXXFLAGS) -c src/engine.cpp -o obj/engine.o
obj/footballer.o: src/footballer.cpp include/footballer.hpp 
	$(CXX) $(CXXFLAGS) -c src/footballer.cpp -o obj/footballer.o
obj/main.o: src/main.cpp include/engine.hpp 
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o
obj/menu.o: src/menu.cpp include/menu.hpp 
	$(CXX) $(CXXFLAGS) -c src/menu.cpp -o obj/menu.o
obj/person.o: src/person.cpp include/person.hpp 
	$(CXX) $(CXXFLAGS) -c src/person.cpp -o obj/person.o
obj/save.o: src/save.cpp include/save.hpp 
	$(CXX) $(CXXFLAGS) -c src/save.cpp -o obj/save.o
clean:
	rm -f superleague
	rm -f obj/*
install:
	mkdir -p /usr/bin
	cp superleague /usr/bin
	

