#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mx = 1e6 + 5;
int f[mx], v[mx];
int tot = 0;

int cal(ll n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    vector<ll> u;
    for (int i = 1; i < min(100LL, n); i++) {
        u.push_back(n - i);
    }

    int l = u.size();
    reverse(u.begin(), u.end());
    vector<vector<ll>> res(l, vector<ll> (1, 1));
    ll pp = u[0];
    for (int i = 0; i < tot; i++) {
        int lef = pp % f[i];
        if (lef == 0) lef = f[i];
        int nxt = f[i] - lef;
        while (nxt < l) {
            int m = res[nxt].size();
            ll p = 1;
            while (u[nxt] % f[i] == 0) {
                p *= f[i];
                for (int j = 0; j < m; j++) res[nxt].push_back(res[nxt][j] * p);
                u[nxt] /= f[i];
            }
            nxt += f[i];
        }
    }
    for (int i = 0; i < l; i++) {
        if (u[i] > 1) {
            int m = res[i].size();
            for (int k = 0; k < m; k++) res[i].push_back(res[i][k] * u[i]);
        }
        int m = res[i].size();
        for (int j = 0; j < m; j++) {
            if (n % res[i][j] == l - i && cal(res[i][j]) == l - i) {
                ans++;
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    for (int i = 0; i < mx; i++) {
        v[i] = f[i] = 0;
    }
    tot = 0;
    for (int i = 2; i < mx; i++) {
        if (!v[i]) f[tot++] = i;
        for (int j = 0; f[j] * i < mx; j++) {
            v[f[j] * i] = 1;
            if (f[j] % i == 0) break;
        }
    }

    while (T--) {
        solve();
    }
    return 0;
}