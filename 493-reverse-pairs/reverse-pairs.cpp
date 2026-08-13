class Solution {
public:

    void countAndMerge(vector<int>& nums, int l, int m, int r, int& count)
    {
        // two-pointer sweep to count reverse pairs across the two halves
        int j = m + 1;
        for (int i = l; i <= m; i++) {
            while (j <= r && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (m + 1));
        }

        // merge step to keep [l..r] sorted
        vector<int> temp;
        int i = l, k = m + 1;
        while (i <= m && k <= r) {
            if (nums[i] <= nums[k]) temp.push_back(nums[i++]);
            else temp.push_back(nums[k++]);
        }
        while (i <= m) temp.push_back(nums[i++]);
        while (k <= r) temp.push_back(nums[k++]);

        for (int idx = l; idx <= r; idx++) {
            nums[idx] = temp[idx - l];
        }
    }

    void mergesort(vector<int>& nums, int l, int r, int& count)
    {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergesort(nums, l, m, count);
        mergesort(nums, m + 1, r, count);
        countAndMerge(nums, l, m, r, count);
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergesort(nums, 0, nums.size() - 1, count);
        return count;
    }
};