#include "comparator.hh"


// Porównuje dwa węzły ze sobą
int comparator::operator () (const node a, const node b) {
    if (a.get_key() < b.get_key()) {
        return -1;
    } else if (a.get_key() > b.get_key()) {
        return 1;
    } else {
        return 0;
    }
}