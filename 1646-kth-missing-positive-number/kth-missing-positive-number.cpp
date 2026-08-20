class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int j = 1;
        int count = 0;
        while (true)
        {
            if (i < arr.size() && arr[i] == j)
            {
                i++;
            }
            else
            {
                count++;
                if (count == k)
                {
                    return j;
                }
            }
            j++;
        }
    }
};