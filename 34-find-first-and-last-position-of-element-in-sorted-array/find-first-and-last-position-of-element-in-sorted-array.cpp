class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left_it = lower_bound(nums.begin(), nums.end(), target);
        
        if (left_it == nums.end() || *left_it != target) {
            return {-1, -1};
        }
        
        auto right_it = upper_bound(nums.begin(), nums.end(), target);
        
        int left_index = left_it - nums.begin();
        int right_index = right_it - nums.begin() - 1;
        
        return {left_index, right_index};
    }
};
