#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> fa,size;
    DSU(int n):fa(n),size(n,1){
        for(int i=0;i<n;i++)fa[i]=i;
    }
    int find(int x){
        if(fa[x]==x)return x;
        fa[x]=find(fa[x]);
        return fa[x];
    }
    bool merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return false;
        size[x]+=size[y];
        fa[y]=x;
        return true;
    }
    int getCount(int x){
        x=find(x);
        return size[x];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        dsu.merge(x, y);
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vector<int> v(n), d(n);
    vector<int> vv(n);
    vector<int> ans;
    vector<vector<int>> sub(n);
    vector<int> cnt(n), f; 
    for (int i = 0; i < n; i++) {
        sub[dsu.find(i)].push_back(i);
        if (v[dsu.find(i)]) continue;
        v[dsu.find(i)] = 1;
        f.push_back(dsu.find(i));
        queue<int> q;
        q.push(i);
        int last = i;
        while (!q.empty()) {
            int p = q.front();
            last = p;
            q.pop();
            vv[p] = 1;
            for (int nxt : e[p]) {
                if (vv[nxt]) continue;
                q.push(nxt);
            }
        }
        d[last] = 1;
        q.push(last);

        while (!q.empty()) {
            int p = q.front();
            q.pop();
            cnt[dsu.find(p)] = d[p];
            for (int nxt : e[p]) {
                if(d[nxt]) continue;
                d[nxt] = d[p] + 1;
                q.push(nxt);
            }
        }
    }
    if (f.size() == 1 && cnt[f[0]] < 4) {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> q(n + 1);
    int pre = 0;
    for (int i = 0; i < f.size(); i++) {
        for (int j = 0; j < sub[f[i]].size(); j++) {
            q[pre + d[sub[f[i]][j]]].push_back(sub[f[i]][j]);
        }
        pre += cnt[f[i]];
    }
    if (pre < 4) {
        if (f.size() == 3) {
            for (int i = 0; i < n; i++) {
                cout << i + 1 << " \n"[i == n - 1];
            }
            return;
        } else {
            if (cnt[f[0]] == 2) {
                int c2 = -1, c1 = -1;
                for (int j = 0; j < 2; j++) {
                    if (d[sub[f[0]][j]] == 2) c2 = sub[f[0]][j] + 1; 
                    else c1 = sub[f[0]][j] + 1;
                }
                cout << c2 << " " << sub[f[1]][0] + 1 << " " << c1 << "\n";
            } else if (cnt[f[1]] == 2){
                int c2 = -1, c1 = -1;
                for (int j = 0; j < 2; j++) {
                    if (d[sub[f[1]][j]] == 2) c2 = sub[f[1]][j] + 1; 
                    else c1 = sub[f[1]][j] + 1;
                }
                cout << c2 << " " << sub[f[0]][0] + 1 << " " << c1 << "\n";
            } else {
                for (int i = 0; i < n; i++) {
                    cout << i + 1 << " \n"[i == n - 1];
                }
            }
            return;
        }
    }
    int now = pre / 2 + 1;
    for (int i : q[now]) ans.push_back(i);
    now -= 2;
    for (int i : q[now]) ans.push_back(i);
    now += 3;
    for (int i : q[now]) ans.push_back(i);
    now -= 2;
    for (int i : q[now]) ans.push_back(i);
    int r = pre / 2 + 3;
    int l = pre / 2 - 2;
    int cur = 4;
    int ok = 1;
    while (cur < pre) {
        if (ok) {
            for (int i : q[r]) ans.push_back(i);
            ok = 0;
            r++;
        } else {
            for (int i : q[l]) ans.push_back(i);
            ok = 1;
            l--;
        }
        cur++;
    } 
    for (int i : ans) {
        cout << i + 1 << " \n"[i == ans.back()];
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