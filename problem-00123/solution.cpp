#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int adjacentBlacks(vector<vector<char>>& hexGrid, int row, int col) {
    int blacks = 0;
    blacks += (hexGrid[row][col+2] == 'B'); // e
    blacks += (hexGrid[row][col-2] == 'B'); // w
    blacks += (hexGrid[row+1][col+1] == 'B'); // se
    blacks += (hexGrid[row+1][col-1] == 'B'); // sw
    blacks += (hexGrid[row-1][col+1] == 'B'); // ne
    blacks += (hexGrid[row-1][col-1] == 'B'); // nw
    return blacks;
}

int main() {
    int n;
    cin>>n;

    int ans = 0;
    int size = 1000;
    vector<vector<char>> hexGrid(size, vector<char>(size, 'W'));
    for (int n_i=0; n_i<n; n_i++) {
        string seq;
        cin>>seq;

        int row = size/2, col = size/2;
        for (int seq_i=0; seq_i<seq.size(); seq_i++) {
            switch (seq[seq_i]) {
                case 'e':
                    col += 2;
                    break;
                case 'w':
                    col -= 2;
                    break;
                case 's':
                    seq_i++;
                    row++;
                    if (seq[seq_i] == 'e') {
                        col++;
                    } else {
                        col--;
                    }
                    break;
                case 'n':
                    seq_i++;
                    row--;
                    if (seq[seq_i] == 'e') {
                        col++;
                    } else {
                        col--;
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

    for (int i=0; i<100; i++) {
        ans = 0;
        vector<vector<char>> tmpHexGrid(size, vector<char>(size, 'W'));
        for (int row=2; row<(size-2); row++) {
            int col = (row%2 == 0) ? 2 : 3;
            for (; col<(size-2); col+=2) {
                if (hexGrid[row][col] == 'W') {
                    if (adjacentBlacks(hexGrid, row, col) == 2) {
                        tmpHexGrid[row][col] = 'B';
                        ans++;
                    } else {
                        tmpHexGrid[row][col] = 'W';
                    }
                } else {
                    int adjacent = adjacentBlacks(hexGrid, row, col);
                    if (adjacent == 0 || adjacent > 2) {
                        tmpHexGrid[row][col] = 'W';
                    } else {
                        tmpHexGrid[row][col] = 'B';
                        ans++;
                    }
                }
            }
        }
        hexGrid = tmpHexGrid;
    }

    cout<<ans<<endl;
	return 0;
}
