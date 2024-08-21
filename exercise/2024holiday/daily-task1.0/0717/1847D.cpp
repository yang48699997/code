#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    vector<int> v(n);
    set<int> p;
    for (int i = 0; i < n; i++) p.insert(i);
    vector<int> re(n);
    int sum = 0;
    int cnt = 0;
    vector<int> a(n + 1);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        auto it = p.lower_bound(l);
        while (it != p.end() && *it <= r) {
            re[*it] = ++sum;
            v[*it] = 1;
            if (s[*it] == '1') cnt++, a[sum] = 1;
            it = p.erase(it);
        }
    }
    int can = 0;
    for (int i = 0; i < n; i++) if (!v[i] && s[i] == '1') can++;
    for (int i = 1; i <= n ; i++) {
        int nxt = i + (i & -i);
        if (nxt <= n) {
            a[nxt] += a[i];
        }
    }
    int ans;
    auto query = [&](int l) -> int {
        int res = 0;
        while (l) {
            res += a[l];
            l -= (l & -l);
        }
        return res;
    };
    auto update = [&](int x, int p) -> void {
        while (x <= n) {
            a[x] += p;
            x += (x & -x);
        }
    };
    ans = min(sum, cnt + can) - query(min(sum, cnt + can));
    while (q--) {
        int x;
        cin >> x;
        x--;
        if (!v[x]) {
            if (s[x] == '0') {
                s[x] = '1';
                can++;
            } else {
                s[x] = '0';
                can--;
            }
        } else {
            if (s[x] == '0') {
                s[x] = '1';
                cnt++;
                update(re[x], 1);
            } else {
                s[x] = '0';
                cnt--;
                update(re[x], -1);
            } 
        }
        ans = min(sum, cnt + can) - query(min(sum, cnt + can));
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}