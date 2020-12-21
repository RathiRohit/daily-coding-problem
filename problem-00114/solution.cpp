#include <iostream>
#include <vector>
#include <unordered_map>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int row, col, n;
    cin>>row>>col>>n;

    vector<vector<vector<char>>> tileArray(n, vector<vector<char>>(row, vector<char>(col, '.')));
    vector<int> ids(n);
    unordered_map<int, vector<string>> edgeMap;
    for (int n_i=0; n_i<n; n_i++) {
        cin>>ids[n_i];
        for (int row_i=0; row_i<row; row_i++) {
            for (int col_i=0; col_i<col; col_i++) {
                cin>>tileArray[n_i][row_i][col_i];
            }
        }
        vector<string> edges;
        string edge = "", revEdge = "";
        for (int row_i=0, col_i=0; col_i<col; col_i++) {
            edge = edge + tileArray[n_i][row_i][col_i];
            revEdge = tileArray[n_i][row_i][col_i] + revEdge;
        }
        edges.push_back(edge);
        edges.push_back(revEdge);
        edge = "", revEdge = "";
        for (int row_i=row-1, col_i=0; col_i<col; col_i++) {
            edge = edge + tileArray[n_i][row_i][col_i];
            revEdge = tileArray[n_i][row_i][col_i] + revEdge;
        }
        edges.push_back(edge);
        edges.push_back(revEdge);
        edge = "", revEdge = "";
        for (int row_i=0, col_i=0; row_i<row; row_i++) {
            edge = edge + tileArray[n_i][row_i][col_i];
            revEdge = tileArray[n_i][row_i][col_i] + revEdge;
        }
        edges.push_back(edge);
        edges.push_back(revEdge);
        edge = "", revEdge = "";
        for (int row_i=0, col_i=col-1; row_i<row; row_i++) {
            edge = edge + tileArray[n_i][row_i][col_i];
            revEdge = tileArray[n_i][row_i][col_i] + revEdge;
        }
        edges.push_back(edge);
        edges.push_back(revEdge);

        edgeMap[ids[n_i]] = edges;
    }

    ull ans = 1;
    for (int n_i=0; n_i<n; n_i++) {
        int noMatchEdges = 0;
        for (int edge_i=0; edge_i<8; edge_i+=2) {
            bool edgeMatched = false;
            for (int n_j=0; n_j<n; n_j++) {
                if (n_i != n_j) {
                    for (int edge_j=0; edge_j<8; edge_j++) {
                        if (edgeMap[ids[n_j]][edge_j] == edgeMap[ids[n_i]][edge_i]) {
                            edgeMatched = true;
                            break;
                        }
                    }
                }
                if (edgeMatched) {
                    break;
                }
            }
            if (!edgeMatched) {
                noMatchEdges++;
            }
        }
        if (noMatchEdges == 2) {
            ans *= ids[n_i];
        }
    }

    cout<<ans<<endl;
	return 0;
}
