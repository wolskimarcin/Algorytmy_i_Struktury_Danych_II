//
// Typ danych setHashed reprezentuje matematyczny zbiór. Hashowanie otwarte.
//
/*
 * Open hashing = Separate Chaining
 * The idea is to keep a list of all elements that hash to the same value.
 */
#ifndef ZESTAW_02_SETHASHED_H
#define ZESTAW_02_SETHASHED_H
#include "SortedList.h"

class setHashed {
    SingleList<int>* table;
    int CAPACITY ;
    int size ;

    int hash (int item) {
        while (item > 9) {
            item = item % CAPACITY;
        }
        std::cout<<"\nreturn index ("<< item <<") from hash function";
        return item;
    }

public:
    setHashed(int c) {
        CAPACITY = c;
        size = 0;
        table = new SingleList<int>[CAPACITY];
    }

    void insert(int item) {
        int index = hash(item);
        std::cout<<"\ninserting("<<item<<") to table["<<index<<"]";
        table[index].insert_sorted(item);
        size++;
    }

    void remove(int item) {
        int index = hash(item);

        table[index].remove_sorted(item);
        size;
    }

    void displayList(int i) {
        table[i].display();
    }

    void display() {
        for (int i = 0; i <= size; i++) {
            table[i].display();
        }
    }
};

#endif //ZESTAW_02_SETHASHED_H
