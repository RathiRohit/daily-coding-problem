class Solution {
    private:
        int ans = 0;

    public:
        int numIslands(vector<vector<char>> grid) {
            vector<vector<int>> ansGrid(grid.size(), vector<int>(grid[0].size(), 0));

            for (int row = 0; row < grid.size(); row++) {
                for (int col = 0; col < grid[0].size(); col++) {
                    if (ansGrid[row][col] > 0) {
                        continue;
                    }

                    if (grid[row][col] == '1') {
                        markIsland(grid, row, col, ansGrid);
                    }
                }
            }

            return ans;
        }

        void markIsland(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& ansGrid) {
            if (ansGrid[row][col] > 0) {
                return;
            }

            if (grid[row][col] == '1') {
                int islandNumber = 0;

                if (row != 0 && ansGrid[row - 1][col] != 0) {
                    islandNumber = ansGrid[row - 1][col];
                } else if (row != (grid.size() - 1) && ansGrid[row + 1][col] != 0) {
                    islandNumber = ansGrid[row + 1][col];
                } else if (col != 0 && ansGrid[row][col - 1] != 0) {
                    islandNumber = ansGrid[row][col - 1];
                } else if (col != (grid[0].size() - 1) && ansGrid[row][col + 1] != 0) {
                    islandNumber = ansGrid[row][col + 1];
                }

                if (islandNumber == 0) {
                    islandNumber = ++ans;
                }
                ansGrid[row][col] = islandNumber;

                if (row != 0 && ansGrid[row - 1][col] == 0) {
                    markIsland(grid, row - 1, col, ansGrid);
                }
                if (row != (grid.size() - 1) && ansGrid[row + 1][col] == 0) {
                    markIsland(grid, row + 1, col, ansGrid);
                }
                if (col != 0 && ansGrid[row][col - 1] == 0) {
                    markIsland(grid, row, col - 1, ansGrid);
                }
                if (col != (grid[0].size() - 1) && ansGrid[row][col + 1] == 0) {
                    markIsland(grid, row, col + 1, ansGrid);
                }
            }
        }
};
