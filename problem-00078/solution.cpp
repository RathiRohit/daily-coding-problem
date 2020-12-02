#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cin>>n;

    int validCount = 0;

    for (int n_i=0; n_i<n; n_i++) {
        string limits;
        char ch;
        char tmp;
        string password;

        cin>>limits;
        cin>>ch;
        cin>>tmp;
        cin>>password;

        int separator = limits.find_first_of('-');
        string lower = limits.substr(0, separator);
        string upper = limits.substr(separator + 1, limits.size() - (separator + 1));
        int lowerBound = stoi(lower);
        int upperBound = stoi(upper);

        int charCount = 0;
        for (char letter: password) {
            if (letter == ch) {
                charCount++;
            }
        }

        if (lowerBound <= charCount && charCount <= upperBound) {
            validCount++;
        }
    }

    cout<<validCount<<endl;
    return 0;
}
