#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string str;
	cout<<"Enter a small-case string:"<<endl;
	cin>>str;

	vector<int> charCount(26, 0);
	int oddCount = 0;
	for(int str_i=0; str_i<str.length(); str_i++) {
		charCount[str[str_i] - 'a']++;
		if((charCount[str[str_i] - 'a'] & 1) == 1) {
			oddCount++;
		} else {
			oddCount--;
		}
	}

	if(oddCount <= 1) {
		cout<<"true"<<endl;
		return 0;
	}

	cout<<"false"<<endl;
	return 0;
}
