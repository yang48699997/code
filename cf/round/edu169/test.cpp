#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mx = 1e7 + 5;
int v[mx];

void init() {
    for (int i = 0; i < mx; i++) v[i] = 0;
    v[1] = 1;
    int now = 1;
    for (int i = 3; i < mx; i += 2) {
        if (v[i]) continue;
        v[i] = ++now;
        for (int j = i; j < mx; j += i * 2) {
            if (v[j]) continue;
            v[j] = now;
        }
    } 
}

const int mx2 = 1000;

int gcd(int x, int y) {
    while (y) {
        int t = y;
        y = x % y;
        x = t;
    };
    return x;
};

void solve() {
    vector<int> dp(mx2 + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= mx2; i++) {
        vector<int> p;
        for (int j = 1; j < i; j++) {
            if (gcd(i, j) == 1) p.push_back(dp[j]);
        }
        sort(p.begin(), p.end());
        int m = unique(p.begin(), p.end()) - p.begin();
        p.resize(m);
        dp[i] = p.size();
        for (int j = 0; j < p.size(); j++) {
            if (p[j] != j) {
                dp[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i <= mx2; i++) {
        cout << i << ": " << dp[i] << "\n"; 
        if (dp[i] != v[i]) {
            cerr << i << " " << dp[i] << " " << v[i] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solve();
    return 0;
}