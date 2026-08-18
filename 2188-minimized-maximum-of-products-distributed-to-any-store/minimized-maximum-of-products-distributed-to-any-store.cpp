class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        int answer = high; // fallback, though loop will always find something valid

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int storesNeeded = 0;
            for(int q : quantities)
            {
                storesNeeded += (q + mid - 1) / mid;
            }

            if(storesNeeded <= n)
            {
                answer = mid;   // mid works, record it
                high = mid - 1; // try smaller
            }
            else
            {
                low = mid + 1;  // mid too small, need bigger cap
            }
        }
        return answer;
    }
};  