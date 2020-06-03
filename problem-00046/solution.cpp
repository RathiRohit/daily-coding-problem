#include <iostream>
#include <map>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cout<<"Enter number of elements in the array:"<<endl;
	cin>>n;

	int arr[n];
	cout<<"Enter "<<n<<" integers:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		cin>>arr[n_i];
	}

	int k;
	cout<<"Enter required sum:"<<endl;
	cin>>k;

	map<int, bool> hash;
	for(int n_i=0; n_i<n; n_i++) {
		int required = k - arr[n_i];
		if(hash.count(required) != 0) {
			cout<<"true"<<endl;
			return 0;
		}
		hash[arr[n_i]] = true;
	}

	cout<<"false"<<endl;
	return 0;
}
