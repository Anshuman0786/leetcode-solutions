class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int ch[26] = {0};
        int ch2[26] = {0};
        for(int i=0;i<s1.size();i++)
        {
            ch[s1[i]-'a']++;
        }

        for(int i=0 ; i<s2.size() ; i++)
        {
            ch2[s2[i]-'a']++; 
            if(i >= s1.size())
            {
                ch2[s2[i-s1.size()]-'a']--;   
            }

            if(i >= s1.size()-1)       
            {
                bool equal = true;
                for(int k=0;k<26;k++)
                {
                    if(ch[k]!=ch2[k]) { equal=false; break; }
                }
                if(equal) return true;
            }
        }
        return false;
    }
};