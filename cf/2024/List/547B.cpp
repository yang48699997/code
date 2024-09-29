#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU{
    vector<int> fa, sz;
    
    DSU(int n) : fa(n), sz(n, 1) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; 

    vector<int> b(n);
    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), [&](int x1, int x2){
        return a[x1] > a[x2];
    });
    vector<int> ans(n);

    DSU dsu(n);
    int mx = 0;
    int now = 0;
    for (int i : b) {
        if (i > 0 && a[i - 1] >= a[i]) {
            dsu.merge(i, i - 1);
        } 
        if (i < n - 1 && a[i + 1] >= a[i]) {
            dsu.merge(i, i + 1);
        }
        mx = max(mx, dsu.size(i));
        while (now < n && mx > now) {
            ans[now] = a[i];
            now++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}