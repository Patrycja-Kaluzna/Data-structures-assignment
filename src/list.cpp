#include "list.hh"


// Dodaje węzeł na końcu listy
void list::add_back_node (const string new_word, const int new_key) {
    if (head == nullptr) {
        head = new node(new_word, new_key);
    } else {
        node* tmp = head;
        while (tmp->get_next_node() != nullptr) {
            tmp = tmp->get_next_node();
        }
        tmp->set_next_node(new node(new_word, new_key));
    }
}


// Usuwa pierwszy węzeł
void list::remove_front_node () {
    if (head != nullptr)
    {
        node* tmp = head;
        head = head->get_next_node();
        tmp->set_next_node(nullptr);
        delete tmp;
    } else {
        cout << "The front node can not be deleted, because the list is empty." << endl;
    }
}


// "Zwraca" wyraz i klucz pierwszego węzła
void list::front_node (string* front_word, int* front_key) const {
    *front_word = head->get_word();
    *front_key = head->get_key();
}


// Informuje czy lista jest pusta
bool list::is_empty () const {
    if (head == nullptr)
    {
        return true;
    } else {
        return false;
    }
}