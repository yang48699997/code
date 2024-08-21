#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x, k;
    cin >> n >> x >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto check = [&](int p) -> int {
        priority_queue<int> q;
        for (int i = 0; i < p; i++) q.push(a[i]);
        int c = k;
        int now = x;
        while (!q.empty()) {
            int x = q.top();
            q.pop();
            if (c) {
                c--;
                continue;
            } else {
                if (now <= x) return 0;
                now -= x;
            }
        }
        return 1;
    };

    int l = 0, r = n;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    cout << r << "\n";
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