#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1 2\n";
        return;
    }
    if (n == 2) {
        cout << "1 2\n";
        cout << "1 3\n";
        return;
    }
    if (n == 3) {
        cout << "1 2\n";
        cout << "1 3\n";
        cout << "1 4\n";
        return;
    }
    if (n == 4 || n == 5) {
        cout << "1 2\n";
        cout << "1 3\n";
        cout << "1 4\n";
        cout << "1 5\n";
        if (n == 5) cout << "1 6\n";
        return;
    }
    int p = 5;
    int q = 4;
    vector<vector<int>> e(4);
    e[1].push_back(2);
    e[1].push_back(3);
    e[1].push_back(4);
    e[1].push_back(5);
    e[2].push_back(3);
    e[2].push_back(4);
    n -= 6;
    int c = 6;
    while (n > 0) {
        if (n >= 3) {
            e[1].push_back(c);
            e[2].push_back(p);
            e[3].push_back(q);
            p++;
            q++;
            c++;
        } else if (n == 1) {
            e[1].push_back(c);
            c++;
        } else if (n == 2) {
            e[1].push_back(c++);
            e[1].push_back(c++);
        }
        n -= 3;
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            cout << i << " " << e[i][j] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}