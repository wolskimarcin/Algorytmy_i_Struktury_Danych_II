//
// Created by busher on 22.03.2022.
//
using namespace std;
#ifndef ZESTAW1_SETSIMPLE_H
#define ZESTAW1_SETSIMPLE_H

class SetSimple {
private:
    bool *array;
public:
    int N;

    explicit SetSimple(int initN) {
        N = initN;
        array = new bool[N];

        for (int i = 0; i < N; i++) {
            array[i] = false; // fill with false (empty set)
        }
    };

    ~SetSimple() {
        delete[] array;
    };

    void insert(int value) {
        array[value] = true;
    }

    void remove(int value) {
        array[value] = false;
    }

    bool ispresent(int position) {
        return array[position];
    }

    void unify(const SetSimple &other) {
        for (int i = 0; i < other.N; i++) {
            if (other.array[i]) {
                this->array[i] = true;
            }
        }
    }

    void intersect(const SetSimple &other) {
        for (int i = 0; i < this-> N; i++) {
            if (!other.array[i]) {
                this->array[i] = false;
            }
        }
    }

    void subtract(const SetSimple &other) {
        for (int i = 0; i < this-> N; i++) {
            if (other.array[i]) {
                this->array[i] = false;
            }
        }
    }

    void print() {
        for (int i = 0; i < N; i++) {
            if (array[i]) {
                cout << i << " ";
            }
        }
    }
};
#endif //ZESTAW1_SETSIMPLE_H
