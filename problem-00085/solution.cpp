#include <iostream>
#include <cmath>
#include <unordered_set>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cin>>n;

    int lowestId = INT_MAX;
    int highestId = INT_MIN;
    unordered_set<int> ids;
    for (int n_i=0; n_i<n; n_i++) {
        string pass;
        cin>>pass;

        int row;
        int rowTop = 0;
        int rowBottom = 127;
        for (int pass_i=0; pass_i<7; pass_i++) {
            row = ceil((rowTop + rowBottom) / 2.0);
            if (pass[pass_i] == 'F') {
                rowBottom = row - 1;
            } else {
                rowTop = row;
            }
        }
        row = ceil((rowTop + rowBottom) / 2.0);

        int col;
        int colLeft = 0;
        int colRight = 7;
        for (int pass_i=7; pass_i<10; pass_i++) {
            col = ceil((colLeft + colRight) / 2.0);
            if (pass[pass_i] == 'L') {
                colRight = col - 1;
            } else {
                colLeft = col;
            }
        }
        col = ceil((colLeft + colRight) / 2.0);

        int id = (row * 8) + col;
        ids.insert(id);

        if (id < lowestId) {
            lowestId = id;
        }
        if (id > highestId) {
            highestId = id;
        }
    }

    for (int id=lowestId; id<=highestId; id++) {
        if (ids.count(id) == 0) {
            if (ids.count(id - 1) == 1 && ids.count(id + 1) == 1) {
                cout<<id<<endl;
                return 0;
            }
        }
    }
	return 1;
}
