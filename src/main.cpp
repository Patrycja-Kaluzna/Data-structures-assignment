#include "sorting_function.cpp"
#include "priority_queue.hh"
#include "sequence.hh"
#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

int main () {
    // Pomiar czasu na potrzeby wyznaczenia złożoności obliczeniowej
    auto start = chrono::high_resolution_clock::now();

    int i, tmp, messages_length, number_of_chars, number_of_packets = 5;
    string message_from_Jan = "Hello, Anna! How are you?";
    int tab[number_of_packets];
    string* word = new string;
    int* key = new int;
    priority_queue P;
    sequence S1, S2;
    
    // Podział wiadomości od Jana na pakiety
    messages_length = message_from_Jan.length();
    number_of_chars = messages_length/number_of_packets;
    if (messages_length % number_of_packets != 0 || number_of_packets == 0) {
        cout << "The message can not be divided into " << number_of_packets << " parts." << endl;
        return 0;
    } else {
        char packet[number_of_chars+1];
        for (i = 0; i < messages_length; i = i + number_of_chars) {
            int counter = 0;
            while (counter < number_of_chars) {  
                packet[counter] = message_from_Jan[i + counter];  
                counter++;  
            }  
            packet[counter] = '\0';
            S1.add_back_node(packet, i);    // Nadawanie pakietom kolejnych numerów
        }

        // Odebranie pakietów przez Annę w losowej kolejności
        tmp = (rand() % number_of_packets) + 1;
        tab[0] = tmp;
        S1.at_index(word, key, tmp);
        S2.add_back_node(*word, *key);
        for (i = 1; i < number_of_packets; i++) {
            tmp = (rand() % number_of_packets) + 1;
            for (int j = 0; j < i; j++) {
                while (tmp == tab[j]) {
                    tmp = (rand() % number_of_packets) + 1;
                    j = 0;
                }
            }
            tab[i] = tmp;
            S1.at_index(word, key, tmp);
            S2.add_back_node(*word, *key);
        }

        // Sortowanie pakietów po stronie Anny
        S2 = priority_queue_sort(P, S2);

        // Sprawdzenie
        cout << "The message, which Jan sent: '" << message_from_Jan << "'" << endl; 
        cout << "The message, which Anna received: '";
        for (i = 0; i < number_of_packets; i++) {
        S2.at_index(word, key, i+1);
        cout << *word;
        }   
        cout << "'" << endl;
    }
    delete word;
    delete key;

    // Pomiar czasu na potrzeby wyznaczenia złożoności obliczeniowej c. d.
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time *= 1e-9;
    cout << "Program's execution time is: " << time << " s" << endl;
}