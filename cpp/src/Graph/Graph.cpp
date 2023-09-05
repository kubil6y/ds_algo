#include "./Graph.h"
#include <iostream>

bool Graph::addVertex(const std::string& vertex) {
    if (m_adjList.count(vertex) != 0) {
        return false;
    }
    m_adjList[vertex];
    return true;
}

bool Graph::removeVertex(const std::string& vertex) {
    if (m_adjList.count(vertex) == 0) {
        return false;
    }
    for (auto otherVertex : m_adjList.at(vertex)) {
        m_adjList.at(otherVertex).erase(vertex);
    }
    m_adjList.erase(vertex);
    return true;
}

bool Graph::addEdge(const std::string& v1, const std::string& v2) {
    if (m_adjList.count(v1) != 0 && m_adjList.count(v2) != 0) {
        m_adjList.at(v1).insert(v2);
        m_adjList.at(v2).insert(v1);
        return true;
    }
    return false;
}

bool Graph::removeEdge(const std::string& v1, const std::string& v2) {
    if (m_adjList.count(v1) != 0 && m_adjList.count(v2) != 0) {
        m_adjList.at(v1).erase(v2);
        m_adjList.at(v2).erase(v1);
        return true;
    }
    return false;
}

void Graph::printGraph() const {
    for (auto [vertex, edges] : m_adjList) {
        std::cout << vertex << ": [ ";
        for (auto edge : edges) {
            std::cout << edge << ' ';
        }
        std::cout << ']' << std::endl;
    }
}
