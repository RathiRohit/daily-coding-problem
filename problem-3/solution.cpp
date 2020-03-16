#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

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

void insertInBST(Node **root, int value) {
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
}

ll sumAcrossBSTInRange(Node *root, int rangeMin, int rangeMax) {
	if(root == NULL) {
		return 0;
	}

	if(rangeMin <= root->value && root->value <= rangeMax) {
		ll sumAtLeft = sumAcrossBSTInRange(root->left, rangeMin, rangeMax);
		ll sumAtRight = sumAcrossBSTInRange(root->right, rangeMin, rangeMax);
		return sumAtLeft + root->value + sumAtRight;
	} else if(root->value < rangeMin) {
		return sumAcrossBSTInRange(root->right, rangeMin, rangeMax);
	} else if(root->value > rangeMax) {
		return sumAcrossBSTInRange(root->left, rangeMin, rangeMax);
	}

	return 0;
}

int main() {
	int nodeCount;
	cout<<"Enter number of nodes in BST:"<<endl;
	cin>>nodeCount;

	Node *bstRoot = NULL;
	for(int nodeCount_i=0; nodeCount_i<nodeCount; nodeCount_i++) {
		int value;
		cout<<"Enter node "<<(nodeCount_i + 1)<<" value:"<<endl;
		cin>>value;

		insertInBST(&bstRoot, value);
	}

	int rangeMin, rangeMax;
	cout<<"Enter min and max values of range:"<<endl;
	cin>>rangeMin>>rangeMax;
	if(rangeMin > rangeMax) {
		cout<<"Wrong input! Min value of range is greater than max value."<<endl;
		return 1;
	}

	cout<<"Some across BST in range ["<<rangeMin<<", "<<rangeMax<<"]:"<<endl;
	cout<<sumAcrossBSTInRange(bstRoot, rangeMin, rangeMax)<<endl;
	return 0;
}
