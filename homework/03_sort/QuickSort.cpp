/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   QuickSort.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#include "QuickSort.h"
#include "ItemType.h"

// TODO implement search
void QuickSort::sort(std::vector<ItemType> &list, int &comparisons,
                     int &writes) {
  comparisons = 0;
  writes = 0;
  quicksort(list, comparisons, writes, 0, list.size() - 1);
}
void QuickSort::quicksort(std::vector<ItemType> &list, int &comparisons,
                          int &writes, int startIndex, int endIndex) {
  // Only sort if at least 2 elements exist
  if (endIndex <= startIndex) {
    return;
  }

  // Partition the array
  int high = Partition(list, comparisons, writes, startIndex, endIndex);

  // Recursively sort the left partition
  quicksort(list, comparisons, writes, startIndex, high);

  // Recursively sort the right partition
  quicksort(list, comparisons, writes, high + 1, endIndex);
}
int QuickSort::Partition(std::vector<ItemType> &list, int &comparisons,
                         int &writes, int startIndex, int endIndex) {
  // Select the middle value as the pivot.
  int pivot = startIndex + (endIndex - startIndex) / 2;

  // "low" and "high" start at the ends of the partition
  // and move toward each other.
  int low = startIndex;
  int high = endIndex;

  bool done = false;
  while (!done) {
    // Increment low while numbers[low] < pivot
    bool moveon = false;
    while (!moveon) {
      comparisons++;
      switch (list[low].ComparedTo(list[pivot])) {
      case LESS:
        low = low + 1;
        break;
      case GREATER:
        // Do something for greater than
        moveon = true;
        break;
      case EQUAL:
        // Do something for equal
        moveon = true;
        break;
      }
    }
    moveon = false;
    // Decrement high while pivot < numbers[high]
    while (!moveon) {
      comparisons++;
      switch (list[pivot].ComparedTo(list[high])) {
      case LESS:
        high = high - 1;
        break;
      case GREATER:
        // Do something for greater than
        moveon = true;
        break;
      case EQUAL:
        // Do something for equal
        moveon = true;
        break;
      }
    }

    // If low and high have crossed each other, the loop
    // is done. If not, the elements are swapped, low is
    // incremented and high is decremented.
    if (low >= high) {
      done = true;
    } else {
      writes += 3;
      ItemType temp = list[low];
      list[low] = list[high];
      list[high] = temp;
      low = low + 1;
      high = high - 1;
    }
  }

  // "high" is the last index in the left partition.
  return high;
}