#include "Trie.hpp"
#include <iostream>

int main(void) {
    Trie trie;

    trie.insert("water");
    trie.insert("cat");
    trie.insert("catch");
    trie.insert("category");
    trie.insert("cause");
    trie.insert("caution");
    trie.print();

    std::cout << "Has cat " << trie.contains("cat") << std::endl;
    std::cout << "Has dog " << trie.contains("dog") << std::endl;

    std::cout << "WT" << trie.countWords() - 2 << trie.getNextLetters("ca") << std::endl;;

    return 0;
}