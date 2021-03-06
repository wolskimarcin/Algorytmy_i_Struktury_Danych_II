#include <chrono>
#include <iostream>
#include "setSimple.h"
#include "chrono"
#include "fstream"
#include "random"
std::mt19937 rng(std::random_device{}());

int random_int(int a, int b) {
    return std::uniform_int_distribution<int>(a, b)(rng);
}


int mai21n() {
    int pomiary = 1000;
    int N = 500;


    SetSimple set1(N);
    SetSimple set2(N);
    for (int i = 1; i <= N; i++) {
        set2.insert(random_int(1,N));
    }
    chrono::high_resolution_clock clock;

    int wybor = 2; // 1 - insert, 2 - unify, 3 - intersect
    if (wybor == 1) {
        ofstream insertOF;
        insertOF.open ("insert.txt");

        for (int i = 1; i <= N; i++) {
            long suma = 0;
            for (int j = 1; j <= pomiary; j++) {
                set1 = SetSimple(N);

                auto start = clock.now();

                for (int k = 0; k < i; k++) {
                    set1.insert(k);
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
        unifyOF.open ("unify.txt");
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

        ofstream intersectOF;
        intersectOF.open ("intersect.txt");
        for (int i = 1; i <= N; i++) {
            long suma = 0;
            for (int j = 1; j <= pomiary; j++) {
                //set1 = SetSimple(N);

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