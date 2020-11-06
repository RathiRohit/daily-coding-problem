class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            unordered_set<int> numSet;
            vector<int> permute;
            vector<vector<int>> ans;
            
            recur(nums, permute, numSet, ans);
            return ans;
        }
    
        void recur(
            vector<int> nums,
            vector<int>& permute,
            unordered_set<int>& numSet,
            vector<vector<int>>& ans
        ) {
            if (numSet.size() == nums.size()) {
                vector<int> newPermute(permute.begin(), permute.end());
                ans.push_back(newPermute);
                return;
            }
            
            for (int num: nums) {
                if (numSet.count(num) == 0) {
                    numSet.insert(num);
                    permute.push_back(num);
                    
                    recur(nums, permute, numSet, ans);
                    
                    permute.pop_back();
                    numSet.erase(num);
                }
            }
        }
};
