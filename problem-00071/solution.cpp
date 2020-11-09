class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool
            { 
                return a[0] < b[0]; 
            });
            
            vector<vector<int>> ans;
            pair<int, int> currentInterval(INT_MAX, INT_MIN);
            for (int intervals_i = 0; intervals_i < intervals.size(); intervals_i++) {
                if (
                    intervals[intervals_i][0] <= currentInterval.second ||
                    currentInterval.second == INT_MIN
                ) {
                    currentInterval.first = min(currentInterval.first, intervals[intervals_i][0]);
                    currentInterval.second = max(currentInterval.second, intervals[intervals_i][1]);
                } else {
                    ans.push_back(vector<int>{currentInterval.first, currentInterval.second});
                    currentInterval.first = intervals[intervals_i][0];
                    currentInterval.second = intervals[intervals_i][1];
                }
            }
            
            if (currentInterval.first != INT_MAX) {
                ans.push_back(vector<int>{currentInterval.first, currentInterval.second});
            }
            
            return ans;
        }
};
