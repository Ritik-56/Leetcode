
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> freq(100001, 0);

        long long maxDiff = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            maxDiff = max(maxDiff, d);
        }

        for (int d = maxDiff; d > 0 && k > 0; d--) {
            long long count = freq[d];
            if (count == 0) continue;

            long long nextCount = freq[d - 1];
            long long cost = count * (d - (d - 1));

            // Can we reduce all differences at d by one?
            if (k >= count) {
                k -= count;
                freq[d - 1] += count;
                freq[d] = 0;
            } else {
                // Reduce only k of them by one
                freq[d] -= k;
                freq[d - 1] += k;
                k = 0;
            }
        }

        long long ans = 0;

        for (int d = 1; d <= 100000; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};
