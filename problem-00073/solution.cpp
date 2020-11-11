class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
            return uniques(m, n, memo);
        }
    
        int uniques(int m, int n, vector<vector<int>>& memo) {
            if (memo[m][n] != 0) {
                return memo[m][n];
            }
            
            if (m == 1 && n == 1) {
                return 1;
            }
            
            int ways = 0;
            if (m > 1) {
                ways += uniques(m - 1, n, memo);
            }
            if (n > 1) {
                ways += uniques(m, n - 1, memo);
            }
            
            memo[m][n] = ways;
            return ways;
        }
};
