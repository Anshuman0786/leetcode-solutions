class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=i;j<n;j++)
            {
                bool duplicate = false;
                for(int k=i;k<j;k++)      // check s[j] against everything before it in this window
                {
                    if(s[k]==s[j])
                    {
                        duplicate = true;
                        break;
                    }
                }
                if(duplicate) break;
                count++;
            }
            if(count>maxLen) maxLen=count;
        }
        return maxLen;
    }
};