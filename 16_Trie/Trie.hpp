#ifndef TRIE_HPP
#define TRIE_HPP
#include <string>

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE] = {};
    bool end_of_word = false;


};

class Trie {
public:
    Trie();
    void insert(const std::string& word);
    void print() const;

    bool contains(const std::string& word) const;

    int countWords() const;
    std::string getNextLetters(const std::string& prefix) const;

private:
    TrieNode* root;
    int word_count;

    int letterToIndex(char c) const;
    char IndexToLetter(int i) const;

    void print(const TrieNode* node, std::string& s) const;
};





#endif