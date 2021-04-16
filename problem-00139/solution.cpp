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

		char cell;
		vector<int> gridRows(n, -1);
		vector<int> gridCols(n, -1);
		for (int n_i=0; n_i<n; n_i++) {
			for (int n_j=0; n_j<n; n_j++) {
				cin>>cell;
				if (cell == '#') {
					gridRows[n_i] = n_j;
					gridCols[n_j] = n_i;
				}
			}
		}

		int ans = 0;
		for (int n_i=0; n_i<n; n_i++) {
            for (int n_j=gridRows[n_i]+1; n_j<n; n_j++) {
                if (gridCols[n_j] < n_i) {
                    ans++;
                }
            }
        }

        cout<<ans<<endl;
	}
	return 0;
}
