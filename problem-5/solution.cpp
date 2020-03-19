#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

class Node {
	public:
		int value;
		Node *left;
		Node *right;

	Node(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
};

void insertIntoBST(Node **root, int value) {
	Node *newNode = new Node(value);

	if(*root == NULL) {
		*root = newNode;
		return;
	}

	Node *traveler = *root;
	while(true) {
		if(newNode->value <= traveler->value) {
			if(traveler->left == NULL) {
				traveler->left = newNode;
				break;
			}
			traveler = traveler->left;
		} else {
			if(traveler->right == NULL) {
				traveler->right = newNode;
				break;
			}
			traveler = traveler->right;
		}
	}
	return;
}

int secondLargestInBST(Node *root) {
	if(root == NULL) {
		throw "No second largest available";
	}

	Node *traveler = root;
	Node *largest = root;
	Node *secondLargest = NULL;
	while(true) {
		if(traveler->right != NULL) {
			secondLargest = largest;
			largest = traveler->right;
			traveler = traveler->right;
		} else if(traveler->left != NULL) {
			secondLargest = traveler->left;
			largest = traveler;
			traveler = traveler->left;
		} else {
			break;
		}
	}

	if(secondLargest == NULL) {
		throw "No second largest available";
	}
	return secondLargest->value;
}

int main() {
	Node *bstRoot = NULL;

	int n;
	cout<<"Enter number of nodes:"<<endl;
	cin>>n;

	cout<<"Enter "<<n<<" numbers:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		int tmp;
		cin>>tmp;

		insertIntoBST(&bstRoot, tmp);
	}

	cout<<"Second largest node in BST: "<<secondLargestInBST(bstRoot)<<endl;
	return 0;
}
