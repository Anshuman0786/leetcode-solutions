#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);  // opening bracket, push it
            } else {
                // closing bracket - check for match
                if (st.empty()) return false;
                
                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop();  // matched, remove from stack
                } else {
                    return false;  // mismatched pair
                }
            }
        }
        
        return st.empty();  // valid only if everything matched
    }
};