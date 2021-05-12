#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long
#define MOD 1000000007

using namespace std;

int main() {
	vector<ll> answers(100001);
	answers[1] = 1;
	for (ll i=2; i<100001; i++) {
		answers[i] = (answers[i-1] * 2) % MOD;
	}

	ll t;
	for (cin>>t; t; t--) {
		ll n;
		cin>>n;
		cout<<answers[n]<<endl;
	}
	return 0;
}
