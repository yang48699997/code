#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 5;
ll tree[N << 2], trmx[N << 2], mark[N << 2], n, m, A[N], mx[N];

void push_down(int p, int len){
    if (len <= 1) return;
    tree[p << 1] += mark[p] * (len - len / 2);
    mark[p << 1] += mark[p];
    trmx[p << 1] += mark[p];
    tree[p << 1 | 1] += mark[p] * (len / 2);
    mark[p << 1 | 1] += mark[p];
    trmx[p << 1 | 1] += mark[p];
    mark[p] = 0;
}
void build(int p = 1, int cl = 1, int cr = n){
    if (cl == cr) return void(tree[p] = A[cl], trmx[p] = mx[cl]);
    int mid = (cl + cr) >> 1;
    build(p << 1, cl, mid);
    build(p << 1 | 1, mid + 1, cr);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
    trmx[p] = max(trmx[p << 1], trmx[p << 1 | 1]);
}
ll query(int l, int r, int p = 1, int cl = 1, int cr = n){
    if (cl >= l && cr <= r) return trmx[p];
    push_down(p, cr - cl + 1);
    ll mid = (cl + cr) >> 1, ans = 0;
    if (mid >= l) ans = max(ans, query(l, r, p << 1, cl, mid));
    if (mid < r) ans += max(ans, query(l, r, p << 1 | 1, mid + 1, cr));
    return ans;
}
void update(int l, int r, int d, int p = 1, int cl = 1, int cr = n){
    if (cl >= l && cr <= r) {
        tree[p] += d * (cr - cl + 1);
        trmx[p] += d;
        mark[p] += d;
        return;
    }
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1;
    if (mid >= l) update(l, r, d, p << 1, cl, mid);
    if (mid < r) update(l, r, d, p << 1 | 1, mid + 1, cr);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
    trmx[p] = max(trmx[p << 1], trmx[p << 1 | 1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)cin >> A[i];
    build();
    while (m--){
        int o, l, r, d;
        cin >> o >> l >> r;
        if (o == 1)
            cin >> d, update(l, r, d);
        else
            cout << query(l, r) << '\n';
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) q.push(i);
    }
    vector<int> d(n);
    while (!q.empty()) {
        int x = q.front();
        for (int nxt : e[x]) {
            deg[nxt]--;
            if (deg[nxt] == 1) {
                q.push(nxt);
                d[nxt] = d[x] + 1;
            }
        }
    }
    vector<int> cir;
    vector<int> v(n);
    auto dfs = [&](auto &&self, int x) -> void {
        cir.push_back(x);
        v[x] = 1;
        for (int nxt : e[x]) {
            if (deg[nxt] == 2) {
                deg[nxt] = 1;
                self(self, nxt);
                break;
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (deg[i] == 2) {
            dfs(dfs, i);
            break;
        }
    }

    int a = cir[0];
    int m = cir.size();
    for (int i = 1; i <= n; i++) {
        A[i] = mx[i] = 0;
    }
    A[1] = mx[1] = d[a];
    for (int i = 1; i < cir.size(); i++) {
        A[i + 1] = mx[i + 1] = d[cir[i]] + max(i, n - i);
    }
    build(1, 1, m);

    for (int i = 0; i < cir.size(); i++) {
        ans[cir[i]] = query(1, n, 1, 1, m);
        if (i == m - 1) continue;
        update(i + 2, i + 2, -m, 1, 1, m);
        update(1, m, 1, 1, 1, m);
        update(max(i + 2 - ), i + 2, -2, 1, 1, m);
    }

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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