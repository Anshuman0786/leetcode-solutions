class Solution {
public:

    bool solve(int index, int k, vector<int>& stones, vector<vector<int>>& dp)
    {
        // base case: reached the last stone
        if (index == (int)stones.size() - 1)
            return true;

        // memoized already?
        if (dp[index][k] != -1)
            return dp[index][k];

        bool ans = false;

        // for k-1, k, k+1 distance
        for (int jump = k - 1; jump <= k + 1 && !ans; jump++)
        {
            if (jump <= 0) continue; // jump size must be positive

            // find the next stone using linear search (as in your version)
            for (int i = index + 1; i < stones.size(); i++)
            {
                if (stones[i] == stones[index] + jump)
                {
                    if (solve(i, jump, stones, dp))
                    {
                        ans = true;
                    }
                    break; // stones are sorted/unique, no need to keep scanning
                }
            }
        }

        return dp[index][k] = ans;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 0, stones, dp);
    }
};