#include "Tree.h"

template<typename T>
Tree<T>::Tree() : root(nullptr) {}

template<typename T>
NodeTree<T>* Tree<T>::getRoot() {
	return this->root;
}

template<typename T>
void Tree<T>::addVertex(T data, NodeTree<T> *current) {
	if (current) {
		current->children.push_back(new NodeTree<T>(data, current));
	}
	else root = new NodeTree<T>(data, nullptr);
}

template<typename T>
void Tree<T>::addVertex(T data, T current) {
	NodeTree<T>* temp = SearchElement(root, current);
	cout << endl << temp->data;
	addVertex(data, temp);
}

template<typename T>
void Tree<T>::deleteVertex(NodeTree<T> *deleteThis) {
	for (int i = 0; i < deleteThis->children.size(); i++) {
		deleteVertex(deleteThis->children[i]);
	}
	delete deleteThis;
	deleteThis = nullptr;
}

template<typename T>
void Tree<T>::deleteVertex(T dat) {
	NodeTree<T>* temp = SearchElement(root, dat);
	int i;
	for (i = 0; i < temp->parent->children.size(); i++)
		if (temp->parent->children[i]->data == dat) break;
	vector<NodeTree<T>*> temp1 = temp->parent->children;
	temp1.erase(temp1.begin() + i);
	deleteVertex(temp);
	temp->parent->children = temp1;
	delete temp;
	temp = nullptr;
}

template<typename T>
void Tree<T>::PrintTree(NodeTree<T>* current, int counter) {
	if (root == nullptr) cout << "Tree is empty" << endl;
	else {
		if (current != nullptr) { //почему там -572662307
			for (int i = 0; i < counter; i++)
				cout << " ";
			cout << current->data << endl;
			if (current->children.empty())
				return;
			else
				for (int i = 0; i < current->children.size(); i++)
					PrintTree(current->children[i], counter + 1);
		}
	}
}

template<typename T>
void Tree<T>::Print() {
	PrintTree(root, 0);
}

template<typename T>
NodeTree<T>* Tree<T>::SearchElement(NodeTree<T>* nextNode, T dat) {
	if (nextNode->data == dat) return nextNode;
	if (nextNode == nullptr) return nullptr;
	else  for (int i = 0; i < nextNode->children.size(); i++) {
		NodeTree<T>* temp = SearchElement(nextNode->children[i], dat);
		if (temp != nullptr)
			return temp;
	}
	return nullptr;
}

template class Tree<int>;