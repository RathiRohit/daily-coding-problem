#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int m, n;
	cout<<"Enter M & N:"<<endl;
	cin>>m>>n;

	int pairCount = 0;
	for(int a=1; a<m; a++) {
		int b = m - a;
		if((a ^ b) == n) {
			pairCount++;
		}
	}

	cout<<"Total possible directional pair counts for given constraints: "<<pairCount<<endl;
	return 0;
}
