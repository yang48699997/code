#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dir[8][2] = {
    {1, 2}, {1, -2}, {2, 1}, {2, -1},
    {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}
};
void solve() {
    ll n;
    cin >> n;
    int m;
    cin >> m;

    set<pair<int, int>> st;
    while (m--) {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
        for (int i = 0; i < 8; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (nx > 0 && nx <= n && ny > 0 && ny <= n) st.insert({nx, ny});
        }
    }

    ll ans = n * n - st.size();

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}