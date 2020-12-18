#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int getNearbyActives(vector<vector<vector<vector<char>>>>& grid, int n, int m, int o, int p) {
    int activeCubes = 0;
    for (int n_i=n-1; n_i<=n+1; n_i++) {
        for (int m_i=m-1; m_i<=m+1; m_i++) {
            for (int o_i=o-1; o_i<=o+1; o_i++) {
                for (int p_i=p-1; p_i<=p+1; p_i++) {
                    if (grid[n_i][m_i][o_i][p_i] == '#') {
                        activeCubes++;
                    }
                }
            }
        }
    }

    activeCubes -= (grid[n][m][o][p] == '#');
    return activeCubes;
}

int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<vector<vector<char>>>> grid(
        n + 16, vector<vector<vector<char>>>(
            m + 16, vector<vector<char>>(
                1 + 16, vector<char>(1 + 16, '.')
            )
        )
    );

    for (int n_i=0; n_i<n; n_i++) {
        for (int m_i=0; m_i<m; m_i++) {
            cin>>grid[8+n_i][8+m_i][8][8];
        }
    }

    n = n + 16;
    m = m + 16;
    int o = 1 + 16;
    int p = 1 + 16;
    ll activeCubes = 0;
    for (int cycle=0; cycle<6; cycle++) {
        activeCubes = 0;
        vector<vector<vector<vector<char>>>> tmpGrid(
            n, vector<vector<vector<char>>>(
                m, vector<vector<char>>(
                    o, vector<char>(p, '.')
                )
            )
        );

        for (int n_i=1; n_i<n-1; n_i++) {
            for (int m_i=1; m_i<m-1; m_i++) {
                for (int o_i=1; o_i<o-1; o_i++) {
                    for (int p_i=1; p_i<p-1; p_i++) {
                        int activeNearby = getNearbyActives(grid, n_i, m_i, o_i, p_i);
                        if (grid[n_i][m_i][o_i][p_i] == '.') {
                            if (activeNearby == 3) {
                                tmpGrid[n_i][m_i][o_i][p_i] = '#';
                                activeCubes++;
                            } else {
                                tmpGrid[n_i][m_i][o_i][p_i] = '.';
                            }
                        } else {
                            if (activeNearby != 2 && activeNearby != 3) {
                                tmpGrid[n_i][m_i][o_i][p_i] = '.';
                            } else {
                                tmpGrid[n_i][m_i][o_i][p_i] = '#';
                                activeCubes++;
                            }
                        }
                    }
                }
            }
        }

        grid = tmpGrid;
    }

    cout<<activeCubes<<endl;
	return 0;
}
