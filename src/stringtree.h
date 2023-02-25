#ifndef STRINGTREE
#define STRINGTREE

#include <string>

using namespace std;

namespace StringTree {

	template <class T> class Node {
		
		public:
			char key;
			Node<T>* left;
			Node<T>* right;
			Node<T>* forward;
			Node<T>* backward;
			T value;

			Node(char key, T value);
			Node(char key);
			~Node();

			Node<T>* find(char key);
			Node<T>* add(char k);
			Node<T>* add(char k, T value);

			void deleteAll();
	};

	template <class T> class Tree {
		Node<T>* root;

		public:
			Tree();
			~Tree();

			void set(string str, T value);
			T get(string str);
			void clear(string str);
	};


	// Node

	template <class T> Node<T>::Node(char k, T v) {
		key = k;
		value = v;
		left = nullptr;
		right = nullptr;
		forward = nullptr;
	}

	template <class T> Node<T>::Node(char k) {
		key = k;
		left = nullptr;
		right = nullptr;
		forward = nullptr;
	}

	template <class T> Node<T>::~Node() {
		left = nullptr;
		right = nullptr;
		forward = nullptr;
	}

	template <class T> void Node<T>::deleteAll() {
		if(this->forward) this->forward->deleteAll();
		if(this->left) this->left->deleteAll();
		if(this->right) this->right->deleteAll();
		delete this;
	}

	template <class T> Node<T>* Node<T>::find(char k) {
		Node* current = this;
		while(current != nullptr) {
			if(current->key == k) return current;
			if(k < current->key) {
				current = current->left;
			} else {
				current = current->right;
			}
		}
		return nullptr;
	}

	template <class T> Node<T>* Node<T>::add(char k) {
		Node<T>* current = this;
		while(true) {
			if(current->key == k) return current;
			if(k < current->key) {
				if(current->left) { 
					current = current->left;
				} else {
					current->left = new Node(k);
					return current->left;
				}
			} else {
				if(current->right) { 
					current = current->right;
				} else {
					current->right = new Node(k);
					return current->right;
				}
			}
		}
	}

	template <class T> Node<T>* Node<T>::add(char k, T value) {
		Node<T>* current = this;
		while(true) {
			if(current->key == k) return current;
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

	// Tree


	template <class T> Tree<T>::Tree() {
		this->root = nullptr;
	}

	template <class T> Tree<T>::~Tree() {
		if(this->root != nullptr) this->root->deleteAll();
	}

	template <class T> void Tree<T>::set(string str, T value) {
		Node<T>** current = &root;
		Node<T>* last = nullptr;
		for(int i = 0; i < str.length(); i++) {
			if(*current == nullptr) {
				*current = new Node<T>(str[i]);
				last = *current;
				current = &((*current)->forward);
			} else {
				Node<T>* tmp = (*current)->add(str[i]);
				last = tmp;
				current = &(tmp->forward);
			}
		}
		last->value = value;
		return;
	}

	template <class T> T Tree<T>::get(string str) {
		Node<T>* current = root;
		Node<T>* last;
		
		for(int i = 0; i < str.length(); i++) {
			if(current == nullptr) return T();
			current = current->find(str[i]);
			if(current == nullptr) return T();
			last = current;
			current = current->forward;
		}
		if(last == nullptr) return T();
		return last->value;
	}

	template <class T> void Tree<T>::clear(string str) {
	}
}

#endif
