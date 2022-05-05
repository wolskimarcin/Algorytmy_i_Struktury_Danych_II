#include "setHashed.h"
#include <iostream>

int main() {
    setHashed set1(10);
    set1.insert(1);
    set1.insert(12);
    set1.insert(13);
    set1.insert(14);
    set1.insert(15);
    set1.insert(15);
    set1.insert(5);
    set1.insert(25);
    set1.display();
}