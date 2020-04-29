#include <iostream>
#include <queue>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n, m;
	cout<<"Enter value of N & M:"<<endl;
	cin>>n>>m;

	int matrix[n][m];
	cout<<"Enter "<<n<<"x"<<m<<" values in row-wise format:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		for(int m_i=0; m_i<m; m_i++) {
			cin>>matrix[n_i][m_i];
		}
	}

	int leftWall = 0;
	int rightWall = m-1;
	int topWall = 0;
	int bottomWall = n-1;
	bool isRowWise = true;
	bool isRowDirectionForward = true;
	bool isColumnDirectionDownward = true;

	cout<<"Clockwise spiral output:"<<endl;
	while(leftWall <= rightWall && topWall <= bottomWall) {
		if(isRowWise) {
			if(isRowDirectionForward) {
				for(int r_i=leftWall; r_i<=rightWall; r_i++) {
					cout<<matrix[topWall][r_i]<<endl;
				}
				topWall++;
			} else {
				for(int r_i=rightWall; r_i>=leftWall; r_i--) {
					cout<<matrix[bottomWall][r_i]<<endl;
				}
				bottomWall--;
			}
			isRowDirectionForward = !isRowDirectionForward;
		} else {
			if(isColumnDirectionDownward) {
				for(int c_i=topWall; c_i<=bottomWall; c_i++) {
					cout<<matrix[c_i][rightWall]<<endl;
				}
				rightWall--;
			} else {
				for(int c_i=bottomWall; c_i>=topWall; c_i--) {
					cout<<matrix[c_i][leftWall]<<endl;
				}
				leftWall++;
			}
			isColumnDirectionDownward = !isColumnDirectionDownward;
		}
		isRowWise = !isRowWise;
	}
	return 0;
}
