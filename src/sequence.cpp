#include "sequence.hh"


// "Zwraca" wyraz i klucz węzła na pozycji index
void sequence::at_index (string* word, int* key, int index) const {
    node* tmp = get_head();
    int i;
    for (i = 0; i < index-1; i++) {
        tmp = tmp->get_next_node();
    }
    *word = tmp->get_word();
    *key = tmp->get_key();
}


// Zwraca pozycję węzła, w którym znajduje 
// się wyraz word i klucz key. Jeśli nie ma
// takiego węzła to zwraca 0. Węzły są 
// numerowane od 1
int sequence::index_of (string word, int key) const {
    node* tmp = get_head();
    int index;
    if (tmp != nullptr) {
        if (tmp->get_word() == word && tmp->get_key() == key) {
            return 1;
        } else {
            tmp = tmp->get_next_node();
            index = 2;
            while (tmp != nullptr) {
                if (tmp->get_word() == word && tmp->get_key() == key) {
                    return index;
                } else {
                    tmp = tmp->get_next_node();
                    index++;
                }
            }
        }
    } 
    return 0;
}