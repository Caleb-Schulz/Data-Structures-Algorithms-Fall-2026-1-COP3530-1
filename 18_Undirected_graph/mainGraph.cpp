#include "Graph.hpp"
#include <vector>
#include <iostream>

int main(void) {
    Graph<std::string> friends;

    friends.insertVertex("Ross");
    friends.insertVertex("Monica");
    friends.insertVertex("Rachel");
    friends.insertVertex("Chandler");
    friends.insertVertex("Joey");
    friends.insertVertex("Phoebe");

    friends.insertEdge("Ross","Rachel");
    friends.insertEdge("Monica","Chandler");
    friends.insertEdge("Joey","Chandler");
    friends.insertEdge("Ross","Chandler");
    friends.insertEdge("Rachel","Joey");
    
    friends.print();

    friends.BFS("Ross");

    return 0;
}