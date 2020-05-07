#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int getNormalDiagonal(int size, int rowIndex, int colIndex) {
	int distanceFromCentralDiagonal = colIndex - rowIndex;
	return (size - 1) - distanceFromCentralDiagonal;
}

int getReverseDiagonal(int size, int rowIndex, int colIndex) {
	int distanceFromCentralDiagonal = (size - 1 - rowIndex) - colIndex;
	return (size - 1) - distanceFromCentralDiagonal;
}

int main() {
	int n;
	cout<<"Enter number of Bishops:"<<endl;
	cin>>n;

	int m;
	cout<<"Enter size of board:"<<endl;
	cin>>m;

	int totalPairs = 0;
	vector<int> normalDiagonalCounter((m - 1)*2 + 1, 0);
	vector<int> reverseDiagonalCounter((m - 1)*2 + 1, 0);
	cout<<"Enter board configuration in "<<m<<"x"<<m<<" fashion:"<<endl;
	for(int m_i=0; m_i<m; m_i++) {
		for(int m_j=0; m_j<m; m_j++) {
			char ch;
			cin>>ch;

			if(ch == 'b') {
				int normalDiagonal = getNormalDiagonal(m, m_i, m_j);
				int reverseDiagonal = getReverseDiagonal(m, m_i, m_j);

				totalPairs += normalDiagonalCounter[normalDiagonal];
				totalPairs += reverseDiagonalCounter[reverseDiagonal];

				normalDiagonalCounter[normalDiagonal]++;
				reverseDiagonalCounter[reverseDiagonal]++;
			}
		}
	}

	cout<<"Total Bishop pairs that can kill each other: "<<totalPairs<<endl;
	return 0;
}
