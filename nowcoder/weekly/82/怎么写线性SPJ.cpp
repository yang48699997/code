#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);

    auto dfs = [&](auto &&self, int l, int r, int x) -> void {
        if (l > r) return;
        else if (l == r) {
            p[l] = x;
            return;
        }

        int mid = (l + r) / 2;
        p[mid] = x++;
        self(self, l, mid - 1, x);
        self(self, mid + 1, r, x);
    };

    dfs(dfs, 0, n - 1, 1);

    int ans = *max_element(p.begin(), p.end());

    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}