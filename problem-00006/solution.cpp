#include <iostream>
#include <map>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int count;
	cout<<"Enter number of people:"<<endl;
	cin>>count;

	if(count < 2) {
		cout<<"Wrong input! No celebrity possible in such a small crowd."<<endl;
		return 1;
	}

	int totalPairs = count * (count - 1);
	map<pair<int, int>, bool> pairs;
	cout<<"Enter "<<totalPairs<<" pairs (person numbers from 1 to "<<count<<"):"<<endl;
	for(int totalPairs_i=0; totalPairs_i<totalPairs; totalPairs_i++) {
		int person1, person2, status;
		cin>>person1>>person2>>status;

		pairs[make_pair(person1, person2)] = status == 1 ? true : false;
	}

	int candidate = 1;
	for(int count_i=2; count_i<=count; count_i++) {
		if(pairs[make_pair(candidate, count_i)]) {
			candidate = 2;
		}
	}

	cout<<"Provided there is exactly one celebrity, that will be: "<<candidate<<endl;
	return 0;
}
