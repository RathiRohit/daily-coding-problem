#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

class Node {
	public:
		int n;
		Node* next;

		Node(int n) {
			this->n = n;
			this->next = NULL;
		}
};

int main() {
	Node* head = NULL;
	cout<<"Enter elements of linked list in order (-1 to end):"<<endl;
	int tmp = 0;
	Node* traveler = head;
	while(true) {
		cin>>tmp;
		if(tmp == -1) {
			break;
		}

		Node* newNode = new Node(tmp);
		if(head == NULL) {
			head = newNode;
		} else {
			traveler->next = newNode;
		}
		traveler = newNode;
	}

	int k;
	cout<<"Enter value of k (must be less than length of the linked list):"<<endl;
	cin>>k;

	if(k <= 0) {
		cout<<"Value of k("<<k<<") can't be less than 1."<<endl;
		return 1;
	}

	Node* back = head;
	Node* front = head;
	for(int i=1; i<=k; i++) {
		if(front->next == NULL) {
			cout<<"Entered value of k("<<k<<") is not less than length("<<i<<") of the list."<<endl;
			return 1;
		}
		front = front->next;
	}

	while(front->next != NULL) {
		back = back->next;
		front = front->next;
	}
	Node* tmpNode = back->next->next;
	delete back->next;
	back->next = tmpNode;

	cout<<"New linked list after removing last "<<k<<"th element:"<<endl;
	tmpNode = head;
	while(tmpNode != NULL) {
		cout<<tmpNode->n<<" ";
		tmpNode = tmpNode->next;
	}
	cout<<endl;
	return 0;
}
