#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU {
    vector<int> fa, p, e, f;
    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        p.resize(n + 1, 1);
        e.resize(n + 1);
        f.resize(n + 1);
    }
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y) { // 设x是y的祖先
        if (x == y)
            f[get(x)] = 1;
        x = get(x), y = get(y);
        e[x]++;
        if (x == y)
            return false;
        if (x < y)
            swap(x, y); // 将编号小的合并到大的上
        fa[y] = x;
        f[x] |= f[y], p[x] += p[y], e[x] += e[y];
        return true;
    }
    bool same(int x, int y) { return get(x) == get(y); }
    bool F(int x) { // 判断连通块内是否存在自环
        return f[get(x)];
    }
    int size(int x) { // 输出连通块中点的数量
        return p[get(x)];
    }
    int E(int x) { // 输出连通块中边的数量
        return e[get(x)];
    }
};

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    DSU dsu(n);
    vector<int> valid(n, 1);
    for (int i = 62; i >= 0; i--) {
        int last = -1;
        if (((1 << i) & k) == 0) {
            for (int j = 0; j < n; j++) {
                if (!valid[j]) continue;
                if ((a[j] & (1 << i)) == 0) continue;
                if (last == -1) last = j;
                else dsu.merge(last, j);
            }
        } else {
            for (int j = 0; j < n; j++) {
                if ((a[j] & (1 << i)) == 0) {
                    valid[j] = 0;
                }
            }
        }
    }
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (!valid[i]) continue;
        if (last == -1) last = i;
        else dsu.merge(last, i);
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dsu.size(i));
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 0;
    cin >> t;
    while (t--) {
       solve();
    }
    return 0;
}