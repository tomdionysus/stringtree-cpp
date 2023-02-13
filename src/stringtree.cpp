#include <iostream>

#include "stringtree.h"

using namespace StringTree;

template <class T> Tree<T>::Tree() {
}

template <class T> Tree<T>::~Tree() {
}

template <class T> void Tree<T>::set(string str, T value) {
	Node<T> **current = &root;
	if(root == nullptr) {
		// If Empty
		for(int i = 0; i < str.length(); i++) {
			*current = new Node<T>(str[i++], nullptr);
			current = &(*current->forward);
		}
	} else {
		// Walk
		for(int i = 0; i < str.length(); i++) {
			if(*current) {
				if(*current->find(str[i]) == nullptr) current = &(*current->add(str[i]));
				current = &(*current->forward);
			}
		}
	}
	*current->value = value;
	return;
}

template <class T> T Tree<T>::get(string str) {
	if(root == nullptr) return nullptr;
}

template <class T> void Tree<T>::clear(string str) {
}


template <class T> Node<T>::Node(char k, T v) {
	key = k;
	value = v;
}

template <class T> Node<T>::~Node() {
}

template <class T> Node<T>* Node<T>::find(char k) {
	Node* current = this;
	if(current->key == k) return current;
	while(current) {
		if(k < current->key) {
			if(current->left) current = current->left;
		} else {
			if(current->right) current = current->right;
		}
	}
	return nullptr;
}

template <class T> Node<T>* Node<T>::add(char k, T value) {
	Node<T>* current = this;
	if(current->key == k) return current;
	while(true) {
		if(k < current->key) {
			if(current->left) { 
				current = current->left;
			} else {
				current->left = new Node(k, value);
				return current->left;
			}
		} else {
			if(current->right) { 
				current = current->right;
			} else {
				current->right = new Node(k, value);
				return current->right;
			}
		}
	}
}