#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int R = 1e9;
const int L = 1;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i][0] >> p[i][1];

    sort(p.begin(), p.end());
    priority_queue<int, vector<int>, greater<int>> q;
    int now = 1;

    for (int i = 0; i < n; i++) {
        while (!q.empty() && now < p[i][0]) {
            if (q.top() < now) {
                cout << "No\n";
                return;
            }
            now++;
            q.pop();
        }
        now = max(now, p[i][0]);
        q.push(p[i][1]);
    }  
    while (!q.empty()) {
        if (q.top() < now) {
            cout << "No\n";
            return;
        }
        now++;
        q.pop();
    }

    cout << "Yes\n";
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