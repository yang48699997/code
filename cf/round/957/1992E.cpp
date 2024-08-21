#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    string s = to_string(n);
    int t = s.size();
    vector<pair<int, int>> ans;
    auto check = [&](int a, int b) -> bool {
        int p = t * a - b;
        if(p > 7) return false;
        string res;
        while (res.size() < p) res += s;
        while (res.size() != p) res.pop_back();
        int d = a * n - b;
        return to_string(d) == res;
    };
    for (int i = 1; i <= 10000; i++) {
        for (int j = min(i * t, 10000) - 7; j <= min(i * t, 10000); j++) {
            if (j < 1) continue;
            if (check(i, j)) ans.push_back({i, j});
        }
    } 
    cout << ans.size() << "\n";
    for (auto [a, b] : ans) {
        cout << a << " " << b << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}