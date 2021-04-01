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
  for(int i = 0; i < 20; i++){
    int centerRow = (row+row2Temp)/2;
    int centerCol = (col+col2Temp)/2;
    board[centerRow][centerCol] = character;
    row2Temp = centerRow;
    col2Temp = centerCol;
  }
  for(int i = 0; i < 20; i++){
    int centerRow = (rowTemp+row2)/2;
    int centerCol = (colTemp+col2)/2;
    board[centerRow][centerCol] = character;
    rowTemp = centerRow;
    colTemp = centerCol;
  }


}

void Draw::drawRectangle(int row, int col, int row2, int col2, char character) {
  if (col2 >= col) {
    for (int i = 0; i <= col2 - col; i++) {
      board[row][col + i] = character;
    }

    for (int i = 0; i <= col2 - col; i++) {
      board[row2][col + i] = character;
    }
  } else {
    for (int i = 0; i <= col - col2; i++) {
      board[row][col2 + i] = character;
    }

    for (int i = 0; i <= col - col2; i++) {
      board[row2][col2 + i] = character;
    }
  }
  if (row2 >= row) {
    for (int i = 0; i <= row2 - row; i++) {
      board[row+i][col] = character;
    }

    for (int i = 0; i <= row2 - row; i++) {
      board[row+i][col2] = character;
    }
  }else{
    for (int i = 0; i <= row - row2; i++) {
      board[row2+i][col] = character;
    }

    for (int i = 0; i <= row - row2; i++) {
      board[row2+i][col2] = character;
    }      
  }
}

void Draw::drawFun() {
    //head
    for(int i = 1; i < 5; i++){
        for(int j = 2; j < 8; j++){
            board[i][j] = '*';
        }
    }
    //eyes
    board[2][3] = '|';
    board[2][6] = '|';

    //neck
    board[5][4] = '*';
    board[5][5] = '*';
    //body
    for(int i = 6; i < 10; i++){
        for(int j = 3; j < 7; j++){
            board[i][j] = '*';
        }
    }
    //shoulders
    board[6][2] = '/';
    board[6][7] = '\\';

    //arms
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
