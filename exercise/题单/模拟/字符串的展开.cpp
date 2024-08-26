#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;
    int n = s.length();
    string res;
    res += s[0];
    for (int i = 1; i < n - 1; i++) {
        if (s[i] != '-') {
            res += s[i];
            continue;
        }
        if (s[i - 1] >= '0' && s[i + 1] >= '0' && s[i - 1] <= '9' && s[i + 1] <= '9' && s[i + 1] - s[i - 1] > 0) {
            string p;
            for (int j = 1; j < s[i + 1] - s[i - 1]; j++) {
                for (int c = 0; c < p2; c++) {
                    if (p1 == 1) {
                        p += s[i - 1] + j;
                    } else if (p1 == 2) {
                        p += s[i - 1] + j;
                    } else {
                        p += '*';
                    }
                }
            }
            if (p3 == 2) reverse(p.begin(), p.end());
            res += p;
        } else if (s[i - 1] >= 'a' && s[i + 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] <= 'z' && s[i + 1] - s[i - 1] > 0) {
            string p;
            for (int j = 1; j < s[i + 1] - s[i - 1]; j++) {
                for (int c = 0; c < p2; c++) {
                    if (p1 == 1) {
                        p += s[i - 1] + j;
                    } else if (p1 == 2) {
                        p += (s[i - 1] + j) ^ 32;
                    } else {
                        p += '*';
                    }
                }
            }
            if (p3 == 2) reverse(p.begin(), p.end());
            res += p;
        } else if (s[i - 1] >= 'A' && s[i + 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] <= 'Z' && s[i + 1] - s[i - 1] > 0) {
            string p;
            for (int j = 1; j < s[i + 1] - s[i - 1]; j++) {
                for (int c = 0; c < p2; c++) {
                    if (p1 == 1) {
                        p += (s[i - 1] + j) ^ 32;
                    } else if (p1 == 2) {
                        p += s[i - 1] + j;
                    } else {
                        p += '*';
                    }
                }
            }
            if (p3 == 2) reverse(p.begin(), p.end());
            res += p;
        } else res += s[i];
    }
    res += s.back();
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}