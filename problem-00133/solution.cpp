#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    string str;
    cin>>str;

    int length = 0;
    vector<char> result;
    for (char ch: str) {
        if ((length == 0) || (result[length - 1] != ch)) {
            result.push_back(ch);
            length++;
        } else {
            result.pop_back();
            length--;
        }
    }

    if (length == 0) {
        cout<<"Empty String";
    } else {
        for (char ch: result) {
            cout<<ch;
        }
    }
    cout<<endl;

	return 0;
}
