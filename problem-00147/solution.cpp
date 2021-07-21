class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int size = nums.size();
            
            sort(nums.begin(), nums.end());
            int minPossibleSum = nums[0] + nums[1] + nums[2];
            int maxPossibleSum = nums[size - 1] + nums[size - 2] + nums[size - 3];
            int maxPossibleDiff = max(abs(target - minPossibleSum), abs(target - maxPossibleSum));
            
            unordered_map<int, int> hash;
            for (int nums_i=0; nums_i<size; nums_i++) {
                if (hash.count(nums[nums_i]) == 0) {
                    hash[nums[nums_i]] = 0;
                }
                hash[nums[nums_i]]++;
            }
            
            for (int diff=0; diff<=maxPossibleDiff; diff++) {
                for (int nums_i=0; nums_i<size-2; nums_i++) {
                    for (int nums_j=nums_i+1; nums_j<size-1; nums_j++) {
                        int preSum = nums[nums_i] + nums[nums_j];
                        hash[nums[nums_i]]--;
                        hash[nums[nums_j]]--;


                        int newTarget = (target + diff) - preSum;
                        if ((hash.count(newTarget) > 0) && (hash[newTarget] > 0)) {
                            return newTarget + preSum;
                        }
                        newTarget = (target - diff) - preSum;
                        if ((hash.count(newTarget) > 0) && (hash[newTarget] > 0)) {
                            return newTarget + preSum;
                        }


                        hash[nums[nums_i]]++;
                        hash[nums[nums_j]]++;
                    }
                }
            }
            
            return 0;
        }
};
