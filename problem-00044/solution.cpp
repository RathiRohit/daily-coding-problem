#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n, x;
	cout<<"Enter value of N & X:"<<endl;
	cin>>n>>x;

	int ans = 0;
	int start = 1;
	int end = n;
	while(start <= end) {
		int val = start * end;

		if(val > x) {
			end--;
		} else if(val < x) {
			start++;
		} else {
			ans++;
			if(start != end) {
				ans++;
			}
			start++;
			end--;
		}
	}

	cout<<"Number of times "<<x<<" appears: "<<ans<<endl;
	return 0;
}
