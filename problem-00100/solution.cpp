#include <iostream>
#include <map>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    ll time;
    cin>>time;

    int n;
    cin>>n;

    map<ll, ll> diffMap;
    for (int n_i=0; n_i<n; n_i++) {
        ll tmp;
        cin>>tmp;

        ll maxDiv = time / tmp;
        ll nextDiv = tmp * (maxDiv + 1);
        ll diff = nextDiv - time;
        if (time % tmp == 0) {
            diff = 0;
        }

        diffMap[diff] = tmp;
    }


    cout<<diffMap.upper_bound(-1)->first * diffMap.upper_bound(-1)->second<<endl;
	return 0;
}
