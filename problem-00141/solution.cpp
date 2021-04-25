#include <iostream>
#include <unordered_set>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int t;
	for (cin>>t; t; t--) {
		int n, tmp;
		cin>>n;

		int longestStick = -1, secondLongestStick = -1;
		unordered_set<int> singleSticks;
		for (int n_i=0; n_i<n; n_i++) {
			cin>>tmp;
			if (singleSticks.count(tmp) == 1) {
				singleSticks.erase(tmp);
				if (tmp >= longestStick) {
					secondLongestStick = longestStick;
					longestStick = tmp;
				} else if (tmp > secondLongestStick) {
					secondLongestStick = tmp;
				}
			} else {
				singleSticks.insert(tmp);
			}
		}

		if (longestStick != -1 && secondLongestStick != -1) {
			cout<<longestStick*secondLongestStick<<endl;
		} else {
			cout<<-1<<endl;
		}
	}
	return 0;
}
