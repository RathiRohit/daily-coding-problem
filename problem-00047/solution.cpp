#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

class Node {
	public:
		int start;
		int end;
		int mul;
		Node *left;
		Node *right;

		Node(int start, int end) {
			this->start = start;
			this->end = end;
			this->mul = 1;
			this->left = NULL;
			this->right = NULL;
		}
};

Node* generateSegTree(int start, int end) {
	Node *root = new Node(start, end);
	if(start == end) {
		return root;
	}

	int mid = (end + start) / 2;
	root->left = generateSegTree(start, mid);
	root->right = generateSegTree(mid+1, end);
	return root;
}

void insertIntoSegTree(Node *root, int start, int end, int mulVal) {
	if(start > end || end < root->start || start > root->end) {
		return;
	}

	if(root->start <= start && end <= root->end) {
		root->mul *= mulVal;

		if(root->start == root->end) {
			return;
		}

		if(min(root->left->end, end) >= root->left->start && start <= root->left->end) {
			insertIntoSegTree(root->left, start, min(root->left->end, end), mulVal);
		}
		if(end >= root->right->start && max(root->right->start, start) <= root->right->end) {
			insertIntoSegTree(root->right, max(root->right->start, start), end, mulVal);
		}
	}
}

int getMulInRange(Node *root, int start, int end) {
	if(root->start == start && root->end == end) {
		return root->mul;
	}

	if(start > end || end < root->start || start > root->end) {
		return 1;
	}

	int mul1 = 1;
	int mul2 = 1;
	if(min(root->left->end, end) >= root->left->start && start <= root->left->end) {
		mul1 = getMulInRange(root->left, start, min(root->left->end, end));
	}
	if(end >= root->right->start && max(root->right->start, start) <= root->right->end) {
		mul2 = getMulInRange(root->right, max(root->right->start, start), end);
	}

	return mul1 * mul2;
}

int main() {
	int n;
	cout<<"Enter number of elements in the array:"<<endl;
	cin>>n;

	int arr[n];
	Node *root = generateSegTree(0, n-1);
	cout<<"Enter "<<n<<" integers:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		cin>>arr[n_i];
		insertIntoSegTree(root, n_i, n_i, arr[n_i]);
	}

	if(n == 1) {
		cout<<"Result array:"<<endl;
		cout<<"0"<<endl;
		return 0;
	}

	cout<<"Result array:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		int leftMul = 1, rightMul = 1;
		if(n_i - 1 >= 0) {
			leftMul = getMulInRange(root, 0, n_i - 1);
		}
		if(n_i + 1 < n) {
			rightMul = getMulInRange(root, n_i + 1, n - 1);
		}
		cout<<leftMul*rightMul<<" ";
	}
	cout<<endl;
	return 0;
}
