class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;   // no need to pre-size with values

        for (int i = 0; i < n; i++) {
            if (mp[nums[i]] != 0) {
                return nums[i];
            }
            mp[nums[i]] = 5;
        }
        return -1;
    }
};