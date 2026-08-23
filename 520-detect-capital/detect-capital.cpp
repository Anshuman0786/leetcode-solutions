class Solution {
public:
    bool detectCapitalUse(string word) {
        int countUpper = 0;
        for (char c : word) {
            if (isupper(c)) countUpper++;
        }
        
        if (countUpper == word.size()) return true;
        if (countUpper == 0) return true;
        if (countUpper == 1 && isupper(word[0])) return true;
        
        return false;
    }
};