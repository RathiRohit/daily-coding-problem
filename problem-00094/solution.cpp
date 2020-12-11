#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> jolts(n);
    for (int n_i=0; n_i<n; n_i++) {
        cin>>jolts[n_i];
    }

    sort(jolts.begin(), jolts.end());

    int _1JoltDiffs = 0;
    int _3JoltDiffs = 0;

    _1JoltDiffs += (jolts[0] == 1);
    _3JoltDiffs += (jolts[0] == 3);
    for (int n_i=1; n_i<n; n_i++) {
        int diff = jolts[n_i] - jolts[n_i - 1];
        _1JoltDiffs += (diff == 1);
        _3JoltDiffs += (diff == 3);
    }
    _3JoltDiffs++;

    cout<<_1JoltDiffs*_3JoltDiffs<<endl;
	return 0;
}
