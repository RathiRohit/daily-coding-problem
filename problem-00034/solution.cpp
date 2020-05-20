#include <iostream>
#include <map>
#include <queue>

#define ll long long
#define ull unsigned long long

using namespace std;

class Node {
	public:
		int n;
		Node *left;
		Node *right;
		Node *parent;

		Node(int n) {
			this->n = n;
			this->left = NULL;
			this->right = NULL;
			this->parent = NULL;
		}
};

void runtimeInsertIntoBT(Node *root, map<int, Node *>& nodeMap) {
	queue<Node *> btTracker;
	btTracker.push(root);

	while(btTracker.size() != 0) {
		Node *currentNode = btTracker.front();
		btTracker.pop();

		int leftVal, rightVal;
		cout<<"Enter left & right node values of "<<currentNode->n<<":"<<endl;
		cout<<"(-1 for null value)"<<endl;
		cin>>leftVal>>rightVal;

		if(leftVal != -1) {
			Node *newNode = new Node(leftVal);
			newNode->parent = currentNode;
            currentNode->left = newNode;
            btTracker.push(newNode);
            nodeMap[leftVal] = newNode;
		}
		if(rightVal != -1) {
			Node *newNode = new Node(rightVal);
			newNode->parent = currentNode;
			currentNode->right = newNode;
			btTracker.push(newNode);
			nodeMap[rightVal] = newNode;
		}
	}
}

int findLCA(Node *node1, Node *node2) {
	if(node1 == NULL || node2 == NULL) {
		return -1;
	}

	map<int, bool> isVisited;

	while(node1 != NULL) {
		isVisited[node1->n] = true;
		node1 = node1->parent;
	}

	while(node2 != NULL) {
		if(isVisited.count(node2->n) == 1) {
			return node2->n;
		}
		isVisited[node2->n] = true;
		node2 = node2->parent;
	}

	return -1;
}

int main() {
	int tmp;
	cout<<"Enter value of root node:"<<endl;
	cin>>tmp;

	Node *root = new Node(tmp);
	map<int, Node *> nodeMap;
	nodeMap[tmp] = root;
	runtimeInsertIntoBT(root, nodeMap);

	int node1, node2;
	cout<<"Enter two nodes to find their LCA (nodes should be present in the tree):"<<endl;
	cin>>node1>>node2;

	cout<<"LCA: "<<findLCA(nodeMap[node1], nodeMap[node2])<<endl;
	return 0;
}
