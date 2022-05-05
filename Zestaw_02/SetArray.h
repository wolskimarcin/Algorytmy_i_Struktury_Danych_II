//
// Created by busher on 04.05.22.
//

#ifndef ZESTAW_02_SetArray_H
#define ZESTAW_02_SetArray_H

#include <utility>
#include <cassert>
#include <iostream>

class SetArray {
public:
    int CAPACITY;
    int size;
    bool* set;

    SetArray(int b);
    //~SetArray() { clear(); delete [] table; }
    bool empty() const;
    void insert(int p) {
        if (!set[p]) {
            set[p] = true;
            size++;
        }
    }

    void remove(int key) {
        if (set[key]) {
            set[key] = false;
            size--;
        }
    }

    void display() const {
        for (int i = 0; i < CAPACITY; i++) {
            if (set[i]) {
                std::cout<<" "<<i;
            }
        }
    }

    SetArray operator+ (SetArray& other) {
        int newCAPACITY = (CAPACITY < other.CAPACITY ? other.CAPACITY : CAPACITY);
        SetArray ResultSet(newCAPACITY);

        for (int i = 0; i < newCAPACITY; i++) {
            if (set[i] || other.set[i]) {
                ResultSet.insert(i);
            }
        }
        return ResultSet;
    }

    SetArray operator- (SetArray& other) {
        int newCAPACITY = (CAPACITY < other.CAPACITY ? other.CAPACITY : CAPACITY);
        SetArray ResultSet(newCAPACITY);

        for (int i = 0; i < newCAPACITY; i++) {
            if (set[i] && !other.set[i]) {
                ResultSet.insert(i);
            }
        }
        return ResultSet;
    }

    SetArray operator* (SetArray& other) {
        int newCAPACITY = (CAPACITY < other.CAPACITY ? other.CAPACITY : CAPACITY);
        SetArray ResultSet(newCAPACITY);

        for (int i = 0; i < newCAPACITY; i++) {
            if (set[i] && other.set[i]) {
                ResultSet.insert(i);
            }
        }
        return ResultSet;
    }

    bool isEqual(SetArray& other) {

        for (int i = 0; i < CAPACITY; i++) {
            if (set[i] != other.set[i]) {
                return false;
            }
        }
        return true;
    }
    void clear();
};

SetArray::SetArray(int b) {
    CAPACITY = b;
    size = 0;
    set = new bool[CAPACITY];

    for (int i = 0; i < CAPACITY; i++)
        set[i] = false;
}

#endif //ZESTAW_02_SetArray_H
