#include <chrono>
#include <iostream>
#include "setLinked.h"
#include "chrono"
#include "fstream"
#include "random"

std::mt19937 rng(std::random_device{}());
using namespace std;
int rand_int(int a, int b) {
    return std::uniform_int_distribution<int>(a, b)(rng);
}

int main() {
    int pomiary = 10;
    int N = 100;


    setLinked set1;
    setLinked set2;
    for (int i = 1; i <= N; i++) {
        set2.add(rand_int(1,N));
    }

    chrono::high_resolution_clock clock;
/*
    ofstream insertOF;
    insertOF.open ("insert2.txt");

    for (int i = 1; i <= N; i++) {
        long suma = 0;
        for (int j = 1; j <= pomiary; j++) {

            auto start = clock.now();

            for (int k = 0; k < i; k++) {
                set1.add(k);
            }

            auto finish = clock.now();
            chrono::duration<long, nano> elapsed = finish - start;

            suma = suma + elapsed.count();
        }

        insertOF << i << " " << suma/pomiary << "\n";
    }
    insertOF.close();
*/


    ofstream unifyOF;
    unifyOF.open ("unify2.txt");
    for (int i = 1; i <= N; i++) {
        long suma = 0;
        for (int j = 1; j <= pomiary; j++) {


            auto start = clock.now();

            for (int k = 0; k < i; k++) {
                set1.unify(set2);
            }

            auto finish = clock.now();
            chrono::duration<long, nano> elapsed = finish - start;

            suma = suma + elapsed.count();
        }

        unifyOF << i << " " << suma/pomiary << "\n";
    }
    unifyOF.close();

/*
    ofstream intersectOF;
    intersectOF.open ("intersect.txt");
    for (int i = 1; i <= N; i++) {
        long suma = 0;
        for (int j = 1; j <= pomiary; j++) {
            set1 = SetSimple(N);

            auto start = clock.now();

            for (int k = 0; k < i; k++) {
                set1.intersect(set2);
            }

            auto finish = clock.now();
            chrono::duration<long, nano> elapsed = finish - start;

            suma = suma + elapsed.count();
        }

        intersectOF << i << " " << suma/pomiary << "\n";
    }
    intersectOF.close();
*/

/*
    ofstream intersectOF;
    intersectOF.open ("intersect.txt");
    for (int i = 1; i <= N; i++) {
        long suma = 0;
        for (int j = 1; j <= pomiary; j++) {
            set1 = SetSimple(N);

            auto start = clock.now();

            for (int k = 0; k < i; k++) {
                set1.intersect(set2);
            }

            auto finish = clock.now();
            chrono::duration<long, nano> elapsed = finish - start;

            suma = suma + elapsed.count();
        }

        intersectOF << i << " " << suma/pomiary << "\n";
    }
    intersectOF.close();
    */



    return 0;
}