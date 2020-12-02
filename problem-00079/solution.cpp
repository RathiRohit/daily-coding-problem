#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cin>>n;

    int validCount = 0;

    for (int n_i=0; n_i<n; n_i++) {
        string positions;
        char ch;
        char tmp;
        string password;

        cin>>positions;
        cin>>ch;
        cin>>tmp;
        cin>>password;

        int separator = positions.find_first_of('-');
        string first = positions.substr(0, separator);
        string second = positions.substr(separator + 1, positions.size() - (separator + 1));
        int firstPos = stoi(first);
        int secondPos = stoi(second);

        if ((password[firstPos - 1] == ch) ^ (password[secondPos - 1] == ch)) {
            validCount++;
        }
    }

    cout<<validCount<<endl;
    return 0;
}
