#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using B = bitset<5005>;

void solve() {
    int n, m;
    cin >> m >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    vector<B> s(n);
    for (int i = 0; i < n; i++) {
        s[i].set();
    }
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);
    while (m--) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(nums.begin(), nums.end(), [&](int x1, int x2) {
            return a[x1] < a[x2];
        });
        B p;
        p.set();
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[nums[j]] == a[nums[i]]) {
                p.reset(nums[j]);
                j++;
            }
            while (i < j) {
                s[nums[i]] &= p;
                i++;
            }
        }
    }
    vector<vector<int>> e(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i].test(j)) {
                e[i].push_back(j);
                deg[j]++;
            }
        }
    }
    vector<ll> d(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            d[i] = val[i];
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nxt : e[x]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
            d[nxt] = max(d[nxt], d[x] + val[nxt]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, d[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}