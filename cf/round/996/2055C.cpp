#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Info {
    ll x = 0;
    ll p = 0;

    Info() = default;
    Info(ll x_, ll p_) : x(x_), p(p_) {}
};

Info operator+(const Info &a, const Info &b) {
    return {a.x + b.x, a.p + b.p};
}
Info operator+=(Info &a, const Info &b) {
    a.x += b.x;
    a.p += b.p;
    return a;
}
Info operator-(const Info &a, const Info &b) {
    return {a.x - b.x, a.p - b.p};
}

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    vector<vector<ll>> g(n, vector<ll> (m));
    vector<vector<Info>> gg(n, vector<Info> (m));

    vector<Info> c(m), r(n);
    vector<ll> cc(m), rr(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            r[i] += {g[i][j], 0};
            c[j] += {g[i][j], 0};
            rr[i] += g[i][j];
            cc[j] += g[i][j];
        }
    }
    
    Info x;
    if (s[0] == 'D') {
        x = Info(r[0].x, 1);
        c[0] += {0, 1};
    } else {
        x = Info(c[0].x, 1);
        r[0] += {0, 1};
    }

    int cx = 0, cy = 0;
    for (int i = 0; i < 2; i++) {
        if (s[i] == 'D') cx++;
        else cy++;
    }

    for (int i = 2; i < n + m - 1; i++) {
        if (s[i - 1] == 'D') {
            gg[cx - 1][cy] = x - r[cx - 1];
            c[cy] += x - r[cx - 1];
            r[cx - 1] = x;
        } else {
            gg[cx][cy - 1] = x - c[cy - 1];
            r[cx] += x - c[cy - 1];
            c[cy - 1] = x;
        }
        if (s[i] == 'D') cx++;
        else cy++;
    }

    ll p = r[n - 1].p - c[m - 1].p;
    ll a = c[m - 1].x - r[n - 1].x;

    ll t = 0;
    if (p != 0) t = a / p;

    cx = 0, cy = 0;
    g[0][0] = t;
    if (s[0] == 'D') {
        cx++;
    } else {
        cy++;
    }

    gg[n - 1][m - 1] = x - r[n - 1];

    for (int i = 1; i < n + m - 1; i++) {
        g[cx][cy] = gg[cx][cy].x + t * gg[cx][cy].p;
        if (i == n + m - 2) continue;
        if (s[i] == 'D') cx++;
        else cy++;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j] << " \n"[j == m - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}