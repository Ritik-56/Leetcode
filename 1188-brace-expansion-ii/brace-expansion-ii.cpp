class Solution {
public:

    set<string> solve(string &s, int &i) {
        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union current with result
                result.insert(current.begin(), current.end());
                current = {""};
                i++;
            }
            else if (s[i] == '{') {
                i++; // skip '{'

                set<string> inside = solve(s, i);

                // concatenate current with inside
                set<string> temp;

                for (string a : current) {
                    for (string b : inside) {
                        temp.insert(a + b);
                    }
                }

                current = temp;

                i++; // skip '}'
            }
            else {
                // Normal character
                set<string> temp;

                for (string x : current) {
                    temp.insert(x + s[i]);
                }

                current = temp;
                i++;
            }
        }

        // Add last concatenation group
        result.insert(current.begin(), current.end());

        return result;
    }

public:
    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};