#include <iostream>
#include <cassert>

template <typename T>
struct Node {
    T value;
    Node *next;
    Node() : value(T()), next(nullptr) {}
    Node(const T& item, Node *ptr = nullptr) : value(item), next(ptr) {}
    ~Node() = default;
};

template <typename T>
class SingleList {
    Node<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList();
    bool empty() const { return head == nullptr; }
    int size() const {
        int size = 0;
        Node<T> *node = head;
        while (node != nullptr) {
            size++;
            node = node->next;
        }
        return size;
    };
    void push_front(const T& item) {
        if (!empty()) {
            head = new Node<T>(item, head);
        } else {
            head = tail = new Node<T>(item);
        }
    }
    void push_back(const T& item) {
        if (!empty()) {
            tail->next = new Node<T>(item);
            tail = tail->next;
        } else {
            head = tail = new Node<T>(item);
        }
    }
    void insert_sorted(const T& item) {

        if (!empty()) {
            Node<T> *node = head;
            if (item < head->value) {
                push_front(item);
                return;
            } // "ITEM IS THE SMALLEST IN LIST"
            if (item > tail->value) {
                push_back(item);
                return;
            } // "ITEM IS THE BIGGEST IN LIST"
            if (find(item) != -1) {
                return ;
            }

            while (node->next->value <= item && node->next->next != nullptr) {
                // ustawiamy node na element po ktorym mamy wstawic item
                if (node->value == item){
                    return;
                }
                node = node->next;
            }
            if (node->next->value == item || node->value == item) {
                return;
            } // NO DUPLICATES

            // "ITEM IS IN BETWEEN TAIL AND HEAD"
            node->next = new Node<T>(item, node->next);

        } else {
            head = tail = new Node<T>(item);
        }
    }
    int find(T item) const { // RETURNS POSITION OF ITEM
        Node<T> *node = head;
        int i = 0;

        while (node->next != nullptr) {
            //std::cout<<"item = "<<item<<"  |  node->value = "<<node->value<< "\n";
            if (node->value == item) {
                return i;
            }
            i++;
            node = node->next;
        }
        if (node->value == item) {
            return i;
        }
        return -1;
    }
    void remove_sorted(const T& item) {
        int i = find(item);
        //std::cout<<"Is "<<item<<" present? : " <<i << "\n";
        if (i != -1) { // IF ITEM IS PRESENT IN LIST
            if (item == head->value) {
                pop_front();
                return;
            } // "ITEM IS THE SMALLEST IN LIST"
            if (item == tail->value) {
                pop_back();
                return;
            } // "ITEM IS THE BIGGEST IN LIST"

            Node<T> *node = head->next;
            Node<T> *before = head;
            while (node->value != item) {
                before = before->next;
                node = node->next;
            } // POINTS ON NODE TO DELETE
            before->next = node->next;
            delete node;

        } else { // ITEM IS NOT PRESENT
            return;
        }
    }
    T& front() const { return  head->value; }
    T& back() const {return tail->value; }
    int pos(int position) const { // RETURNS ITEM AT GIVEN POSITION

        if (empty()) {return -1;}
        Node<T> *node = head;
        int i = 0;
        while (node != nullptr){
            if (i == position) {
                return node->value;
            }
            node = node->next;
            i++;
        }
    }
    void pop_front() {
        assert(!empty());
        Node<T> *node = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
        }
        delete node;
    }
    void pop_back() {
        assert(!empty());
        Node<T> *node = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            Node<T> *before = head;
            while (before->next != tail) {
                before = before->next;
            }
            tail = before;
            tail->next = nullptr;
        }
        delete node;
    }
    void clear() {
        while (!empty()) { pop_front(0); }
    }
    void display() {
        Node<T> *node = head;
        while (node != nullptr){
            std::cout << node->value << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }
};

template <typename T>
SingleList<T>::~SingleList() {
    // I sposob.
    for (Node<T> *node; !empty(); ) {
        node = head->next;
        delete head;
        head = node;
    }
    // II sposob.
    // while (!empty()) { pop_front(); }
}