#include <iostream>
#include <string>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int reverse(int n) {
	if(n < 10) {
		return n;
	}

	int revN = 0;
	while(n != 0) {
		int lastDigit = n % 10;
		revN += lastDigit;
		revN *= 10;
		n /= 10;
	}

	revN /= 10;
	return revN;
}

int main() {
	int n;
	cout<<"Enter number:"<<endl;
	cin>>n;

	int revNumber = reverse(n);
	if(revNumber == n) {
		cout<<"Number "<<n<<" is a palindrome."<<endl;
		return 0;
	}

	cout<<"Number "<<n<<" is not a palindrome."<<endl;
	return 0;
}
