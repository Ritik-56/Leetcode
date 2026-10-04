class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        const long long NEG = LLONG_MIN / 4;

        vector<long long> plus0(n, NEG);
        vector<long long> minus0(n, NEG);
        vector<long long> plus1(n, NEG);
        vector<long long> minus1(n, NEG);

        // No deletion
        plus0[0] = nums[0];

        for (int i = 1; i < n; i++) {
            plus0[i] = max(
                (long long)nums[i],
                minus0[i - 1] + nums[i]
            );

            minus0[i] = plus0[i - 1] - nums[i];
        }

        // One deletion
        for (int i = 2; i < n; i++) {

            // Delete nums[i-1]
            // OR deletion happened earlier
            plus1[i] = max(
                minus1[i - 1] + nums[i],
                minus0[i - 2] + nums[i]
            );

            minus1[i] = max(
                plus1[i - 1] - nums[i],
                plus0[i - 2] - nums[i]
            );
        }

        long long ans = NEG;

        for (int i = 0; i < n; i++) {
            ans = max(ans, plus0[i]);
            ans = max(ans, minus0[i]);
            ans = max(ans, plus1[i]);
            ans = max(ans, minus1[i]);
        }

        return ans;
    }
};