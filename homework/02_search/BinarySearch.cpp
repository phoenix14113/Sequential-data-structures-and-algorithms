/*************************************************************************
 *
 * Assignment: Searching
 *
 * File Name:   BinarySearch.cpp
 * Name:        Adam Taylor
 * Course:      CPTR 242
 * Date:        4/11/2021
 */
#include "BinarySearch.h"
#include "ItemType.h"

// TODO implement search

void BinarySearch::Search(std::vector<ItemType> list, ItemType key,
                          int &location, int &comparisons) {
  comparisons = 0;
  location = -2;
  int listMax = list.max_size()-1;
  int listMin = 0;
  int listMid = 0;
  while (listMax >= listMin) {
    comparisons++;
    listMid = (listMax + listMin) / 2;
    switch (key.ComparedTo(list.at(listMid))) {
    case LESS:
      listMax = listMid - 1;
      break;
    case GREATER:
      listMin = listMid + 1;
      break;
    case EQUAL:
      location = listMid;
      break;
    }
    if (location != -2) {
      break;
    }
  }
  if (location == -2) {
    location = -1;
  }
}