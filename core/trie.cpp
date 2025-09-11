#include "trie.h"
#include <iostream>
#include <chrono>

// Trie constructor
Trie::Trie() {
    root = new TrieNode();
}

// Trie insertion
void Trie::ins(string s) {
    TrieNode *curr = root;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (curr->children.find(ch) == curr->children.end())
            curr->children.insert(make_pair(ch, new TrieNode()));
        curr = curr->children[ch];
    }
    curr->isEoW = true;
}

// Trie exact search
TrieNode *Trie::search_exact(string s) {
    TrieNode *curr = root;
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (curr->children.find(ch) == curr->children.end())
            return NULL;
        curr = curr->children[ch];
    }
    auto stop = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cerr << "\033[032m\n"
         << curr->isEoW << "result in"
         << double(dur.count()) / double(1000000) << "ms.\033[0m\n\n";

    return curr->isEoW ? curr : NULL;
}

// Helper function for prefix search
void get_words_dfs(TrieNode *curr, string pre, vector<string> &results) {
    if (curr == NULL)
        return;
    if (curr->isEoW)
        results.push_back(pre);

    for (auto child : curr->children)
        get_words_dfs(child.second, (pre + child.first), results);
}

// Trie prefix search
vector<string> Trie::search_pre(string s) {
    auto start = chrono::high_resolution_clock::now();
    TrieNode *curr = root;
    vector<string> results;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (curr->children.find(ch) == curr->children.end())
            return results;
        curr = curr->children[ch];
    }
    get_words_dfs(curr, s, results);
    auto stop = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cerr << "\033[032m\n"
         << results.size() << " results in "
         << double(dur.count()) / double(1000000) << "ms.\033[0m\n\n";
    return results;
}

// Trie deletion
void Trie::del(string s) {
    _del(root, s, 0);
}

// Helper function for deletion
bool Trie::_del(TrieNode *curr, string s, int index) {
    if (index == s.size()) {
        if (!curr->isEoW)
            return false;
        curr->isEoW = false;
        return curr->children.size() == 0;
    }
    char ch = s[index];
    if (!curr->children[ch])
        return false;

    if (_del(curr->children[ch], s, index + 1)) {
        curr->children.erase(ch);
        return curr->children.size() == 0;
    }
    return false;
}

// Trie drawing
void Trie::draw(TrieNode *curr, int depth) {
    if (!curr)
        curr = root;

    for (auto ch : curr->children) {
        for (int i = 0; i < depth; i++)
            cout << "_";
        cout << ch.first << "\n";
        draw(ch.second, depth + 1);
    }
}