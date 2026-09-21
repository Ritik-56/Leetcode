class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at the
        // previous position whose product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);

            int rem = num % k;

            // Start a new subarray with only num
            newDp[rem]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                int newRem = (r * rem) % k;
                newDp[newRem] += dp[r];
            }

            // Add all subarrays ending here to answer
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};