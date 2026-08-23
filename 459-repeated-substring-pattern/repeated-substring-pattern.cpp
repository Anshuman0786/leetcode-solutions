class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int len = 1; len <= n / 2; len++) {
            if (n % len == 0) {
                string sub = s.substr(0, len);
                string built = "";
                for (int i = 0; i < n / len; i++) {
                    built += sub;
                }
                if (built == s) return true;
            }
        }
        return false;
    }
};