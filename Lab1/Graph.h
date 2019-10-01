#pragma once
#include <iostream> 
#include <vector> 
#include "Tree.h"
#include "ListNode.h"

template <typename T>
class Graph {
	std::vector<ListNode> adj;
	std::vector<T> info;
	void SpanningTreeRec(vector<bool> check, int thisVertex, Tree<T>* result);
public:
	Graph();
	void addVertex(T data);
	void deleteVertex(int x);
	void addEdge(int x, int y);
	void deleteEdge(int x, int y);
	void PrintGraph();
	std::Tree<T>* SpanningTree();
};