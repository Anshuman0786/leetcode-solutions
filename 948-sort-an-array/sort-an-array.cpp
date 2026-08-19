class Solution {
public:
    

    void Conquer(vector<int>& nums,int low,int mid,int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low; i <= high; i++)
        {
            nums[i] = temp[i-low];
        }
    }


    void Divide(vector<int>& nums,int low,int high)
    {
        if(low >= high) return;
        int mid = low + (high - low)/2;
        Divide(nums,low,mid);
        Divide(nums,mid+1,high);
        Conquer(nums,low,mid,high);
    }





    vector<int> sortArray(vector<int>& nums) {
        Divide(nums,0,nums.size()-1);
        return nums;
    }
};