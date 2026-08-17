class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int i = 0;
        
        while(i < chars.size()) {
            int count = 0;
            int j = i;
            
            while(j < chars.size() && chars[j] == chars[i]) {
                count++;
                j++;
            }
            
            chars[index++] = chars[i];
            
            if(count > 1) {
                string countStr = to_string(count);
                for(char c : countStr) {
                    chars[index++] = c;
                }
            }
            i = j;
        }
        chars.erase(chars.begin() + index, chars.end());
        
        return chars.size();
    }
};