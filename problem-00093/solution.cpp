#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    ll sum = 552655238;

    int n;
    cin>>n;

    vector<ll> numbers(n);
    for (int n_i=0; n_i<n; n_i++) {
        cin>>numbers[n_i];
    }

    int start = 0;
    int end = 0;
    ll currentSum = numbers[start];

    while (currentSum != sum || start == end) {
        end++;
        currentSum += numbers[end];

        while (currentSum > sum) {
            currentSum -= numbers[start];
            start++;
        }
    }

    ll min = INT_MAX;
    ll max = INT_MIN;
    for (int n_i=start; n_i<=end; n_i++) {
        if (numbers[n_i] < min) {
            min = numbers[n_i];
        }
        if (numbers[n_i] > max) {
            max = numbers[n_i];
        }
    }

    cout<<min+max<<endl;
	return 0;
}
