#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU{
    vector<int> fa, sz;
    
    DSU(int n) : fa(n), sz(n, 1) {
        for ( int i = 0; i < n; i++) fa[i]=i;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
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
    int n;
    ll k;
    cin >> n >> k;
    DSU dsu(n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k == 0) {
        cout << n << "\n";
        return;
    }
    ll mask = 0;
    for (int i = 60; i >= 0; i--) {
        if ((1LL << i | mask) >= k) {
            int p = -1;
            for (int j = 0; j < n; j++) {
                if ((1LL << i & a[j]) && ((a[j] & mask) == mask)) {
                    if (p == -1) p = j;
                    else dsu.merge(j, p); 
                }
            }
        } else {
            mask |= 1LL << i;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dsu.size(i));
    }
    cout << ans << "\n";
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