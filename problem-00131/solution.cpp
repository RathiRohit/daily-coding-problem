#include <iostream>
#include <stack>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    stack<int> shelf;

    int q, n;
    for (cin>>q; q; q--) {
        int queryType;
        cin>>queryType;

        if (queryType == 1) {
            cin>>n;
            shelf.push(n);
        } else if (shelf.empty()) {
            cout<<"kuchbhi?"<<endl;
        } else {
            cout<<shelf.top()<<endl;
            shelf.pop();
        }
    }
	return 0;
}
