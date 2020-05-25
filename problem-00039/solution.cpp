#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Node {
	public:
		int n;
		Node *left;
		Node *right;

		Node(int n) {
			this->n = n;
			this->left = NULL;
			this->right = NULL;
		}
};

void runtimeInsertIntoBT(Node *root) {
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
            currentNode->left = newNode;
            btTracker.push(newNode);
		}
		if(rightVal != -1) {
			Node *newNode = new Node(rightVal);
			currentNode->right = newNode;
			btTracker.push(newNode);
		}
	}
}

int main() {
	int tmp;
	cout<<"Enter root node of binary tree:"<<endl;
	cin>>tmp;

	Node *root = new Node(tmp);
	runtimeInsertIntoBT(root);

	int n;
	cout<<"Enter node value to find it's cousins:"<<endl;
	cin>>n;

	vector<int> cousins;
	queue<pair<Node *, pair<int, int> > > btTracker;
	btTracker.push(make_pair(root, make_pair(-1, 0)));
	int levelToFind = -1;
	int ownParent = -1;
	while(btTracker.size() != 0) {
		pair<Node *, pair<int, int> > current = btTracker.front();
		Node *currentNode = current.first;
		int parent = current.second.first;
		int level = current.second.second;
		btTracker.pop();

		if(currentNode->n == n) {
			levelToFind = level;
			ownParent = parent;
		} else if(level == levelToFind) {
			if(parent != ownParent) {
				cousins.push_back(currentNode->n);
			}
		} else if(levelToFind != -1 && level > levelToFind) {
			break;
		}

		if(currentNode->left != NULL) {
			btTracker.push(make_pair(currentNode->left, make_pair(currentNode->n, level + 1)));
		}
		if(currentNode->right != NULL) {
			btTracker.push(make_pair(currentNode->right, make_pair(currentNode->n, level + 1)));
		}
	}

	cout<<"Cousins of "<<n<<" are:"<<endl;
	for(int i=0; i<cousins.size(); i++) {
		cout<<cousins[i]<<" ";
	}
	if(cousins.empty()) {
		cout<<"No cousins found.";
	}
	cout<<endl;
	return 0;
}
