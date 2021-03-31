/*************************************************************************
 *
 * Project: Test driver
 *
 * Course:    CPTR 242
 */
#include "DrawMenu.h"
#include <iostream>
#include <string>

int main() {
  std::string outputLabel;

  // Prompt for test name
  std::cout << "Enter name of test run; press return." << std::endl;
  std::cin >> outputLabel;

  std::ofstream outStream;
  outStream.open("solutions.txt");

  DrawMenu(std::cin, outStream, outputLabel);
};
