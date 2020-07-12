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

void invertBT(Node *root) {
    if(root == NULL) {
        return;
    }

    Node *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invertBT(root->left);
    invertBT(root->right);
}

void printBT(Node *root) {
    queue<Node *> btTracker;
    btTracker.push(root);

    while(btTracker.size() != 0) {
        Node *currentNode = btTracker.front();
        btTracker.pop();

        cout<<currentNode->n<<" => ";
        if(currentNode->left != NULL) {
            cout<<currentNode->left->n<<" ";
            btTracker.push(currentNode->left);
        } else {
            cout<<"-1 ";
        }
        if(currentNode->right != NULL) {
            cout<<currentNode->right->n<<endl;
            btTracker.push(currentNode->right);
        } else {
            cout<<"-1"<<endl;
        }
    }
}

int main() {
    Node *root = new Node(1);
    runtimeInsertIntoBT(root);

    invertBT(root);

    cout<<"Inverted tree (in <parent => leftChild rightChild> format):"<<endl;
    cout<<"(Because I didn't want to spend time in drawing tree on terminal)"<<endl;
    printBT(root);
	return 0;
}
