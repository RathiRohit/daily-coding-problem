#include <iostream>
#include <vector>
#include <queue>

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

int runtimeInsertIntoBT(Node *root) {
	int nodeCount = 1;
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
            nodeCount++;
		}
		if(rightVal != -1) {
			Node *newNode = new Node(rightVal);
			currentNode->right = newNode;
			btTracker.push(newNode);
			nodeCount++;
		}
	}

	return nodeCount;
}

int getDistanceIndex(int arrSize, int distance) {
	int zeroIndex = (arrSize - 1) / 2;
	return zeroIndex + distance;
}

void measureHDs(Node *root, vector<pair<int, int> >& hd, int *leftMost, int *rightMost, int currentDist, int currentDepth) {
	if(root == NULL) {
		return;
	}

	int currentDistIndex = getDistanceIndex(hd.size(), currentDist);
	*leftMost = (currentDistIndex < *leftMost) ? currentDistIndex : *leftMost;
	*rightMost = (currentDistIndex > *rightMost) ? currentDistIndex : *rightMost;

	if(currentDepth >= hd[currentDistIndex].second) {
		hd[currentDistIndex].first = root->n;
		hd[currentDistIndex].second = currentDepth;
	}

	measureHDs(root->left, hd, leftMost, rightMost, currentDist - 1, currentDepth + 1);
	measureHDs(root->right, hd, leftMost, rightMost, currentDist + 1, currentDepth + 1);
}

int main() {
	int tmp;
	cout<<"Enter value of root node:"<<endl;
	cin>>tmp;

	Node *root = new Node(tmp);
    int nodeCount = runtimeInsertIntoBT(root);

	vector<pair<int, int> > hd(2 * nodeCount + 1, make_pair<int, int>(-1, -1));
	int leftMost = nodeCount;
	int rightMost = nodeCount;
	measureHDs(root, hd, &leftMost, &rightMost, 0, 0);

	cout<<"View from bottom can be:"<<endl;
	for(int i=leftMost; i<=rightMost; i++) {
		cout<<hd[i].first<<" ";
	}
	cout<<endl;
	return 0;
}
