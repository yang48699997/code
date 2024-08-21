#include <bits/stdc++.h>
using namespace std;


struct DSU{
    vector<int> fa, size;
    
    DSU(int n) : fa(n), size(n, 1) {
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
        size[x] += size[y];
        fa[y] = x;
        return true;
    }
    
    int getCount(int x) {
        x = find(x);
        return size[x];
    }
};

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    
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