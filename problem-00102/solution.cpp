#include <iostream>
#include <unordered_map>

#define ll long long
#define ull unsigned long long

using namespace std;

ull getMasked(ull num, string mask) {
    ull bit = 1;
    for (ll i=mask.size() - 1; i>=0; i--) {
        if (mask[i] == '1') {
            num |= bit;
        } else if (mask[i] == '0') {
            num &= ~bit;
        }
        bit = bit << 1;
    }

    return num;
}

int main() {
    int n;
    cin>>n;

    string mask;
    unordered_map<string, ull> memory;

    for (int n_i=0; n_i<n; n_i++) {
        string code;
        cin>>code;

        if (code == "mask") {
            cin>>mask;
        } else {
            string address;
            cin>>address;

            ull value;
            cin>>value;

            memory[address] = getMasked(value, mask);
        }
    }

    ull sum = 0;
    for (auto address: memory) {
        sum += address.second;
    }
    cout<<sum<<endl;
	return 0;
}
