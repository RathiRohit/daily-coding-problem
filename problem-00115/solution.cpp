#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ull unsigned long long

using namespace std;

void copy(vector<vector<char>> src, vector<vector<char>>& dest) {
    int size = src.size();
    for (int row_i=0; row_i<size; row_i++) {
        for (int col_i=0; col_i<size; col_i++) {
            dest[row_i][col_i] = src[row_i][col_i];
        }
    }
}

void rotateAndFlip(vector<vector<char>>& grid, int rotation, string flip) {
    int size = grid.size();
    if (rotation >= 1) {
        vector<vector<char>> tmpGrid(size, vector<char>(size, '.'));
        copy(grid, tmpGrid);
        for (int row_i=0; row_i<size; row_i++) {
            for (int col_i=0; col_i<size; col_i++) {
                grid[col_i][size-1-row_i] = tmpGrid[row_i][col_i];
            }
        }
        rotateAndFlip(grid, rotation-1, "NONE");
    }

    if (flip == "VERTICAL_AXIS") {
        for (int row_i=0; row_i<size; row_i++) {
            for (int col_i=0; col_i<(size/2); col_i++) {
                char tmp = grid[row_i][col_i];
                grid[row_i][col_i] = grid[row_i][size-1-col_i];
                grid[row_i][size-1-col_i] = tmp;
            }
        }
    } else if (flip == "HORIZONTAL_AXIS") {
        for (int col_i=0; col_i<size; col_i++) {
            for (int row_i=0; row_i<(size/2); row_i++) {
                char tmp = grid[row_i][col_i];
                grid[row_i][col_i] = grid[size-1-row_i][col_i];
                grid[size-1-row_i][col_i] = tmp;
            }
        }
    }
}

int outerCorner(vector<int> edges) {
    if (edges[0] == 0 && edges[1] == 6) {
        return 3;
    } else if (edges[0] == 2 && edges[1] == 6) {
        return 2;
    } else if (edges[0] == 2 && edges[1] == 4) {
        return 1;
    }
    return 0;
}

string bottomEdge(vector<vector<char>> tile) {
    string edge = "";
    for (int col_i=0; col_i<10; col_i++) {
        edge += tile[9][col_i];
    }
    return edge;
}

string rightEdge(vector<vector<char>> tile) {
    string edge = "";
    for (int row_i=0; row_i<10; row_i++) {
        edge += tile[row_i][9];
    }
    return edge;
}

int countMonsters(vector<vector<char>>& sea) {
    vector<vector<int>> monsterShape = {
        {18},
        {0, 5, 6, 11, 12, 17, 18, 19},
        {1, 4, 7, 10, 13, 16},
    };
    int monsters = 0;
    for (int row_i=0; row_i<(sea.size()-2); row_i++) {
        for (int col_i=0; col_i<(sea[0].size()-19); col_i++) {
            int count = 0;
            for (int mRow_i=0; mRow_i<3; mRow_i++) {
                for (int colIndex: monsterShape[mRow_i]) {
                    if (sea[row_i+mRow_i][col_i+colIndex] == '#') {
                        count++;
                    }
                }
            }
            if (count == 15) {
                monsters++;
            }
        }
    }
    return monsters;
}

int main() {
    int row, col, n;
    cin>>row>>col>>n;

    //scan input & calculate edgeMap
    vector<int> ids(n);
    unordered_map<int, vector<vector<char>>> tileMap;
    unordered_map<int, vector<string>> edgeMap;
    for (int n_i=0; n_i<n; n_i++) {
        //cin a tile & its ID and add to tileMap
        vector<vector<char>> tile(row, vector<char>(col));
        cin>>ids[n_i];
        for (int row_i=0; row_i<row; row_i++) {
            for (int col_i=0; col_i<col; col_i++) {
                cin>>tile[row_i][col_i];
            }
        }
        tileMap[ids[n_i]] = tile;

        //calculate its edges and store in edgeMap
        vector<string> edges;
        string edge = "", revEdge = "";
        for (int row_i=0, col_i=0; col_i<col; col_i++) {
            edge = edge + tile[row_i][col_i];
            revEdge = tile[row_i][col_i] + revEdge;
        }
        edges.push_back(edge);
        edges.push_back(revEdge);
        edge = "", revEdge = "";
        for (int row_i=row-1, col_i=0; col_i<col; col_i++) {
            edge = edge + tile[row_i][col_i];
            revEdge = tile[row_i][col_i] + revEdge;
        }
        edges.push_back(edge);
        edges.push_back(revEdge);
        edge = "", revEdge = "";
        for (int row_i=0, col_i=0; row_i<row; row_i++) {
            edge = edge + tile[row_i][col_i];
            revEdge = tile[row_i][col_i] + revEdge;
        }
        edges.push_back(edge);
        edges.push_back(revEdge);
        edge = "", revEdge = "";
        for (int row_i=0, col_i=col-1; row_i<row; row_i++) {
            edge = edge + tile[row_i][col_i];
            revEdge = tile[row_i][col_i] + revEdge;
        }
        edges.push_back(edge);
        edges.push_back(revEdge);
        edgeMap[ids[n_i]] = edges;
    }

    //find any one corner tile and orient it to be at topLeft
    int topLeftTile;
    for (int n_i=0; n_i<n; n_i++) {
        vector<int> edgesWithoutMatch;
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
                edgesWithoutMatch.push_back(edge_i);
            }
        }
        if (edgesWithoutMatch.size() == 2) {
            rotateAndFlip(tileMap[ids[n_i]], outerCorner(edgesWithoutMatch), "NONE");
            topLeftTile = ids[n_i];
            break;
        }
    }

    //initialize with topLeft tile in place
    int totalRows = 1;
    vector<vector<int>> tileGrid(150, vector<int>(150));
    unordered_set<int> tilesPlaced = { topLeftTile };
    int tileRotation = 0;
    string tileFlip = "NONE";
    tileGrid[0][0] = topLeftTile;

    //place first column of tile IDs
    string edgeToMatch = bottomEdge(tileMap[topLeftTile]);
    for (int row_i=1;;row_i++,totalRows++) {
        bool edgeMatched = false;
        for (int n_j=0; n_j<n; n_j++) {
            if (tilesPlaced.count(ids[n_j]) == 0) {
                for (int edge_j=0; edge_j<8; edge_j++) {
                    if (edgeMap[ids[n_j]][edge_j] == edgeToMatch) {
                        switch (edge_j) {
                            case 0:
                                tileRotation = 0;
                                tileFlip = "NONE";
                                break;
                            case 1:
                                tileRotation = 0;
                                tileFlip = "VERTICAL_AXIS";
                                break;
                            case 2:
                                tileRotation = 2;
                                tileFlip = "VERTICAL_AXIS";
                                break;
                            case 3:
                                tileRotation = 2;
                                tileFlip = "NONE";
                                break;
                            case 4:
                                tileRotation = 1;
                                tileFlip = "VERTICAL_AXIS";
                                break;
                            case 5:
                                tileRotation = 1;
                                tileFlip = "NONE";
                                break;
                            case 6:
                                tileRotation = 3;
                                tileFlip = "NONE";
                                break;
                            case 7:
                                tileRotation = 3;
                                tileFlip = "VERTICAL_AXIS";
                                break;
                        }
                        tileGrid[row_i][0] = ids[n_j];
                        tilesPlaced.insert(ids[n_j]);
                        edgeMatched = true;

                        rotateAndFlip(tileMap[ids[n_j]], tileRotation, tileFlip);
                        edgeToMatch = bottomEdge(tileMap[ids[n_j]]);
                        break;
                    }
                }
            }
            if (edgeMatched) {
                break;
            }
        }
        if (!edgeMatched) {
            break;
        }
    }

    //place rest of the tile IDs row by row
    int totalCols = 0;
    for (int row_i=0; row_i<totalRows; row_i++) {
        edgeToMatch = rightEdge(tileMap[tileGrid[row_i][0]]);
        for (int col_i=1;;col_i++) {
            if (row_i == 0) {
                totalCols++;
            }
            bool edgeMatched = false;
            for (int n_j=0; n_j<n; n_j++) {
                if (tilesPlaced.count(ids[n_j]) == 0) {
                    for (int edge_j=0; edge_j<8; edge_j++) {
                        if (edgeMap[ids[n_j]][edge_j] == edgeToMatch) {
                            switch (edge_j) {
                                case 0:
                                    tileRotation = 3;
                                    tileFlip = "HORIZONTAL_AXIS";
                                    break;
                                case 1:
                                    tileRotation = 3;
                                    tileFlip = "NONE";
                                    break;
                                case 2:
                                    tileRotation = 1;
                                    tileFlip = "NONE";
                                    break;
                                case 3:
                                    tileRotation = 1;
                                    tileFlip = "HORIZONTAL_AXIS";
                                    break;
                                case 4:
                                    tileRotation = 0;
                                    tileFlip = "NONE";
                                    break;
                                case 5:
                                    tileRotation = 0;
                                    tileFlip = "HORIZONTAL_AXIS";
                                    break;
                                case 6:
                                    tileRotation = 2;
                                    tileFlip = "HORIZONTAL_AXIS";
                                    break;
                                case 7:
                                    tileRotation = 2;
                                    tileFlip = "NONE";
                                    break;
                            }
                            tileGrid[row_i][col_i] = ids[n_j];
                            tilesPlaced.insert(ids[n_j]);
                            edgeMatched = true;

                            rotateAndFlip(tileMap[ids[n_j]], tileRotation, tileFlip);
                            edgeToMatch = rightEdge(tileMap[ids[n_j]]);
                            break;
                        }
                    }
                }
                if (edgeMatched) {
                    break;
                }
            }
            if (!edgeMatched) {
                break;
            }
        }
    }

    //create grid of actual tiles as per grid of IDs
    vector<vector<char>> finalGrid(totalRows*8, vector<char>(totalCols*8, '.'));
    for (int row_i=0; row_i<totalRows; row_i++) {
        for (int col_i=0; col_i<totalCols; col_i++) {
            for (int tileRow_i=0; tileRow_i<8; tileRow_i++) {
                for (int tileCol_i=0; tileCol_i<8; tileCol_i++) {
                    finalGrid[row_i*8 + tileRow_i][col_i*8 + tileCol_i]
                        = tileMap[tileGrid[row_i][col_i]][tileRow_i+1][tileCol_i+1];
                }
            }
        }
    }

    //count monsters in all possible unique positions of the grid
    int monsters = 0;
    monsters += countMonsters(finalGrid);
    rotateAndFlip(finalGrid, 0, "VERTICAL_AXIS");
    monsters += countMonsters(finalGrid);
    rotateAndFlip(finalGrid, 0, "VERTICAL_AXIS");
    rotateAndFlip(finalGrid, 0, "HORIZONTAL_AXIS");
    monsters += countMonsters(finalGrid);
    rotateAndFlip(finalGrid, 0, "VERTICAL_AXIS");
    monsters += countMonsters(finalGrid);
    rotateAndFlip(finalGrid, 0, "VERTICAL_AXIS");
    rotateAndFlip(finalGrid, 0, "HORIZONTAL_AXIS");

    rotateAndFlip(finalGrid, 1, "NONE");
    monsters += countMonsters(finalGrid);
    rotateAndFlip(finalGrid, 0, "VERTICAL_AXIS");
    monsters += countMonsters(finalGrid);
    rotateAndFlip(finalGrid, 0, "VERTICAL_AXIS");
    rotateAndFlip(finalGrid, 0, "HORIZONTAL_AXIS");
    monsters += countMonsters(finalGrid);
    rotateAndFlip(finalGrid, 0, "VERTICAL_AXIS");
    monsters += countMonsters(finalGrid);
    rotateAndFlip(finalGrid, 0, "VERTICAL_AXIS");
    rotateAndFlip(finalGrid, 0, "HORIZONTAL_AXIS");

    //count total hash count
    ll hashCount = 0;
    for (int row_i=0; row_i<totalRows*8; row_i++) {
        for (int col_i=0; col_i<totalCols*8; col_i++) {
            hashCount += finalGrid[row_i][col_i] == '#';
        }
    }

    cout<<"Monsters: "<<monsters<<endl;
    cout<<"Hash count: "<<hashCount<<endl;
    cout<<"Hash count without monsters: "<<(hashCount - monsters*15)<<endl;
	return 0;
}
