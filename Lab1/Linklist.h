#pragma once
#include <iostream> 
class Node {
public:
	int num;
	int weight;
	Node* next;
};

class Linklist {
	Node* first;
	Node* end;
public:
	Linklist() : first(nullptr), end(nullptr);
	Node* getFirst();
	void addNode(int num);
	void display();
	void deleteNode(int y, int x = -1);
};