#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> d(n + 1);
    int now = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        now += d[i];
        a[i] += now;

        int t = n - i - 1;
        t = min(t, a[i]);
        a[i] -= t;

        if (t) {
            d[i + 1]++;
            d[i + t + 1]--;
        }

        cout << a[i] << " \n"[i == n - 1];
    } 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}