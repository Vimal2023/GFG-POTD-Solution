class Solution {
public:
    int mod = 1e9 + 7;

    int TotalWays(int N) {
        long long curr, prev, next;
        curr = prev = 1;
        for (int i = 1; i <= N; ++i) {
            next = (curr + prev) % mod;
            prev = curr;
            curr = next;
        }

        return (curr * curr) % mod;
    }
};
