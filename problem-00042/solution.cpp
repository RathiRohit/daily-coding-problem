#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n, m;
	cout<<"Enter values for N & M:"<<endl;
	cin>>n>>m;

	char grid[n][m];
	vector<char> isToBeRemoved(m, '0');
	int ans = 0;
	cout<<"Enter grid of "<<n<<"x"<<m<<" lowercase characters:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		for(int m_i=0; m_i<m; m_i++) {
			cin>>grid[n_i][m_i];

			if(isToBeRemoved[m_i] == '0') {
				isToBeRemoved[m_i] = grid[n_i][m_i];
			} else if(isToBeRemoved[m_i] != '1') {
				isToBeRemoved[m_i] = grid[n_i][m_i];
				if(grid[n_i][m_i] < grid[n_i - 1][m_i]) {
					isToBeRemoved[m_i] = '1';
					ans++;
				}
			}
		}
	}

	cout<<"Minimum number of columns that needs to be removed: "<<ans<<endl;
	return 0;
}
