/*************************************************************************
 *
 * Homework: Submitty Grading
 *
 * File Name:   submitty_driver.cpp
 * Course:      CPTR 242
 *
 */
#include "sortMenu.h"

#include <cassert>
#include <iostream>

inline bool fileExists(const std::string &name) {
  if (FILE *file = fopen(name.c_str(), "r")) {
    fclose(file);
    return true;
  } else {
    return false;
  }
}

int main(int argc, char *argv[]) {

  std::ifstream inStream;
  std::ofstream outStream;

  if (argc > 1 && *argv[1] == '1') {

    std::string input = "input1_selectionSort_test.txt";
    if (!fileExists(input)) {
      // Change path for local testing.
      input = "../test_input/" + input;
    }
    // Test binary search
    inStream.open(input.c_str());
    outStream.open("solutions.txt");
    sortMenu(inStream, outStream, "SelectionSort Test");

  } else if (argc > 1 && *argv[1] == '2') {

    std::string input = "input2_insertionSort_test.txt";
    if (!fileExists(input)) {
      // Change path for local testing.
      input = "../test_input/" + input;
    }
    // Test linear search
    inStream.open(input.c_str());
    outStream.open("solutions.txt");
    sortMenu(inStream, outStream, "InsertionSort Test");

  } else if (argc > 1 && *argv[1] == '3') {

    std::string input = "input3_quickSort_test.txt";
    if (!fileExists(input)) {
      // Change path for local testing.
      input = "../test_input/" + input;
    }
    // Test linear search
    inStream.open(input.c_str());
    outStream.open("solutions.txt");
    sortMenu(inStream, outStream, "QuickSort Test");

  } else if (argc > 1 && *argv[1] == '4') {

    std::string input = "input4_mergeSort_test.txt";
    if (!fileExists(input)) {
      // Change path for local testing.
      input = "../test_input/" + input;
    }
    // Test linear search
    inStream.open(input.c_str());
    outStream.open("solutions.txt");
    sortMenu(inStream, outStream, "MergeSort Test");

  } else if (argc > 1 && *argv[1] == '5') {

    std::string input = "input5_micro_test.txt";
    if (!fileExists(input)) {
      // Change path for local testing.
      input = "../test_input/" + input;
    }
    // Test linear search
    inStream.open(input.c_str());
    outStream.open("solutions.txt");
    sortMenu(inStream, outStream, "Micro SortTest");

  } else {
    std::cout << "Invalid test selected" << std::endl;
  }

  inStream.close();
  outStream.close();
  return 0;
}
