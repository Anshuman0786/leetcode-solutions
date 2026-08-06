class Solution {
public:
    int numTrees(int n) {
        long long result = 1;
        
        for (int i = 1; i <= n; ++i) {
            // Multiply by the numerator term and divide by the denominator term progressively
            result = result * (n + i) / i;
        }
        
        return (int)(result / (n + 1));
    }
};
