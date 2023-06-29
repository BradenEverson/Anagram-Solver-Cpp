#include <vector>
#include <algorithm>
#include "../headers/trie.h"

namespace AnagramHelpers{

    std::vector<std::string> Get_All_Words_In_String(std::string input, trie_elem dictionary_root, std::vector<std::string> &all_strings){
        trie_elem *current = &dictionary_root;
        //alphabetize input for sanitization purposes
        input = alphabetize_string(input);
        //iterate through each character in our input, going through ever possibility to find words present in the anagram tree
        for(int i = 0; i < input.length(); i++){
            auto END_OF_TRIE = current->children.end();
            if((current->children.find(input[i]) != END_OF_TRIE)){
                trie_elem current_child = current->children.at(input[i]);
                if(current_child.end_of_word){
                    if(std::find(all_strings.begin(), all_strings.end(), current_child.value) == all_strings.end()){
                        all_strings.push_back(current_child.value);
                    }
                }
                std::string placeholder_input = input;
                placeholder_input.erase(i, 1);
                
                all_strings = Get_All_Words_In_String(placeholder_input, current_child, all_strings);
            }
        }
        return all_strings;
    }
    
    std::vector<std::string> Get_All_Words_In_String(std::string input, trie_elem dictionary_root){
        std::vector<std::string> all_strings;
        return Get_All_Words_In_String(input, dictionary_root, all_strings);
    }

    std::string Remove_Substring(std::string &input, std::string remove){
        for(int i = 0; i < remove.length(); i++){
            for(int j = 0; j < input.length(); j++){
                if(input[j] == remove[i]){
                    input.erase(j);
                    break;
                }
            }
        }
        return input;
    }
}