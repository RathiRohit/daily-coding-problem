#include <iostream>
#include <map>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cout<<"Enter number of elements:"<<endl;
	cin>>n;

	map<int, int> numHash;
	int arr[n];
	cout<<"Enter "<<n<<" integers:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		cin>>arr[n_i];
		numHash[arr[n_i]] = 0;
	}

	if(n <= 1) {
		cout<<"Max unique subarray length: "<<n;
		return 0;
	}

	int leftIndex = 0;
	int rightIndex = 1;
	int maxLength = 1;
	numHash[arr[0]]++;
	while(true) {
		int length;
		if(numHash[arr[rightIndex]] == 0) {
			numHash[arr[rightIndex]]++;
			length = rightIndex - leftIndex + 1;
		} else {
			numHash[arr[rightIndex]]++;
			while(true) {
				if(numHash[arr[leftIndex]] > 1) {
					break;
				}
				numHash[arr[leftIndex]]--;
				leftIndex++;
			}
			numHash[arr[leftIndex]]--;
            leftIndex++;
			length = rightIndex - leftIndex + 1;
		}

		if(length > maxLength) {
			maxLength = length;
		}

		rightIndex++;
		if(rightIndex >= n) {
			break;
		}
	}

	cout<<"Max unique subarray length: "<<maxLength<<endl;
	return 0;
}
