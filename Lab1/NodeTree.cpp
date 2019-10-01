#include "NodeTree.h"

template <typename T>
NodeTree<T>::NodeTree() :parent(nullptr), children(NULL) {}

template <typename T>
NodeTree<T>::NodeTree(T data) :parent(nullptr), children(NULL), data(data) {}

template <typename T>
NodeTree<T>::NodeTree(T data, NodeTree<T>* parent) :data(data), parent(parent) {}

template class NodeTree<int>;