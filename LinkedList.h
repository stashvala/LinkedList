#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <gtest/gtest.h>

template<class T>
class LinkedList {
private:
    Node<T> *_head;
    std::size_t _size;

public:
    LinkedList<T>() : _head(NULL), _size(0) {}

    ~LinkedList<T>() {
        Node<T> *node = _head;
        while (node) {
            Node<T> *tmp = node->getNext();
            delete node;
            node = tmp;
        }
    }

    void append(T d) {
        Node<T> *n = new Node<T>(d, NULL);

        if (_head == NULL) { // if list is empty, set list head
            _head = n;
        }
        else { // if list isn't empty, append new node at the end
            Node<T> *tail = _head;

            while (tail->getNext() != NULL) {
                tail = tail->getNext();
            }

            tail->setNext(n);
        }

        _size++;
    }

    void remove(T d) {
        if (_head->getVal() == d) { // if deleting head, set next element for head
            Node<T> *tmp = _head->getNext();
            delete _head;
            _head = tmp;
        }
        else { // find element that needs to be deleted
            Node<T> *del = _head;
            while (del->getNext()->getVal() != d) {
                del = del->getNext();
            }

            Node<T> *tmp = del->getNext();
            del->setNext(tmp->getNext()); // set prev element pointer to next one

            delete tmp;
        }

        _size--;
    }

    T &operator[](const int index) {

        Node<T> *node = _head;
        for (int i = 0; node != NULL; i++) {
            if (i == index) {
                return node->getVal();
            }

            node = node->getNext();
        }

        T *t = NULL;
        return *t;
    }

    std::ostream &operator<<(std::ostream &os) {
        os << "List: ";

        Node<T> *n = _head;
        while (n) {
            os << n->getVal() << " -> ";
            n = n->getNext();
        }

        return os;
    }

    std::size_t size() {
        return _size;
    }

private:
    // testAppend
//    FRIEND_TEST(testAppend, appendToEmptyList);
//    FRIEND_TEST(testAppend, appendSecondElement);
//    FRIEND_TEST(testAppend, appendMultipleElements);
//    FRIEND_TEST(testAppend, appendVariousTypes);
//    FRIEND_TEST(testAppend, appendDuplicate);
//
//    // testRemove
//    FRIEND_TEST(testRemove, removeFromOneElementList);
//    FRIEND_TEST(testRemove, removeSecondFromTwoElementList);
//    FRIEND_TEST(testRemove, removeFirstFromTwoElementList);
//    FRIEND_TEST(testRemove, removeMiddleFromThreeElementList);
//    FRIEND_TEST(testRemove, removeMultipleElements);
//    FRIEND_TEST(testRemove, removeFromEmptyList);
//    FRIEND_TEST(testRemove, removeNonexistentElement);
//    FRIEND_TEST(testRemove, removeDuplicates);
//
//    // testPrint
//    FRIEND_TEST(testPrint, printOneElementList);
//    FRIEND_TEST(testPrint, printTwoElementList);
//    FRIEND_TEST(testPrint, printMultipleElementList);
//    FRIEND_TEST(testPrint, printEmptyList);
//
//    // testCLI
//    FRIEND_TEST(testCLI, inputPositiveInteger);
//    FRIEND_TEST(testPrint, inputNegativeInteger);
//    FRIEND_TEST(testPrint, input64BitInteger);
//    FRIEND_TEST(testPrint, inputFloat);
//    FRIEND_TEST(testPrint, inputChar);
//    FRIEND_TEST(testPrint, inputString);
};

#endif