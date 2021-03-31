/*************************************************************************
 *
 * Project: Menu
 *
 * File Name: DrawMenu.cpp
 * Course:    CPTR 242
 * Date:      May 22, 2019
 */
#include "Draw.h"
#include <fstream>
#include <iostream>
#include <string>

void DrawMenu(std::istream &inStream, std::ostream &outStream,
              std::string outputLabel) {
  // Used for test driver functionality.
  std::string option;
  // Used to interact with Draw.
  char character;
  int col;
  int row;
  int col2;
  int row2;

  Draw board;

  outStream << outputLabel << std::endl;
  inStream >> option;

  // Test driver menu and options
  int numOptions = 0;
  while (option != "Quit") {
    std::cout << option;
    if (option == "Menu") {
      outStream << "Menu options:" << std::endl;
      outStream
          << "  DrawPoint <row> <col> <character>. Adds a point to the GameBoard."
          << std::endl;
      outStream
          << "  DrawLine <row> <col> <row2> <col2> <character>. Adds a line to "
             "the GameBoard."
          << std::endl;
      outStream
          << "  DrawRectangle <row> <col> <row2> <col2> <character>. Adds a "
             "rectangle to the GameBoard."
          << std::endl;
      outStream << "  DrawSmile <row> <col> <row2> <col2>. Adds a SmileFace to "
                   "the GameBoard."
                << std::endl;
      outStream << "  DrawFun. Adds a creative drawing to the GameBoard."
                << std::endl;
      outStream << "  Visualize. Draws the GameBoard." << std::endl;
      outStream << "  ResetVisualization. Reset the GameBoard to empty."
                << std::endl;
      outStream << "  Quit. Quit application." << std::endl;
      outStream << "  Menu. Display menu." << std::endl;
    } else if (option == "DrawPoint") {
      inStream >> row;
      inStream >> col;
      inStream >> character;

      board.drawPoint(row, col, character);
      outStream << "Draw " << character << " point at (" << row << "," << col
                << ")." << std::endl;
    } else if (option == "DrawLine") {
      inStream >> row;
      inStream >> col;
      inStream >> row2;
      inStream >> col2;
      inStream >> character;

      board.drawLine(row, col, row2, col2, character);
      outStream << "Draw " << character << " line at (" << row << "," << col
                << ") to (" << row2 << "," << col2 << ")." << std::endl;
    } else if (option == "DrawRectangle") {
      inStream >> row;
      inStream >> col;
      inStream >> row2;
      inStream >> col2;
      inStream >> character;

      board.drawRectangle(row, col, row2, col2, character);
      outStream << "Draw " << character << " rectangle at (" << row << ","
                << col << ") to (" << row2 << "," << col2 << ")." << std::endl;
    } else if (option == "DrawFun") {
      board.drawFun();
      outStream << "Draw "
                << "creative drawing." << std::endl;
    } else if (option == "ResetBoard") {
      board.resetVisualization();
      outStream << "Reset board." << std::endl;
    } else if (option == "Visualize") {
      board.visualization(outStream);
    } else {
      std::cout << option << " is not a valid command." << std::endl;
    }
    numOptions++;
    std::cout << " Command number " << numOptions << " completed." << std::endl;
    inStream >> option;
  };

  std::cout << "Quit" << std::endl << "Testing completed." << std::endl;
}
