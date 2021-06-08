/*************************************************************************
 *
 * Project: UsgsTree implementation
 *
 * File Name: UsgsTree.cpp
 * Name:      Adam Taylor
 * Course:    CPTR 242
 * Date:      6/06/2021
 *
 */
#include "UsgsTree.h"
#include "BSTElement.h"
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/EarthquakeUSGS.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace bridges;

// Function: Finds the smallest quake magnitude in a BST.
// Pre:  BST has been initialized and populated.
// Post: The smallest quake will be visualized and returned.
EarthquakeUSGS
UsgsTree::getLargestQuake(BSTElement<float, EarthquakeUSGS> *root,
                          std::string color) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->getRight() == nullptr) {
    root->getVisualizer()->setColor(color);
    return root->getValue();
  }
  return getLargestQuake(root->getRight(), color);
}

// Function: Finds the largest quake magnitude in a BST.
// Pre:  BST has been initialized and populated.
// Post: The largest quake will be visualized and returned.
EarthquakeUSGS
UsgsTree::getSmallestQuake(BSTElement<float, EarthquakeUSGS> *root,
                           std::string color) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->getLeft() == nullptr) {
    root->getVisualizer()->setColor(color);
    return root->getValue();
  }
  return getSmallestQuake(root->getLeft(), color);
}

// Function: Finds all nodes in the BST that are between the min and max
// parameters.
// Pre:  BST has been initialized and populated.
// Post: Returns the number of quakes in this range and visualizes them.
int UsgsTree::countRange(float min, float max,
                         BSTElement<float, EarthquakeUSGS> *root,
                         std::string color) {
  if (root == nullptr) {
    return 0;
  } else if (root->getKey() >= min && root->getKey() <= max) {
    root->getVisualizer()->setColor(color);
    return 1 + countRange(min, max, root->getLeft(), color) +
           countRange(min, max, root->getRight(), color);
  } else if (root->getKey() < min) {
    return countRange(min, max, root->getRight(), color);
  } else if (root->getKey() > max) {
    return countRange(min, max, root->getLeft(), color);
  }
  return 0;
}
// Function:  Finds all nodes in the BST that in the specified location.
// Pre:  BST has been initialized and populated.
// Post: Returns the number of quakes in this location and visualizes them.
int UsgsTree::countByLocation(std::string location,
                              BSTElement<float, EarthquakeUSGS> *root,
                              std::string color) {
  if (root == nullptr) {
    return 0;
  } else if (root->getValue().getLocation().find(location) !=
             std::string::npos) {
    root->getVisualizer()->setColor(color);
    return 1 + countByLocation(location, root->getLeft(), color) +
           countByLocation(location, root->getRight(), color);
  } else {
    return countByLocation(location, root->getLeft(), color) +
           countByLocation(location, root->getRight(), color);
  }
}

// Function: Updates all nodes and edges with a visualization.
// Pre:  BST has been initialized and populated.
// Post: Returns the number of quakes in the BST and visualizes them.
int UsgsTree::countWithStyle(BSTElement<float, EarthquakeUSGS> *root,
                             std::string colorVertex, std::string colorEdge) {
  if (root != nullptr) {
    root->getVisualizer()->setColor(colorVertex);
    return 1 + countWithStyle(root->getLeft(), colorVertex, colorEdge) +
           countWithStyle(root->getRight(), colorVertex, colorEdge);
  } else {
    return 0;
  }
}

// Function: Resets the BST visualization back to the defaults.
// Pre:  BST has been initialized and populated.
// Post: The BST has no visualizations.
void UsgsTree::resetVisualization(BSTElement<float, EarthquakeUSGS> *root) {
  if (root != nullptr) {
    root->getVisualizer()->setColor("steelblue");
    resetVisualization(root->getLeft());
    resetVisualization(root->getRight());
  }
}
