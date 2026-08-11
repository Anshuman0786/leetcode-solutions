class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;


deque<int> dq;  // stores indices

    for (int i = 0; i < nums.size(); i++) {
        // remove indices out of window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // remove smaller elements from back — they're useless
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

            dq.push_back(i);

        // front is the max once window has size k
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
        }
        return ans;


    }
};