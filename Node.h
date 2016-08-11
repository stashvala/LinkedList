#ifndef NODE_H
#define NODE_H

template<class T>
class Node {

private:
    T _val;
    Node<T> *_next;

public:
    Node<T>(T val, Node<T> *next) {
        _val = val;
        _next = next;
    }

    void setNext(Node<T> *next) {
        _next = next;
    }

    Node<T> *getNext() {
        return _next;
    }

    void setVal(T val) {
        _val = val;
    }

    T &getVal() {
        return _val;
    }
};

#endif