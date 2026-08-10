class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);   // start with the first interval

        for (int i = 1; i < intervals.size(); i++) {
            // compare current interval with the last one pushed into result
            if (intervals[i][0] <= result.back()[1]) {
                // overlap -> extend the end of the last merged interval
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // no overlap -> start a new merged interval
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};