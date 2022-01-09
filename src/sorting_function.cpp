#include "priority_queue.hh"
#include "sequence.hh"


// Sortuje sekwencję przepisując jej elementy
// do kolejki priorytetowej, a następnie
// wywołująć metodę remove_min() i dodając
// je spowrotem do sekwencji
sequence priority_queue_sort (priority_queue P, sequence S) {
    string* word = new string;
    int* key = new int;
    int i = 1;
    while (!S.is_empty()) {
        S.front_node(word, key);
        S.remove_front_node();
        P.insert(*word, *key);
    }
    while (!P.is_empty()) {
        *word = P.remove_min();
        S.add_back_node(*word, i);
        i++;
    }
    delete word;
    delete key;
    return S;
} 