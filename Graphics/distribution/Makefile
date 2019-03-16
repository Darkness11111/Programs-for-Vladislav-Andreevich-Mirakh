# You can create it with commands:
# $ make
# $ ./game
.PHONY: all clean install uninstall
all: game
clean:
	rm -rf game *.o
teorpol.o: teorpol.cpp
	g++ -c -o teorpol.o teorpol.cpp 
game: teorpol.o
	g++ teorpol.o -o game -lsfml-graphics -lsfml-window -lsfml-system
install: 
	install ./game /usr/local/bin
uninstall:
	rm -rf /usr/local/bin/game
