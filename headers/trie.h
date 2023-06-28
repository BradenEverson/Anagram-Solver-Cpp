#include <unordered_map>

#ifndef TRIE_H
#define TRIE_H

class trie_elem{
    public:
        char value;
        std::unordered_map<char, trie_elem> children;
        bool end_of_word;
};

class trie{
    public:
        trie_elem root_element;
        trie(trie_elem root);
        trie();
        bool insert(std::string input);
        bool has_child(std::string input);
        void add_dictionary(std::string file);
};

#endif