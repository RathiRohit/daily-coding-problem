#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int t;
    for (cin>>t; t; t--) {
        string word;
        cin>>word;
        int wordSize = word.size();

        vector<int> charCount(26, 0);
        for (int word_i=0; word_i<wordSize/2; word_i++) {
            charCount[word[word_i] - 'a']++;
            charCount[word[wordSize - word_i - 1] - 'a']--;
        }

        bool isLapindrome = true;
        for (char letterIndex=0; letterIndex<26; letterIndex++) {
            if (charCount[letterIndex] != 0) {
                isLapindrome = false;
                break;
            }
        }

        if (isLapindrome) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
	return 0;
}
