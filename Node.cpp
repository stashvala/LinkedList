#include "Node.h"

template <class T>
Node<T>::Node(T val, Node<T> *next) {
    _val = val;
    _next = next;
}

template <class T>
void Node<T>::setNext(Node<T> *next) {
  _next = next; 
}

template <class T>
Node<T>* Node<T>::getNext() { 
  return _next; 
}

template <class T>
void Node<T>::setVal(T val) { 
  _val = val; 
}

template <class T>
T Node<T>::getVal() { 
  return _val;
}