/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   InsertionSort.h
 * Name:        Adam Taylor
 * Course:      CPTR 242
 * Date:        4/14/2021
 */
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "ItemType.h"
#include "vector"

class InsertionSort {
public:
  static void sort(std::vector<ItemType> &list, int &comparisons, int &writes);
  // Function: Insertion Sort a vector for key and count the number of
  // comparisons and writes.
  // Pre:     List has been initialized.
  // Post:    The list is modified to be in sorted order,
  // comparisons has the number comparisons and writes made during the sort.

private:
  // TODO Add any necessary private functions
};
#endif // INSERTION_SORT_H