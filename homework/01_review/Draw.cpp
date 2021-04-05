/*************************************************************************
 *
 * Project: Draw
 *
 * Course:    CPTR 242
 * Date:      March 29, 2021
 */

#include "Draw.h"
#include <iostream>

Draw::Draw() { resetVisualization(); }

void Draw::drawPoint(int row, int col, char character) {
  board[row][col] = character;
}

void Draw::drawLine(int row, int col, int row2, int col2, char character) {
  board[row][col] = character;
  board[row2][col2] = character;
  int rowTemp = row;
  int row2Temp = row2;
  int colTemp = col;
  int col2Temp = col2;

  // fill in points left of the original 2 point's center point
  if ((row <= row2 && col <= col2) || (row2 <= row && col2 <= col)) {
    for (int i = 0; i < 4; i++) {
      int centerRow = (row + row2Temp) / 2;
      int centerCol = (col + col2Temp) / 2;
      board[centerRow][centerCol] = character;
      board[(centerRow + row2) / 2][(centerCol + col2) / 2] = character;
      row2Temp = centerRow;
      col2Temp = centerCol;
    }
    // fill in points right of the original 2 point's center point
    for (int i = 0; i < 4; i++) {
      int centerRow = (rowTemp + row2) / 2;
      int centerCol = (colTemp + col2) / 2;
      board[centerRow][centerCol] = character;
      board[(centerRow + row) / 2][(centerCol + col) / 2] = character;
      rowTemp = centerRow;
      colTemp = centerCol;
    }
  } else {
    for (int i = 0; i < 2; i++) {
      int centerRow = (row + row2Temp) / 2;
      int centerCol = (col + col2Temp) / 2;
      board[centerRow][centerCol] = character;
      board[(centerRow + 1 + row2) / 2][(centerCol + col2) / 2] = character;
      row2Temp = centerRow;
      col2Temp = centerCol;
    }
    // fill in points right of the original 2 point's center point
    for (int i = 0; i < 2; i++) {
      int centerRow = (rowTemp + row2) / 2;
      int centerCol = (colTemp + col2) / 2;
      board[centerRow][centerCol] = character;
      board[(centerRow + 1 + row) / 2][(centerCol + col) / 2] = character;
      rowTemp = centerRow;
      colTemp = centerCol;
    }
  }
}

void Draw::drawRectangle(int row, int col, int row2, int col2, char character) {
  if (row > row2) {
    if (col > col2) {
      for (int i = row2; i <= row; i++) {
        for (int j = col2; j <= col; j++) {
          board[i][j] = character;
        }
      }
    } else {
      for (int i = row2; i < row; i++) {
        for (int j = col; j <= col2; j++) {
          board[i][j] = character;
        }
      }
    }
  } else {
    if (col > col2) {
      for (int i = row; i <= row2; i++) {
        for (int j = col2; j < col; j++) {
          board[i][j] = character;
        }
      }
    } else {
      for (int i = row; i <= row2; i++) {
        for (int j = col; j <= col2; j++) {
          board[i][j] = character;
        }
      }
    }
  }
}

void Draw::drawFun() {
  // head
  for (int i = 1; i < 5; i++) {
    for (int j = 2; j < 8; j++) {
      board[i][j] = '*';
    }
  }
  // eyes
  board[2][3] = '|';
  board[2][6] = '|';

  // neck
  board[5][4] = '*';
  board[5][5] = '*';
  // body
  for (int i = 6; i < 10; i++) {
    for (int j = 3; j < 7; j++) {
      board[i][j] = '*';
    }
  }
  // shoulders
  board[6][2] = '/';
  board[6][7] = '\\';

  // arms
  board[7][1] = '|';
  board[8][1] = '|';

  board[7][8] = '|';
  board[8][8] = '|';
}

void Draw::resetVisualization() {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      board[i][j] = ' ';
    }
  }
}
