class Solution {
public:
    string reverseWords(string s) {
        int low = s.size() - 1;
        int high = s.size() - 1;
        string result;
        for(int i = s.size()-1 ; i>=0 ; i--)
        {
            if(s[i] == ' ')
            {
                if(low != high)
                {
                    for(int j=low+1;j<=high;j++)     
                    {
                        result.push_back(s[j]);
                    }
                    result.push_back(' ');
                }
                high = i-1;  
            }
            low = i-1;
        }
        if(low != high)
        {
            for(int j=low+1;j<=high;j++)
                result.push_back(s[j]);
        }
        if(!result.empty() && result.back() == ' ')
            result.pop_back();
        return result;
    }
};