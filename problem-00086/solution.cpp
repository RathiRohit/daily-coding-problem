#include <iostream>
#include <unordered_set>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cin>>n;

    int ans = 0;
    unordered_set<char> yesSet;
    for (int n_i=0; n_i<n;) {
        string answers;
        cin>>answers;

        if (answers == "---") {
            ans += yesSet.size();
            yesSet.clear();
            n_i++;
            continue;
        }

        for (char ch: answers) {
            yesSet.insert(ch);
        }
    }

    cout<<ans<<endl;
	return 0;
}
