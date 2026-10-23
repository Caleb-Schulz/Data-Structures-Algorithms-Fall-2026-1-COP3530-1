#include "Trie.hpp"

Trie::Trie() : word_count(0) {
    root = new TrieNode;
}

void Trie::insert(const std::string& word) {
    TrieNode* cur = root;
    
    for(char c : word) {
        int i = letterToIndex(c);
        if (cur->children[i] != nullptr) {
            cur->children[i] = new TrieNode;
        }
        cur = cur->children[i];
    }
    
}


void Trie::print() const{

}

int Trie::letterToIndex(char c) const {
    return c - 'a';
}