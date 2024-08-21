#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        deg[y]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        if (q.size() != 1) {
            cout << "No";
            return;
        }
        int x = q.front();
        q.pop();
        for (int nxt : e[x]) {
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
        ans[x] = i;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}