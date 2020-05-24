#include <iostream>
#include <vector>
#include <climits>
#include <bitset>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cout<<"Enter number of elements in array:"<<endl;
	cin>>n;

	int arr[n];
	cout<<"Enter "<<n<<" integers:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		cin>>arr[n_i];
	}

	const int sizeOfInt = sizeof(int) * CHAR_BIT;
	vector<int> bitArr(sizeOfInt, 0);
	for(int n_i=0; n_i<n; n_i++) {
		bitset<sizeOfInt> bitRep(arr[n_i]);

		for(int i=0; i<sizeOfInt; i++) {
			if(bitRep[i]) {
				bitArr[i]++;
				if(bitArr[i] == 3) {
					bitArr[i] = 0;
				}
			}
		}
	}

	bitset<sizeOfInt> res;
	for(int i=0; i<sizeOfInt; i++) {
		res[i] = bitArr[i];
	}
	int result = (int)(res.to_ulong());

	cout<<"Non-duplicated integer: "<<result<<endl;
	return 0;
}
