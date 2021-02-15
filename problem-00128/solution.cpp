#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int t;
    for (cin>>t; t; t--) {
        int n;
        cin>>n;

        string str;
        cin>>str;

        int oneCount = 0;
        ll substringCount = 0;
        for (int n_i=0; n_i<n; n_i++) {
            if (str[n_i] == '1') {
                oneCount++;
                substringCount += oneCount;
            }
        }

        cout<<substringCount<<endl;
    }
	return 0;
}
