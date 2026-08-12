class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int n = nums.size();
        unordered_map<int,int> mp;
        int l_sub = 0;
        int start = 0;
        int end = 0;
        for (int i=0;i<n;i++)
        {
            mp[nums[i]]=mp[nums[i]]+1;
            l_sub++;
            end++;
            
            while(mp[nums[i]]>k)
            {
                l_sub--;
                mp[nums[start]]=mp[nums[start]]-1;
                start++;
            }
            if(ans<l_sub)
            {
                ans=l_sub;
            }
        }
        return ans;
    }
};