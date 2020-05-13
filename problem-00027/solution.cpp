#include <iostream>
#include <map>

#define ll long long
#define ull unsigned long long

using namespace std;

ll getMaxLengthOfSeq(ll n, map<ll, ll>& memoMap) {
	if(memoMap.count(n) != 0) {
		return memoMap[n];
	}

	if(n == 1) {
		memoMap[n] = 1;
	} else if((n & 1) == 1) {
		memoMap[n] = 1 + getMaxLengthOfSeq(3 * n + 1, memoMap);
	} else {
		memoMap[n] = 1 + getMaxLengthOfSeq(n / 2, memoMap);
	}

	return memoMap[n];
}

ll getMaxSeqLengthInput(ll limit) {
	map<ll, ll> memoMap;

	ll maxLength = 1;
	ll maxLengthInput = 1;
	for(ll i=1; i<=limit; i++) {
		ll lengthOfSeq = getMaxLengthOfSeq(i, memoMap);
		if(lengthOfSeq > maxLength) {
			maxLength = lengthOfSeq;
			maxLengthInput = i;
		}
	}

	return maxLengthInput;
}

int main() {
	cout<<"Input which has max length is: "<<getMaxSeqLengthInput(1000000)<<endl;
	return 0;
}
