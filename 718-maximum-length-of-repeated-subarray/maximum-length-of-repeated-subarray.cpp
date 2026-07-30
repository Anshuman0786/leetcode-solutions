class Solution {
public:
    int solve(int index1, int index2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp)
    {
        // Base case: if either array is exhausted, no more characters to match
        if (index1 == nums1.size() || index2 == nums2.size())
            return 0;

        // Return memoized result if already computed
        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (nums1[index1] == nums2[index2])
        {
            // Characters match: extend the streak by 1, move both pointers forward
            dp[index1][index2] = 1 + solve(index1 + 1, index2 + 1, nums1, nums2, dp);
        }
        else
        {
            // Characters don't match: streak breaks completely here.
            // NO skipping allowed — this pair simply cannot be part of any
            // common subarray that continues past this point.
            dp[index1][index2] = 0;
        }

        return dp[index1][index2];
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, -1));
        int best = 0;

        // Unlike LCS, the answer isn't just solve(0,0) — a matching streak
        // can start at ANY pair of indices, not just the very beginning.
        // So we must call solve() from every starting pair and take the max.
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                best = max(best, solve(i, j, nums1, nums2, dp));
            }
        }

        return best;
    }
};