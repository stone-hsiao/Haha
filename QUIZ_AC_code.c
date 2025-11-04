#include <stdio.h>
#include <stdlib.h>

#define int long long
#define N 105

int fact[N * N], inv_fact[N * N];
const int M = (int)1e9 + 7;

int binpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x % 2) {
            ans *= a;
            ans %= M;
        }
        a *= a;
        a %= M;
        x /= 2;
    }
    return ans;
}

int C(int k, int n) {
    if (k > n || k < 0) return 0;
    return (((fact[n] * inv_fact[k]) % M) * inv_fact[n - k] % M);
}

void solve() {
    int n, c, m;
    scanf("%lld %lld %lld", &n, &c, &m);

    int a[m + 1];
    int last[n + 1];
    int cnt[n + 1];

    for (int i = 0; i <= n; i++) {
        last[i] = 0;
        cnt[i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        scanf("%lld", &a[i]);
        if (a[i] != 0) {
            last[a[i]] = i;
            cnt[a[i]]++;
        }
    }

    int **more_on_prefix = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        more_on_prefix[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++)
            more_on_prefix[i][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int el = 1; el <= n; el++) {
            more_on_prefix[i][el] = more_on_prefix[i - 1][el] + (a[i] >= el);
        }
    }

    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((m + 1) * sizeof(int));
        for (int j = 0; j <= m; j++)
            dp[i][j] = 0;
    }

    dp[0][0] = 1;

    for (int el = 1; el <= n; el++) {
        for (int sum = 0; sum <= m; sum++) {
            dp[el][sum] = 0;
            for (int x = 0; x <= c; x++) {
                if (sum < x)
                    continue;
                if (last[el] > c + sum - x)
                    continue;
                if (x < cnt[el])
                    continue;
                if (c + sum - x > m)
                    continue;

                int free_spots = c - more_on_prefix[c + sum - x][el];
                int need_to_put = x - cnt[el];

                dp[el][sum] += (dp[el - 1][sum - x] * C(need_to_put, free_spots)) % M;
                if (dp[el][sum] >= M)
                    dp[el][sum] -= M;
            }
        }
    }

    printf("%lld\n", dp[n][m]);

    // 釋放動態記憶體
    for (int i = 0; i <= m; i++) free(more_on_prefix[i]);
    free(more_on_prefix);
    for (int i = 0; i <= n; i++) free(dp[i]);
    free(dp);
}

signed main() {
    fact[0] = inv_fact[0] = 1;
    for (int x = 1; x < N * N; x++) {
        fact[x] = ((x * fact[x - 1]) % M);
        inv_fact[x] = binpow(fact[x], M - 2);
    }

    int t;
    scanf("%lld", &t);
    while (t--) {
        solve();
    }
    return 0;
}
