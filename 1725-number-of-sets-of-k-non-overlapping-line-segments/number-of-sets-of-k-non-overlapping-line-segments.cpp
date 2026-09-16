class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }

    int numberOfSets(int n, int k) {
        int r = 2 * k;

        long long ans = 1;

        // C(n+k-1, 2k)
        for (int i = 1; i <= r; i++) {
            ans = ans * (n + k - i) % MOD;
            ans = ans * power(i, MOD - 2) % MOD;
        }

        return ans;
    }
};