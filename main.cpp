#include <iostream>
#include <fstream>
#include "headers/trie.h"
#include "headers/trie.cpp"
#include "services/AnagramService.cpp"

int main(){
    trie test_trie;
    //iterate through dictionary, mapping out the trie
    test_trie.add_dictionary("input/dictionary.txt");

    std::vector<std::string> all_words = AnagramHelpers::Get_All_Words_In_String("georgebush");


    return 0;
}