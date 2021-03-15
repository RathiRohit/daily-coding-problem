#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int t;
    for (cin>>t; t; t--) {
        int days, whites, blacks, tmp;
        cin>>days>>whites>>blacks;

        ll ans = 0;
        vector<int> pendingTasks(days);
        for (int days_i=0; days_i<days; days_i++) {
            cin>>pendingTasks[days_i];
        }
        for (int days_i=0; days_i<days; days_i++) {
            cin>>tmp;
            pendingTasks[days_i] = pendingTasks[days_i] - tmp;
            ans += pendingTasks[days_i];
        }
        sort(pendingTasks.begin(), pendingTasks.end(), greater<int>());

        vector<int> buttons(whites + blacks);
        for (int whites_i=0; whites_i<whites; whites_i++) {
            cin>>buttons[whites_i];
        }
        for (int blacks_i=0; blacks_i<blacks; blacks_i++) {
            cin>>buttons[whites + blacks_i];
        }
        sort(buttons.begin(), buttons.end(), greater<int>());

        int i = 0, j = 0, buttonsCount = whites + blacks;
        while (i < days && j < buttonsCount) {
            if (pendingTasks[i] >= buttons[j]) {
                ans -= buttons[j];
                i++;
            }
            j++;
        }

        cout<<ans<<endl;
    }
	return 0;
}
