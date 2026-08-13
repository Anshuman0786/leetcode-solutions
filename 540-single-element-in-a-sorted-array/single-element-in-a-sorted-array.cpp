class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(left==right) return nums[left];

            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1])
                {
                    //culprit is in right side
                    left = mid+1;
                }
                else
                {
                    //culprit is in left side
                    right = mid;
                }
            }
            else
            {
                if(nums[mid]==nums[mid+1])
                {
                    //culprit is in left side
                    right = mid;
                }
                else
                {
                    //culprit is in right side
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};