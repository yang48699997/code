#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct Point{
    T x, y;
    Point(){
        this -> x = 0;
        this -> y = 0;
    }
    Point(T x, T y) {
        this -> x = x;
        this -> y = y;
    }
    Point operator +(const Point& p) const {
        return Point{x + p.x, y + p.y};
    }
    Point operator -(const Point& p) const {
        return Point{x - p.x, y - p.y};
    }
    T operator *(const Point& p) const {
        T res = x * p.x + y * p.y;
    }
    T operator ^(const Point& p) const {
        T res = x * p.y - y * p.x;
        return res;
    }
    bool operator == (const Point& p) const {
        if(x != p.x) return false;
        if(y != p.y) return false;
        return true;
    }
    T dis(const Point &p){
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<Point<double>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].y;
        p[i].x = i;
    }
    vector<Point<double>> P;
    P.emplace_back(p[0]);
    P.emplace_back(p[1]);
    int m = 2;
    for (int i = 2; i < n; i++) {
        while (m > 1) {
            if (((P[m - 1] - P[m - 2]) ^ (p[i] - P[m - 1])) > 0) {
                m--;
                P.pop_back();
            } else break;
        }
        P.emplace_back(p[i]);
        m++;
    }
    int l = m - 1;
    vector<pair<ll, ll>> ask(q);
    for (int i = 0; i < q; i++) {
        cin >> ask[i].first >> ask[i].second;
    }
    vector<int> nums(q);
    vector<ll> ans(q);
    iota(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), [&](int x1, int x2){
        return ask[x1].second < ask[x2].second;
    });

    for (int i : nums) {
        ll s = ask[i].first;
        ll d = ask[i].second;
        while (l > 0) {
            if (P[l].y - P[l - 1].y < d * (P[l].x - P[l - 1].x)) l--;
            else {
                break;
            }
        }
        ans[i] = s - P[l].y + d * P[l].x; 
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}