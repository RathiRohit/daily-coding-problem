#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int t;
    for (cin>>t; t>0; t--) {
        int M, x, y;
        cin>>M>>x>>y;

        int range = x * y;
        vector<int> houses(101, 0);
        for (int M_i=0; M_i<M; M_i++) {
            int house;
            cin>>house;

            houses[max(1, house - range)]++;
            houses[min(100, house + range)]--;
        }

        int safeHouseCount = 0;
        int danger = 0;
        for (int houses_i=1; houses_i<101; houses_i++) {
            if (houses[houses_i] != 0) {
                danger += houses[houses_i];
            } else if (danger == 0) {
                safeHouseCount++;
            }
        }

        cout<<safeHouseCount<<endl;
    }
	return 0;
}
