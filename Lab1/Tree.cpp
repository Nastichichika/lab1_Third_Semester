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
	std::cout << std::endl << temp->data;
	addVertex(data, temp);
}

template<typename T>
void Tree<T>::deleteVertex(NodeTree<T> *deleteThis) {
	for (int i = 0; i < deleteThis->children.size(); i++) {
		deleteVertex(deleteThis->children[i]);
	}
	delete deleteThis;
}

template<typename T>
void Tree<T>::deleteVertex(T dat) {
	NodeTree<T>* temp = SearchElement(root, dat);
	int i;
	for (i = 0; i < temp->parent->children.size(); i++)
		if (temp->parent->children[i]->data == dat) break;
	temp->parent->children.erase(temp->parent->children.begin() + i);
	deleteVertex(temp);
}

template<typename T>
void Tree<T>::PrintTree(NodeTree<T>* current, int counter) {
	if (root == nullptr) std::cout << "Tree is empty" << std::endl;
	else {
		if (current != nullptr) {
			for (int i = 0; i < counter; i++)
				std::cout << " ";
			std::cout << current->data << std::endl;
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