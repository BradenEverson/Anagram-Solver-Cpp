#include <headers/trie.h>

void trie::insert(std::string& alphabetized_string){
    trie_elem current = rootElement;
    for(int i = 0; i < alphabetized_string.length(); i++){
        TriePayload currentTrie;
        for(int j = i+1; j < alphabetized_string.length(); j++){
            if(!(alphabetized_string[i] == alphabetized_string[j])){
                j = i;
                break;
            }
            currentTrie.count = i;
            currentTrie.character = alphabetized_string[i];
            if(current.children.find(currentTrie) == current.children.end()){
                //not present
                trie_elem newTrie_elem;
                newTrie_elem.value = currentTrie;
                if(i == alphabetized_string.length()-1){
                    newTrie_elem.isEndOfTrie = true;
                }
                current.children.insert({currentTrie, newTrie_elem});
            }
            current = current.children.at(currentTrie);
        }
    }
}

trie::trie(trie_elem rootElement){
    this->rootElement = rootElement;
}