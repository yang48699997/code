#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 998244353;
const int N =205;
ll c[N][N];
ll fac[N];
void init() {
    for (int i = 0; i < N; i++) {
        fac[i] = 1;
        for (int j = 0; j < N; j++) {
            c[i][j] = 0;
        }
    }
    c[0][0] = 1;
    for (int i = 1; i < N; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= mod;
        }
    }
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
}
vector<ll> dfs(const vector<ll> &a, const vector<ll> &b, ll k, ll p) {
    int m1 = a.size(), m2 = b.size();
    int m = min(m1, m2);
    vector<ll> res(m + 1);
    res[0] = 1;
    if (a.empty() || b.empty()) return res;
    if (p < 0) {
        for (int i = 1; i <= m; i++) {
            res[i] = c[m1][i] * c[m2][i] % mod * fac[i] % mod;
        }
        return res;
    }
    vector<ll> a0, a1, b0, b1;
    for (int i = 0; i < a.size(); i++) {
        if (1LL << p & a[i]) a1.emplace_back(a[i]);
        else a0.emplace_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        if (1LL << p & b[i]) b1.emplace_back(b[i]);
        else b0.emplace_back(b[i]);
    }
    if (1LL << p & k) {
        vector<ll> res1 = dfs(a0, b1, k, p - 1);
        vector<ll> res2 = dfs(a1, b0, k, p - 1);
        for (int i = 0; i < res1.size(); i++) {
            for (int j = 0; j < res2.size(); j++) {
                if (i + j == 0) continue;
                res[i + j] = (res[i + j] + res1[i] * res2[j]) % mod;
            }
        }
    } else {
        vector<ll> res1 = dfs(a0, b0, k, p - 1); 
        vector<ll> res2 = dfs(a1, b1, k, p - 1);
        for (int i = 0; i < res1.size(); i++) {
            for (int j = 0; j < res2.size(); j++) {
                int pk = min(a1.size() - j, b0.size() - i);
                int pl = min(a0.size() - i, b1.size() - j);
                for (int p = 0; p <= pk; p++) {
                    for (int l = 0; l <= pl; l++) {
                        if (i + j + p + l == 0) continue;
                        res[i + j + p + l] = (res[i + j + p + l] + res1[i] * res2[j] % mod * c[a0.size() - i][l] % mod * c[a1.size() - j][p] % mod * c[b1.size() - j][l]  % mod * c[b0.size() - i][p] % mod * fac[l] * fac[p]) % mod;
                    }
                }
            }
        } 
    }
    return res;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    vector<ll> ans = dfs(a, b, k, 60);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solve();
    return 0;
}