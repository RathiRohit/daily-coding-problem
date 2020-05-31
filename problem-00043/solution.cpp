#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

class Node {
	public:
		int start;
		int end;
		int min;
		Node *left;
		Node *right;

		Node(int start, int end) {
			this->start = start;
			this->end = end;
			this->min = -1;
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

void insertIntoSegTree(Node *root, int start, int end, int minVal) {
	if(start > end || end < root->start || start > root->end) {
		return;
	}

	if(root->start <= start && end <= root->end) {
		if(root->min == -1 || root->min > minVal) {
			root->min = minVal;
		}

		if(root->start == root->end) {
			return;
		}

		if(min(root->left->end, end) >= root->left->start && start <= root->left->end) {
			insertIntoSegTree(root->left, start, min(root->left->end, end), minVal);
		}
		if(end >= root->right->start && max(root->right->start, start) <= root->right->end) {
			insertIntoSegTree(root->right, max(root->right->start, start), end, minVal);
		}
	}
}

int getMinInSeg(Node *root, int start, int end) {
	if(root->start == start && root->end == end) {
		return root->min;
	}

	if(start > end || end < root->start || start > root->end) {
		return -1;
	}

	int min1 = -1;
	int min2 = -1;
	if(min(root->left->end, end) >= root->left->start && start <= root->left->end) {
		min1 = getMinInSeg(root->left, start, min(root->left->end, end));
	}
	if(end >= root->right->start && max(root->right->start, start) <= root->right->end) {
		min2 = getMinInSeg(root->right, max(root->right->start, start), end);
	}

	if(min1 == -1) {
		return min2;
	} else if(min2 == -1) {
		return min1;
	} else {
		return min(min1, min2);
	}
}

int main() {
	int n;
	cout<<"Enter number of elements in the array:"<<endl;
	cin>>n;

	int arr[n];
	cout<<"Enter "<<n<<" integers:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		cin>>arr[n_i];
	}

	if(n == 1) {
		cout<<"Minimum jumps required to reach end: "<<0<<endl;
		return 0;
	}

	Node *root = generateSegTree(0, n-1);
	int ans = 0;

	insertIntoSegTree(root, n-1, n-1, 0);
	for(int n_i=n-2; n_i>=0; n_i--) {
		if(arr[n_i] == 0) {
			ans = -1;
			continue;
		}
		ans = getMinInSeg(root, n_i+1, min(n_i + arr[n_i], n-1));
		if(ans != -1) {
			insertIntoSegTree(root, n_i, n_i, ans + 1);
		}
	}

	if(ans == -1) {
		cout<<"It is not possible to reach the end from start."<<endl;
		return 0;
	}

	cout<<"Minimum jumps required to reach end: "<<ans + 1<<endl;
	return 0;
}
