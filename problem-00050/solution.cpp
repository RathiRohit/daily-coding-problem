#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cout<<"Enter number of buildings:"<<endl;
	cin>>n;

	int heights[n];
	for(int heights_i=0; heights_i<n; heights_i++) {
		cin>>heights[heights_i];
	}

	int sunsetHavingHeights = 0;
	int maxOnWest = 0;
	for(int heights_i=n-1; heights_i>=0; heights_i--) {
		if(heights[heights_i] > maxOnWest) {
			sunsetHavingHeights++;
			maxOnWest = heights[heights_i];
		}
	}

	cout<<"People from "<<sunsetHavingHeights<<" buildings are lucky enough to have view of setting sun."<<endl;
	return 0;
}
