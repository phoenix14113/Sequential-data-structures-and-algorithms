/*************************************************************************
 *
 * Project: GameList implemented using linked list
 *
 * File Name: GameList.cpp
 * Name:      Adam Taylor
 * Course:    CPTR 242
 * Date:      4/18/2021
 *
 */
#include "GameList.h"
#include "Array.h"
#include "Bridges.h"
#include "DataSource.h"
#include "SLelement.h"
#include <iostream>

using namespace bridges;

GameList::GameList() {
  // Class constructor
  length = 0;
  listData = NULL;
}

GameList::~GameList() {
  // Post: List is empty; all items have been deallocated.
  MakeEmpty();
}

bool GameList::IsFull() const {
  // Returns true if there is no room for another actor
  //  on the free store; false otherwise.
  SLelement<string> *location;
  try {
    location = new SLelement<string>;
    delete location;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}

int GameList::GetLength() const {
  // Post: Number of items in the list is returned.
  return length;
}

void GameList::MakeEmpty() {
  // TODO Add code here.
  SLelement<string> *currentNode = listData;
  while (currentNode) {
    SLelement<string> *toBeDeleted = currentNode;
    currentNode = currentNode->getNext();
    delete toBeDeleted;
  }
  length = 0;
  ResetList();
}

SLelement<string> *GameList::GetHead() { return listData; }

void GameList::PutGame(std::string title, std::string gameDetails,
                       double rating) {
  // create new node.
  SLelement<std::string> *newGame = new SLelement<std::string>;
  newGame->setLabel(title + "\n" + gameDetails);
  newGame->setValue(title);

  // visualization customization
  // size of node
  float size = 0;
  if (rating < 1) {
    size = 10.0f;
  } else if (rating < 2) {
    size = 11.0f;
  } else if (rating < 3) {
    size = 12.5f;
  } else if (rating < 4) {
    size = 15.0f;
  } else if (rating < 5) {
    size = 18.0f;
  } else if (rating < 6) {
    size = 21.5f;
  } else if (rating < 7) {
    size = 25.5f;
  } else if (rating < 8) {
    size = 31.0f;
  } else if (rating < 9) {
    size = 38.0f;
  } else if (rating < 10) {
    size = 45.5f;
  } else {
    size = 60.0f;
  }
  newGame->getVisualizer()->setSize(size);

  // color of node
  std::string color;
  if (rating <= 2) {
    color = "darkred";
  } else if (rating <= 4) {
    color = "red";
  } else if (rating <= 6) {
    color = "orange";
  } else if (rating <= 8) {
    color = "yellow";
  } else if (rating < 10) {
    color = "green";
  } else {
    color = "blue";
  }
  newGame->getVisualizer()->setColor(color);

  // adding elements to the list
  if (length == 0) {
    // empty list
    listData = newGame;
    length++;
  } else {
    // not empty list
    ResetList();
    SLelement<std::string> *previous = new SLelement<std::string>;
    for (int i = 1; i <= length; i++) {
      if (currentPos->getValue() > title &&
          currentPos->getValue() == listData->getValue()) {
        // first node case
        // insert the new node before the first node greater than it
        newGame->setNext(currentPos);
        previous->setNext(newGame);
        listData = newGame;
        length++;
        break;
      } else if (currentPos->getValue() > title) {
        // insert the new node before the first node greater than it
        newGame->setNext(currentPos);
        previous->setNext(newGame);
        length++;
        break;
      } else if (i == length) {
        // final element case
        currentPos->setNext(newGame);
        length++;
        break;
      } else {
        // compare next node
        previous = currentPos;
        currentPos = currentPos->getNext();
      }
    }
  }
  ResetList();
}

void GameList::GetGame(std::string title, std::string &gameDetails,
                       bool &found) {
  // determine if title is in the list
  found = false;
  for (int i = 0; i < length; i++) {
    if (currentPos->getValue() == title) {
      // if it is the current node
      gameDetails = currentPos->getValue();
      found = true;
      ResetList();
      return;
    } else if (currentPos->getValue() > title) {
      // if the current node is greater it won't be in the list
      ResetList();
      return;
    }
    // if it is neither equal to or greater than compare the next element
    currentPos = currentPos->getNext();
  }
}

void GameList::DeleteGame(std::string title) {
  // find and delete a node
  SLelement<std::string> *previous = nullptr;
  SLelement<std::string> *current = listData;
  // search the list for the element
  for (int i = 0; i < length; i++) {
    if (current->getValue() == title) {
      // if it is in the list delete it
      if (current = listData) {
        // first node case
        listData = current->getNext();
        delete current;
        length--;
        break;
      } else {
        // other node case
        previous->setNext(current->getNext());
        delete current;
        length--;
        break;
      }
    } else if (current->getValue() > title) {
      // if it is ever greater
      break;
    }
    previous = current;
    currentPos = current->getNext();
  }
  ResetList();
}

void GameList::ResetList() {
  // TODO Add code here.
  currentPos = listData;
}

void GameList::GetNextGame(std::string &title, std::string &gameDetails) {
  // TODO Add code here.
  title = currentPos->getValue();
  gameDetails = currentPos->getLabel();
  currentPos = currentPos->getNext();
}
