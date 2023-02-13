#ifndef STRINGTREE
#define STRINGTREE

#include <string>

using namespace std;

namespace StringTree {

	template <class T> class Node {
		Node* left;
		Node* right;
		Node* forward;
		Node* backward;
		char key;
		
		public:
			T value;

			Node(char key, T value);
			~Node();

			Node* find(char key);
			Node<T>* add(char k, T value);
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
}

#endif
