#pragma once
#include <iostream> 
class Node {
public:
	int num;
	int weight;
	Node* next;
};

class ListNode {
	Node* first;
	Node* end;
public:
	ListNode();
	Node* getFirst();
	void addNode(int num);
	void display();
	void deleteNode(int y, int x = -1);
};