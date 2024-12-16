#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    
    deque<array<int, 2>> q;

    vector<int> dif(n + 1);
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.back()[0] < h[i]) q.pop_back();

        if (q.empty()) dif[0]++;
        else dif[q.back()[1]]++;

        q.push_back({h[i], i});
        dif[i]--;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dif[i];
        cout << ans << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}