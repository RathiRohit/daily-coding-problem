#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cout<<"Enter number of integers in array:"<<endl;
	cin>>n;

	vector<int> arr(n);
	vector<int> sortedArr(n);
	cout<<"Enter "<<n<<" integers:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		cin>>arr[n_i];
		sortedArr[n_i] = arr[n_i];
	}

	sort(sortedArr.begin(), sortedArr.end());
	int startIndex = -1;
	int endIndex = -1;
	for(int n_i=0; n_i<n; n_i++) {
		if(sortedArr[n_i] != arr[n_i]) {
			if(startIndex == -1) {
				startIndex = n_i;
			}
			endIndex = n_i;
		}
	}

	if(startIndex == -1 && endIndex == -1) {
		cout<<"No need to sort anything, array is already sorted."<<endl;
		return 0;
	}

	cout<<"Smallest window that needs to be sorted: ";
	cout<<"("<<startIndex<<", "<<endIndex<<")"<<endl;
	return 0;
}
