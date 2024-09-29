#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    cout << "1\n";
    cout << "5 10\n";
    for (int i = 0; i < 5; i++) {
        string s;
        for (int j = 0; j < 10; j++) {
            int t = rng() % 26;
            char c = 'a' + t;
            s += c;
        }
        cout << s << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}