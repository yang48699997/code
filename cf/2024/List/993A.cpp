#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    vector<pair<int, int>> p1(4), p2(4);
    for (int i = 0; i < 4; i++) cin >> p1[i].first >> p1[i].second;
    for (int i = 0; i < 4; i++) cin >> p2[i].first >> p2[i].second;
    double x = 0, y = 0;
    for (int i = 0; i < 4; i++) {
        x += p1[i].first;
        y += p1[i].second;
    }
    x /= 4;
    y /= 4;

    auto check1 = [&](int x, int y) -> int {
        int mix = 100, mxx = -100;
        int miy = 100, mxy = -100;
        for (int i = 0; i < 4; i++) {
            mix = min(mix, p1[i].first);
            miy = min(miy, p1[i].second);
            mxx = max(mxx, p1[i].first);
            mxy = max(mxy, p1[i].second);
        }
        if (x >= mix && x <= mxx && y >= miy && y <= mxy) return 1;
        return 0;
    };

    auto check2 = [&](double x, double y) -> int {
        double res = 0;
        int mix = 100, mxx = -100;
        int miy = 100, mxy = -100;
        for (int i = 0; i < 4; i++) {
            mix = min(mix, p2[i].first);
            miy = min(miy, p2[i].second);
            mxx = max(mxx, p2[i].first);
            mxy = max(mxy, p2[i].second);
        }
        for (int i = 0; i < 4; i++) {
            double x1 = x - p2[i].first; 
            double y1 = y - p2[i].second; 
            double y2 = y - p2[(i + 1) % 4].second; 
            double x2 = x - p2[(i + 1) % 4].first; 
            res += abs(x1 * y2 - y1 * x2);
        }
        // cerr << res << "\n";
        // cerr << (mxx - mix) * (mxy - miy) << "\n";
        if (res == (mxx - mix) * (mxy - miy)) return 1;
        return 0;
    };
    // cout << fixed << setprecision(2) << x << " " << y << "\n";
    int ok = 0;
    ok |= check2(x, y);
    // cerr << ok << "\n";
    for (int i = 0; i < 4; i++) {
        ok |= check1(p2[i].first, p2[i].second);
        ok |= check2(p1[i].first, p1[i].second);
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}