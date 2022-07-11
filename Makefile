all: compile run

compile :
		g++ -c unit/Unit.cpp
		g++ -c player/Player.cpp
		g++ main.cpp Unit.o Player.o -lsfml-graphics  -lsfml-window -lsfml-system
run:
		./a.out
clean:
		rm *.o a.out
