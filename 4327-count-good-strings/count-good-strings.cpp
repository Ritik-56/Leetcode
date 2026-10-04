class Solution {
public:
    using ll = long long;

    const ll MOD = 1000000007LL;

    pair<ll, ll> fib(ll n) {
        // {F(n), F(n+1)}
        if (n == 0)
            return {0, 1};

        auto [a, b] = fib(n / 2);

        ll c = a * ((2 * b % MOD - a + MOD) % MOD) % MOD;
        ll d = (a * a % MOD + b * b % MOD) % MOD;

        if (n % 2 == 0)
            return {c, d};

        return {d, (c + d) % MOD};
    }

    int countGoodStrings(long long n) {
        return (2LL * fib(n).first) % MOD;
    }
};