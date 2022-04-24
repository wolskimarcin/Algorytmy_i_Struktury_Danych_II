#include <chrono>
#include <iostream>
#include "setSimple.h"
#include "chrono"
#include "fstream"
#include "random"
#include "SortedList.h"

//
/*int rand_int(int a, int b) {
    return std::uniform_int_distribution<int>(a, b)(rng);
}*/

int main() {
    SingleList<int> list;
    list.insert_sorted(6);
    list.insert_sorted(1);
    list.insert_sorted(2);
    list.insert_sorted(6);
    list.insert_sorted(5);

    list.display();

    return 0;
}