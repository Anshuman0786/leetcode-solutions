class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ones = count(students.begin(), students.end(), 1);
        int zeros = students.size() - ones;
        
        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 0) {
                if (zeros == 0) break;
                zeros--;
            } else {
                if (ones == 0) break;
                ones--;
            }
        }
        
        return zeros + ones;
    }
};