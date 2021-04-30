#ifndef DEQUE_H
#define DEQUE_H

#include "DoublyLinkedList.h"

class Deque {
private:
   LinkedList linkedList;

public:
   Deque() {
   }
   
   void PushFront(int newData) {
      // TODO
      Node* newNode = new Node(newData);
      
      linkedList.Prepend(newNode);
   }
   
   void PushBack(int newData) {
      // TODO
      Node* newNode = new Node(newData);

      linkedList.Append(newNode);
   }

   int PopFront() {
      // TODO
      
   }
   
   int PopBack() {
      // TODO
   }

   int PeekFront() {
      // TODO
       
   }
   
   int PeekBack() {
      // TODO
   }
   
   void Print(std::ostream& printStream) {
      linkedList.PrintList(printStream);
   }
};

#endif