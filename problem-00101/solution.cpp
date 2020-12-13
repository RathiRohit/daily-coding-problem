#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> position;
    vector<int> value;
    for (int n_i=0; n_i<n; n_i++) {
        ll tmp;
        cin>>tmp;

        if (tmp != -1) {
            position.push_back(n_i);
            value.push_back(tmp);
        }
    }

    ll LIMIT = 1e+17;
    ll start = 1;
    ll increment = 1;
    ll checkTill = 0;

    while (checkTill < position.size()) {
        ll firstValid = -1;
        ll secondValid = -1;

        for (ll i=start; i<LIMIT; i+=increment) {
            bool isValid = true;
            if (((i + position[checkTill]) % value[checkTill]) != 0) {
                isValid = false;
            }

            if (isValid) {
                if (firstValid == -1) {
                    firstValid = i;
                } else {
                    secondValid = i;
                    break;
                }
            }
        }

        start = firstValid;
        increment = secondValid - firstValid;
        checkTill++;
    }

    cout<<start<<endl;
	return 0;
}
