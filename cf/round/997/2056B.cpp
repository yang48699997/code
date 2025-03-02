#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<vector<int>> e(n);
    vector<int> deg(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i][j] == '0') {
                e[j].push_back(i);
                deg[i]++;
            } else {
                e[i].push_back(j);
                deg[j]++;
            }
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (deg[i]) continue;
        q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        cout << x + 1 << " ";

        for (int nxt : e[x]) {
            deg[nxt]--;
            if (deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    cout << "\n";
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