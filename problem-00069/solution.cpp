class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int currentRed = 0;
            int currentBlue = nums.size() - 1;

            for (int nums_i = 0; nums_i < nums.size() && nums_i <= currentBlue; nums_i++) {
                if (nums[nums_i] == 0) {
                    int tmp = nums[nums_i];
                    nums[nums_i] = nums[currentRed];
                    nums[currentRed] = tmp;
                    if (currentRed != nums_i)
                        nums_i--;
                    currentRed++;
                } else if (nums[nums_i] == 2) {
                    int tmp = nums[nums_i];
                    nums[nums_i] = nums[currentBlue];
                    nums[currentBlue] = tmp;
                    if (currentBlue != nums_i)
                        nums_i--;
                    currentBlue--;
                }
            }
        }
};
