#include <iostream>
#include <queue>
#include <vector>

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

void dfTraverseToRoot(Node *root, vector<vector<int> > &paths, vector<int> &tempPath) {
    tempPath.push_back(root->n);
    if(root->left == NULL && root->right == NULL) {
        paths.push_back(vector<int>(tempPath.begin(), tempPath.end()));
        tempPath.pop_back();
        return;
    }

    if(root->left != NULL) {
        dfTraverseToRoot(root->left, paths, tempPath);
    }
    if(root->right != NULL) {
        dfTraverseToRoot(root->right, paths, tempPath);
    }

    tempPath.pop_back();
    return;
}

vector<vector<int> > getPathsToLeaves(Node *root) {
    vector<vector<int> > paths;
    vector<int> tempPath;

    dfTraverseToRoot(root, paths, tempPath);
    return paths;
}

int main() {
    Node *root = new Node(1);
    runtimeInsertIntoBT(root);

    vector<vector<int> > pathsToLeaves = getPathsToLeaves(root);
    cout<<"All paths to leaves:"<<endl<<"[";
    for(int path_i=0; path_i<pathsToLeaves.size(); path_i++) {
        cout<<"[";
        for(int node_i=0; node_i<pathsToLeaves[path_i].size(); node_i++) {
            cout<<pathsToLeaves[path_i][node_i];
            if(node_i != pathsToLeaves[path_i].size() - 1) {
                cout<<", ";
            }
        }
        cout<<"]";
        if(path_i != pathsToLeaves.size() - 1) {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
	return 0;
}
