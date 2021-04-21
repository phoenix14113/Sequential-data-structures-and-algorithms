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
  // TODO Add code here.
  SLelement<std::string> *newGame = new SLelement<std::string>;
  newGame->setLabel(title);
  newGame->setValue(gameDetails);

  if (length == 0) {
    listData = newGame;
    length++;
  } else {
    ResetList();
    SLelement<std::string> *previous = new SLelement<std::string>;
    for (int i = 1; i <= length; i++) {
      // std::cout << "hi" << std::endl;

      if (currentPos->getLabel() > title &&
          currentPos->getLabel() == listData->getLabel()) {

        newGame->setNext(currentPos);
        previous->setNext(newGame);
        listData = newGame;
        length++;
        break;
      } else if (currentPos->getLabel() > title) {
        // std::cout << "hi" << std::endl;
        newGame->setNext(currentPos);
        previous->setNext(newGame);
        length++;
        break;
      } else if (i == length) {
        currentPos->setNext(newGame);
        length++;

        break;
      } else {
        previous = currentPos;
        currentPos = currentPos->getNext();
      }
    }
  }
  ResetList();
}

void GameList::GetGame(std::string title, std::string &gameDetails,
                       bool &found) {
  // TODO Add code here.
  found = false;
  SLelement<std::string> *previous = nullptr;
  for (int i = 0; i < length; i++) {
    if (currentPos->getLabel() == title) {
      gameDetails = currentPos->getValue();
      found = true;
      ResetList();
      return;
    } else if (currentPos->getLabel() > title) {
      ResetList();
      return;
    }
    previous = currentPos;
    currentPos = currentPos->getNext();
  }
}

void GameList::DeleteGame(std::string title) {
  // TODO Add code here.
  SLelement<std::string> *previous = nullptr;
  SLelement<std::string> *current = listData;
  for (int i = 0; i < length; i++) {
    if (current->getLabel() == title) {
      if (current = listData) {
        listData = current->getNext();
        delete current;
        length--;
        break;
      } else {
        previous->setNext(current->getNext());
        delete current;
        length--;
        break;
      }
    } else if (current->getLabel() > title) {
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
  title = currentPos->getLabel();
  gameDetails = currentPos->getValue();
  currentPos = currentPos->getNext();
}
