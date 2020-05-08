#include <iostream>
#include<map>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cout<<"Enter number of integers in array:"<<endl;
	cin>>n;

	map<int, pair<int, int> > numMap;
	int result = 0;
	for(int n_i=0; n_i<n; n_i++) {
		int tmp;
		cin>>tmp;

		if(numMap.count(tmp) == 1) {
			continue;
		}

		int newMin = tmp;
		int newMax = tmp;

		if(numMap.count(tmp - 1) == 1) {
			newMin = numMap[tmp - 1].first;
		}

		if(numMap.count(tmp + 1) == 1) {
			newMax = numMap[tmp + 1].second;
		}

		numMap[newMin] = make_pair(newMin, newMax);
		numMap[newMax] = make_pair(newMin, newMax);

		if((newMax - newMin + 1) > result) {
			result = newMax - newMin + 1;
		}
	}

	cout<<"Longest consequent elements sequence length is: "<<result<<endl;
	return 0;
}
