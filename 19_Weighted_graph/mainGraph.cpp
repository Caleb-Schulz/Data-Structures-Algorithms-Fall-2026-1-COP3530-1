#include "Graph.hpp"
#include <vector>
#include <iostream>

int main(void) {
    Graph<std::string> map;

    map.insertVertex("Tampa");
    map.insertVertex("Lakeland");
    map.insertVertex("Orlando");
    map.insertVertex("Miami");
    map.insertVertex("Naples");

    map.insertEdge("Tampa", "Lakeland", 40);
    map.insertEdge("Tampa", "Naples", 185);
    map.insertEdge("Tampa", "Miami", 500);
    map.insertEdge("Lakeland", "Orlando", 50);
    map.insertEdge("Lakeland", "Miami", 350);
    map.insertEdge("Orlando", "Miami", 200);
    map.insertEdge("Miami", "Naples", 150);
    
    map.print();

    map.BFS("Tampa");
    map.DFS("Tampa");

    std::cout << "isConnected: " << map.isConnected() << std::endl;

    std::cout << "shortestPath: " << map.shortestPathByEdges("Tampa", "Orlando") << std::endl;

    return 0;
}