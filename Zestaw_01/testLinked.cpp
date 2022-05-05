#include <chrono>
#include <iostream>
#include "setLinked.h"
#include "chrono"
#include "fstream"
#include "random"

std::mt19937 rng2(std::random_device{}());
using namespace std;
int rand_int(int a, int b) {
    return std::uniform_int_distribution<int>(a, b)(rng2);
}

int main() {
    int pomiary = 2000;
    int N = 500;


    setLinked set1;
    setLinked set2;
    for (int i = 1; i <= N; i++) {
        set2.add(rand_int(1,N));
    }
    for (int i = 1; i <= 1; i++) {
        set1.add(rand_int(1,N));
    }


    chrono::high_resolution_clock clock;

    int wybor = 1; // 1 - insert, 2 - unify, 3 - difference, 4 - intersection
    if (wybor == 1) {

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
    } else if (wybor == 2) {
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
    } else if (wybor == 3) {

        ofstream diffOF;
        diffOF.open ("diff2.txt");
        for (int i = 1; i <= N; i++) {
            long suma = 0;
            for (int j = 1; j <= pomiary; j++) {


                auto start = clock.now();

                for (int k = 0; k < i; k++) {
                    set1.diff(set2);
                }

                auto finish = clock.now();
                chrono::duration<long, nano> elapsed = finish - start;

                suma = suma + elapsed.count();
            }

            diffOF << i << " " << suma/pomiary << "\n";
        }
        diffOF.close();

    } else if (wybor == 4) {

        ofstream intersectOF;
        intersectOF.open ("intersect2.txt");
        for (int i = 1; i <= N; i++) {
            long suma = 0;
            for (int j = 1; j <= pomiary; j++) {

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
    }


    return 0;
}