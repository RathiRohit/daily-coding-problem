#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cin>>n;

    int ans = 0;
    vector<vector<char>> hexGrid(1000, vector<char>(1000, 'W'));
    for (int n_i=0; n_i<n; n_i++) {
        string seq;
        cin>>seq;

        int row = 50, col = 50;
        for (int seq_i=0; seq_i<seq.size(); seq_i++) {
            switch (seq[seq_i]) {
                case 'e':
                    col++;
                    break;
                case 'w':
                    col--;
                    break;
                case 's':
                    seq_i++;
                    row++;
                    if (seq[seq_i] == 'e') {
                        if (row%2 == 1) {
                            col++;
                        }
                    } else {
                        if (row%2 == 0) {
                            col--;
                        }
                    }
                    break;
                case 'n':
                    seq_i++;
                    row--;
                    if (seq[seq_i] == 'e') {
                        if (row%2 == 1) {
                            col++;
                        }
                    } else {
                        if (row%2 == 0) {
                            col--;
                        }
                    }
                    break;
            }
        }

        if (hexGrid[row][col] == 'W') {
            hexGrid[row][col] = 'B';
            ans++;
        } else {
            hexGrid[row][col] = 'W';
            ans--;
        }
    }

    cout<<ans<<endl;
	return 0;
}
