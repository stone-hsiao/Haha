#include <stdio.h>
#define int long long
#define N 105

const int M=1e9+7;

int n, c, m;
int fact[N * N];
int inv_fact[N * N];
int dp[N][N * N];

// 快速冪
int binpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x % 2)  ans = (ans * a) % M;
        a = (a * a) % M;
        x /= 2;
    }
    return ans;
}

// 組合數
int C(int k, int n) {
    if (k > n || k < 0) return 0;
    return (((fact[n] * inv_fact[k]) % M) * inv_fact[n - k]) % M;
}

// 遞迴 + 記憶化
int xd(int n, int m, int c) {
    if (m < c || m > n * c) return 0;
    if (n == 1) return (m == c);
    if (dp[n][m]!=-1) return dp[n][m];

    int ans = 0;
    for (int k = 0; k <= c; k++) {
        ans = (ans + xd(n - 1, m - k, c) * C(k, c)) % M;
    }
    dp[n][m] = ans % M;
    return ans;
}

void solve() {
    scanf("%lld %lld %lld", &n, &c, &m);

    // 清空記憶化表
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n * c; j++) {
            dp[i][j] = -1;
        }
    }

    printf("%lld\n", xd(n, m, c));
}

signed main() {
    fact[0] = inv_fact[0] = 1;
    for (int x = 1; x < N * N; x++) {
        fact[x] = (x * fact[x - 1]) % M;
        inv_fact[x] = binpow(fact[x], M - 2);
    }

    int t;
    scanf("%lld", &t);
    while (t--) {
        solve();
    }
    return 0;
}
