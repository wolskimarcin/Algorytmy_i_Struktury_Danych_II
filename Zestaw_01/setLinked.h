//
// Sorted set based on sorted linked list
//

#include <algorithm>
#include <vector>
#ifndef ZESTAW1_SETLINKED_H
#define ZESTAW1_SETLINKED_H

#include "SortedList.h"
class setLinked {
private:
    SingleList<int> zbior; // This DS represents sorted list without duplicates
public:

    void add (int x) {
        zbior.insert_sorted(x);
    }
    void remove (int x) {
        zbior.remove_sorted(x);
    }
    void display() {
        zbior.display();
    }
    bool isPresent(int x) const {
        return (zbior.find(x) == -1) ? false : true;
    }
    int size() const{
        return zbior.size();
    }
    int valueAt(int x) {
        return (zbior.pos(x));
    }

    void diff(setLinked &other) {
        zbior.sortedDiff(other.zbior);
    }
    void unify(setLinked &other) {
        zbior.sortedMerge(other.zbior);
    }

    void intersect(setLinked &other) {
        zbior.sortedIntersection(other.zbior);
    }
};


#endif //ZESTAW1_SETLINKED_H
