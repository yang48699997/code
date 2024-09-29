#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mx = 2e5 + 5;
vector<int> p[mx];
int v[mx], pri[mx];
void init() {
    int tot = 0;
    for (int i = 0; i < mx; i++) {
        v[i] = 0;
        pre[i] = 0;
        p[i].clear(); 
    }
    for (int i = 2; i < mx; i++) {
        if (!v[i]) {
            pri[tot++] = i;
            for (int j = i; j < mx; j += i) {
                p[j].push_back(i);
            }
        }
        for (int j = 0; pri[j] * i < mx; j++) {
            v[pri[j] * i] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int p = 0;
    while (1 << p < n) {
        p++;
    }
    vecotr<vector<int>> st(n, vecotr<int> (p));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st[i][0] = x;
    }
    vector<int> lg(n + 1);
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int j = 1; j < p; j++) {
        for (int i = 0; i < n; i++) {
            st[i][j] = __gcd(st[i][j - 1], st[min(n - 1, i + (1 << j >> 1))][j - 1]);
        }
    }
    vecotr<vector<int>> st2(n, vecotr<int> (p));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st2[i][0] = x;
    }
    for (int j = 1; j < p; j++) {
        for (int i = 0; i < n; i++) {
            st2[i][j] = __gcd(st2[i][j - 1], st2[min(n - 1, i + (1 << j >> 1))][j - 1]);
        }
    }
    auto q1 = [&](int l, int r) -> int {
        int len = (r - l) / 2;
        return __gcd(st[l][lg[len]], st[min(n - 1, l + lg[len])][lg[len]]);
    };
    auto q2 = [&](int l, int r) -> int {
        int len = (r - l) / 2;
        return __gcd(st2[l][lg[len]], st2[min(n - 1, l + lg[len])][lg[len]]);
    };
    map<int, int> cnt;
    for (int i = 0; i < n - 1; i++) {
        int res = __gcd(q1(0, i), q2(i + 1, n - 1)) + __gcd(q2(0, i), q1(i + 1, n - 1));
        cnt[res] += 2;
    }
    cnt[__gcd(q1(0, n - 1), q2(0, n - 1))]++;
    int g1 = __gcd(st[0][0], st[n - 1][0]);
    int g2 = __gcd(st2[0][0], st2[n - 1][0]);
    vector<int> d1(1, 1);
    for (int i = 0; i < p[g1].size(); i++) {
        int now = g1;
        int pp = 1;
        int sz = d1.size();
        while (now % p[g1][i] == 0) {
            pp *= p[g1][i];
            now /= p[g1][i];
            for (int j = 0; j < sz; j++) {
                d1.push_back(pp * d1[j]);
            }
        }
    }
    vector<int> d2(1, 1);
    for (int i = 0; i < p[g2].size(); i++) {
        int now = g2;
        int pp = 1;
        int sz = d2.size();
        while (now % p[g2][i] == 0) {
            pp *= p[g2][i];
            now /= p[g2][i];
            for (int j = 0; j < sz; j++) {
                d2.push_back(pp * d2[j]);
            }
        }
    }
    for (int i = 0; i < d1.size(); i++) {
        for (int j = 0; j < d2.size(); j++) {
            int l = 0;
            int r = n - 1;
            while (l < n && q1(0, l) % d1[i] == 0) l++;
            while (r >= 0 && q1(r, n - 1) % d1[i] == 0) r--;
            int l2 = 0;
            int r2 = n - 1;
            while (l2 < n && q2(0, l2) % d2[j] == 0) l2++;
            while (r2 >= 0 && q2(r2, n - 1) % d2[j] == 0) r2--;
            int l3 = min(l, l2);
            int r3 = max(r, r2);
            while (l3 >= 0 && q1(l3, ))
        }
    }
    cout << *cnt.rbegin().first << " " << *cnt.rbegin().second << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    init();
    while (T--) {
        solve();
    }
    return 0;
}