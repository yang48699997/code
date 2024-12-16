#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> e(n);
    vector<int> deg(n);
    vector<int> siz(n, 1);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        e[i].push_back(x);
        deg[x]++;
    }

    queue<int> q, tmp;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    }

    int ans = 2;

    while (!q.empty()) {

        while (!q.empty()) {
            int x = q.front();
            ans = max(ans, siz[x] + 2);
            q.pop();

            for (int nxt : e[x]) {
                deg[nxt]--;
                siz[nxt] += siz[x];
                if (deg[nxt] == 0) tmp.push(nxt);
            }
        }

        swap(q, tmp);
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