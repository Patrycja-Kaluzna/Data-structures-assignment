#ifndef LIST_HH
#define LIST_HH

#include "node.hh"
#include <memory>

// Klasa modelująca pojęcie listy,
// którą cechuje wskaźnik na
// pierwszy węzeł
class list {

    private:

    // Wskaźnik na pierwszy węzeł
    node* head = nullptr; 

    public:

    list () {}

    // Alokuje pod wskaźnikiem head pamięć i wczytuje
    // nowy wyraz i klucz do pierwszego węzła
    list (const string new_word, const int new_key):
       head(new node(new_word, new_key)) {}

    ~list () {}

    // Zwraca wskaźnik na pierwszy węzeł
    node* get_head () const {
        return head;
    }
    
    // Ustawia nowy węzeł jako pierwszy
    void set_head (node* new_head) {
        head = new_head;
    }

    // Dodaje węzeł na końcu listy
    void add_back_node (const string new_word, const int new_key);

    // Usuwa pierwszy węzeł
    void remove_front_node ();

    // "Zwraca" wyraz i klucz pierwszego węzła
    void front_node (string* front_word, int* front_key) const;

    // Informuje czy lista jest pusta
    virtual bool is_empty () const;

};

#endif 