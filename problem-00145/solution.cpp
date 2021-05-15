class Solution {
    private:
        vector<vector<int>> grid;
        vector<vector<int>> memo;

        int recur(int row, int col) {
            if (row >= this->grid.size() || col >= this->grid[0].size()) {
                return INT_MAX;
            }

            if (this->memo[row][col] != -1) {
                return this->memo[row][col];
            }

            this->memo[row][col] = grid[row][col] + min(recur(row, col+1), recur(row+1, col));
            return this->memo[row][col];
        }
    public:
        int minPathSum(vector<vector<int>>& grid) {
            this->grid = grid;
            this->memo = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));
            this->memo[grid.size() - 1][grid[0].size() - 1] = grid[grid.size() - 1][grid[0].size() - 1];
            return recur(0, 0);
        }
};
