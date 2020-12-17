#include <iostream>
#include <unordered_set>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int fieldCount;
    cin>>fieldCount;

    unordered_set<int> validValues;
    for (int fieldCount_i=0; fieldCount_i<fieldCount; fieldCount_i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        for (int i=a; i<=b; i++) {
            validValues.insert(i);
        }
        for (int i=c; i<=d; i++) {
            validValues.insert(i);
        }
    }

    int ticketCount, numberCount;
    cin>>ticketCount>>numberCount;

    ll ans = 0;
    for (int ticketCount_i=0; ticketCount_i<ticketCount; ticketCount_i++) {
        for (int numberCount_i=0; numberCount_i<numberCount; numberCount_i++) {
            int tmp;
            cin>>tmp;

            if (validValues.count(tmp) == 0) {
                ans += tmp;
            }
        }
    }

    cout<<ans<<endl;
	return 0;
}
