#ifndef NODE_HH
#define NODE_HH

#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Klasa modelująca pojęcie węzła, który
// cechują wyraz, jego klucz (priorytet)
// i wzkaźnik na nastęny węzeł
class node {

    // Wyraz
    string word;

    // Klucz (priorytet)
    int key;

    // Wzkaźnik na następny węzeł
    node* next_node = nullptr;

    public:

    node () {}

    // Wczytuje nowy wyraz i klucz
    node (const string new_word, const int new_key):
        word(new_word), key(new_key) {}

    ~node () {}

    // Wczytuje nowy wyraz
    void set_word (string new_word) {
        word = new_word;
    }

    // Wczytuje nowy klucz
    void set_key (int new_key) {
        key = new_key;
    }

    // Ustawia nowy następny węzeł
    void set_next_node (node* new_next_node) {
        next_node = new_next_node;
    }

    // Czyta aktualny wyraz
    string get_word () const {
        return word;
    }

    // Czyta aktualny klucz
    int get_key () const {
        return key;
    }

    // Zwraca wzkaźnik na aktualny następny węzeł
    node* get_next_node () const {
        return next_node;
    }

};

#endif