#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int getWordsCount(vector<string> words, int startIndex, int k) {
    int curSize = 0;
    int count = 0;
    for(int i=startIndex; i<words.size(); i++) {
        if(curSize >= k || (curSize+words[i].size()) >= k) {
            break;
        }

        curSize += words[i].size();
        count++;
        if(curSize < k) {
            curSize++;
        }
    }
    return count;
}

int getWordsLength(vector<string> words, int startIndex, int count) {
    int length = 0;
    for(int i=0; i<count; i++) {
        length += words[startIndex + i].size();
    }
    return length;
}

int getExtraSpaces(int k, int wordsLength, int wordsCount) {
    int essential = wordsLength + (wordsCount - 1);
    return k - essential;
}

void printSpaces(int n) {
    while(n != 0) {
        cout<<" ";
        n--;
    }
}

int main() {
    int n, k;
    cout<<"Enter number of words & line length (k):"<<endl;
    cin>>n>>k;

    vector<string> words(n);
    cout<<"Enter "<<n<<" words (each on new line):"<<endl;
    for(int n_i=0; n_i<n; n_i++) {
        cin>>words[n_i];
    }

    int n_i=0;
    while(n_i < words.size()) {
        int wordsToUse = getWordsCount(words, n_i, k);
        int wordsLength = getWordsLength(words, n_i, wordsToUse);
        int extraSpaces = getExtraSpaces(k, wordsLength, wordsToUse);

        if(wordsToUse == 1) {
            cout<<words[n_i];
            printSpaces(extraSpaces);
        } else {
            int extraEach = extraSpaces / (wordsToUse - 1);
            int remainingExtras = extraSpaces % (wordsToUse - 1);
            for(int i=0; i<wordsToUse; i++) {
                cout<<words[n_i + i]<<" ";
                printSpaces(extraEach);
                if(i < remainingExtras) {
                    printSpaces(1);
                }
            }
        }

        n_i += wordsToUse;
        cout<<endl;
    }
	return 0;
}
