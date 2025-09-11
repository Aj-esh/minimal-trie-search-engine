#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

class TrieNode {
    public:
    unordered_map<char, TrieNode*> children;
    bool isEoW;

    TrieNode() {
        isEoW = false;
    }
};

class Trie {
    public:
    int n_nodes = 0, n_words = 0; 
    TrieNode* root;

    Trie();
    void ins(string s);
    void del(string s);
    bool _del(TrieNode *curr, string s, int index);
    TrieNode *search_exact(string s);
    vector<string> search_pre(string s);
    void draw(TrieNode* curr, int depth);
};

#endif