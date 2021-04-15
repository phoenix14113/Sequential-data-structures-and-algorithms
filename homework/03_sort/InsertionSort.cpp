/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   InsertionSort.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#include "InsertionSort.h"
#include "ItemType.h"

// TODO implement search
void InsertionSort::sort(std::vector<ItemType> &list, int &comparisons,
                         int &writes) {
  for (int i = 1; i < list.size(); i++) {
    int j = i;
    while (j > 0) {
      // Swap numbers[j] and numbers [j - 1]
      comparisons++;
      ItemType temp;
      switch (list[j].ComparedTo(list[j - 1])) {
      case LESS:
        writes += 3;
        temp = list[j];
        list[j] = list[j - 1];
        list[j - 1] = temp;
        j--;
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