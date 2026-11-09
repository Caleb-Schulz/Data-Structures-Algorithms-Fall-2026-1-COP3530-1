// Create a hash table
// Insert 5 records

// Print the content.

#include "HashMap.hpp"
#include <string>
#include <vector>

int main(void) {

    HashMap<std::string> map(7);

   map.insert(8, "a");
   map.insert(15, "b");
   map.insert(22, "c");

   map.remove(15);
   map.print();

   map.update(8, "d");
   std::cout << "has 8: " << map.contains(8) << std::endl;
   map.print();

    return 0;
}
