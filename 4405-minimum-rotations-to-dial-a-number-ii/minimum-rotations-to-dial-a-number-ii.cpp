class Solution {
public:
    int dist(int a, int b) {
        int diff = abs(a - b);
        return min(diff, 10 - diff);
    }

    int minRotations(int n, string s) {
        int ans = dist(0, s[0] - '0');

        for (int i = 1; i < n; i++) {
            ans += dist(s[i - 1] - '0', s[i] - '0');
        }

        int original = ans;

        // Reverse suffix starting from index 0
        ans = min(ans,
                  original
                  - dist(0, s[0] - '0')
                  + dist(0, s[n - 1] - '0'));

        // Reverse suffix starting from index k
        for (int k = 1; k < n; k++) {
            int curr = original
                     - dist(s[k - 1] - '0', s[k] - '0')
                     + dist(s[k - 1] - '0', s[n - 1] - '0');

            ans = min(ans, curr);
        }

        return ans;
    }
};