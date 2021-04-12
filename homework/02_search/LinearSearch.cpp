/*************************************************************************
 *
 * Assignment: Searching
 *
 * File Name:   LinearSearch.cpp
 * Name:        Adam Taylor
 * Course:      CPTR 242
 * Date:        4/11/2021
 */
#include "LinearSearch.h"
#include "ItemType.h"

// TODO implement search
void LinearSearch::Search(std::vector<ItemType> list, ItemType key,
                          int &location, int &comparisons) {
  comparisons = 0;
  location = -2;
  for (int i = 0; i < list.max_size(); i++) {
    comparisons++;
    switch (key.ComparedTo(list.at(i))) {
    case LESS:
      location = -1;
      break;
    case GREATER:
      break;
    case EQUAL:
      location = i;
      break;
    }
    if (location != -2) {
      break;
    }
  }
}