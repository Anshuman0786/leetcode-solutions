class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> present(mx - mn + 1, false);
        for (int x : nums) {
            present[x - mn] = true;
        }

        vector<int> miss;
        for (int i = 0; i < (int)present.size(); i++) {
            if (!present[i]) {
                miss.push_back(mn + i);
            }
        }
        return miss;
    }
};