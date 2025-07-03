#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll dp[20][2][10][2];
bool seen[20][2][10][2];
string S;
int gcd_table[10][10];

ll dfs(int pos, int tight, int g, int z) {
    if (pos == S.size()) {
        if (g == 0) return 0;
        return z ? 0 : g;
    }
    if (seen[pos][tight][g][z])
        return dp[pos][tight][g][z];
    seen[pos][tight][g][z] = true;

    ll ans = 0;
    int limit = tight ? (S[pos] - '0') : 9;
    for (int d = 0; d <= limit; d++) {
        int nt = tight && (d == limit);
        int ng = g, nz = z;

        if (g == 0) {
            if (d > 0) ng = d;
        } else {
            if (d == 0)
                nz = 1;
            else
                ng = gcd_table[g][d];
        }

        ans = (ans + dfs(pos + 1, nt, ng, nz)) % MOD;
    }

    return dp[pos][tight][g][z] = ans;
}

ll sum_upto(ll X) {
    if (X < 0) return 0;
    S = to_string(X);
    memset(seen, 0, sizeof(seen));
    return dfs(0, 1, 0, 0);
}

ll SubsequenceGCD(long long L, long long R) {
    for (int i = 1; i < 10; i++)
        for (int j = 1; j < 10; j++)
            gcd_table[i][j] = __gcd(i, j);
    ll ans = (sum_upto(R) - sum_upto(L - 1)) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}
