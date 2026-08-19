class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& temp, set<vector<int>>& result)
    {
        result.insert(temp);
        if(index >= nums.size()) return;

        temp.push_back(nums[index]);
        solve(nums, index+1, temp, result); 
        temp.pop_back();

        solve(nums, index+1, temp, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // add this
    set<vector<int>> result;
    vector<int> temp;
    solve(nums, 0, temp, result);
    return vector<vector<int>>(result.begin(), result.end());
    }
};