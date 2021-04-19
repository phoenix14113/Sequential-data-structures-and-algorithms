/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   InsertionSort.cpp
 * Name:        Adam Taylor
 * Course:      CPTR 242
 * Date:        4/17/2021
 */
#include "InsertionSort.h"
#include "ItemType.h"

// TODO implement search
void InsertionSort::sort(std::vector<ItemType> &list, int &comparisons,
                         int &writes) {
  comparisons = 0;
  writes = 0;
  for (int i = 1; i < list.size(); i++) {
    int j = i;
    bool continuation = true;
    comparisons++;
    while (j > 0 && continuation) {
      // Swap numbers[j] and numbers [j - 1]
      comparisons++;
      ItemType temp;
      continuation = false;
      switch (list[j].ComparedTo(list[j - 1])) {
      case LESS:
        writes += 3;
        temp = list[j];
        list[j] = list[j - 1];
        list[j - 1] = temp;
        j--;
        continuation = true;
        break;
      case GREATER:
        // Do something for greater than
        break;
      case EQUAL:
        // Do something for equal
        break;
      }
    }
  }
}