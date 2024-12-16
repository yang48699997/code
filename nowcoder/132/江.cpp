#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    ll l = 0, r = n + k;
    while (l <= r) {
        ll mid = (l + r) / 2;
        int ok = 0;
        queue<int> q;
        for (int i = 0; i < a.size(); i++) {
            while (!q.empty() && q.front() <= a[i] - mid) q.pop();
            q.push(a[i]);
            int lef = mid - q.size();
            if (k < lef) continue;
            if (min((int)q.size() + k, m) >= mid) {
                ok = 1;
                break;
            }
        }

        if (ok) l = mid + 1;
        else r = mid - 1;
    }

    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}