#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    if (s.size() <= 6) {
        int n = stoi(s);
        
        auto check = [&](int x) {
            int sum = 0;
            int now = x;
            while (now) {
                sum += now % 10;
                now /= 10;
            }
            return x % sum == 0;
        };
        
        for (int i = n; i < n * 2; i++) {
            if (check(i) && check(i + 1)) {
                cout << i << '\n';
                return;
            }
        }
        cout << "-1\n";
        return;
    }

    string p = s.substr(0, 2);

    string ans = string(s.size(), '0');

    if (p < "17") {
        ans[0] = '1';
        ans[1] = '7';
    } else if (p < "26") {
        ans[0] = '2';
        ans[1] = '6';
    } else if (p < "35") {
        ans[0] = '3';
        ans[1] = '5';
    } else if (p < "44") {
        ans[0] = '4';
        ans[1] = '4';
    } else if (p < "71") {
        ans[0] = '7';
        ans[1] = '1';
    } else {
        ans += '0';
        ans[0] = '1';
        ans[2] = '7';
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}