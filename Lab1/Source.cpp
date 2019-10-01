#include <iostream> 
#include <vector> 
#include <cmath>
#include "Graph.h"
#include "Tree.h"
#include "NodeTree.h"
#include "ListNode.h"
#include "Figure.h"
using namespace std;

int main() {
	Graph<int> abc = Graph<int>();
	abc.addVertex(0);
	abc.addVertex(1);
	abc.addVertex(2);
	abc.addVertex(3);
	abc.addVertex(4);
	abc.addEdge(0, 1);
	abc.addEdge(2, 1);
	abc.addEdge(4, 1);
	abc.addEdge(2, 3);
	abc.PrintGraph();
	Tree<int>* bcd = abc.SpanningTree();
	bcd->Print();
	cout << endl << endl;
	Tree<int> sfdzv = Tree<int>();
	sfdzv.addVertex(5, sfdzv.getRoot());
	sfdzv.addVertex(1, 5);
	sfdzv.addVertex(2, 5);
	sfdzv.addVertex(3, 5);
	sfdzv.addVertex(4, 5);
	sfdzv.addVertex(9, 4);
	sfdzv.Print();
	sfdzv.deleteVertex(1);
	sfdzv.Print();
	return 0;
}