class Solution {
public:
    void solve(int start, vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& temp)
    {
        if(target == 0) { result.push_back(temp); return; }

        for(int i = start; i < candidates.size(); i++)
        {
            if(candidates[i] > target) break; 
            if(i > start && candidates[i] == candidates[i-1]) continue;

            temp.push_back(candidates[i]);
            solve(i+1, candidates, target - candidates[i], result, temp); 
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(0, candidates, target, result, temp);
        return result;
    }
};