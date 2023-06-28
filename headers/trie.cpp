#include "trie.h"

trie::trie(trie_elem root){
    this->root_element = root;
}
trie::trie(){
    trie_elem root;
    this->root_element = root;
}

std::string alphabetize_string(std::string input) {
    std::string output = "";
    for (char c : input) {
        c = tolower(c);
        std::string placeholder = "";
        bool inserted = false;
        for (char o : output) {
            o = tolower(o);
            if (c <= o) {
                output = placeholder + c + output.substr(placeholder.length());
                inserted = true;
                break;
            }
            placeholder += o;
        }
        if (!inserted) {
            output += c;
        }
    }
    return output;
}


bool trie::insert(std::string input){
    trie_elem *current = &(this->root_element);
    //alphabetize input for trie creation
    input = alphabetize_string(input);

    //We can now safely iterate through the entire input string and cache each point into the trie.
    for(char character : input){
        if(current->children.find(character) == current->children.end()){
            //Branch of trie does not currently exist, implement it in
            trie_elem next_branch;
            next_branch.value = character;
            next_branch.end_of_word = false;
            current->children.insert({character, next_branch});
        }
        current = &(current->children.at(character));
    }
    current->end_of_word = true;
    
    return true;
}

bool trie::has_child(std::string input){
    trie_elem *current = &(this->root_element);
    input = alphabetize_string(input);
    for(char character : input){
        if(current->children.find(character) == current->children.end()){
            return false;
        }
        current = &(current->children.at(character));
    }
    return current->end_of_word;
}

void trie::add_dictionary(std::string file){
    std::ifstream Source(file);
    std::string currentLine;

    while(std::getline(Source, currentLine)){
        this->insert(currentLine);
    }
}