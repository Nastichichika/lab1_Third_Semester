#pragma once
#include <iostream> 
#include <vector> 
#include "NodeTree.h"

template <typename T>
class Tree {
	NodeTree<T>* root;
	void PrintTree(NodeTree<T>* current, int counter);
public:
	Tree<T>();
	NodeTree<T>* getRoot();
	void addVertex(T data, NodeTree<T> *current);
	void addVertex(T data, T current);
	void deleteVertex(NodeTree<T> *deleteThis);
	void deleteVertex(T dat);
	NodeTree<T>* SearchElement(NodeTree<T>* nextNode, T dat);
	void Print();
};