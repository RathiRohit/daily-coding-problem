#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cout<<"Enter value of N:"<<endl;
	cin>>n;

	ll total = 0;
	ll power = 1;
	while(power <= n) {
		ll startFrom = n - (power - 1);
		ll fullCount = (startFrom / (power * 2)) * power;
		ll partial = startFrom % (power * 2);
		ll partialCount = min(partial, power);
		total += fullCount + partialCount;
		power *= 2;
	}

	cout<<"Total set bits between 1 to "<<n<<": "<<total<<endl;
	return 0;
}
