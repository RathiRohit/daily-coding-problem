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
	Node* list1Head;
	Node* list1Traveler = NULL;

	Node* list2Head;
	Node* list2Traveler = NULL;

	int list1Count;
	cout<<"Enter number of nodes in List 1:"<<endl;
	cin>>list1Count;

	cout<<"Enter "<<list1Count<<" node values for List 1:"<<endl;
	for(int list1Count_i=0; list1Count_i<list1Count; list1Count_i++) {
		int tmp;
		cin>>tmp;

		if(list1Traveler == NULL) {
			list1Head = new Node(tmp);
			list1Traveler = list1Head;
		} else {
			Node* newNode = new Node(tmp);
			list1Traveler->next = newNode;
			list1Traveler = newNode;
		}
	}

	int list2Count;
	cout<<"Enter number of nodes in List 2:"<<endl;
	cin>>list2Count;

	cout<<"Enter "<<list2Count<<" node values for List 2:"<<endl;
	for(int list2Count_i=0; list2Count_i<list2Count; list2Count_i++) {
		int tmp;
		cin>>tmp;

		if(list2Traveler == NULL) {
			list2Head = new Node(tmp);
			list2Traveler = list2Head;
		} else {
			Node* newNode = new Node(tmp);
			list2Traveler->next = newNode;
			list2Traveler = newNode;
		}
	}

	int diff = abs(list1Count - list2Count);
	list1Traveler = list1Head;
	list2Traveler = list2Head;
	if(list1Count > list2Count) {
		for(int diff_i=0; diff_i<diff; diff_i++) {
			list1Traveler = list1Traveler->next;
		}
	} else {
		for(int diff_i=0; diff_i<diff; diff_i++) {
			list2Traveler = list2Traveler->next;
		}
	}

	while(list1Traveler != NULL) {
		if(list1Traveler->n == list2Traveler->n) {
			cout<<"Intersection node: "<<list1Traveler->n<<endl;
			return 0;
		}
		list1Traveler = list1Traveler->next;
		list2Traveler = list2Traveler->next;
	}

	cout<<"No intersection node found."<<endl;
	return 0;
}
