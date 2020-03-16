#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	double number;
	cin>>number;

	bool isNegative = false;
	if(number < 0) {
		isNegative = true;
		number = -number;
	}

	double answer;
	if(number == 0) {
		answer = 0;
	} else if(number == 1) {
		answer = 1;
	} else {
		double leftLimit = min(1.0, number);
		double rightLimit = max(1.0, number);
		double midValue = (leftLimit + rightLimit) / 2;

		double newSquare;
		do {
			newSquare = midValue * midValue;

			if(newSquare < number) {
				leftLimit = midValue;
			} else if(newSquare > number) {
				rightLimit = midValue;
			}

			midValue = (leftLimit + rightLimit) / 2;
			midValue = midValue;
		} while(abs(newSquare - number) > 0.0001);

		answer = midValue;
	}

	cout<<fixed<<setprecision(3);
	if(isNegative) {
		cout<<answer<<'i'<<endl;
	} else {
		cout<<answer<<endl;
	}

	return 0;
}
