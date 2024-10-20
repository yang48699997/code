#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU{
    vector<int> fa, sz;
    DSU(int n) : fa(n), sz(n, 1) {
        for (int i = 0; i < n; i++) fa[i]=i;
    }
    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if( x == y) return false;
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
    int size(int x) {
        x = find(x);
        return sz[x];
    }
};

void solve() {
    int n, p;
    cin >> n >> p;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s] = i;
    }

    DSU dsu(n);
    vector<array<int, 2>> e(p);
    for (int i = 0; i < p; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        e[i][0] = mp[s1];
        e[i][1] = mp[s2];
    }

    int q;
    cin >> q;
    vector<int> ask(q);
    vector<int> v(n, q);
    int now = n - q - 1;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        ask[i] = mp[s];
        v[ask[i]] = i;
    }

    vector<int> ans(q);
    sort(e.begin(), e.end(), [&](auto &e1, auto &e2){
        return min(v[e1[0]], v[e1[1]]) > min(v[e2[0]], v[e2[1]]);
    });
    int l = 0;

    for (int i = q - 1; i >= 0; i--) {
        now++;
        while (l < p && min(v[e[l][0]], v[e[l][1]]) > i) {
            auto ne = e[l++];
            now -= dsu.merge(ne[0], ne[1]);
        }
        ans[i] = now;
    }

    now++;
    while (l < p) {
        auto ne = e[l++];
        now -= dsu.merge(ne[0], ne[1]);
    }
    cout << now << "\n";
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}