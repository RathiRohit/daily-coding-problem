#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int getNeighbourIsland(vector<vector<int> > &matrix, int row, int col, int n, int m) {
    if((row-1 >= 0) && matrix[row-1][col] > 1) {
        return matrix[row-1][col];
    } if((row-1 >= 0) && (col+1 < m) && matrix[row-1][col+1] > 1) {
        return matrix[row-1][col+1];
    } if((col+1 < m) && matrix[row][col+1] > 1) {
        return matrix[row][col+1];
    } if((row+1 < n) && (col+1 < m) && matrix[row+1][col+1] > 1) {
        return matrix[row+1][col+1];
    } if((row+1 < n) && matrix[row+1][col] > 1) {
        return matrix[row+1][col];
    } if((row+1 < n) && (col-1 >= 0) && matrix[row+1][col-1] > 1) {
        return matrix[row+1][col-1];
    } if((col-1 >= 0) && matrix[row][col-1] > 1) {
        return matrix[row][col-1];
    } if((row-1 >= 0) && (col-1 >= 0) && matrix[row-1][col-1] > 1) {
        return matrix[row-1][col-1];
    }
    return -1;
}

void islandsCount(vector<vector<int> > &matrix, int n, int m, int row, int col, int &currentCount);

void visitNeighbours(vector<vector<int> > &matrix, int row, int col, int &currentCount, int n, int m) {
    if((row-1 >= 0) && (matrix[row-1][col] == 0 || matrix[row-1][col] == 1)) {
        islandsCount(matrix, n, m, row-1, col, currentCount);
    } if((row-1 >= 0) && (col+1 < m) && (matrix[row-1][col+1] == 0 || matrix[row-1][col+1] == 1)) {
        islandsCount(matrix, n, m, row-1, col+1, currentCount);
    } if((col+1 < m) && (matrix[row][col+1] == 0 || matrix[row][col+1] == 1)) {
        islandsCount(matrix, n, m, row, col+1, currentCount);
    } if((row+1 < n) && (col+1 < m) && (matrix[row+1][col+1] == 0 || matrix[row+1][col+1] == 1)) {
        islandsCount(matrix, n, m, row+1, col+1, currentCount);
    } if((row+1 < n) && (matrix[row+1][col] == 0 || matrix[row+1][col] == 1)) {
        islandsCount(matrix, n, m, row+1, col, currentCount);
    } if((row+1 < n) && (col-1 >= 0) && (matrix[row+1][col-1] == 0 || matrix[row+1][col-1] == 1)) {
        islandsCount(matrix, n, m, row+1, col-1, currentCount);
    } if((col-1 >= 0) && (matrix[row][col-1] == 0 || matrix[row][col-1] == 1)) {
        islandsCount(matrix, n, m, row, col-1, currentCount);
    } if((row-1 >= 0) && (col-1 >= 0) && (matrix[row-1][col-1] == 0 || matrix[row-1][col-1] == 1)) {
        islandsCount(matrix, n, m, row-1, col-1, currentCount);
    }
}

void islandsCount(vector<vector<int> > &matrix, int n, int m, int row, int col, int &currentCount) {
    if(matrix[row][col] == 1) {
        int neighbourIsland = getNeighbourIsland(matrix, row, col, n, m);
        if(neighbourIsland == -1) {
            currentCount++;
            matrix[row][col] = currentCount;
        } else {
            matrix[row][col] = neighbourIsland;
        }
        visitNeighbours(matrix, row, col, currentCount, n, m);
    } else if(matrix[row][col] == 0) {
        matrix[row][col] = -1;
        visitNeighbours(matrix, row, col, currentCount, n, m);
    }
}

int main() {
    int n, m;
    cout<<"Enter number of rows & columns in matrix:"<<endl;
    cin>>n>>m;

    vector<vector<int> > matrix(n, vector<int>(m));
    cout<<"Enter "<<n<<"x"<<m<<" matrix of 1s & 0s:"<<endl;
    for(int n_i=0; n_i<n; n_i++) {
        for(int m_i=0; m_i<m; m_i++) {
            cin>>matrix[n_i][m_i];
        }
    }

    int count = 1;
    islandsCount(matrix, n, m, 0, 0, count);
    cout<<"Total number of islands in the matrix:"<<endl;
    cout<<(count - 1)<<endl;
	return 0;
}
