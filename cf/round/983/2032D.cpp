#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int q(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);

    int now = 2;
    while (now < n && q(1, now) == 1) now++;

    if (now == n) {
        cout << "! ";
        for (int i = 1; i < n; i++) {
            cout << i - 1 << " ";
        }
        cout << endl;
        return;
    }

    vector<int> pp;
    for (int i = 1; i < now; i++) {
        pp.push_back(i);
    }

    while (now < n) {
        vector<int> tmp;
        int l = now;
        for (int j = 0; j < pp.size() && l < n; j++) {
            if (pp[j] == 1 || q(pp[j], l) == 0) {
                tmp.push_back(l);
                p[l] = pp[j];
                l++;
            }
        }
        swap(tmp, pp);
        now = l;
    }

    cout << "! ";
    for (int i = 1; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
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