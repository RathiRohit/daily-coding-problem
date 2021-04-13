#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n, x, y;
	cin>>n>>x>>y;

	vector<int> andyTips(n);
	for (int n_i=0; n_i<n; n_i++) {
		cin>>andyTips[n_i];
	}

	vector<int> bobTips(n);
	vector<pair<int, int>> forAndy;
	vector<pair<int, int>> forBob;
	ll ans = 0;
    for (int n_i=0; n_i<n; n_i++) {
        cin>>bobTips[n_i];

        if (andyTips[n_i] < bobTips[n_i]) {
            forBob.push_back(make_pair(bobTips[n_i] - andyTips[n_i], bobTips[n_i]));
        } else if (andyTips[n_i] > bobTips[n_i]) {
            forAndy.push_back(make_pair(andyTips[n_i] - bobTips[n_i], andyTips[n_i]));
        } else {
            ans += bobTips[n_i];
        }
    }

    sort(forAndy.begin(), forAndy.end(), greater<pair<int, int>>());
    sort(forBob.begin(), forBob.end(), greater<pair<int, int>>());

    if (forAndy.size() > x) {
        for (int i=0; i<x; i++) {
            ans += forAndy[i].second;
        }
        for (int i=x; i<forAndy.size(); i++) {
            ans += forAndy[i].second - forAndy[i].first;
        }
    } else {
        for (int i=0; i<forAndy.size(); i++) {
            ans += forAndy[i].second;
        }
    }

    if (forBob.size() > y) {
        for (int i=0; i<y; i++) {
            ans += forBob[i].second;
        }
        for (int i=x; i<forBob.size(); i++) {
            ans += forBob[i].second - forBob[i].first;
        }
    } else {
        for (int i=0; i<forBob.size(); i++) {
            ans += forBob[i].second;
        }
    }

    cout<<ans<<endl;
	return 0;
}
