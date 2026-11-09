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
    std::vector<int> tmp;
    adjacency_list.push_back(tmp);  // Creates empty list of neighbours for the vertex
}

template <typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2) {
    // Search if vertices exist
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);

    if (i_v1 == -1 || i_v2 == -1) {
        std::cout << "insertEdge: incorrect vertices\n";
        return;
    }

    for(int neighbor : adjacency_list[i_v1]) {
        if (neighbor == i_v2) {
            return;
        }
    }

    adjacency_list[i_v1].push_back(i_v2);
    adjacency_list[i_v2].push_back(i_v1);
}

template <typename T>
void Graph<T>::print() const {
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << ": ";
        for (int j : adjacency_list[i]) {
            std::cout << vertices[j] << " ";
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

    for(int neighbor : adjacency_list[i_v1]) {
        if (neighbor == i_v2) {
            return true;
        }
    }
    return false;
}

template <typename T>
void Graph<T>::BFS(const T& start) const {
    int start_index = searchVertexIndex(start);

    if (start_index == -1) {
        std::cout << "BFS: incorrect start vertex\n";
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

        for(int neighbor : adjacency_list[current_index]) {
            if(!discovered[neighbor]) {
                discovered[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}