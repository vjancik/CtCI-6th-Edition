#include "LinkedList.hpp"

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* tmp;
    while (head != nullptr) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <class T>
void LinkedList<T>::push_back(T data) {
    Node<T>* node = new Node<T>(data);
    if (head == nullptr) {
        head = node;
        tail = head;
    } else {
        tail->next = node;
        tail = node;
    }
    ++size;
}

template <class T>
T LinkedList<T>::pop_back() {
    if (size > 1) {
        Node<T>* tmp = head;
        while (tmp->next != nullptr && tmp->next->next != nullptr) {
            tmp = tmp.next;
        }
        T ret = tmp->next->data;
        delete tmp->next; //old tail
        tail = tmp; //new tail
        --size;
        return ret;
    }
    else if (size == 1) {
        T ret = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        --size;
        return ret;
    }
    return 0;
}

template <class T>
void LinkedList<T>::push_front(T data) {
    Node<T>* node = new Node<T>(data);
    if (head == nullptr) { 
        head = node;
        tail = head;
    } else {
        node->next = head; //old head
        head = node; //new head
    }
    ++size;
}

template <class T>
T LinkedList<T>::pop_front() {
    if (size > 1) {
        Node<T>* tmp = head;
        head = head->next;
        T ret = tmp->data;
        delete tmp;
        --size;
        return ret;
    }
    else if (size == 1) {
        T ret = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        --size;
        return ret;
    }
    return 0;
}

