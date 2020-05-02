#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

void printSpaces(int spaceCount) {
	while(spaceCount > 0) {
		cout<<" ";
		spaceCount--;
	}
}

int main() {
	string str;
	int k;
	cout<<"Enter value for K:"<<endl;
	cin>>k;
	cout<<"Enter string:"<<endl;
	cin>>str;

	for(int k_i=1; k_i<=k; k_i++) {
		int startSpacesCount = k_i - 1;
		printSpaces(startSpacesCount);

		int currentIndex = k_i - 1;
		bool isDownToBeMeasured = true;
		while(currentIndex < str.size()) {
			cout<<str[currentIndex];
			int middleSpacesCount;
			if(isDownToBeMeasured) {
				middleSpacesCount = ((k - k_i) * 2) - 1;
			} else {
				middleSpacesCount = ((k_i - 1)  * 2) - 1;
			}
			if (middleSpacesCount <= 0) {
				middleSpacesCount = ((k - 1) * 2) - 1;
			}
			printSpaces(middleSpacesCount);
            currentIndex += middleSpacesCount + 1;
			isDownToBeMeasured = !isDownToBeMeasured;
		}
		cout<<endl;
	}
	return 0;
}
