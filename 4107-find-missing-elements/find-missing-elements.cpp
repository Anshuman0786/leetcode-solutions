class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        unordered_map<int,bool> mp;
        vector<int> miss;

        for(int x : nums)
        {
            mp[x] = true;
        }

        for(int i = mn; i <= mx; i++)
        {
            if(mp[i] == false)
            {
                miss.push_back(i);
            }
        }
        return miss;
    }
};