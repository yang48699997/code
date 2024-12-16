#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> q(n), j(n), k(n);
    for (int i = 0; i < n; i++) cin >> q[i];
    for (int i = 0; i < n; i++) cin >> j[i];
    for (int i = 0; i < n; i++) cin >> k[i];

    vector<array<int, 2>> nxt(n, {-1, -1});
    vector<int> mi(3), p(3, n - 1);
    mi[0] = q[n - 1];
    mi[1] = j[n - 1];
    mi[2] = k[n - 1];
    
    for (int i = n - 2; i >= 0; i--) {
        int ok = 0;
        if (q[i] > mi[0]) {
            ok = 1;
            nxt[i] = {p[0], 0};
        } else if (j[i] > mi[1]) {
            ok = 1;
            nxt[i] = {p[1], 1};
        } else if (k[i] > mi[2]) {
            ok = 1;
            nxt[i] = {p[2], 2};
        }
        
        if (ok) {
            if (q[i] < mi[0]) {
                mi[0] = q[i];
                p[0] = i;
            }
            if (j[i] < mi[1]) {
                mi[1] = j[i];
                p[1] = i;
            }
            if (k[i] < mi[2]) {
                mi[2] = k[i];
                p[2] = i;
            }
        }
    }

    if (nxt[0][0] == -1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int now = 0;
    vector<array<int, 2>> ans;
    while (now != n - 1) {
        ans.push_back({nxt[now][0], nxt[now][1]});
        now = nxt[now][0];
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        char c = 'q';
        if (ans[i][1] == 1) c = 'k';
        if (ans[i][1] == 2) c = 'j';
        cout << c << " " << ans[i][0] + 1 << "\n";
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