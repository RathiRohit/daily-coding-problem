#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int t;
    for (cin>>t; t; t--) {
        int n;
        cin>>n;

        vector<int> distances(n);
        for (int n_i=0; n_i<n; n_i++) {
            cin>>distances[n_i];
        }

        vector<int> stations(n);
        for (int n_i=0; n_i<n; n_i++) {
            cin>>stations[n_i];
        }
        sort(stations.begin(), stations.end());

        vector<int> minDistances(1001, -1);
        minDistances[0] = 0;
        queue<int> toProcess;
        toProcess.push(0);

        while (!toProcess.empty()) {
            int current = toProcess.front();
            toProcess.pop();
            for (int n_i=0; n_i<n; n_i++) {
                int newMin = current + stations[n_i];
                if (newMin > 1000) {
                    break;
                }

                if (minDistances[newMin] == -1) {
                    minDistances[newMin] = minDistances[current] + 1;
                    toProcess.push(newMin);
                }
            }
        }

        ll ans = 0;
        for (int n_i=0; n_i<n; n_i++) {
            ans += minDistances[distances[n_i]*2];
        }
        cout<<ans<<endl;
    }
	return 0;
}
