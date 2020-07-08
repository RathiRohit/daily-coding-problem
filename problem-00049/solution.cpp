#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll firstGameAmount() {
	srand(time(NULL));

	ll amount = 0;
	ll lastResult = 0;
	while(true) {
		ll currentResult = rand() % 6 + 1;
		amount++;
		if(currentResult == 6 && lastResult == 5) {
			break;
		}
		lastResult = currentResult;
	}
	return amount;
}

int secondGameAmount() {
	srand(time(NULL));

	ll amount = 0;
	ll lastResult = 0;
	while(true) {
		ll currentResult = rand() % 6 + 1;
		amount++;
		if(currentResult == 5 && lastResult == 5) {
			break;
		}
		lastResult = currentResult;
	}
	return amount;
}

int main() {
	ll experimentCount = 1000000;
	double expectedAmountWithFirstGame = 0;
	double expectedAmountWithSecondGame = 0;

	for(ll i=0; i<experimentCount; i++) {
		expectedAmountWithFirstGame += firstGameAmount();
		expectedAmountWithSecondGame += secondGameAmount();
	}
	expectedAmountWithFirstGame /= experimentCount;
    expectedAmountWithSecondGame /= experimentCount;

    cout<<"Expected amount with first game: "<<expectedAmountWithFirstGame<<endl;
    cout<<"Expected amount with second game: "<<expectedAmountWithSecondGame<<endl;
    cout<<"Over a long run both the games will yield same expected results."<<endl;
    cout<<"Alice can elect to play any of two games. Both games have same probabilities."<<endl;
	return 0;
}
