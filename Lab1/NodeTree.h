#pragma once
#include <vector> 

template <typename T>
class NodeTree {
public:
	T data;
	NodeTree<T>* parent;
	std::vector<NodeTree<T>*> children;
	std::vector<int> weight;

	NodeTree();
	NodeTree(T data);
	NodeTree(T data, NodeTree<T>* parent);
};