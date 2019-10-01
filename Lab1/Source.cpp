#include <iostream> 
#include <vector> 
#include <cmath>
using namespace std;

template <typename T>
class NodeTree {
public:
	T data;
	NodeTree<T>* parent;
	vector<NodeTree<T>*> children;
	vector<int> weight;

	NodeTree() :parent(NULL), children(NULL) {}
	NodeTree(T data) :parent(NULL), children(NULL), data(data) {}
	NodeTree(T data, NodeTree<T>* parent) :data(data), parent(parent) {}

	//вставить поиск
};

template <typename T>
class Tree {
	NodeTree<T>* root;
public:
	Tree<T>() : root() {}
	NodeTree<T>* getRoot() {
		return this->root;
	}
	void addVertex(T data, NodeTree<T> *current) {
		if (current) {
			current->children.push_back(new NodeTree<T>(data, current));
		}
		else root = new NodeTree<T>(data, nullptr);
	}
	void addVertex(T data, T current) {
		NodeTree<T>* temp = SearchElement(root, current);
		cout << endl << temp->data;
		addVertex(data, temp);
	}
	void deleteVertex(NodeTree<T> *deleteThis) {
		for (int i = 0; i < deleteThis->children.size(); i++) {
			deleteVertex(deleteThis->children[i]);
		}
		delete deleteThis;
		deleteThis = nullptr;
	}
	void deleteVertex(T data) {
		NodeTree<T>* temp = SearchElement(root, data);
		deleteVertex(temp);
	}
	void PrintTree(NodeTree<T>* current, int counter) {
		if (root == nullptr) cout << "Tree is empty" << endl;
		else {
			if (current != nullptr) { //почему там -572662307
				for (int i = 0; i < counter; i++)
					cout << " ";
				cout << current->data << endl;
				if (current->children.empty())
					return;
				else
					for (int i = 0; i < current->children.size(); i++)
						PrintTree(current->children[i], counter + 1);
			}
		}

	}
	void Print() {
		PrintTree(root, 0);
	}
	NodeTree<T>* SearchElement(NodeTree<T>* nextNode, T dat) {
		if (nextNode->data == dat) return nextNode;
		if (nextNode == nullptr) return nullptr;
		else  for (int i = 0; i < nextNode->children.size(); i++) {
			NodeTree<T>* temp = SearchElement(nextNode->children[i], dat);
			if (temp != nullptr)
				return temp;
		}
		return nullptr;
	}

};

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
	Linklist() : first(nullptr), end(nullptr) {}
	Node* getFirst() {
		return this->first;
	}
	void addNode(int num) {
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
	void display() {
		Node* current = first;
		if (current == nullptr) cout << "List is clear";
		while (current) {
			cout << current->num << " ";
			current = current->next;
		}
	}
	void deleteNode(int y, int x = -1) {
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
	~Linklist() {
		while (first) {
			Node* temp = first;
			first = first->next;
			delete temp;
		}
	}
};

template <typename T>
class Graph {
	vector<Linklist> adj;
	vector<T> info;
public:
	Graph() {}
	void addVertex(T data) {
		Linklist temp = Linklist();
		adj.push_back(temp);
		info.push_back(data);
	}
	void deleteVertex(int x) {
		adj[x] = adj[adj.size() - 1];
		adj.pop_back();
		for (int i = 0; i < adj.size() - 1; i++) {
			adj[i].deleteNode(x, adj.size());
		}
		info[x] = adj[adj.size() - 1];
		info.pop_back();
	}
	void addEdge(int x, int y) {
		adj[x].addNode(y);
		adj[y].addNode(x);
	}
	void deleteEdge(int x, int y) {
		adj[x].deleteNode(y);
		adj[y].deleteNode(x);
	}
	void PrintGraph() {
		for (int i = 0; i < adj.size(); i++) {
			adj[i].display();
			cout << endl;
		}
	}
	void SpanningTreeRec(vector<bool> check, int thisVertex, Tree<T>* result) {
		check[thisVertex] = 1;
		cout << check[thisVertex];
		Linklist listVertex = adj[thisVertex];
		Node* temp = listVertex.getFirst();
		while (temp) {
			if (check[temp->num] == false) {
				result->addVertex(info[thisVertex], result->SearchElement(result->getRoot(), info[thisVertex]));
				SpanningTreeRec(check, temp->num, result);
			}
			temp = temp->next;
		}
	}
	Tree<T>* SpanningTree() {
		int sizeGraph = this->adj.size();
		vector<bool> check;
		Tree<T>* result = new Tree<T>;
		for (int i = 0; i < sizeGraph; i++)
			check.push_back(false);
		if (!info.empty()) result->addVertex(info[0], result->getRoot());
		SpanningTreeRec(check, 0, result);
		return result;
	}
};

class Circle {
public:
	double x0, y0;
	double radius;
	Circle(double x0, double y0, double radius) {
		this->radius = radius;
		this->x0 = x0;
		this->y0 = y0;
	}
	Circle(double radius) {
		this->radius = radius;
		this->x0 = 0;
		this->y0 = 0;
	}
	void inversion(Circle fig) {
		double newx = x0 + ((radius*radius)*(x0 - fig.x0)) / ((x0 - fig.x0)*(x0 - fig.x0) + (y0 - fig.y0)*(y0 - fig.y0));
		double newy = y0 + ((radius*radius)*(y0 - fig.y0)) / ((x0 - fig.x0)*(x0 - fig.x0) + (y0 - fig.y0)*(y0 - fig.y0));

	}
};

class Line {
public:
	double k, b;

	Line(double k, double b) {
		this->k = k;
		this->b = b;
	}
	Circle reflection(Circle fig2) {
		double newk = (-1) / k;
		double newb = fig2.y0 - fig2.x0*newk;
		double perx = (b - newb) / (newk - k);
		double pery = newk*perx + newb;
		double rezx = 2 * perx - fig2.x0;
		double rezy = 2 * pery - fig2.y0;
		Circle result(rezx, rezy, fig2.radius);
		return result;
	}
	Line reflection(Line fig2) {
		double tg = abs((k - fig2.k) / (1 + k*fig2.k));
		double newk = (tg + k) / (1 - k*tg);
		double curx = (b - fig2.b) / (fig2.k - k);
		double cury = k*curx + b;
		double newb = cury - curx*newk;
		Line result(newk, newb);
		return result;
	}
};

class Point {
	double x, y;
public:
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	void reflectionPoint(Line some) {

	}

};

int main() {
	Graph<int> abc = Graph<int>();
	abc.addVertex(0);
	abc.addVertex(1);
	abc.addVertex(2);
	abc.PrintGraph();
	abc.addEdge(0, 2);
	abc.PrintGraph();
	abc.addEdge(1, 0);
	abc.PrintGraph();
	abc.addEdge(2, 1);
	abc.PrintGraph();
	Tree<int>* bcd = abc.SpanningTree();
	bcd->Print();
	/*Tree<int> bcd = Tree<int>();
	bcd.addVertex(5, bcd.getRoot());
	bcd.addVertex(1, 5);
	bcd.addVertex(2, 5);
	bcd.addVertex(3, 5);
	bcd.addVertex(4, 5);
	bcd.addVertex(9, 4);
	bcd.Print();
	bcd.deleteVertex(5);
	bcd.Print();*/
	return 0;
}