#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

bool occupiedUp(int row, int col, vector<vector<char> >& grid) {
    for (int row_i=row-1; row_i>=0; row_i--) {
        if (grid[row_i][col] == '#') {
            return true;
        } else if (grid[row_i][col] == 'L') {
            return false;
        }
    }
    return false;
}

bool occupiedDown(int row, int col, vector<vector<char> >& grid) {
    for (int row_i=row+1; row_i<grid.size(); row_i++) {
        if (grid[row_i][col] == '#') {
            return true;
        } else if (grid[row_i][col] == 'L') {
            return false;
        }
    }
    return false;
}

bool occupiedLeft(int row, int col, vector<vector<char> >& grid) {
    for (int col_i=col-1; col_i>=0; col_i--) {
        if (grid[row][col_i] == '#') {
            return true;
        } else if (grid[row][col_i] == 'L') {
            return false;
        }
    }
    return false;
}

bool occupiedRight(int row, int col, vector<vector<char> >& grid) {
    for (int col_i=col+1; col_i<grid[0].size(); col_i++) {
        if (grid[row][col_i] == '#') {
            return true;
        } else if (grid[row][col_i] == 'L') {
            return false;
        }
    }
    return false;
}

bool occupiedUpRight(int row, int col, vector<vector<char> >& grid) {
    for (int row_i=row-1,col_i=col+1; row_i>=0 && col_i<grid[0].size(); row_i--,col_i++) {
        if (grid[row_i][col_i] == '#') {
            return true;
        } else if (grid[row_i][col_i] == 'L') {
            return false;
        }
    }
    return false;
}

bool occupiedDownRight(int row, int col, vector<vector<char> >& grid) {
    for (int row_i=row+1,col_i=col+1; row_i<grid.size() && col_i<grid[0].size(); row_i++,col_i++) {
        if (grid[row_i][col_i] == '#') {
            return true;
        } else if (grid[row_i][col_i] == 'L') {
            return false;
        }
    }
    return false;
}

bool occupiedDownLeft(int row, int col, vector<vector<char> >& grid) {
    for (int row_i=row+1,col_i=col-1; row_i<grid.size() && col_i>=0; row_i++,col_i--) {
        if (grid[row_i][col_i] == '#') {
            return true;
        } else if (grid[row_i][col_i] == 'L') {
            return false;
        }
    }
    return false;
}

bool occupiedUpLeft(int row, int col, vector<vector<char> >& grid) {
    for (int row_i=row-1,col_i=col-1; row_i>=0 && col_i>=0; row_i--,col_i--) {
        if (grid[row_i][col_i] == '#') {
            return true;
        } else if (grid[row_i][col_i] == 'L') {
            return false;
        }
    }
    return false;
}

int occupiedAround(int row, int col, vector<vector<char> >& grid) {
    int occupied = 0;
    occupied += occupiedUp(row, col, grid);
    occupied += occupiedUpRight(row, col, grid);
    occupied += occupiedRight(row, col, grid);
    occupied += occupiedDownRight(row, col, grid);
    occupied += occupiedDown(row, col, grid);
    occupied += occupiedDownLeft(row, col, grid);
    occupied += occupiedLeft(row, col, grid);
    occupied += occupiedUpLeft(row, col, grid);
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
                    if (occupiedAround(n_i, m_i, grid) >= 5) {
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
