#include <iostream>
#include <fstream>
#include<vector>
#include "headers/trie.h"
#include "headers/trie.cpp"
#include "services/AnagramService.cpp"

int main(){
    trie test_trie;
    //iterate through dictionary, mapping out the trie
    test_trie.add_dictionary("input/dictionary.txt");

    std::string fName;
    std::string lName;

    std::cout << "First name: ";
    std::cin >> fName;
    std::cout << "Last name: ";
    std::cin >> lName;

    std::string test = fName + lName;
    std::vector<std::string> possibilities = AnagramHelpers::Get_All_Words_In_String(test, test_trie.root_element);

    for(std::string sub_anagram : possibilities){
        std::cout << "\"" << sub_anagram << "\"\n";
    }

    return 0;
}