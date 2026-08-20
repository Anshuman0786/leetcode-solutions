class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        int count = 0;
        bool hasOdd = false;
        for(auto& [key, value] : mp)
        {
            count += (value/2)*2;
            if(value % 2 != 0)
            {
                hasOdd = true;
            }
        }
        if(hasOdd) count++;
        return count;
    }
};