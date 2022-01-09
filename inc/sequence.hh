#ifndef SEQUENCE_HH
#define SEQUENCE_HH

#include "list.hh"

// Klasa modelująca pojęcie sekwencji,
// którą cechuje wskaźnik na pierwszy
// węzeł
class sequence: public list {

    public:

    sequence () {}

    ~sequence () {}

    // "Zwraca" wyraz i klucz węzła na pozycji index
    void at_index (string* word, int* key, int index) const;
    
    // Zwraca pozycję węzła, w którym znajduje 
    // się wyraz word i klucz key
    int index_of (string word, int key) const;

};

#endif