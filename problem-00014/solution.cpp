#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cout<<"Enter number of elements in array:"<<endl;
	cin>>n;

	int max = 0;
	int totalMax = 0;
	for(int n_i=0; n_i<n; n_i++) {
		int tmp;
		cin>>tmp;

		totalMax += tmp;
		if(totalMax < 0) {
			totalMax = 0;
		} else if(totalMax > max) {
			max = totalMax;
		}
	}

	cout<<"Max possible subarray sum: "<<max<<endl;
	return 0;
}
