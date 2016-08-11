#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList(std::ostream &outStream)
  : _size(0),
    _outStream(outStream)
{}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* end = _head;
    while(end) {
	Node<T> *tmp = end->getNext();
	delete end;
	end = tmp;
    }
}

template <class T>
void LinkedList<T>::append(T d) {
    Node<T> *n = new Node<T>(d, NULL);

    if (_head == NULL) { // if list is empty, set list head
	_head = n;
    }
    else { // if list isn't empty, append new node at the end
	Node<T>* end = _head;

	while (end->getNext() != NULL) {
	    end = end->getNext();
	}

	end->setNext(n);
    }

    _size++;

    _outStream << "Število [" << d << "] je bilo dodano!"
	      << std::endl;
}

template <class T>
void LinkedList<T>::remove(T d) {
    if (_head->getVal() == d) { // if deleting head, set next element for head
	Node<T>* tmp = _head->getNext(); // TEST: what if there is only one element
	delete _head;
	_head = tmp;
    }
    else { // find element that needs to be deleted
	Node<T>* del = _head;
	while (del->getNext()->getVal() != d) { // TEST: if there is no element found
	    del = del->getNext();
	}

	Node<T>* tmp = del->getNext();
	del->setNext(tmp->getNext()); // set prev element pointer to next one

	delete tmp;
    }

    _outStream << "Število [" << d << "] je bilo izbrisano!"
	      << std::endl;

    _size--;
}

template <class T>
void LinkedList<T>::print() {
    _outStream << "Seznam: ";

    Node<T>* n = _head;
    while (n) { // TEST: printing empty
	_outStream << n->getVal() << " -> ";
	n = n->getNext();
    }

    _outStream << "konec" << std::endl
	      << "Velikost seznama je: "
	      << _size << std::endl;

}
