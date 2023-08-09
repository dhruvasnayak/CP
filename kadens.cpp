#include <vector>  
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int sum = 0;
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < 0) {
                sum = 0;
            }
            if (sum > max) {
                max = sum;
            }
        }
        
        if (max > 0)
            return max;
        else
            return *std::max_element(nums.begin(), nums.end());
    }
};
