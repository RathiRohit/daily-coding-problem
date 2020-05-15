#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cout<<"Enter number of elements in array:"<<endl;
	cin>>n;

	vector<int> arr(n);
	cout<<"Enter "<<n<<" integers:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		cin>>arr[n_i];
	}

	int k;
	cout<<"Enter required sum amount:"<<endl;
	cin>>k;

	sort(arr.begin(), arr.end());

	for(int n_i=0; n_i<(n-2); n_i++) {
		int start = n_i + 1;
		int end = n - 1;
		int requiredSum = k - arr[n_i];
		while(start < end) {
			int currentSum = arr[start] + arr[end];
			if(requiredSum == currentSum) {
				cout<<"true"<<endl;
				return 0;
			}
			if(requiredSum < currentSum) {
				end--;
			} else {
				start++;
			}
		}
	}

	cout<<"false"<<endl;
	return 0;
}
