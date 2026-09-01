class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp;

        int l = 0;
        int maxval = 0;

        for (int i = 0; i < s.length(); i++) {

            if (mp.find(s[i]) != mp.end()) {
                l = max(l, mp[s[i]] + 1);
            }

            mp[s[i]] = i;

            int length = i - l + 1;

            maxval = max(maxval, length);
        }

        return maxval;
    }
};