#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q1, q2;
    for (int i = 0; i < n; i++) {
        int a, b, c1, c2;
        cin >> a >> b >> c1 >> c2;
        if (c1 && c2) {
            if (a < b) q1.push({a, i + 1});
            else q2.push({b, i + 1});
        } else if (c1) {
            q1.push({a, i + 1});
        } else {
            q2.push({b, i + 1});
        }
    }

    cout << q1.size() << " \n"[q1.empty()];
    while (!q1.empty()) {
        auto [x, i] = q1.top();
        q1.pop();
        cout << i << " \n"[q1.empty()];
    }

    cout << q2.size() << " \n"[q2.empty()];
    while (!q2.empty()) {
        auto [x, i] = q2.top();
        q2.pop();
        cout << i << " \n"[q2.empty()];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}