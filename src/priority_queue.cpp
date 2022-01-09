#include "priority_queue.hh"


// Dodaje wyraz new_word o kluczu 
// (priorytecie) new_key do kolejki
void priority_queue::insert (const string new_word, const int new_key) {
    if (size() > 0) {
        add_back_node(new_word, new_key);
    } else {
        set_head(new node(new_word, new_key));
    }
}


// Usuwa element o najwyższym priorytecie 
// (najmniejszym kluczu)
string priority_queue::remove_min () {
    node* tmp1 = get_head();
    node* tmp2 = get_head()->get_next_node();
    string min_key_word;
    comparator compare;
    int min_key = get_head()->get_key();
    if (get_head() != nullptr) {
        while (tmp2 != nullptr) {
            if (compare(*tmp1, *tmp2) < 0) {
                if (tmp1->get_key() < min_key)
                    min_key = tmp1->get_key();
            } else if (compare(*tmp1, *tmp2) == 0) {
                if (tmp1->get_key() < min_key)
                    min_key = tmp1->get_key();
            } else if (compare(*tmp1, *tmp2) > 0) {
                if (tmp2->get_key() < min_key)
                    min_key = tmp2->get_key();
            }
            tmp1 = tmp2;
            tmp2 = tmp2->get_next_node();
        }
    }
    if (get_head()->get_key() == min_key) {
        min_key_word = get_head()->get_word();
        remove_front_node();
    } else {
        node* tmp3 = get_head()->get_next_node();
        if (tmp3->get_key() == min_key) {
            min_key_word = tmp3->get_word();
            get_head()->set_next_node(tmp3->get_next_node());
            tmp3->set_next_node(nullptr);
            delete tmp3;
        } else {
            while (tmp3->get_key() != min_key) {
            tmp2 = tmp3;
            tmp3 = tmp3->get_next_node();
            }
            min_key_word = tmp3->get_word();
            tmp2->set_next_node(tmp3->get_next_node());
            tmp3->set_next_node(nullptr);
            delete tmp3;
        }
    }
    return min_key_word;
}


// Zwraca bez usuwania element o najwyższym 
// priorytecie (najmniejszym kluczu)
string priority_queue::min () {
    node* tmp1 = get_head();
    node* tmp2 = get_head()->get_next_node();
    string min_key_word;
    comparator compare;
    int min_key = get_head()->get_key();
    if (get_head() != nullptr) {
        while (tmp2 != nullptr) {
            if (compare(*tmp1, *tmp2) < 0) {
                if (tmp1->get_key() < min_key)
                    min_key = tmp1->get_key();
            } else if (compare(*tmp1, *tmp2) == 0) {
                if (tmp1->get_key() < min_key)
                    min_key = tmp1->get_key();
            } else if (compare(*tmp1, *tmp2) > 0) {
                if (tmp2->get_key() < min_key)
                    min_key = tmp2->get_key();
            }
            tmp1 = tmp2;
            tmp2 = tmp2->get_next_node();
        }
    }
    tmp1 = get_head()->get_next_node();
    if (get_head()->get_key() == min_key) {
        min_key_word = get_head()->get_word();
    } else {
        while (tmp1->get_key() != min_key) {
            tmp1 = tmp1->get_next_node();
        }
        min_key_word = tmp1->get_word();
    }
    return min_key_word;
}


// Zwraca liczbę elementów znajdujących
// się w kolejce
 int priority_queue::size () const {
     int counter;
     if (get_head() != nullptr) {
         counter = 1;
         node* tmp = get_head()->get_next_node();
         while (tmp != nullptr) {
             counter++;
             tmp = tmp->get_next_node();
         }
     } else {
         return 0;
     }
     return counter;
 }