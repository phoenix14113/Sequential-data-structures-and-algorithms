/*************************************************************************
 *
 * Assignment: QueueType implementation file
 *
 * File Name: QueueType.cpp
 * Course:    CPTR 242
 * Date:        ?
 */

#include "QueueType.h"
#include "StackType.h"

// Default class constructor
// Post: Top have been initialized.
QueueType::QueueType() {}

// Post: Top and QueueStack have been reset to the empty state.
void QueueType::MakeEmpty() {
  while (!IsEmpty()) {
    queueStack.Pop();
  }
}

// Returns true if the queue is empty; false otherwise.
bool QueueType::IsEmpty() const { return queueStack.IsEmpty(); }

// Returns true if the queue is full; false otherwise.
bool QueueType::IsFull() const { return queueStack.IsFull(); }

// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.
void QueueType::Enqueue(ItemType newItem) {
  ItemType tmpItem;

  if (queueStack.IsFull()) {
    throw FullQueue();
  } else {
    // move to tmpStack, reverses the order "last out first in"
    while (!queueStack.IsEmpty()) {
      tmpItem = queueStack.Top();
      queueStack.Pop();
      tmpStack.Push(tmpItem);
    }
    // add new element queueStack, "first in last out"
    queueStack.Push(newItem);
    // reverts the order again  "first in last out" + new element
    while (!tmpStack.IsEmpty()) {
      tmpItem = tmpStack.Top();
      tmpStack.Pop();
      queueStack.Push(tmpItem);
    }
  }
}

// Post: If (queue is not empty) the front of the queue has been
//       removed and a copy returned in item;
//       otherwise a EmptyQueue exception has been thrown.
void QueueType::Dequeue(ItemType &item) {
  if (queueStack.IsEmpty())
    throw EmptyQueue();
  else {
    item = queueStack.Top();
    queueStack.Pop();
  }
}

// Post: If (queue is empty) do nothing else search for oldItem in QueueStack,
// replace oldItem in newItem without breaking the order of Items
void QueueType::ReplaceItem(ItemType oldItem, ItemType newItem) {

  if (!queueStack.IsEmpty()) {
    ItemType tmpItem;
    // search requires moving everything to tmp stack, search as it goes.
    while (!queueStack.IsEmpty()) {
      tmpItem = queueStack.Top();
      queueStack.Pop();
      if (tmpItem == oldItem) {
        tmpStack.Push(newItem);
      } else {
        tmpStack.Push(tmpItem);
      }
    }
    // the put everything back to its correct order
    while (!tmpStack.IsEmpty()) {
      tmpItem = tmpStack.Top();
      tmpStack.Pop();
      queueStack.Push(tmpItem);
    }
  }
}
