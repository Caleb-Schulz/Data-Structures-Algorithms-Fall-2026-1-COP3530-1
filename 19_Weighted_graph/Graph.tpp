#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <queue>

template <typename T>
int Graph<T>::searchVertexIndex(const T& value) const {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] == value) {
            return i;
        }
    }
    
    return -1;
}

template <typename T>
void Graph<T>::insertVertex(const T& v) {
    // Check for duplicates
    if (searchVertexIndex(v) != -1) {
        std::cout << "insertVertex: vertex already exists\n";
        return;
    }

    // Add new vertex
    vertices.push_back(v);
    std::vector<Edge> tmp;
    adjacency_list.push_back(tmp);  // Creates empty list of neighbours for the vertex
}

template <typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2, int weight) {
    if (weight < 0) {
        std::cout << "insertEdge: negative weight\n";
        return;
    }

    // Search if vertices exist
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);

    if (i_v1 == -1 || i_v2 == -1) {
        std::cout << "insertEdge: incorrect vertices\n";
        return;
    }

    for(const Edge& edge : adjacency_list[i_v1]) {
        if (edge.neighbor == i_v2) {
            return;
        }
    }

    adjacency_list[i_v1].push_back(Edge(i_v2, weight));
    adjacency_list[i_v2].push_back(Edge(i_v1, weight));
}

template <typename T>
void Graph<T>::print() const {
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << ": ";
        for (const Edge& edge : adjacency_list[i]) {
            std::cout << vertices[edge.neighbor] << "(" << edge.weight << ") ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
int Graph<T>::getDegree(const T& vertex) const {
    int i_v = searchVertexIndex(vertex);
    // int degree = 0;

    if (i_v == -1) {
        std::cout << "getDegree: Vertex not found\n";
        return -1;
    }

    // for (int j : adjacency_list[i_v]) {
    //     degree++;
    // }
    // return degree;

    return adjacency_list[i_v].size();
}

template <typename T>
bool Graph<T>::hasEdge(const T& v1, const T& v2) const {
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);

    if (i_v1 == -1 || i_v2 == -1) {
        std::cout << "hasEdge: incorrect vertices\n";
        return false;
    }

    for(const Edge& edge : adjacency_list[i_v1]) {
        if (edge.neighbor == i_v2) {
            return true;
        }
    }
    return false;
}

template <typename T>
int Graph<T>::getEdgeWeight(const T& v1, const T& v2) const {
    if (!hasEdge(v1, v2)){
        return -1;
    }
    
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);

    if (i_v1 == -1 || i_v2 == -1) {
        std::cout << "getEdgeWeight: incorrect vertices\n";
        return -1;
    }

    for(const Edge& edge : adjacency_list[i_v1]) {
        if (edge.neighbor == i_v2) {
            return edge.weight;
        }
    }
    return -1;
}

template <typename T>
void Graph<T>::BFS(const T& start) const {
    int start_index = searchVertexIndex(start);

    if (start_index == -1) {
        std::cout << "BFS: incorrect start vertex\n";
        return;
    }

    std::cout << "BSF: ";
    std::queue<int> q;
    std::vector<bool> discovered(vertices.size(), false);

    q.push(start_index);
    discovered[start_index] = true;

    while(!q.empty()) {
        int current_index = q.front();
        q.pop();

        std::cout << vertices[current_index] << " ";

        for(const Edge& edge : adjacency_list[current_index]) {
            if(!discovered[edge.neighbor]) {
                discovered[edge.neighbor] = true;
                q.push(edge.neighbor);
            }
        }
    }
    std::cout << std::endl;
}


template <typename T>
void Graph<T>::DFS(const T& start) const {
    int start_index = searchVertexIndex(start);

    if (start_index == -1) {
        std::cout << "DFS: incorrect start vertex\n";
        return;
    }

    std::cout << "DSF: ";
    std::vector<bool> visited(vertices.size(), false);

    DFSExplore(start_index, visited);
    std::cout << std::endl;
}

template <typename T>
void Graph<T>::DFSExplore(int index, std::vector<bool>& visited, bool print) const{
    visited[index] = true;

    if (print) {
        std::cout << vertices[index] << " ";
    }

    for(const Edge& edge : adjacency_list[index]) {
        if (!visited[edge.neighbor]) {
            DFSExplore(edge.neighbor, visited, print);
        }
    }
}

template <typename T>
bool Graph<T>::isConnected() const {
    if (vertices.empty()) {
        return true;
    }

    std::vector<bool> visited(vertices.size(), false);

    DFSExplore(0, visited, false);

    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }
    return true;
}

template <typename T>
int Graph<T>::shortestPathByEdges(const T& start, const T& end) const {
    int start_index = searchVertexIndex(start);
    int end_index = searchVertexIndex(end);

    if (start_index == -1 || end_index == -1) {
        std::cout << "shortestPath: incorrect vertices\n";
        return -1;
    }

    if (start == end) {
        return 0;
    }

    std::queue<int> q;
    std::vector<int> distances(vertices.size(), -1);

    q.push(start_index);
    distances[start_index] = 0;

    while(!q.empty()) {
        int current_index = q.front();
        q.pop();

        for(const Edge& edge : adjacency_list[current_index]) {
            if(distances[edge.neighbor] == -1) {
                distances[edge.neighbor] = distances[current_index] + 1;
                q.push(edge.neighbor);

                if (edge.neighbor == end_index) {
                    return distances[edge.neighbor];
                }
            }
        }
    }
    return -1;
}