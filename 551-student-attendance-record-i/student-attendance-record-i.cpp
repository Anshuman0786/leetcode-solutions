class Solution {
public:
    bool checkRecord(string s) {
        int countAbsent = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                countAbsent++;
                if (countAbsent >= 2) return false;
            }
            if (i >= 2 && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L') {
                return false;
            }
        }
        
        return true;
    }
};