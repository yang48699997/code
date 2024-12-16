#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;

    cin >> n >> s;

    ll ans = 0;
    vector<int> cnt(n + 2);

    for (int i = 0; i < n; ) {
        int j = i;
        int c = 0;
        
        while (j < n && s[i] == s[j]) {
            j++;
            c++;
        }

        i = j;
        cnt[1] += 1;
        cnt[c + 1] -= 1; 
    }

    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];

    ll sum = n;
    for (int i = 1; i <= n; i++) {
        sum -= cnt[i];
        ans ^= (n - sum) * i;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}