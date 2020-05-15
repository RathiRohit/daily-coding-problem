#include <iostream>
#include <string>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int option;
	cout<<"Enter 1 for Encoding / 2 for Decoding:"<<endl;
	cin>>option;

	string str;
	cout<<"Enter input string:"<<endl;
	cin>>str;

	int len = str.length();
	string res = "";
	if(option == 1) {
		int lastCharCount = 0;
		char lastChar = ' ';

		for(int len_i=0; len_i<len; len_i++) {
			if(str[len_i] == lastChar) {
				lastCharCount++;
			} else {
				if(lastCharCount > 0) {
					res.append(to_string(lastCharCount));
                	res.push_back(lastChar);
				}

				lastChar = str[len_i];
				lastCharCount = 1;
			}
		}
		if(lastCharCount > 0) {
			res.append(to_string(lastCharCount));
			res.push_back(lastChar);
		}
	} else {
		int currentCount = 0;
		for(int len_i=0; len_i<len; len_i++) {
			if('0' <= str[len_i] && str[len_i] <= '9') {
				currentCount = currentCount*10 + (str[len_i] - '0');
			} else {
				while(currentCount > 0) {
					res.push_back(str[len_i]);
					currentCount--;
				}
			}
		}
	}

	cout<<"Result: "<<res<<endl;
	return 0;
}
