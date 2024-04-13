Pacman project in C++. The main idea was to practice making a scalable code. This might be an overcomplicated implementation of a simple Pacman game. It is a turn-based implementation and in terminal.

How to run the game: You must be in the root directory (the one with Makefile) with g++ installed. Use 'make all' to compile the application. Then you can use 'make run' to run the game.

Use of polymorphism:
Ghost behaviour: chasing, dumb, zombie (moves randomly but attacks Pacman on sight)
Effects: cherry (Pacman powerup, allows to hunt ghosts), coins (score), teleport (teleports Pacman to the other end of map)

In config.utf8 file you can configurate the map (Easy, Medium, Hard) and the length of powerups.

You can also create a custom map following these rules:
* Top and bottom are all walls, sides can be either walls or teleports
* Teleports can only be placed on the side borders. They must all be paired up - one on each side of the border in line. They can't be blocked by walls.
* Cherries are marked as 'g', coins as '.', pacman as 'O'.
* Ghosts are maked '1' for 'Chaser', '2' for 'Zombie' and '3' for 'Dumb'.

If the map is not valid, the application will end.

Controls: w (up), s (down), a (left), d (right).
