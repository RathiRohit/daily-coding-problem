#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int answer(int s, int t, int i) {
	cout<<s<<' '<<t<<endl;
	if (s == t) {
		return 1;
	}

	int mid = (s + t) / 2;
	if (i <= mid) {
		return answer(s, mid, i) + 1;
	} else {
		return answer(mid+1, t, i) + 1;
	}
}

int main() {
	int t;
	for (cin>>t;t;t--) {
		int s, t, i;
		cin>>s>>t>>i;

		if (i < s || t < i) {
			cout<<-1<<endl;
		} else {
			cout<<answer(s, t, i)<<endl;
		}
	}
	return 0;
}
