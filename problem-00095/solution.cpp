#include <iostream>
#include <vector>
#include <unordered_map>

#define ll long long
#define ull unsigned long long

using namespace std;

ll possiblePaths(int index, vector<int>& jolts, unordered_map<int, ll>& memo) {
    if (memo.count(index) != 0) {
        return memo[index];
    }

    if (index == (jolts.size() - 1)) {
        memo[index] = 1;
        return 1;
    }

    ll ans = 0;
    for (int n_i=index+1; n_i<jolts.size() && (jolts[n_i] - jolts[index])<=3; n_i++) {
        ans += possiblePaths(n_i, jolts, memo);
    }
    memo[index] = ans;

    return ans;
}

int main() {
    int n;
    cin>>n;

    vector<int> jolts(n+1);
    jolts[0] = 0;
    for (int n_i=1; n_i<=n; n_i++) {
        cin>>jolts[n_i];
    }
    sort(jolts.begin(), jolts.end());
    jolts.push_back(jolts[n] + 3);

    unordered_map<int, ll> memo;
    cout<<possiblePaths(0, jolts, memo)<<endl;

	return 0;
}
