#include <iostream>
#include <unordered_map>

#define ll long long
#define ull unsigned long long

using namespace std;

unordered_map<ull, ull> memory;

void storeMasked(ull& num, ull& address, string& mask, ull setter, ll index) {
    if (index == -1) {
        memory[address] = num;
        return;
    }

    ull newSetter = setter << 1;
    if (mask[index] == '1') {
        address |= setter;
        storeMasked(num, address, mask, newSetter, index - 1);
    } else if (mask[index] == 'X') {
        ull tmp = address;
        address |= setter;
        storeMasked(num, address, mask, newSetter, index - 1);
        address = tmp;
        address &= ~setter;
        storeMasked(num, address, mask, newSetter, index - 1);
    } else {
        storeMasked(num, address, mask, newSetter, index - 1);
    }
}

int main() {
    int n;
    cin>>n;

    string mask;

    for (int n_i=0; n_i<n; n_i++) {
        string code;
        cin>>code;

        if (code == "mask") {
            cin>>mask;
        } else {
            ull address;
            cin>>address;

            ull value;
            cin>>value;

            storeMasked(value, address, mask, 1, mask.size() - 1);
        }
    }

    ull sum = 0;
    for (auto address: memory) {
        sum += address.second;
    }
    cout<<sum<<endl;
	return 0;
}
