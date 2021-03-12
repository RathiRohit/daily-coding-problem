#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    ll n, d;
    cin>>n>>d;

    vector<ll> sticks(n);
    for (ll n_i=0; n_i<n; n_i++) {
        cin>>sticks[n_i];
    }
    sort(sticks.begin(), sticks.end());

    ll usablePairs = 0;
    for (ll n_i=0; n_i<n-1; n_i++) {
        if ((sticks[n_i + 1] - sticks[n_i]) <= d) {
            usablePairs++;
            n_i++;
        }
    }

    cout<<usablePairs<<endl;
	return 0;
}
