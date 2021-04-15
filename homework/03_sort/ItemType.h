/*************************************************************************
 *
 * Assignment: The following declarations and definitions go into file
 * ItemType.h
 *
 * File Name:  ItemType.h
 * Course:     CPTR 242
 * Source:     C++ Plus Data Structures 6th Edition
 *             by Nell Dale, Chip Weems, Tim Richards
 */
#ifndef ITEM_TYPE_H
#define ITEM_TYPE_H

#include <fstream>
const int MAX_ITEMS = 5;
enum RelationType { LESS, GREATER, EQUAL };

class ItemType {
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream &) const;
  void Initialize(int number);

private:
  int value;
};

#endif // ITEM_TYPE_H
