#include <iostream>
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

bool isHeightBalanced(Node *root, int *height) {
	if(root == NULL) {
		*height = 0;
		return true;
	}

	int leftHeight;
	int rightHeight;
	bool isLeftHeightBalanced;
	bool isRightHeightBalanced;

	isLeftHeightBalanced = isHeightBalanced(root->left, &leftHeight);
	isRightHeightBalanced = isHeightBalanced(root->right, &rightHeight);

	*height = max(leftHeight, rightHeight) + 1;
	return isLeftHeightBalanced && isRightHeightBalanced && (abs(leftHeight - rightHeight) <= 1);
}

int main() {
	Node *root = new Node(1);

	runtimeInsertIntoBT(root);

	int height = 0;
	if(isHeightBalanced(root, &height)) {
		cout<<"Binary tree is height balanced."<<endl;
		return 0;
	}

	cout<<"Binary tree is not height balanced."<<endl;
	return 0;
}
