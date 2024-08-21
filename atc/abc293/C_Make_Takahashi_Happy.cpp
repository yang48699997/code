#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> g(h, vector<int> (w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin>>g[i][j];
    }
    int ans = 0;
    vector<int> p(h + w - 2, 1);
    for (int i = 0; i < h - 1; i++) p[i] = 0;
    do {
        set<int> st;
        st.insert(g[0][0]);
        int x = 0, y = 0;
        for (int i : p) {
            if (i == 0) x++;
            else y++;
            st.insert(g[x][y]);
        }
        if (st.size() == h + w -1) ans++;
    } while (next_permutation(p.begin(), p.end()));
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}