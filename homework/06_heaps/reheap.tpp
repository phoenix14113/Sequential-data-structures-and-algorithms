/****************************************************************************
 *
 * Homework 09: Implement ReheapDown and ReheapUp functions using iteration.
 *
 * File Name:  reheap.tpp
 * Name:       Adam Taylor
 * Course:     CPTR 242
 * Date:       5/6/2021
 * Time Taken: 30 min.
 */
#include "Heap.h"

using namespace std;

template <class ItemType>
void HeapType<ItemType>::ReheapDownIterative(int root, int bottom) {
  // TODO Implement a Iterative ReheapDown Function.
  int maxChild;
  int current = root;
  int rightChild;
  int leftChild;

  do {
    leftChild = current * 2 + 1;
    rightChild = current * 2 + 2;
    if (leftChild <= bottom) {
      if (leftChild == bottom) {
        maxChild = leftChild;
      } else {
        if (elements[leftChild] <= elements[rightChild]) {
          maxChild = rightChild;
        } else {
          maxChild = leftChild;
        }
      }
      if (elements[current] < elements[maxChild]) {
        Swap(elements[current], elements[maxChild]);
        current = maxChild;
      } else {
        return;
      }
    }else{
        return;
    }
  } while (true);
}

template <class ItemType>
void HeapType<ItemType>::ReheapUpIterative(int root, int bottom) {
  // TODO Implement a Iterative ReheapUp Function.
  int parent;
  int current = bottom;
  do {
    if (current >= root) {
      parent = (current - 1) / 2;
      if (elements[parent] < elements[bottom]) {
        Swap(elements[parent], elements[bottom]);
        current = parent;
      } else {
        return;
      }
    } else {
      return;
    }
  } while (true);
}
