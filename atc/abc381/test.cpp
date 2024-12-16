#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    float a, b, c;
    cin >> a >> b >> c;
    float ans = -a;

    float p = 1;
    for (int i = 0; i < 10; i++) {
        p *= (1 + c);
        ans += b / p;
    }

    cout << fixed << setprecision(10) << ans << "\n";
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}