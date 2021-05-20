/*************************************************************************
 *
 * Project: ImdbGraph implementation
 *
 * File Name: ImdbGraph.cpp
 * Name:      Adam Taylor
 * Course:    CPTR 242
 * Date:      5/20/2021
 *
 */
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"
#include "ImdbGraph.h"
#include "SLelement.h"
#include "data_src/ActorMovieIMDB.h"

using namespace bridges;

// Constructor
ImdbGraph::ImdbGraph() {}

// Destructor
ImdbGraph::~ImdbGraph() {}

// Function: Adds a vertex to the graph.
// Pre:  Graph has been initialized.
// Post: The actor or movie will be added as a vertex.
//          No duplicate vertics will be created.
void ImdbGraph::AddVertex(string actorOrMovie) {
  graph.addVertex(actorOrMovie);
}

// Function: Adds a edge to the graph.
// Pre:  Graph has been initialized.
//          Vertics have been already added to the graph.
// Post: The actor movie edge will be added to the graph.
//          No duplicate edges will be created.
void ImdbGraph::AddEdge(string actorOrMovie, string movieOrActor2) {
  if (!doesEdgeExist(actorOrMovie, movieOrActor2)) {
    graph.addEdge(actorOrMovie, movieOrActor2);
    graph.addEdge(movieOrActor2, actorOrMovie);
  }
}

// Function: Updates the visualization for to vertex.
// Pre:  Graph has been initialized.
//          Vertex is in the graph.
// Post: The vertex will display the new color.
void ImdbGraph::setVertexColor(string actorOrMovie, string color) {
  graph.getVisualizer(actorOrMovie)->setColor(color);
  graph.getVisualizer(actorOrMovie)->setSize(50.0);
}

// Function: Updates the visualization for to edge.
// Pre:  Graph has been initialized.
//          Edge is in the graph.
// Post: The edge will display the new color.
void ImdbGraph::setEdgeColor(string actorOrMovie, string movieOrActor2,
                             string color) {
  graph.getLinkVisualizer(actorOrMovie, movieOrActor2)->setColor(color);
  graph.getLinkVisualizer(movieOrActor2, actorOrMovie)->setColor(color);
  graph.getLinkVisualizer(actorOrMovie, movieOrActor2)->setThickness(5.0);
  graph.getLinkVisualizer(movieOrActor2, actorOrMovie)->setThickness(5.0);
}

// Function: Resets all visualizations to the default.
// Pre:  Graph has been initialized.
// Post: The vertics and edges will display the default color.
void ImdbGraph::ResetVisualizer() {
  // iterate over every vertex in the graph
  for (auto &vertex : *graph.getVertices()) {
    graph.getVisualizer(vertex.first)->setColor("steelblue");
    graph.getVisualizer(vertex.first)->setSize(10.0);
    // find each vertex's adjacent node
    auto sl_list = graph.getAdjacencyList(vertex.first);
    for (auto sle = sl_list; sle != NULL; sle = sle->getNext()) {
      // get destination vertex
      auto destination = ((Edge<string>)sle->getValue()).to();
      // use the adjacent node to find all edges in graphs
      graph.getEdge(vertex.first, destination).setColor("steelblue");
      graph.getEdge(vertex.first, destination).setThickness(1.0);
    }
  }
}

// Function: Calculates the Bacon Number for two actors.
//           In addition to returning the number, the graph is update to
//           highlight the path.
//           https://en.wikipedia.org/wiki/Six_Degrees_of_Kevin_Bacon
// Pre:  Graph has been initialized.
//          Vertices are in the graph.
//          Edges connect the actors in the graph.
// Post: The number returned will be lowest number of actor connections used to
// connect them.
//          The graph will visually show the path to connect the actors.
int ImdbGraph::GetBaconNumber(string sourceActor, string destinationActor) {
  // TODO Add code here.
  // create a map that holds each vertex name with its associated distance from
  // the beginning
  bool destinationDiscovered = false;
  unordered_set<string> discoveredSet;
  map<string, int> distance;
  queue<string> frontierQueue;
  // create values for starting point
  distance.emplace(sourceActor, 0.0);
  frontierQueue.push(sourceActor);
  discoveredSet.insert(sourceActor);
  // interate over all of the points until you get to the end point
  while (frontierQueue.size() > 0) {
    string currentVertex = frontierQueue.front();
    frontierQueue.pop();
    auto adjacent = graph.getAdjacencyList(currentVertex);
    // iterate over all adjacent verticies
    for (auto sle = adjacent; sle != NULL; sle = sle->getNext()) {
      // get an adjacent vertex
      auto adjacentVertex = ((Edge<string>)sle->getValue()).to();
      // if this vertex is in the discoversed set already move to the next one
      if (0 == discoveredSet.count(adjacentVertex)) {
        frontierQueue.push(adjacentVertex);
        discoveredSet.insert(adjacentVertex);
        distance.emplace(adjacentVertex, distance[currentVertex] + 1);
        // if it is the ending point exit out of the loop
        if (adjacentVertex == destinationActor) {
          destinationDiscovered = true;
          break;
        }
      }
    }
    if (destinationDiscovered == true) {
      break;
    }
  }

  // do it again but from the end point to the beginning point
  bool destinationDiscovered1 = false;
  unordered_set<string> discoveredSet1;
  map<string, int> distance1;
  queue<string> frontierQueue1;
  // create the starting point
  distance1.emplace(destinationActor, 0.0);
  frontierQueue1.push(destinationActor);
  discoveredSet1.insert(destinationActor);
  // find and add distances for all points up to the end point
  while (frontierQueue1.size() > 0) {
    string currentVertex = frontierQueue1.front();
    frontierQueue1.pop();
    auto adjacent = graph.getAdjacencyList(currentVertex);
    // iterate over all adjacent verticies
    for (auto sle = adjacent; sle != NULL; sle = sle->getNext()) {
      // get an adjacent vertex
      auto adjacentVertex = ((Edge<string>)sle->getValue()).to();
      // if this vertex is in the discoversed set already move to the next one
      if (0 == discoveredSet1.count(adjacentVertex)) {
        frontierQueue1.push(adjacentVertex);
        discoveredSet1.insert(adjacentVertex);
        distance1.emplace(adjacentVertex, distance1[currentVertex] + 1);
        // if it is the ending point exit out of the loop
        if (adjacentVertex == sourceActor) {
          destinationDiscovered1 = true;
          break;
        }
      }
    }
    if (destinationDiscovered1 == true) {
      break;
    }
  }

  // iterate over every point between the start and the end and determin if it
  // is part of the shortest path
  queue<string> reverseFrontierQueue;
  frontierQueue.push(destinationActor);
  while (true) {
    string currentVertex = frontierQueue.front();
    // if it reaches the other side of the path exit
    if (currentVertex != sourceActor) {
      frontierQueue.pop();
      auto adjacent = graph.getAdjacencyList(currentVertex);
      // iterate over all adjacent verticies
      for (auto sle = adjacent; sle != NULL; sle = sle->getNext()) {
        // get an adjacent vertex
        auto adjacentVertex = ((Edge<string>)sle->getValue()).to();
        // if this vertex is the correct distance away from the starting and end
        // points and it is the next level away from the starting point color it
        // to make it look like part of the path
        if (distance[adjacentVertex] == distance[currentVertex] - 1 &&
            distance1[adjacentVertex] == distance1[currentVertex] + 1 &&
            distance[adjacentVertex] ==
                distance[destinationActor] - distance1[adjacentVertex]) {

          frontierQueue.push(adjacentVertex);
          discoveredSet.insert(adjacentVertex);
          // color the vertex and the edge that connects it to the previous
          // point
          setVertexColor(adjacentVertex, "yellow");
          setEdgeColor(currentVertex, adjacentVertex, "yellow");
        }
      }
    } else {
      break;
    }
  }
  // color the start and end points unique colors
  setVertexColor(destinationActor, "green");
  setVertexColor(sourceActor, "red");
  // return the the number of actors it takes to get from the starting person to
  // the ending person. (this excludes movies)
  return static_cast<int>(distance[destinationActor]) / 2;
}
