class Solution {
public:
    int solve(int index1, int index2, string& text1, string& text2, vector<vector<int>>& dp)
    {
        // Base case: if either string is exhausted, no more characters to match
        if (index1 == text1.size() || index2 == text2.size())
            return 0;

        // Return memoized result if already computed
        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (text1[index1] == text2[index2])
        {
            // Characters match: take this character, move both pointers forward
            dp[index1][index2] = 1 + solve(index1 + 1, index2 + 1, text1, text2, dp);
        }
        else
        {
            // Characters don't match: try skipping one char from either string, take the best
            int skip1 = solve(index1 + 1, index2, text1, text2, dp);
            int skip2 = solve(index1, index2 + 1, text1, text2, dp);
            dp[index1][index2] = max(skip1, skip2);
        }

        return dp[index1][index2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return solve(0, 0, text1, text2, dp);
    }
};