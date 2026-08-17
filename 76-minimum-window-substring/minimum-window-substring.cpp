class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";

        int mp[128] = {0};
        for (char c : t) {
            mp[c]++;
        }

        int start = 0, minLen = INT_MAX, startIndex = 0;
        int counter = t.size();

        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] > 0) {
                counter--;
            }
            mp[s[i]]--;

            while (counter == 0) {
                if (i - start + 1 < minLen) {
                    minLen = i - start + 1;
                    startIndex = start; 
                }

                mp[s[start]]++;
                if (mp[s[start]] > 0) {
                    counter++;
                }
                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};