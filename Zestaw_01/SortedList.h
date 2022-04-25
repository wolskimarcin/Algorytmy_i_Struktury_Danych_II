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
    T& front() const { return  head->value; }
    T& back() const {return tail->value; }
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
        while (!empty()) { pop_front(); }
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