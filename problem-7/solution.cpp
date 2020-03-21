#include <iostream>
#include <string>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string inputString;
	cout<<"Enter string with small case letters:"<<endl;
	cin>>inputString;

	int k;
	cout<<"Enter number of allowed distinct letters:"<<endl;
	cin>>k;

	if(k < 2) {
		cout<<"Max possible length: "<<k<<endl;
		return 0;
	}

	vector<int> hashCount(26, 0);
	int maxLength = 0;
	int length = 1;
	int startPos = 0, currentPos = 1;
	int stringLength = inputString.size();
	int distinctChars = 1;

	hashCount[inputString[0] - 'a']++;
	while(currentPos < stringLength) {
		char currentChar = inputString[currentPos];
		bool newCharacter = hashCount[currentChar - 'a'] == 0;
		if(!newCharacter) {
			length = currentPos - startPos + 1;
		} else if(distinctChars == k) {
			while(hashCount[inputString[startPos] - 'a'] != 1) {
				hashCount[inputString[startPos] - 'a']--;
				startPos++;
			}
			hashCount[inputString[startPos] - 'a']--;
            startPos++;
            length = currentPos - startPos + 1;
		} else {
			length = currentPos - startPos + 1;
			distinctChars++;
		}

		if(length > maxLength && distinctChars == k) {
			maxLength = length;
		}
		hashCount[currentChar - 'a']++;
		currentPos++;
	}

	cout<<"Max possible length: "<<maxLength<<endl;
	return 0;
}
