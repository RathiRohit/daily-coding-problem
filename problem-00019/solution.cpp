#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int getMinEditDistance(string str1, string str2, int len1, int len2) {
	int memo[len1 + 1][len2 + 1];

	for(int len1_i=0; len1_i<=len1; len1_i++) {
		for(int len2_i=0; len2_i<=len2; len2_i++) {
			if(len1_i == 0) {
				memo[len1_i][len2_i] = len2_i;
			} else if(len2_i == 0) {
				memo[len1_i][len2_i] = len1_i;
			} else if(str1[len1_i - 1] == str2[len2_i - 1]) {
				memo[len1_i][len2_i] = memo[len1_i - 1][len2_i - 1];
			} else {
				memo[len1_i][len2_i] = 1 + min(
					min(memo[len1_i - 1][len2_i], memo[len1_i][len2_i - 1]),
					memo[len1_i - 1][len2_i - 1]
				);
			}
		}
	}

	return memo[len1][len2];
}

int main() {
	string str1;
	string str2;
	cout<<"Enter two strings on separate lines:"<<endl;
	cin>>str1>>str2;

	cout<<"Min edit distance to convert 1st string into 2nd is: ";
	cout<<getMinEditDistance(str1, str2, str1.size(), str2.size())<<endl;
	return 0;
}
