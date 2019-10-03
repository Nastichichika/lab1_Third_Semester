#include "Graph.h"

template<typename T>
Graph<T>::Graph() {}

template <typename T>
void Graph<T>::addVertex(T data) {
	ListNode temp = ListNode();
	adj.push_back(temp);
	info.push_back(data);
}

template <typename T>
void Graph<T>::deleteVertex(int x) {
	adj[x] = adj[adj.size() - 1];
	adj.pop_back();
	for (int i = 0; i < adj.size() - 1; i++) {
		adj[i].deleteNode(x, adj.size());
	}
	info[x] = info[info.size() - 1];
	info.pop_back();
}

template <typename T>
void Graph<T>::addEdge(int x, int y) {
	adj[x].addNode(y);
	adj[y].addNode(x);
}

template <typename T>
void Graph<T>::deleteEdge(int x, int y) {
	adj[x].deleteNode(y);
	adj[y].deleteNode(x);
}

template <typename T>
void Graph<T>::PrintGraph() {
	for (int i = 0; i < adj.size(); i++) {
		adj[i].display();
		std::cout << std::endl;
	}
}

template <typename T>
void Graph<T>::SpanningTreeRec(std::vector<bool> check, int thisVertex, Tree<T>* result) {
	check[thisVertex] = 1;
	ListNode listVertex = adj[thisVertex];
	Node* temp = listVertex.getFirst();
	while (temp) {
		if (check[temp->num] == false) {
			std::cout << info[thisVertex];
			result->addVertex(info[temp->num], result->SearchElement(result->getRoot(), info[thisVertex]));
			SpanningTreeRec(check, temp->num, result);
		}
		int sum = 0;
		for (int i = 0; i < check.size(); i++)
			sum += check[i];
		if (sum == check.size()) return;
		temp = temp->next;
	}
}

template <typename T>
Tree<T>* Graph<T>::SpanningTree() {
	int sizeGraph = this->adj.size();
	std::vector<bool> check;
	Tree<T>* result = new Tree<T>;
	for (int i = 0; i < sizeGraph; i++)
		check.push_back(false);
	if (!info.empty()) result->addVertex(info[0], result->getRoot());
	SpanningTreeRec(check, 0, result);
	return result;
}

template class Graph<int>;
template class Graph<int>;