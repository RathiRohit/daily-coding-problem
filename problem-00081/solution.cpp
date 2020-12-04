#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n, m;
    cin>>n>>m;

    ll trees = 1;
    vector<vector<int> > slopes = {
        {1, 1, 0, 0},
        {3, 1, 0, 0},
        {5, 1, 0, 0},
        {7, 1, 0, 0},
        {1, 2, 0, 0}
    };
    string row;
    cin>>row;
    for (int n_i=1; n_i<n; n_i++) {
        cin>>row;

        for (int slope_i=0; slope_i<5; slope_i++) {
            if ((n_i % slopes[slope_i][1]) == 0) {
                slopes[slope_i][2] += slopes[slope_i][0];
                slopes[slope_i][2] %= m;

                if (row[slopes[slope_i][2]] == '#') {
                    slopes[slope_i][3]++;
                }
            }
        }
    }

    for (int slope_i=0; slope_i<5; slope_i++) {
        trees *= slopes[slope_i][3];
    }
    cout<<trees<<endl;
	return 0;
}
