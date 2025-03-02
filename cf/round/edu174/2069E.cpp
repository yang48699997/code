#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> cnt(4);
    for (int i = 0; i < 4; i++) cin >> cnt[i];

    vector<array<int, 2>> p;
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n && s[j] != s[j - 1]) j++;
        p.push_back({s[i] - 'A', j - i});
        i = j;
    }

    sort(p.begin(), p.end(), [](auto &a, auto &b) {
        if (a[1] % 2 != b[1] % 2) return a[1] % 2 < b[1] % 2;
        return a[1] < b[1];
    });

    for (int i = 0; i < p.size(); i++) {
        int x = p[i][1];
        // cerr << x << " " << p[i][0] << "------\n";

        if (x & 1) {
            cnt[p[i][0]]--;
            x /= 2;

            int y = min(x, cnt[2]);
            x -= y;
            cnt[2] -= y;

            y = min(x, cnt[3]);
            x -= y;
            cnt[3] -= y;

            cnt[0] -= x;
            cnt[1] -= x;
        } else {
            x /= 2;
            if (p[i][0] == 0) {
                int y = min(x, cnt[2]);
                x -= y;
                cnt[2] -= y;

                if (x) {
                    x--;
                    cnt[0]--;
                    cnt[1]--;

                    y = min(x, cnt[3]);
                    x -= y;
                    cnt[3] -= y;
                    
                    cnt[0] -= x;
                    cnt[1] -= x;
                }
            } else {
                int y = min(x, cnt[3]);
                x -= y;
                cnt[3] -= y;

                if (x) {
                    x--;
                    cnt[0]--;
                    cnt[1]--;

                    y = min(x, cnt[2]);
                    x -= y;
                    cnt[2] -= y;

                    cnt[0] -= x;
                    cnt[1] -= x;
                }
            }
        }

        // cerr << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << "\n";

        if (*min_element(cnt.begin(), cnt.end()) < 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

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