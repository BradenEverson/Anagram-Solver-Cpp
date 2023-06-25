#include <iostream>
#include <unordered_map>

#ifndef TRIE_H
#define TRIE_H

class trie{
    public:
        trie_elem rootElement;
        trie(trie_elem root);
        void insert(std::string& alphabetized_string);
};

#endif

#ifndef TRIE_ELEM_H
#define TRIE_ELEM_H

class trie_elem{
    public:
        TriePayload value;
        std::unordered_map<TriePayload, trie_elem> children;
        bool isEndOfTrie;
};

#endif

struct TriePayload{
    char character;
    int count;
};