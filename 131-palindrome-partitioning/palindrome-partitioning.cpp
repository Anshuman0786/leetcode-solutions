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

    void solve(string& s, int index, vector<string>& path, vector<vector<string>>& result) {
        // base case: reached end of string, path is a valid partition
        if (index == s.size()) {
            result.push_back(path);
            return;
        }

        for (int end = index; end < s.size(); end++) {
            string sub = s.substr(index, end - index + 1);

            if (isStringPalindrome(sub)) {
                // take
                path.push_back(sub);
                solve(s, end + 1, path, result);
                // not take (backtrack)
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        solve(s, 0, path, result);
        return result;
    }
};