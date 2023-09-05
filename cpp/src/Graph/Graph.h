#pragma once

#include <unordered_map>
#include <unordered_set>

class Graph {
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> m_adjList;

public:
    Graph() = default;

    bool addVertex(const std::string& vertex);
    bool removeVertex(const std::string& vertex);
    bool addEdge(const std::string& v1, const std::string& v2);
    bool removeEdge(const std::string& v1, const std::string& v2);

    void printGraph() const;
};

/*
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
*/
