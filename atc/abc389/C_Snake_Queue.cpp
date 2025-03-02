#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int q;
    cin >> q;

    ll sum = 0;
    vector<ll> a(1);
    int l = 0;

    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            ll x;
            cin >> x;
            a.push_back(x + sum);
            sum += x;
        } else if (c == 2) {
            l++;
        } else {
            int k;
            cin >> k;
            k--;

            cout << a[k + l] - a[l] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int q;
    cin >> q;

    ll sum = 0;
    vector<ll> a(1);
    int l = 0;

    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            ll x;
            cin >> x;
            a.push_back(x + sum);
            sum += x;
        } else if (c == 2) {
            l++;
        } else {
            int k;
            cin >> k;
            k--;

            cout << a[k + l] - a[l] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}