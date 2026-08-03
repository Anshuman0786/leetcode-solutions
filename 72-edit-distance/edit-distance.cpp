class Solution {
public:
    int solve(int index1, int index2,string word1, string word2, vector<vector<int>>& dp)
    {
        if (index1==word1.size())
        {
            return word2.size() - index2; // insert remaining chars
        }
        if (index2==word2.size())
        {
            return word1.size() - index1; // delete remaining chars
        }
        if(dp[index1][index2]!=-1)
        {
            return dp[index1][index2];
        }

        if(word1[index1]==word2[index2])
        {
            dp[index1][index2] = solve(index1+1,index2+1,word1,word2,dp);
        }
        else
        {
            //calling all three functions one by one
            int insert1= 1 + solve(index1,index2+1,word1,word2,dp);
            int delete1= 1 + solve(index1+1,index2,word1,word2,dp);
            int replace1= 1 + solve(index1+1,index2+1,word1,word2,dp);
            dp[index1][index2]=min({insert1,delete1,replace1});
        }
        return dp[index1][index2];
    }


    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1,-1));

        return solve(0,0,word1,word2,dp);
    }
};