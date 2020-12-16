#include <iostream>
#include <unordered_map>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    ll n;
    cin>>n;

    unordered_map<ll, ll> posMap;
    ll count = 1;
    ll last = 0;
    for (ll n_i=0; n_i<n; n_i++) {
        ll tmp;
        cin>>tmp;

        if (posMap.count(tmp) == 0) {
            last = 0;
        } else {
            last = count - posMap[tmp];
        }
        posMap[tmp] = count;
        count++;
    }

    while (count < 30000000) {
        ll tmp = last;
        if (posMap.count(tmp) == 0) {
            last = 0;
        } else {
            last = count - posMap[tmp];
        }
        posMap[tmp] = count;
        count++;
    }

    cout<<last<<endl;
	return 0;
}
