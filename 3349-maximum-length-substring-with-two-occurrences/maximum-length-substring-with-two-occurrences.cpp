class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        int start = 0;
        int max_len=0;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            while(mp[s[i]]>2)
            {
                mp[s[start]]--;
                start++;
            }
            max_len = max(max_len, i - start + 1);
        }
        return max_len;
    }
};