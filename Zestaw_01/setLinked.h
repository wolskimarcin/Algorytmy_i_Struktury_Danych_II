//
// Created by busher on 05.04.2022.
//
#include <algorithm>
#include <vector>
#ifndef ZESTAW1_SETLINKED_H
#define ZESTAW1_SETLINKED_H

#include "SortedList.h"
class setLinked {
private:
    SingleList<int> zbior; // This DS represents sorted list without duplicates
public:

    void add (int x) {
        zbior.insert_sorted(x);
    }
    void remove (int x) {
        zbior.remove_sorted(x);
    }
    void display() {
        zbior.display();
    }
    bool isPresent(int x) const {
        return (zbior.find(x) == -1) ? false : true;
    }
    int size() const{
        return zbior.size();
    }
    int valueAt(int x) {
        return (zbior.pos(x));
    }

    void unify(const setLinked &other) {
        for (int i = 0; i < other.size(); i++) {
            int valueToAdd = other.zbior.pos(i);
            if (valueToAdd != -1) {
                this->add(valueToAdd);
            }
        }
    }

    void subtract(const setLinked &other) {
        for (int i = 0; i < other.size(); i++) {
            int otherValue = other.zbior.pos(i);
            if (isPresent(otherValue)) {
                this->remove(otherValue);
            }
        }
    }

    void intersect(const setLinked &other) {
        std::cout<<"\nsize = "<<size()<<"\n";
        for (int i = 0; i < size(); i++) {
            std::cout<<"\nis set1 valueAt("<<i<<") ="<<valueAt(i);
            if (!other.isPresent(valueAt(i))) {
                remove(valueAt(i));
            }
        }

    }
};


#endif //ZESTAW1_SETLINKED_H
