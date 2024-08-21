#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int gcd(int x, int y) {
    if (x == -1) return y;
    while (y) {
        int t = y;
        y = x % y;
        x = t;
    };
    return x;
};

const int mx = 1e5 + 5;
void solve() {
    int n;
    cin >> n;
    vector<int> v(mx);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x] = 1;
    }
    int cnt = 0;
    for (int i = mx - 1; i > 0; i--) {
        if (v[i]) continue;
        int g = -1;
        for (int j = i * 2; j < mx; j += i) {
            if (v[j]) {
                int gg = gcd(g, j);
                if (gg == i) {
                    v[i] = 1;
                    cnt++;
                    // cerr << i << "\n";
                    break;
                } else if (gg == g){
                    continue;
                } else if (v[gg]){
                    g = gg;
                    continue;
                } else {
                    v[gg] = 1;
                    g = gg;
                    cnt++;
                    // cerr << i << "\n";
                }
            }
        }
    }
    cerr << cnt << "\n";
    if (cnt & 1) cout << "dXqwq\n";
    else cout << "Haitang\n";
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