class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            if (nums.size() == 1 || nums[0] > nums[1]) {
                return 0;
            }
            
            if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
                return nums.size() - 1;
            }
            
            for (int nums_i = 1; nums_i < (nums.size() - 1); nums_i++) {
                if (nums[nums_i + 1] < nums[nums_i]) {
                    if (nums[nums_i - 1] < nums[nums_i]) {
                        return nums_i;
                    }
                    nums_i++;
                }
            }
            
            return 0;
        }
};
