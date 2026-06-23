class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> up(m), down(m);

        for (int i = 0; i < m; i++) {
            up[i] = i;             
            down[i] = m - i - 1;   
        }

        // Hoist these allocations OUTSIDE the loop to avoid MLE
        vector<long long> prefUp(m + 1, 0), prefDown(m + 1, 0);
        vector<long long> newUp(m), newDown(m);

        for (int len = 3; len <= n; len++) {
            // Compute prefix sums in place
            for (int i = 0; i < m; i++) {
                prefUp[i + 1] = (prefUp[i] + up[i]) % MOD;
                prefDown[i + 1] = (prefDown[i] + down[i]) % MOD;
            }

            for (int i = 0; i < m; i++) {
                newUp[i] = prefDown[i];
                newDown[i] = (prefUp[m] - prefUp[i + 1] + MOD) % MOD;
            }

            // Efficiently swap buffers without allocation overhead
            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return ans;
    }
};
