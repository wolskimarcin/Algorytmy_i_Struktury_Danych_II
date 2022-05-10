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

    int hash (int item) {
        //std::cout<<"\nreturn index ("<< (item % CAPACITY) <<") from hash function";
        return (item % CAPACITY);
    }

public:
    int size;
    setHashed(int c) {
        CAPACITY = c;
        size = 0;
        table = new SingleList<int>[CAPACITY];
    }

    ~setHashed() {
        delete [] table;
    }

    void insert(int item) {
        int index = hash(item);
        //std::cout<<"\ninserting("<<item<<") to table[index="<<index<<"]";
        table[index].insert_sorted(item);
        size++;
    }

    void remove(int item) {
        int index = hash(item);

        table[index].remove_sorted(item);
        size--;
    }

    void displayList(int i) {
        table[i].display();
    }

    bool consist(int item) {
        int index = hash(item);

        return (table[index].find(item) != -1) ? true : false;
    }
    void display() {
        for (int i = 0; i < CAPACITY; i++) {
            //std::cout<<"\nTable["<<i<<"] is empty?: "<<table[i].empty();
            if (!table[i].empty()) {
                table[i].display();
            }
        }
    }

    setHashed operator+ (setHashed& other) {
        setHashed newSet(this->CAPACITY);

        for (int i = 0; i < CAPACITY; i++) {
            if (!table[i].empty()) {
                Node<int> *traverse = table[i].head;  // point on linked list's head
                newSet.insert(traverse->value); // insert every linked list value to new hash table
                while (traverse->next != nullptr) {
                    traverse = traverse->next;
                    newSet.insert(traverse->value); // insert every linked list value to new hash table
                }
            }
        }

        for (int i = 0; i < CAPACITY; i++) {
            if (!other.table[i].empty()) {
                Node<int> *traverse = other.table[i].head;
                newSet.insert(traverse->value);
                while (traverse->next != nullptr) {
                    traverse = traverse->next;
                    newSet.insert(traverse->value);
                }
            }
        }
        return newSet;
    }

    setHashed operator- (setHashed& other) {
        setHashed newSet(this->CAPACITY);

        for (int i = 0; i < CAPACITY; i++) {
            if (!table[i].empty()) {
                Node<int> *traverse = table[i].head;  // point on linked list's head
                newSet.insert(traverse->value); // insert every linked list value to new hash table
                while (traverse->next != nullptr) {
                    traverse = traverse->next;
                    newSet.insert(traverse->value); // insert every linked list value to new hash table
                }
            }
        }

        for (int i = 0; i < CAPACITY; i++) {
            if (!other.table[i].empty()) {
                Node<int> *traverse = other.table[i].head;
                newSet.remove(traverse->value);
                while (traverse->next != nullptr) {
                    traverse = traverse->next;
                    newSet.remove(traverse->value);
                }
            }
        }
        return newSet;
    }

    setHashed operator* (setHashed& other) {
        setHashed newSet(this->CAPACITY);

        for (int i = 0; i < CAPACITY; i++) {
            if (!other.table[i].empty()) {
                Node<int> *traverse = other.table[i].head;
                if (consist(traverse->value)) {
                    newSet.insert(traverse->value);
                }
                while (traverse->next != nullptr) {
                    traverse = traverse->next;
                    if (consist(traverse->value)) {
                        newSet.insert(traverse->value);
                    }
                }
            }
        }
        return newSet;
    }

    bool operator== (setHashed& other) {

        for (int i = 0; i < CAPACITY; i++) {
            if (!other.table[i].empty()) {
                Node<int> *traverse = other.table[i].head;
                if (!consist(traverse->value)) {
                    return false;
                }
                while (traverse->next != nullptr) {
                    traverse = traverse->next;
                    if (!consist(traverse->value)) {
                        return false;
                    }
                }
            }
        }

        for (int i = 0; i < CAPACITY; i++) {
            if (!table[i].empty()) {
                Node<int> *traverse = other.table[i].head;
                if (!other.consist(traverse->value)) {
                    return false;
                }
                while (traverse->next != nullptr) {
                    traverse = traverse->next;
                    if (!other.consist(traverse->value)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

#endif //ZESTAW_02_SETHASHED_H
