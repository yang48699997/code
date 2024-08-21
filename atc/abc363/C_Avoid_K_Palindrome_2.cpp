#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int ans = 0;

    auto check = [&]() -> int {
        for (int i = 0; i <= n - k; i++) {
            int ok = 1;
            int p = k - 1;
            for (int j = i; j < i + k; j++) {
                if (s[j] != s[j + p]) {
                    ok = 0;
                    break;
                }
                p -= 2;
            }
            if (ok) return 0;
        }
        return 1;
    };
    int cnt = 0;
    do {
        ans += check();
        // if (check()) cerr << s << "\n";
    }while (next_permutation(s.begin(), s.end()));
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}