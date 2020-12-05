#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cin>>n;

    int validPassports = 0;
    int fields = 0;
    int countryCodeNotFound = 1;
    for (int n_i=0; n_i<n;) {
        string field;
        string value;

        cin>>field;
        if (field == "---") {
            fields += countryCodeNotFound;
            validPassports += (fields == 8);
            n_i++;
            fields = 0;
            countryCodeNotFound = 1;
            continue;
        }
        cin>>value;

        if (field == "cid") {
            countryCodeNotFound = 0;
        }
        fields++;
    }

    cout<<validPassports<<endl;
	return 0;
}
