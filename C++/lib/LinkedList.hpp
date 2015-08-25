#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <cstddef>

using namespace std;

template <class T>
class Node {
    T data;
    Node<T>* next;
    Node();
    public:
        Node(Node<T>&& other) : data(move(other.data)), next(move(other.next)) {}
        Node(T data) : data(data) {}
};

template <class T>
class LinkedList {
    Node<T>* head;
    Node<T>* tail;
    size_t size;
    public:
        LinkedList();
        ~LinkedList();

        void push_back(T data);
        T pop_back();
        void push_front(T data);
        T pop_front();
};

#endif
