#include "ListNode.h"

ListNode::ListNode() : first(nullptr), end(nullptr) {}

Node* ListNode::getFirst() {
	return this->first;
}

void ListNode::addNode(int num) {
	if (first == nullptr) {
		Node* temp = new Node;
		temp->num = num;
		temp->next = nullptr;
		first = temp;
		end = first;
	}
	else {
		Node* temp = new Node;
		temp->num = num;
		end->next = temp;
		temp->next = nullptr;
		end = temp;
	}
}

void ListNode::display() {
	Node* current = first;
	if (current == nullptr) std::cout << "List is clear";
	while (current) {
		std::cout << current->num << " ";
		current = current->next;
	}
}

void ListNode::deleteNode(int y, int x) {
	Node* cur = first;
	if (y > -1) {
		int temp = x;
		x = y;
		y = temp;
	}
	if (first != nullptr) {
		if (y > -1 && cur->num == y) cur->num = y;
		if (first->num == x) {
			if (first->next == nullptr) {
				Node* temp = first;
				first = nullptr;
				delete temp;
			}
			else {
				Node* temp = first;
				first = first->next;
				delete temp;
			}
		}
		else
			while (cur->next) {
				if (cur->next->num == x) {
					Node* temp = cur->next;
					cur->next = cur->next->next;
					delete temp;
				}
				else if (y > -1 && cur->next->num == y) cur->num = y;
			}
	}
}
