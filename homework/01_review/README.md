# CPTR 242: Homework Assignment #1

## Problem Overview

Complete a program that draws shapes and other items on a board.

## Description

A class named _Draw_ has been given to you that showcases the interaction you will have with the board.
Use the board two dimensional array of the _Draw_ class to manipulate the board display.
You will need to initialize and clear the board.
To clear the board, update the location on the board to a empty character.

These are the complete menu options available:

```sh
Menu options:
  DrawPoint <row> <col> <character>. Adds a point to the GameBoard.
  DrawLine <row> <col> <row2> <col2> <character>. Adds a line to the GameBoard.
  DrawRectangle <row> <col> <row2> <col2> <character>. Adds a rectangle to the GameBoard.
  DrawSmile <row> <col> <row2> <col2>. Adds a SmileFace to the GameBoard.
  DrawFun. Adds a creative drawing to the GameBoard.
  Visualize. Draws the GameBoard.
  ResetVisualization. Reset the GameBoard to empty.
  Quit. Quit application.
  Menu. Display menu.
```

## Solution Specification

Your Draw.cpp should support the following features:

1. Draw a point
1. Draw a Line
1. Draw a Rectangle
1. Draw a fun picture
1. Clear board

A DrawDriver.cpp has been provided to allow a user to run test input.
The code can be compile by running the following command.

```sh
make
```

To test the code, run this command:

```sh
./Draw.out 
```

Example Input:

```sh
MyTest
DrawPoint 4 3 *
Visualize
Quit
```

Resulting Standard Output:

```sh
DrawPoint Command number 1 completed.
Visualize Command number 2 completed.
Quit
Testing completed.
```

Resulting `solutions.txt`:

```sh
MyTest
Draw * point at (4,3).
+----------+
|          |
|          |
|          |
|          |
|   *      |
|          |
|          |
|          |
|          |
|          |
+----------+
```

**You will also find the solution in a `solutions.txt` file while the standard output is primarily for logging.**

The input shown above displays the interaction you will have in order to use the various functions seen in your `Draw.cpp`.
The `Menu` command will displays all the various keywords you can use to correctly call the action you will like to do.
In this case we had called the _DrawPoint_ function from `Draw.cpp` by using the keyword `DrawPoint 4 3 *`.
Keep in mind the two numbers after _DrawPoint_ are followed by a character that will show on the board.
Other functions are set up with a similar set of parameters.

## Tips

* Start with the drawPoint function in _Draw_ class and simply place a random symbol at a random coordinate location.

## Submission

The submission should only include changes to `Draw.cpp`.
All other files (_.h_ and _.cpp_) should remain unchanged.
