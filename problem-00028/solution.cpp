#include <iostream>
#include <queue>
#include <stack>

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
	cout<<"Enter value of root node:"<<endl;
	cin>>tmp;

	Node *root = new Node(tmp);
    runtimeInsertIntoBT(root);

    queue<Node *> unattended;
    unattended.push(root);
    unattended.push(new Node(-1));

    cout<<"Tree nodes in boustrophedon order:"<<endl;

    bool isGoingLeftToRight = true;
    stack<Node *> tempHolder;
    while(!unattended.empty()) {
    	Node *currentNode = unattended.front();
        unattended.pop();

        if(currentNode->n == -1) {
        	if(tempHolder.size() == 0) {
        		isGoingLeftToRight = !isGoingLeftToRight;
                continue;
        	}
        	while(!tempHolder.empty()) {
        		unattended.push(tempHolder.top());
        		tempHolder.pop();
        	}
        	unattended.push(new Node(-1));
        	isGoingLeftToRight = !isGoingLeftToRight;
        	continue;
        }

		cout<<currentNode->n<<"    ";
		if(isGoingLeftToRight) {
			if(currentNode->left != NULL) {
				tempHolder.push(currentNode->left);
			}
			if(currentNode->right != NULL) {
				tempHolder.push(currentNode->right);
			}
		} else {
			if(currentNode->right != NULL) {
				tempHolder.push(currentNode->right);
			}
			if(currentNode->left != NULL) {
				tempHolder.push(currentNode->left);
			}
		}
    }

    cout<<endl;
	return 0;
}
