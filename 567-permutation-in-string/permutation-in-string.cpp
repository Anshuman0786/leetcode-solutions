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
            ch2[s2[i]-'a']++;                       // add current char first

            if(i >= s1.size())
            {
                ch2[s2[i-s1.size()]-'a']--;          // remove char sliding out of window
            }

            if(i >= s1.size()-1)                     // window has reached full size
            {
                bool equal = true;
                for(int k=0;k<26;k++)                // manual comparison, since arrays can't use ==
                {
                    if(ch[k]!=ch2[k]) { equal=false; break; }
                }
                if(equal) return true;
            }
        }
        return false;                                 // added: fallback if no match found
    }
};