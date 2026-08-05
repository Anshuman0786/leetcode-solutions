class Solution {
public:

    bool isStringPalindrome(const string& s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false; // Characters mismatch
            }
            left++;
            right--;
        }
        return true; // All characters matched
    }

    void solve(string& s, vector<vector<bool>>& isPalindrome, vector<int>& dp) {
        int n = s.size();

        // build isPalindrome table for substrings of increasing length
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true; // single char is always palindrome
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2) {
                        isPalindrome[i][j] = true;
                    } else {
                        isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                    }
                }
            }
        }

        // fill dp[i] = minimum cuts needed for s[0..i]
        for (int i = 0; i < n; i++) {
            if (isPalindrome[0][i]) {
                dp[i] = 0; // whole prefix is already a palindrome
            } else {
                dp[i] = INT_MAX;
                for (int j = 0; j < i; j++) {
                    if (isPalindrome[j + 1][i] && dp[j] != INT_MAX) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        solve(s, isPalindrome, dp);

        return dp[n - 1];
    }
};