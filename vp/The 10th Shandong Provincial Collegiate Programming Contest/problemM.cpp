#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int Y, M, D;
    string p;
    cin >> Y >> M >> D >> p;
    vector<string> s{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int l = 0;
    for (int i = 0; i < 5; i++) {
        if (s[i] == p) {
            l = i;
            break;
        }
    }
    int y, m, d;
    cin >> y >> m >> d;
    cout << s[((d - D) % 5 + 5 + l) % 5] << "\n";
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