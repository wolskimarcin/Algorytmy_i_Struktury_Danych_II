#include "setHashed.h"
#include <iostream>
#include <chrono>
#include "fstream"
#include "random"
std::mt19937 rng(std::random_device{}());

int rand_int(int a, int b) {
    return std::uniform_int_distribution<int>(a, b)(rng);
}

int main() {
    /*int CAPACITY = 14;
    setHashed setA(CAPACITY);
    setHashed setB(CAPACITY);
    setA.insert(1);
    setA.insert(12);
    setA.insert(13);
    setA.insert(14);
    setA.insert(15);
    setA.insert(15);
    setA.insert(5);
    setA.insert(25);
    setA.insert(9);
    //setA.insert(3);

    setB.insert(2);
    setB.insert(3);
    setB.insert(9);

    std::cout<<"\nsetB:\n";
    setB.display();
    std::cout<<"\nsetA:\n";
    setA.display();

    setHashed set3 = setA + setB;
    std::cout<<"\nset3 = setA + setB:\n";
    set3.display();

    set3 = setA - setB;
    std::cout<<"\nset3 = setA - setB:\n";
    set3.display();

    set3 = setA * setB;
    std::cout<<"\nset3 = setA * setB:\n";
    set3.display();

    std::cout<<"\n[equality test] setA == setB ? (0 if false, 1 if true): " << (setA == setB);
*/
    // ------------TEST BENCH--------------------
    int pomiary = 100;
    int N = 500;
    std::chrono::high_resolution_clock clock;
    // ------------------------------------------

    setHashed set1(N+1);
    setHashed set2(N+1);
    for (int i = 1; i <= N; i++) {
        set2.insert(rand_int(1,N));
    }
    for (int i = 1; i <= 0; i++) {
        set1.insert(rand_int(1,N));
    }


    int wybor = 4; // 1 - insert, 2 - unify, 3 - intersection, 4 - difference
    if (wybor == 1) {
        std::ofstream insertOF;
        insertOF.open ("insert.txt");

        for (int i = 1; i <= N; i++) {
            long suma = 0;
            for (int j = 1; j <= pomiary; j++) {

                auto start = clock.now();

                for (int k = 1; k <= i; k++) {
                    set1.insert(k);
                }

                auto finish = clock.now();
                std::chrono::duration<long, std::nano> elapsed = finish - start;

                suma = suma + elapsed.count();
            }

            insertOF << i << " " << suma / pomiary << "\n";

        }
        insertOF.close();

    } else if (wybor == 2) {
        std::ofstream unifyOF;
        unifyOF.open ("unify.txt");

        for (int i = 1; i <= N; i++) {
            long suma = 0;
            for (int j = 1; j <= pomiary; j++) {

                auto start = clock.now();

                for (int k = 1; k <= i; k++) {
                    (set1 + set2);
                }

                auto finish = clock.now();
                std::chrono::duration<long, std::nano> elapsed = finish - start;

                suma = suma + elapsed.count();
            }

            unifyOF << i << " " << suma / pomiary << "\n";

        }
        unifyOF.close();

    } else if (wybor == 3) {
        std::ofstream intersectionOF;
        intersectionOF.open ("intersection.txt");

        for (int i = 1; i <= N; i++) {
            long suma = 0;
            for (int j = 1; j <= pomiary; j++) {

                auto start = clock.now();

                for (int k = 1; k <= i; k++) {
                    set1 * set2;
                }

                auto finish = clock.now();
                std::chrono::duration<long, std::nano> elapsed = finish - start;

                suma = suma + elapsed.count();
            }

            intersectionOF << i << " " << suma / pomiary << "\n";

        }
        intersectionOF.close();

    } else if (wybor == 4) {
        std::ofstream differenceOF;
        differenceOF.open ("difference.txt");

        for (int i = 1; i <= N; i++) {
            long suma = 0;
            for (int j = 1; j <= pomiary; j++) {

                auto start = clock.now();

                for (int k = 1; k <= i; k++) {
                    set1 - set2;
                }

                auto finish = clock.now();
                std::chrono::duration<long, std::nano> elapsed = finish - start;

                suma = suma + elapsed.count();
            }

            differenceOF << i << " " << suma / pomiary << "\n";

        }
        differenceOF.close();
    }

}