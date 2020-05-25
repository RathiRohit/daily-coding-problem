#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int biasedToss() {
	int res = rand() % 3;

	if(res < 2) {
		return 0;
	}
	return 1;
}

int tossCoin() {
	int biasedRes1 = biasedToss();
	int biasedRes2 = biasedToss();

	if(biasedRes1 == 1 && biasedRes2 == 0) {
		return 0;
	} else if(biasedRes1 == 0 && biasedRes2 == 1) {
		return 1;
	}

	return tossCoin();
}

int main() {
	srand(time(NULL));

	cout<<"Result of coin toss: "<<tossCoin()<<endl;
	return 0;
}
