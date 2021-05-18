/*************************************************************************
 *
 * Assignment: BreadthFirstSearch
 *
 * File Name: BreadthFirstSearch.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */

#include "GraphType.h"
#include "QueueType.h"
#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>
#include <vector>

template <class VertexType>
map<VertexType, int>
GraphType<VertexType>::BreadthFirstSearch(VertexType startVertex) {
  unordered_set<VertexType> discoveredSet;
  map<VertexType, int> distance;
  queue<VertexType> frontierQueue;
  QueueType<VertexType> adjacent;
  
  distance.emplace(startVertex, 0);

  frontierQueue.push(startVertex);   // Enqueue startVertex in frontierQueue
  discoveredSet.insert(startVertex); // Add startVertex to discoveredSet

  while (frontierQueue.size() > 0) {
    VertexType currentVertex = frontierQueue.front();
    frontierQueue.pop();
    GetToVertices(currentVertex, adjacent);
    
    while (!adjacent.IsEmpty()) {

      VertexType adjacentVertex;

      adjacent.Dequeue(adjacentVertex);
      if (0 == discoveredSet.count(adjacentVertex)) {
        frontierQueue.push(adjacentVertex);
        discoveredSet.insert(adjacentVertex);

        // Distance of adjacentVertex is 1 more than currentVertex
        distance.emplace(adjacentVertex, distance[currentVertex] + 1);
      }
    }
  }

  return distance;
}

// Keep this at the end of the file.
template class GraphType<int>;