#include "Trie.hpp"
#include <string>
#include <iostream>

Trie::Trie() : word_count(0) {
    root = new TrieNode;
}

void Trie::insert(const std::string& word) {
    TrieNode* cur = root;
    
    for(char c : word) {
        int i = letterToIndex(c);
        if (cur->children[i] == nullptr) {
            cur->children[i] = new TrieNode;
        }
        cur = cur->children[i];
    }

    if (!cur->end_of_word) {
        cur->end_of_word = true;
        word_count++;
    }
}


void Trie::print() const{
    std::string s;
    print(root, s);
}

void Trie::print(const TrieNode* node, std::string& s) const {
    if(!node) {
        return;
    }
    else if (node->end_of_word) {
        std::cout << s << std::endl;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if(!node->children[i]) {
            continue;
        }
        s += IndexToLetter(i);
        print(node->children[i], s);
        s.pop_back();
    }
}

int Trie::letterToIndex(char c) const {
    return c - 'a';
}

char Trie::IndexToLetter(int i) const {
    return 'a' + i;
}

bool Trie::contains(const std::string& word) const {
    const TrieNode* cur = root;
    for (char c : word) {
        int i = letterToIndex(c);

        if (!cur->children[i]) {
            return false;
        }
        cur = cur->children[i];
    }

    return cur->end_of_word;
}

int Trie::countWords() const {
    return word_count;
}

std::string Trie::getNextLetters(const std::string& prefix) const {
    const TrieNode* cur = root;
    
    for (char c : prefix) {
        int i = letterToIndex(c);
        if (!cur->children[i]) {
            return "";
        }
        cur = cur->children[i];
    }
    
    std::string result = "";
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (cur->children[i] != nullptr) {
            result += IndexToLetter(i);
        }
    }
    
    return result;
}