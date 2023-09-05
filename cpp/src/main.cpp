#include <iostream>

#include "./Graph/Graph.h"

int main(int argc, char* argv[]) {
    Graph* graph = new Graph();

    graph->addVertex("A");
    graph->addVertex("B");
    graph->addVertex("C");
    graph->addVertex("D");

    graph->addEdge("A", "B");
    graph->addEdge("A", "C");
    graph->addEdge("A", "D");
    graph->addEdge("B", "D");
    graph->addEdge("C", "D");

    graph->removeVertex("D");

    graph->printGraph();
    return 0;
}
