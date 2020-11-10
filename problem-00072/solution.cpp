class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int pivot = -1;
            int ansIndex = -1;
            
            if (nums.size() == 0) {
                return -1;
            }
            
            if (nums.size() == 1) {
                if (nums[0] == target) {
                    return 0;
                }
                return -1;
            }
            
            if (nums[0] < nums[nums.size() - 1]) {
                pivot = 0;
            } else {
                int left = 0;
                int right = nums.size() - 1;
                
                while(left <= right) {
                    if (nums[left] > nums[right]) {
                        pivot = right;
                    } else if (nums[left] < nums[right]) {
                        if (nums[left] < nums[pivot]) {
                            pivot = left;
                        }
                        break;
                    } else {
                        if (nums[left] < nums[pivot]) {
                            pivot = left;
                        }
                        break;
                    }
                    
                    left++;
                    right--;
                }
            }
            
            int left = 0;
            int right = pivot - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                
                if (nums[mid] == target) {
                    ansIndex = mid;
                    break;
                }
                
                if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            if (ansIndex != -1) {
                return ansIndex;
            }
            
            left = pivot;
            right = nums.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                
                if (nums[mid] == target) {
                    ansIndex = mid;
                    break;
                }
                
                if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            return ansIndex;
        }
};
