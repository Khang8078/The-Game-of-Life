# The-Game-of-Life
# INTRODUCTION TO PROGRAMMING
# BERKELEY CITY COLLEGE
# Project
The life game consists of a board with size of NxN cells and cells are occupied by creatures. Each cell can have at most one creature. The surrounding cells are called the neighbors of this cell.  
Each game state is called “generation”. The game progresses from one generation to the next according to the following rules:
1.  A creature that has more than 3 neighbors – dies of crowding. Its   cell will be empty in thenext generation.
2.  A creature that has less than 2 neighbors dies of loneliness. 
3.  If an empty cell that has exactly 3 neighbors, a new creature is born in that cell.
Write a program that consists of a 10 x 10 cell grid board. The program will prompt for the initial state of the world and the number of generations to be played. After each generation the program will update the state of the board and will display the updated board. The program can stop if it has reached the number of required generations or if no further changes occur ( i.e., no more creatures alive or it has reached a steady or repeating pattern) 
Note that the changes in the board in each generation are done simultaneously on all the cells, so you may need to define and use two boards for computing the changes.

--> The Input:
1. An integer indicating the number of stages that should be played.
2. The initial state of the board – the locations of the creatures on the board.

-->The Output:

The state of the board in each generation, starting with the initial state: Print ‘-‘ for an empty cell and ‘X’ for a creature.

