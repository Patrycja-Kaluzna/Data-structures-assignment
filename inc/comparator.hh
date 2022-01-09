#ifndef COMPARATOR_HH
#define COMPARATOR_HH

#include "node.hh"

// Klasa modelująca pojęcie komparatora,
// który porównuje dwa obiekty ze sobą
// zgodnie z koncepcją całkowitego 
// uporządkowania
class comparator {
public:

comparator () {}

~comparator () {}

// Porównuje dwa węzły ze sobą
int operator () (const node a, const node b);

};

#endif