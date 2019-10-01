#pragma once

template <typename T>
class NodeTree {
public:
	T data;
	NodeTree<T>* parent;
	vector<NodeTree<T>*> children;
	vector<int> weight;

	NodeTree();
	NodeTree(T data);
	NodeTree(T data, NodeTree<T>* parent);
};