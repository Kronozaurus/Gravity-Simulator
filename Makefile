all: compile link

compile:
	g++ -I src/include -c main.cpp simulation.cpp celestial_body.cpp

link:
	g++ main.o -o main simulation.o -o simulation celestial_body.o -o celestial_body -L src/lib -l sfml-graphics -l sfml-window -l sfml-system