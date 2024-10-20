#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<set<int>> pos(n);
    for (int i = 0; i < m; i++) {
        pos[mp[b[i]]].insert(i);
    }

    vector<int> res(n);
    int ok = 0;
    for (int i = 0; i < n; i++) {
        if (pos[i].empty() || i == 0) {
            ok++;
            res[i] = 1;
            continue;
        }
        if (pos[i - 1].empty() || *pos[i - 1].begin() > *pos[i].begin()) continue;
        ok++;
        res[i]++;
    }
    if (ok == n) cout << "YA\n";
    else cout << "TIDAK\n";

    while (q--) {
        int s, t;
        cin >> s >> t;
        s--;
        int p1 = mp[b[s]];
        int p2 = mp[t];
        b[s] = t;
        pos[p1].erase(s);
        if (pos[p1].empty() || p1 == 0 || (!pos[p1 - 1].empty() && *pos[p1 - 1].begin() < *pos[p1].begin())) {
            ok += 1 - res[p1];
            res[p1] = 1;
        } else {
            ok -= res[p1];
            res[p1] = 0;
        }
        if (p1 < n - 1) {
            p1++;
            if (pos[p1].empty() || p1 == 0 || (!pos[p1 - 1].empty() && *pos[p1 - 1].begin() < *pos[p1].begin())) {
                ok += 1 - res[p1];
                res[p1] = 1;
            } else {
                ok -= res[p1];
                res[p1] = 0;
            }
        }

        pos[p2].insert(s);
        p1 = p2;
        if (pos[p1].empty() || p1 == 0 || (!pos[p1 - 1].empty() && *pos[p1 - 1].begin() < *pos[p1].begin())) {
            ok += 1 - res[p1];
            res[p1] = 1;
        } else {
            ok -= res[p1];
            res[p1] = 0;
        }
        if (p1 < n - 1) {
            p1++;
            if (pos[p1].empty() || p1 == 0 || (!pos[p1 - 1].empty() && *pos[p1 - 1].begin() < *pos[p1].begin())) {
                ok += 1 - res[p1];
                res[p1] = 1;
            } else {
                ok -= res[p1];
                res[p1] = 0;
            }
        }
        if (ok == n) cout << "YA\n";
        else cout << "TIDAK\n";
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