#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

class Node {
	public:
		int n;
		int leftSubtreeCount;
		Node *left;
		Node *right;

		Node(int n) {
			this->n = n;
			this->leftSubtreeCount = 0;
			this->left = NULL;
			this->right = NULL;
		}
};

int insertWithCountingIntoBST(Node *root, int val) {
	Node *traveler = root;
	int count = 0;

	while(traveler != NULL) {
		if(val < traveler->n) {
			traveler->leftSubtreeCount++;
			if(traveler->left == NULL) {
				traveler->left = new Node(val);
				return count;
			}
			traveler = traveler->left;
		} else {
			count += traveler->leftSubtreeCount;
			count += (val == traveler->n) ? 0 : 1;
			if(traveler->right == NULL) {
				traveler->right = new Node(val);
				return count;
			}
			traveler = traveler->right;
		}
	}

	return count;
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

	int result[n];
	Node *root = new Node(arr[n-1]);
	result[n-1] = 0;
	for(int n_i=n-2; n_i>=0; n_i--) {
		result[n_i] = insertWithCountingIntoBST(root, arr[n_i]);
	}

	cout<<"Result array:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		cout<<result[n_i]<<" ";
	}
	cout<<endl;
	return 0;
}
