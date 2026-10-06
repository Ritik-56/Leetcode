class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
                count++;
            }
            else if(!st.empty() && st.top() == '(' && s[i] == ')') {
                st.pop();
                count--;
            }
            else {
                st.push(s[i]);
                count++;
            }
        }

        return count;
    }
};