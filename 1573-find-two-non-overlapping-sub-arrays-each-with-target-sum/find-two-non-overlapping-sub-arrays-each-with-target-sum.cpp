class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> dp(n, INF);

        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefix = 0;
        int ans = INF;
        int best = INF;

        for (int i = 0; i < n; i++) {
            prefix += arr[i];

            // If prefix - target exists,
            // subarray from mp[prefix-target]+1 to i has sum target
            if (mp.find(prefix - target) != mp.end()) {

                int j = mp[prefix - target];

                int len = i - j;

                // Previous subarray must end before j
                if (j >= 0 && dp[j] != INF) {
                    ans = min(ans, len + dp[j]);
                }

                // This is the best subarray ending at or before i
                best = min(best, len);
            }

            // Store minimum subarray length found so far
            if (i == 0)
                dp[i] = best;
            else
                dp[i] = min(dp[i - 1], best);

            mp[prefix] = i;
        }

        return ans == INF ? -1 : ans;
    }
};