#include <iostream>
#include <limits>
#include <vector>

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

	vector<int> bitArr(numeric_limits<int>::digits, 0);
	for(int n_i=0; n_i<n; n_i++) {
		int bitIndex = bitArr.size() - 1;
		int bitRecognizer = 1;
		while(bitIndex >= 0 && bitRecognizer <= arr[n_i]) {
			if((arr[n_i] & bitRecognizer) != 0) {
				bitArr[bitIndex]++;
				if(bitArr[bitIndex] == 3) {
					bitArr[bitIndex] = 0;
				}
			}
			bitRecognizer = (bitRecognizer << 1);
			bitIndex--;
		}
	}

	int res = 0;
	int bitRecognizer = 1;
	for(int n_i=bitArr.size()-1; n_i>=0; n_i--) {
		if(bitArr[n_i] != 0) {
			res = (res | bitRecognizer);
		}
		bitRecognizer = (bitRecognizer << 1);
	}

	cout<<"Non-duplicated integer: "<<res<<endl;
	return 0;
}
