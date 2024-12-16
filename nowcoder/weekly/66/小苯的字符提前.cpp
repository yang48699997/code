#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }

    int sum = 0;
    int t;
    for (int i = 0; i < 26; i++) {
        if (sum + pos[i].size() >= k) {
            t = i;
            break;
        } else {
            sum += pos[i].size();
        }
    }

    string ans;
    char p = t + 'a';

    int lef = pos[t].size();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == p) {
            int l = i;
            int r = i;
            string now;
            while (r < n - 1 && s[r] == p) {
                r++;
                now += p;
            }
            int cnt = r - l;
            if (s[r - 1] >= s[r]) {
                if (sum + cnt >= k) {
                    ans += s.substr(l + 1, n - l - 1);
                    break;
                } else {
                    ans += now;
                    sum += cnt;
                }
            } else {
                if (sum + lef - cnt < k) {
                    ans += s.substr(l + 1, n - l - 1);
                    break;
                } else {
                    ans += now;
                }
            }
            i = r - 1;
            lef -= cnt;
        } else {
            ans += s[i];
        }
        
    }

    cout << p << ans << "\n";
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