#ifndef PRIORITY_QUEUE_HH
#define PRIORITY_QUEUE_HH

#include "comparator.hh"
#include "list.hh"

// Klasa modelująca pojęcie kolejki
// priorytetowej, którą cechuje
// wskaźnik na pierwszy węzeł
class priority_queue: public list {

    public:

    priority_queue () {}

    // Alokuje pod wskaźnikiem head pamięć i wczytuje
    // nowy wyraz i klucz do pierwszego węzła
    priority_queue (const string new_word, const int new_key) {
        set_head(new node(new_word, new_key));
    }

    ~priority_queue () {}

    // Dodaje wyraz new_word o kluczu 
    // (priorytecie) new_key do kolejki
    void insert (const string new_word, const int new_key);

    // Usuwa element o najwyższym priorytecie 
    // (najmniejszym kluczu)
    string remove_min ();

    // Zwraca bez usuwania element o najwyższym 
    // priorytecie (najmniejszym kluczu)
    string min ();

    // Zwraca liczbę elementów znajdujących
    // się w kolejce
    int size () const;

};

#endif