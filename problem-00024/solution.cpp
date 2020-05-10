#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string treeStr;
	cout<<"Enter string representation of binary tree:"<<endl;
	cin>>treeStr;

	int currentDepth = -1;
	int maxDepth = -1;

	for(int treeStr_i=0; treeStr_i<treeStr.length(); treeStr_i++) {
		if(treeStr[treeStr_i] == '(') {
			currentDepth++;
			if(currentDepth > maxDepth) {
				maxDepth = currentDepth;
			}
		} else if(treeStr[treeStr_i] == ')') {
			currentDepth--;
		}
	}

	cout<<"Depth of binary tree: "<<maxDepth<<endl;
	return 0;
}
