#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<int> p1, p2, p3;

    for (int i = 0; i < n; i++) {
        if (s[i] == '/') p3.push_back(i);
        else if (s[i] == '1') p1.push_back(i);
        else if (s[i] == '2') p2.push_back(i);
    }

    while (q--) {
        int cl, cr;
        cin >> cl >> cr;
        cl--;
        cr--;

        int L = -1;
        int R = -1;

        auto it = lower_bound(p3.begin(), p3.end(), cl);
        if (it == p3.end() || *it > cr) {
            cout << 0 << "\n";
            continue;
        }

        it = lower_bound(p1.begin(), p1.end(), cl);
        if (it == p1.end() || *it > cr) {
            cout << 1 << "\n";
            continue;
        }
        L = it - p1.begin();

        it = upper_bound(p2.begin(), p2.end(), cr);
        if (it == p2.begin()) {
            cout << 1 << "\n";
            continue;
        }
        it--;
        if (*it < cl) {
            cout << 1 << "\n";
            continue;
        }
        R = it - p2.begin();

        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (L + mid > p1.size() || R - mid + 1 < 0) {
                r = mid - 1;
            } else {
                int cl = L + mid - 1;
                int cr = R - mid + 1;
                it = lower_bound(p3.begin(), p3.end(), p1[cl]);
                if (it == p3.end() || *it > p2[cr]) {
                    r = mid - 1;
                } else l = mid + 1;
            }
        }
        
        cout << 1 + 2 * r << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}