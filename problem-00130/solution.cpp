#include <iostream>
#include <unordered_map>
#include <map>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int t;
    for (cin>>t; t; t--) {
        int strOneLength, strTwoLength;
        cin>>strOneLength>>strTwoLength;

        string strOne, strTwo;
        cin>>strOne>>strTwo;

        int strOneStart = strOneLength - 1;
        int strTwoStart = 0;

        int maxLength = 0;
        unordered_map<string, int> maxSubstrings;
        unordered_map<string, int> maxSubstringsStart;
        while (strTwoStart != strTwoLength) {
            int strOne_i = strOneStart;
            int strTwo_i = strTwoStart;

            string currentSubstring = "";
            while (strOne_i < strOneLength && strTwo_i < strTwoLength) {
                if (strOne[strOne_i] == strTwo[strTwo_i]) {
                    currentSubstring += strOne[strOne_i];
                } else {
                    int currentLength = currentSubstring.size();
                    int currentSubstringStart = strOne_i - currentLength;
                    if (currentLength >= maxLength) {
                        if (currentLength > maxLength) {
                            maxSubstrings.clear();
                            maxSubstringsStart.clear();
                            maxLength = currentLength;
                        }
                        if (maxSubstrings.count(currentSubstring) == 0) {
                            maxSubstrings[currentSubstring] = 0;
                            maxSubstringsStart[currentSubstring] = currentSubstringStart;
                        }
                        if (maxSubstringsStart[currentSubstring] == currentSubstringStart) {
                            maxSubstrings[currentSubstring]++;
                        }
                    }
                    currentSubstring = "";
                }

                strOne_i++;
                strTwo_i++;
            }

            int currentLength = currentSubstring.size();
            int currentSubstringStart = strOne_i - currentLength;
            if (currentLength >= maxLength) {
                if (currentLength > maxLength) {
                    maxSubstrings.clear();
                    maxSubstringsStart.clear();
                    maxLength = currentLength;
                }
                if (maxSubstrings.count(currentSubstring) == 0) {
                    maxSubstrings[currentSubstring] = 0;
                    maxSubstringsStart[currentSubstring] = currentSubstringStart;
                }
                if (maxSubstringsStart[currentSubstring] == currentSubstringStart) {
                    maxSubstrings[currentSubstring]++;
                }
            }

            if (strOneStart != 0) {
                strOneStart--;
            } else {
                strTwoStart++;
            }
        }

        cout<<maxLength<<endl;
        if (maxLength != 0) {
            map<string, int> sortedMaxSubstrings(maxSubstrings.begin(), maxSubstrings.end());
            for (auto substring: sortedMaxSubstrings) {
                cout<<substring.first<<' '<<substring.second<<endl;
            }
        }
    }
	return 0;
}
