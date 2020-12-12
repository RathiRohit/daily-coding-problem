#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int occupiedAround(int row, int col, vector<vector<char> >& grid) {
    int occupied = 0;
    occupied += (grid[row - 1][col] == '#');
    occupied += (grid[row - 1][col + 1] == '#');
    occupied += (grid[row][col + 1] == '#');
    occupied += (grid[row + 1][col + 1] == '#');
    occupied += (grid[row + 1][col] == '#');
    occupied += (grid[row + 1][col - 1] == '#');
    occupied += (grid[row][col - 1] == '#');
    occupied += (grid[row - 1][col - 1] == '#');
    return occupied;
}

int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<char> > grid(n+2, vector<char>(m+2, '.'));
    for (int n_i=1; n_i<=n; n_i++) {
        for (int m_i=1; m_i<=m; m_i++) {
            cin>>grid[n_i][m_i];
        }
    }

    int changes = 0;
    int occupied = 0;
    do {
        changes = 0;
        occupied = 0;

        vector<vector<char> > tmpGrid(n+2, vector<char>(m+2, '.'));

        for (int n_i=1; n_i<=n; n_i++) {
            for (int m_i=1; m_i<=m; m_i++) {
                if (grid[n_i][m_i] == 'L') {
                    if (occupiedAround(n_i, m_i, grid) == 0) {
                        tmpGrid[n_i][m_i] = '#';
                        changes++;
                        occupied++;
                    } else {
                        tmpGrid[n_i][m_i] = 'L';
                    }
                } else if (grid[n_i][m_i] == '#') {
                    if (occupiedAround(n_i, m_i, grid) >= 4) {
                        tmpGrid[n_i][m_i] = 'L';
                        changes++;
                    } else {
                        tmpGrid[n_i][m_i] = '#';
                        occupied++;
                    }
                }
            }
        }

        grid = tmpGrid;
    } while (changes != 0);

    cout<<occupied<<endl;
	return 0;
}
