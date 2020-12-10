#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

bool notPossible(vector<ll>& numbers, ll sum, int start, int end) {
    for (int i=start; i<end; i++) {
        for (int j=i+1; j<=end; j++) {
            if ((numbers[i] != numbers[j]) && (numbers[i] + numbers[j] == sum)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int PREAMBLE = 25;

    int n;
    cin>>n;

    vector<ll> numbers(n);
    for (int n_i=0; n_i<PREAMBLE; n_i++) {
        cin>>numbers[n_i];
    }

    for (int n_i=PREAMBLE; n_i<n; n_i++) {
        cin>>numbers[n_i];

        if (notPossible(numbers, numbers[n_i], n_i - PREAMBLE - 1, n_i - 1)) {
            cout<<numbers[n_i]<<endl;
            return 0;
        }
    }

	return 1;
}
