#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

template <typename T>
class Graph {
public:
    void insertVertex(const T& v);
    void insertEdge(const T& v1, const T& v2, int weight);

    void print() const; // Prints vertices and adjacency list

    int getDegree(const T& vertex) const;

    bool hasEdge(const T& v1, const T& v2) const;
    int getEdgeWeight(const T& v1, const T& v2) const;
    bool isConnected() const;

    void BFS(const T& start) const;
    void DFS(const T& start) const;

    int shortestPathByEdges(const T& start, const T& end) const;
private:
    class Edge {
    public:
        int neighbor;
        int weight;
        Edge(int n, int w) : neighbor(n), weight(w) {

        }
    };

    std::vector<T> vertices;
    std::vector<std::vector<Edge>> adjacency_list;

    int searchVertexIndex(const T& value) const;

    void DFSExplore(int index, std::vector<bool>& visited, bool print = true) const;
};

#include "Graph.tpp"

#endif