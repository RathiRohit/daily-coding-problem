#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cout<<"Enter number of elements in array:"<<endl;
	cin>>n;

	int arr[n];
	bool isGoodStep[n];
	cout<<"Enter "<<n<<" non-negative integers:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		cin>>arr[n_i];
		isGoodStep[n_i] = false;
	}
	isGoodStep[n - 1] = true;

	for(int n_i=n-2; n_i>=0; n_i--) {
		for(int j=1; j<=arr[n_i]; j++) {
			if(isGoodStep[n_i + j]) {
				isGoodStep[n_i] = true;
				break;
			}
		}
	}

	if(isGoodStep[0]) {
		cout<<"true"<<endl;
		return 0;
	}

	cout<<"false"<<endl;
	return 0;
}
