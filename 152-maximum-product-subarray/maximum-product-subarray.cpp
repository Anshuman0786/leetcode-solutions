class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            // if curr is negative, swapping max/min before multiplying
            // handles the sign flip correctly
            if (curr < 0) {
                swap(maxEndingHere, minEndingHere);
            }

            maxEndingHere = max(curr, maxEndingHere * curr);
            minEndingHere = min(curr, minEndingHere * curr);

            maxSoFar = max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }
};