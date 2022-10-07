all: compile link run
compile:
	g++ -I src/include -c main.cpp
link:
	g++ main.o -o app -L src/lib -l sfml-graphics -l sfml-window -l sfml-system
run:
	./app