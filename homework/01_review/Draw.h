/*************************************************************************
 *
 * Project: Draw header
 *
 * Course:    CPTR 242
 * Date:      March 29, 2021
 */
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

#ifndef DRAW_H
#define DRAW_H

class Draw {
private:
  const static int ROW = 10;
  const static int COL = 10;
  char board[ROW][COL];

public:
  Draw();

  void drawPoint(int row, int col, char character);
  // Function: Place a symbol at a specific point on the GameBoard
  // Pre: GameBoard has been initialized
  // Post: The GameBoard has a point drawn and can be visualized

  void drawLine(int row, int col, int row2, int col2, char character);
  // Function: Make a line by the use of symbols on the GameBoard
  // Pre: GameBoard has been initialized
  // Post: A line has been drawn on the GameBoard and can be visualized

  void drawRectangle(int row, int col, int row2, int col2, char character);
  // Function: Draw a Rectangle shape by the use of symbols on the GameBoard
  // Pre: GameBoard has been initialized
  // Post: A Rectangle shape has been drawn on the GameBoard and can be
  // visualized

  void drawFun();
  // Function: Draw something that is creative on the GameBoard
  // Pre: GameBoard has been initialized
  // Post: User unique piece is drawn on the GameBoard and can be visualized

  void visualization(std::ostream &outStream) {
    // Function: Visualizes all drawings on the GameBoard
    // Pre: GameBoard has been initialized
    // Post: The GameBoard is visualized and able to display all drawings
    outStream << "+----------+" << std::endl;
    for (int row = 0; row < ROW; row++) {
      outStream << "|";
      for (int col = 0; col < COL; col++) {
        outStream << board[row][col];
      }
      outStream << "|";
      outStream << std::endl;
    }
    outStream << "+----------+" << std::endl;
  }

  void resetVisualization();
  // Function: Clears the GameBoard
  // Pre: GameBoard has been initialized
  // Post: GameBoard is reset and set empty from any drawings
};

#endif // DRAW_H
