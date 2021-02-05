#include <iostream>
#include <unordered_map>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int t;
    for (cin>>t; t>0; t--) {
        int wordCount, phraseCount;
        cin>>wordCount>>phraseCount;

        unordered_map<string, bool> isInUse;
        vector<string> words(wordCount);
        for (int wordCount_i=0; wordCount_i<wordCount; wordCount_i++) {
            cin>>words[wordCount_i];
            isInUse[words[wordCount_i]] = false;
        }

        for (int phraseCount_i=0; phraseCount_i<phraseCount; phraseCount_i++) {
            int words;
            cin>>words;

            string word;
            for (int words_i=0; words_i<words; words_i++) {
                cin>>word;
                if (isInUse.count(word) == 1) {
                    isInUse[word] = true;
                }
            }
        }

        for (int wordCount_i=0; wordCount_i<wordCount; wordCount_i++) {
            if (isInUse[words[wordCount_i]]) {
                cout<<"YES ";
            } else {
                cout<<"NO ";
            }
        }
        cout<<endl;
    }
	return 0;
}
