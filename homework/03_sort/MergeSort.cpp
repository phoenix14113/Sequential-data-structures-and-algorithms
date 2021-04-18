/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   MergeSort.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#include "MergeSort.h"
#include "ItemType.h"

// TODO implement search
void MergeSort::sort(std::vector<ItemType> &list, int &comparisons,
                     int &writes) {
  comparisons = 0;
  writes = 0;
  mergesort(list, comparisons, writes, 0, list.size() - 1);
}
void MergeSort::merge(std::vector<ItemType> &list, int &comparisons,
                      int &writes, int leftFirst, int leftLast, int rightLast) {
  int mergedSize = rightLast - leftFirst + 1; // Size of merged partition
  ItemType *mergedItems =
      new ItemType[mergedSize]; // Dynamically allocates temporary
                                // array for merged numbers
  int mergePos = 0;             // Position to insert merged number
  int leftPos = leftFirst;      // Initialize left partition position
  int rightPos = leftLast + 1;  // Initialize right partition position

  // Add smallest element from left or right partition to merged numbers
  while (leftPos <= leftLast && rightPos <= rightLast) {
    comparisons++;
    writes++;
    switch (list[leftPos].ComparedTo(list[rightPos])) {
    case LESS:
      mergedItems[mergePos] = list[leftPos];
      leftPos++;
      break;
    case GREATER:
      // Do something for greater than
      mergedItems[mergePos] = list[rightPos];
      rightPos++;
      break;
    case EQUAL:
      // Do something for equal
      mergedItems[mergePos] = list[leftPos];
      leftPos++;
      break;
    }
    mergePos++;
  }

  // If left partition is not empty, add remaining elements to merged numbers
  while (leftPos <= leftLast) {
    writes++;
    mergedItems[mergePos] = list[leftPos];
    leftPos++;
    mergePos++;
  }

  // If right partition is not empty, add remaining elements to merged numbers
  while (rightPos <= rightLast) {
    writes++;
    mergedItems[mergePos] = list[rightPos];
    rightPos++;
    mergePos++;
  }

  // Copy merged numbers back to numbers
  for (mergePos = 0; mergePos < mergedSize; mergePos++) {
    writes++;
    list[leftFirst + mergePos] = mergedItems[mergePos];
  }

  // Free temporary array
  delete[] mergedItems;
}
void MergeSort::mergesort(std::vector<ItemType> &list, int &comparisons,
                          int &writes, int startIndex, int endIndex) {

  if (startIndex < endIndex) {
    // Find the midpoint in the partition
    int mid = (startIndex + endIndex) / 2;

    // Recursively sort left and right partitions
    mergesort(list, comparisons, writes, startIndex, mid);
    mergesort(list, comparisons, writes, mid + 1, endIndex);

    // Merge left and right partition in sorted order
    merge(list, comparisons, writes, startIndex, mid, endIndex);
  }
}