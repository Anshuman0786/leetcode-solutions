class Solution {
public:

    void solve(int index,vector<int>& candidates, int target,vector<vector<int>>& result,vector<int>& temp,int sum)
    {
        if(index >= candidates.size()) return;
        if(sum > target) return;
        if(sum == target) {result.push_back(temp); return;}
        temp.push_back(candidates[index]);
        solve(index, candidates, target, result, temp, sum + candidates[index]);
        temp.pop_back(); 

        solve(index+1, candidates, target, result, temp, sum); 
        }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(0,candidates,target,result,temp,0);
        return result;
    }
};