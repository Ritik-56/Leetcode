class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int count = 0;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(') {
                st.push('(');
            }
            else {
                if(i + 1 < s.length() && s[i + 1] == ')') {
                    // We have a pair of closing brackets ))
                    i++;
                }
                else {
                    // Only one ), insert another )
                    count++;
                }

                if(!st.empty()) {
                    st.pop();
                }
                else {
                    // No opening bracket, insert (
                    count++;
                }
            }
        }

        return count + 2 * st.size();
    }
};