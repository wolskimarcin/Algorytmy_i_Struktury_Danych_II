//
// Created by busher on 05.05.22.
//
#include "SetArray.h"
#include <iostream>

//HASH FUNCTION FOR RANGE OF INTEGER NUMBERS <first, last> : n, n+1, n+2, ... , m ; n < m
int capacityOfRange (int first,int last) { // fe. {-2,-1,0,1,2,3} => return 3 + 2 + 1 = 6
    return last - first + 1;
}

int generateIndex (int number, int first) { // fe. index for -1 : return -1 + 2 = 1
    return number - first;
}

void displaySet (SetArray& set, int first, int last) {
    for (int i = first; i <= last; i++) {
        if (set.set[generateIndex(i, first)]) {
            std::cout << " " << i;
        }
    }
}

//HASH FUNCTION FOR RANGE OF EVEN INTEGER NUMBERS <first, last> : n, n+2, n+4, ... , m ; n < m
int capacityOfEvenRange (int first,int last) { // fe. {-4,-2, 0,2,4,6} => return (6 - - 4 + 2)/2 = 12 / 2 = 6
    return (last - first + 2)/2;
}

int generateIndexEven (int number, int first) { // fe. index for 22 : return (2 + 4)/2 = 6/2 = 3
    return (number - first)/2;
}

void displayEvenSet (SetArray& set, int first, int last) {
    for (int i = first; i <= last; i++) {
        if (set.set[generateIndexEven(i, first)]) {
            std::cout << " " << i;
        }
    }
}

/*
 * FROM ASCII TABLE:
 * a = 97 (dec)
 * b = 98
 * c = 99
 * d = 100
 * ...
 * z = 122
 */

//HASH FUNCTION FOR RANGE OF LETTERS <first = a, last = z> : a,b,c,...,z
int generateIndexLetter (char letter) { // np. index for d : 'd' - 'a' = 100 - 97 = 3
    return letter - 'a';
}

void displayLettersSet (SetArray& set) {
    for (int i = 0; i <= 26; i++) {
        if (set.set[generateIndexLetter(i)]) {
            std::cout << " " << i;
        }
    }
}
/*
 * e = 101 (dec)
 * then ee:
 * (101 - 97) * 26 + (101 - 97) = 104 + 4 = 108
 *
 * a = 97 (dec)
 * then aa:
 * (97 - 97) * 26 + (97 - 97) = 0
 *
 * b = 98 (dec)
 * then ab:
 * (97 - 97) * 26 + (98 - 97) = 1
 */
//HASH FUNCTION FOR RANGE OF PAIRS OF LETTERS fe : aa,be,cd,...,zz
int generateIndexLetterPair (char letter1, char letter2) {
    return (letter1 - 'a')*26 + (letter2 - 'a');
}

void displayLettersPairSet (SetArray& set) {
    for (int i = 0; i <= 26; i++) {
        for (int j = 0; j <= 26; j++) {
            if (set.set[i*26 + j]) {
                std::cout << " " << (char)(i + 'a') <<", "<< (char)(j + 'a');
            }
        }
    }
}

int main2() {
    // TEST OF RANGE OF n, n+1, n+2, ... , m ; n < m
    SetArray set1(capacityOfEvenRange(-5, 5));
    set1.display();

    set1.insert(generateIndex(-2, -5));
    set1.insert(generateIndex(-1, -5));
    set1.insert(generateIndex(0, -5));
    set1.insert(generateIndex(4, -5));
    set1.insert(generateIndex(5, -5));
    displaySet(set1, -5, 5);

    // TO DO -

}
