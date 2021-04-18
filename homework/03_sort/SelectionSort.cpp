/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   SelectionSort.cpp
 * Name:        Adam Taylor
 * Course:      CPTR 242
 * Date:        4/17/2021
 */
#include "SelectionSort.h"
#include "ItemType.h"


// TODO implement search
void SelectionSort::sort(std::vector<ItemType> &list, int &comparisons,
                         int &writes) {
  comparisons = 0;
  writes = 0;
  for (int i = 0; i < list.size() - 1; i++) {
    // Find index of smallest remaining element
    int indexSmallest = i;
    for (int j = i + 1; j < list.size(); j++) {
      comparisons++;
      switch (list[indexSmallest].ComparedTo(list[j])) {
      case LESS:
        break;
      case GREATER:
        // Do something for greater than
        indexSmallest = j;
        break;
      case EQUAL:
        // Do something for equal
        break;
      }
    }

    // Swap numbers[i] and numbers[indexSmallest]
    writes += 3;
    ItemType temp = list[i];
    list[i] = list[indexSmallest];
    list[indexSmallest] = temp;
  }
}