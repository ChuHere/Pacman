CXX=g++
CXXFLAGS=-Wall -pedantic
LD=g++
LDFLAGS=-Wall -pedantic

SRC=$(wildcard src/*.cpp)
HDR=$(wildcard src/*.h)
OBJ=$(patsubst src/%.cpp, %.o, $(SRC))

all: compile

pacman: $(OBJ)
	$(LD) $(LDFLAGS) $^ -o $@

compile: pacman

run: pacman
	./pacman

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf pacman *.o core

Application.o: src/Application.cpp src/Application.h src/Game.h \
 src/Config.h src/Board.h src/GameState.h src/Pacman.h src/Coord.h \
 src/BoardTile.h src/Effect.h src/Ghost.h
Board.o: src/Board.cpp src/Board.h src/GameState.h src/Pacman.h \
 src/Coord.h src/BoardTile.h src/Effect.h src/Coin.h
BoardTile.o: src/BoardTile.cpp src/BoardTile.h src/Effect.h \
 src/GameState.h src/Pacman.h src/Coord.h
Chaser.o: src/Chaser.cpp src/Chaser.h src/Ghost.h src/Board.h \
 src/GameState.h src/Pacman.h src/Coord.h src/BoardTile.h src/Effect.h
Cherry.o: src/Cherry.cpp src/Cherry.h src/Effect.h src/GameState.h \
 src/Pacman.h src/Coord.h
Coin.o: src/Coin.cpp src/Coin.h src/Effect.h src/GameState.h src/Pacman.h \
 src/Coord.h
Config.o: src/Config.cpp src/Config.h
Coord.o: src/Coord.cpp src/Coord.h
Dumb.o: src/Dumb.cpp src/Dumb.h src/Ghost.h src/Board.h src/GameState.h \
 src/Pacman.h src/Coord.h src/BoardTile.h src/Effect.h
Effect.o: src/Effect.cpp src/Effect.h src/GameState.h src/Pacman.h \
 src/Coord.h
Game.o: src/Game.cpp src/Game.h src/Config.h src/Board.h src/GameState.h \
 src/Pacman.h src/Coord.h src/BoardTile.h src/Effect.h src/Ghost.h \
 src/Coin.h src/Cherry.h src/Teleport.h src/Dumb.h src/Chaser.h \
 src/Zombie.h
GameState.o: src/GameState.cpp src/GameState.h src/Pacman.h src/Coord.h
Ghost.o: src/Ghost.cpp src/Ghost.h src/Board.h src/GameState.h \
 src/Pacman.h src/Coord.h src/BoardTile.h src/Effect.h
Pacman.o: src/Pacman.cpp src/Pacman.h src/Coord.h
Teleport.o: src/Teleport.cpp src/Teleport.h src/Effect.h src/GameState.h \
 src/Pacman.h src/Coord.h
Zombie.o: src/Zombie.cpp src/Zombie.h src/Ghost.h src/Board.h \
 src/GameState.h src/Pacman.h src/Coord.h src/BoardTile.h src/Effect.h
main.o: src/main.cpp src/Application.h src/Game.h src/Config.h \
 src/Board.h src/GameState.h src/Pacman.h src/Coord.h src/BoardTile.h \
 src/Effect.h src/Ghost.h