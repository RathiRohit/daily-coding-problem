#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int result = -1;
	int count = 0;
	int tmp;
	cout<<"Enter next number in the stream (-1 to end):"<<endl;
	cin>>tmp;

	if(tmp == -1) {
		cout<<"Nothing in the stream to select the number from."<<endl;
		return 1;
	}
	count++;
	result = tmp;

	srand(time(NULL));

	while(true) {
		cout<<"Enter next number in the stream (-1 to end):"<<endl;
		cin>>tmp;

		if(tmp == -1) {
			break;
		}

		int newIndex = rand() % (count + 1);
		if(newIndex == 0) {
			result = tmp;
		}
		count++;
	}

	cout<<"Uniformly chosen random number with probability (1/"<<count<<"): "<<result<<endl;
	return 0;
}
