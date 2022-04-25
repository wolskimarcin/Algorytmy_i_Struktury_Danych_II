#include <chrono>
#include <iostream>
#include "chrono"
#include "fstream"
#include "random"
//#include "SortedList.h"
#include "setLinked.h"

//
/*int rand_int(int a, int b) {
    return std::uniform_int_distribution<int>(a, b)(rng);
}*/

int main() {
    setLinked set1;
    set1.add(6);
    set1.add(10);
    set1.add(5);


    setLinked set2;
    set2.add(6);
    set2.add(7);
    set2.add(8);
    set2.add(5);
    set2.add(10);
    std::cout<<"\nset1 = ";
    set1.display();
    std::cout<<"\nset2 = ";
    set2.display();
    //set1.unify(set2);
    //std::cout<<"\nset1.unify(set2) = ";
    //set1.display();
    //set1.subtract(set2);
    //std::cout<<"\nset1.subtract(set2) = ";
    //set1.display();
    set1.intersect(set2); std::cout<<"\nset1.intersect(set2) = 6 10 =?= ";
    set1.display();


    /*
    list.insert_sorted(6);
    list.insert_sorted(1);
    list.insert_sorted(2);
    list.insert_sorted(6);
    list.display();
    list.remove_sorted(2);
    //list.remove_sorted(6);

    list.display();
    list.remove_sorted(6);
    list.display();
    list.remove_sorted(6);
    list.display();
    list.remove_sorted(1);
    list.display();
    */


    return 0;
}