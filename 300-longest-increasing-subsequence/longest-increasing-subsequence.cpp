class Solution {
public:
    int solve(int index, int prevIndex, vector<int>& nums, vector<vector<int>>& dp)
    {
        if (index == nums.size())
        {
            return 0;
        }

        // shift prevIndex by 1 so we can store -1 case as index 0 in dp
        if (dp[index][prevIndex + 1] != -1)
        {
            return dp[index][prevIndex + 1];
        }

        // option 1: skip current element
        int notTake = solve(index + 1, prevIndex, nums, dp);

        // option 2: take current element, only if it extends the subsequence
        int take = 0;
        if (prevIndex == -1 || nums[index] > nums[prevIndex])
        {
            take = 1 + solve(index + 1, index, nums, dp);
        }

        dp[index][prevIndex + 1] = max(take, notTake);
        return dp[index][prevIndex + 1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, -1, nums, dp);
    }
};