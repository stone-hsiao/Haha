#include <bits/stdc++.h>
 
#define int long long
using namespace std;
const int N = 105;
int fact[N * N], inv_fact[N * N];
const int M = (int) 1e9 + 7;
 
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
 
unordered_map<int, int> info;
const int B = 10007;
 
int xd(int n, int m, int c) {
    if (m < c || m > n * c) return 0;
    if (n == 1) return (m == c);
    if (info.find(n*B*B+m*B+c) != info.end())return info[n*B*B+m*B+c];
    int ans = 0;
    for (int k = 0; k <= c; k++) {
        ans += xd(n - 1, m - k, c) * C(k, c) % M;
    }
    ans %= M;
    return info[n*B*B+m*B+c] = ans;
}
 
void solve() {
    int n, c, m;
    cin >> n >> c >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    cout << xd(n, m, c) << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = inv_fact[0] = 1;
    for (int x = 1; x < N * N; x++) {
        fact[x] = ((x * fact[x - 1]) % M);
        inv_fact[x] = binpow(fact[x], M - 2);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
