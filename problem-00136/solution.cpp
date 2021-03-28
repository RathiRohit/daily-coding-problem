#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int t;
    for (cin>>t; t; t--) {
        int n;
        cin>>n;

        vector<int> arr(n);
        for (int n_i=0; n_i<n; n_i++) {
            cin>>arr[n_i];
        }

        vector<int> ans(n);
        ans[n-1] = 1;
        for (int n_i=n-2; n_i>=0; n_i--) {
            ans[n_i] = 1;
            if ((arr[n_i] > 0 && arr[n_i+1] < 0) || (arr[n_i] < 0 && arr[n_i+1] > 0)) {
                ans[n_i] += ans[n_i+1];
            }
        }

        for (int n_i=0; n_i<n; n_i++) {
            cout<<ans[n_i]<<' ';
        }
        cout<<endl;
    }
	return 0;
}
