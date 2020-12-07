#include <iostream>
#include <unordered_map>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cin>>n;

    int ans = 0;
    unordered_map<char, int> yesMap;
    int persons = 0;
    for (int n_i=0; n_i<n;) {
        string answers;
        cin>>answers;

        if (answers == "---") {
            for (auto pr: yesMap) {
                if (pr.second == persons) {
                    ans++;
                }
            }
            yesMap.clear();
            n_i++;
            persons = 0;
            continue;
        }

        for (char ch: answers) {
            if (yesMap.count(ch) == 0) {
                yesMap[ch] = 0;
            }
            yesMap[ch]++;
        }
        persons++;
    }

    cout<<ans<<endl;
	return 0;
}
