all:
		g++ -c unit/Unit.cpp
		g++ main.cpp Unit.o -lsfml-graphics  -lsfml-window -lsfml-system
