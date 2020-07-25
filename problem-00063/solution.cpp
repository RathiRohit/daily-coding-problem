#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

class Node {
    public:
        int n;
        Node *left;
        Node *right;
        Node *parent;

        Node(int n) {
            this->n = n;
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
        }
};

Node* inputBST(int n) {
    int tmp;
    cout<<"Enter node values of BST in insertion order:"<<endl;
    cin>>tmp;

    Node *root = new Node(tmp);
    for(int i=1; i<n; i++) {
        cin>>tmp;
        Node *newNode = new Node(tmp);
        Node *traveler = root;
        while(true) {
            if(tmp >= traveler->n) {
                if(traveler->right == NULL) {
                    traveler->right = newNode;
                    newNode->parent = traveler;
                    break;
                }
                traveler = traveler->right;
            } else if(tmp < traveler->n) {
                if(traveler->left == NULL) {
                    traveler->left = newNode;
                    newNode->parent = traveler;
                    break;
                }
                traveler = traveler->left;
            }
        }
    }

    return root;
}

int getSmallestNode(Node *current) {
    if(current->left == NULL) {
        return current->n;
    }
    return getSmallestNode(current->left);
}

int getSmallestLargerNodeThan(Node *current) {
    if(current->right != NULL) {
        return getSmallestNode(current->right);
    }
    if(current->parent->n > current->n) {
        return current->parent->n;
    }
    throw "ERROR: No successor found";
}

int getInorderSuccessor(Node *root, int n) {
    Node *traveler = root;
    while(traveler != NULL && traveler->n != n) {
        if(n > traveler->n) {
            traveler = traveler->right;
        } else {
            traveler = traveler->left;
        }
    }

    if(traveler == NULL) {
        throw "ERROR: Node not found in BST";
    }

    return getSmallestLargerNodeThan(traveler);
}

int main() {
    int n;
    cout<<"Enter number of nodes in BST:"<<endl;
    cin>>n;

    Node *root = inputBST(n);

    int nodeValue;
    cout<<"Enter node value to find it's inorder successor:"<<endl;
    cin>>nodeValue;

    try {
        int inorderSuccessor = getInorderSuccessor(root, nodeValue);
        cout<<"Inorder successor of "<<nodeValue<<": ";
        cout<<inorderSuccessor<<endl;
    } catch(const char *error) {
        cout<<error<<endl;
    }
	return 0;
}
