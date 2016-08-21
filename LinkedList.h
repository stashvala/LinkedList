#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>

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

    void append(const T val) {
        Node<T> *n = new Node<T>(val, NULL);

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

    void remove(const T val) {
        if (_size <= 0) {
            throw std::out_of_range("LinkedList::remove: List is empty!");
        }

        if (_head->getVal() == val) { // if deleting head, set next element for head
            Node<T> *tmp = _head->getNext();
            delete _head;
            _head = tmp;
        }
        else { // find element that needs to be deleted
            Node<T> *del = _head;
            while (true) {
                if (del->getNext() == NULL) { // end of list reached
                    throw std::out_of_range("LinkedList::remove: Element wasn't found!");
                }
                else if (del->getNext()->getVal() == val) { // element was found
                    break;
                }
                else {
                    del = del->getNext(); // move to next element
                }
            }

            Node<T> *tmp = del->getNext();
            del->setNext(tmp->getNext()); // set prev element pointer to next one

            delete tmp;
        }

        _size--;
    }

    T &operator[](const size_t index) {

        Node<T> *node = _head;
        for (size_t i = 0; node != NULL; i++) {
            if (i == index) {
                return node->getVal();
            }

            node = node->getNext();
        }

        throw std::out_of_range("LinkedList::operator[]: Index doesn't exist in list!");
    }

    std::string print() {
        if (_size <= 0) {
            return "";
        }

        std::ostringstream os;

        Node<T> *n = _head;
        while (true) {
            os << n->getVal();
            if (n->getNext() == NULL) {
                break;
            }
            os << " -> ";
            n = n->getNext();

        }

        return os.str();
    }

    void sort(bool ascending = true) {
        if (_size <= 0) {
            throw std::out_of_range("LinkedList::sort: List is empty!");
        }

        bool unsorted = true;
        while (unsorted) {
            unsorted = false;
            Node<T> *current = _head;

            while (current->getNext() != NULL) {
                Node<T> *next = current->getNext();
                if (ascending) {
                    if (current->getVal() > next->getVal()) {
                        swapVals(current, next);
                        unsorted = true;
                    }
                }
                else {
                    if (current->getVal() < next->getVal()) {
                        swapVals(current, next);
                        unsorted = true;
                    }
                }

                current = next;
            }
        }
    }

    std::size_t size() const {
        return _size;
    }

private:

    void swapVals(Node<T> *n1, Node<T> *n2) {
        T tempVal = n1->getVal();
        n1->setVal(n2->getVal());
        n2->setVal(tempVal);
    }

};

#endif