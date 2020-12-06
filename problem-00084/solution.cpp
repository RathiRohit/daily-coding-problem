#include <iostream>
#include <cmath>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cin>>n;

    int maxID = 0;
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
        if (id > maxID) {
            maxID = id;
        }
    }

    cout<<maxID<<endl;
	return 0;
}
