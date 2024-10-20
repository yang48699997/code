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

struct DSU{
    vector<int> fa, sz;
    
    DSU(int n) : fa(n), sz(n, 1) {
        for ( int i = 0; i < n; i++) fa[i]=i;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if( x == y) return false;
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
    
    int size(int x) {
        x = find(x);
        return sz[x];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<double, double>> p1, p2;
    for (int i = 0; i < n; i++) {
        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        p1.emplace_back(x1, y1);
        p2.emplace_back(x2, y2);
    }
    double ans = 0;
    
    auto cal = [](double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4) -> Point<double> {
        if (x1 == x2) {
            double x = x1;
            double m2 = (y4 - y3) / (x4 - x3);
            double b2 = y3 - m2 * x3;
            double y = m2 * x1 + b2;
            return {x, y};
        } else if (x3 == x4) {
            double x = x3;
            double m1 = (y2 - y1) / (x2 - x1);
            double b1 = y1 - m1 * x1;
            double y = m1 * x3 + b1;
            return {x, y};
        }
        double m1 = (y2 - y1) / (x2 - x1);
        double b1 = y1 - m1 * x1;
        double m2 = (y4 - y3) / (x4 - x3);
        double b2 = y3 - m2 * x3;

        double x = (b2 - b1) / (m1 - m2);
        double y = m1 * x + b1;
        return {x, y};
    };

        
    DSU dsu(n);

    for (int i = 0; i < n; i++) {
        double x1 = p1[i].first;
        double y1 = p1[i].second;
        double x2 = p2[i].first;
        double y2 = p2[i].second;
        for (int j = i + 1; j < n; j++) {
            double x3 = p1[j].first;
            double y3 = p1[j].second;
            double x4 = p2[j].first;
            double y4 = p2[j].second;
            if ((y4 - y3) * (x2 - x1) == (x4 - x3) * (y2 - y1)) {
                dsu.merge(i, j);
                continue;
            }
            for (int k = j + 1; k < n; k++) {
                double x5 = p1[k].first;
                double y5 = p1[k].second;
                double x6 = p2[k].first;
                double y6 = p2[k].second;
                if ((y6 - y5) * (x2 - x1) == (x6 - x5) * (y2 - y1)) continue;
                if ((y4 - y3) * (x6 - x5) == (x4 - x3) * (y6 - y5)) continue;
                Point<double> p1 = cal(x1, x2, x3, x4, y1, y2, y3, y4);
                Point<double> p2 = cal(x1, x2, x5, x6, y1, y2, y5, y6);
                Point<double> p3 = cal(x5, x6, x3, x4, y5, y6, y3, y4);
                double res = ((p2 - p1) ^ (p3 - p1));
                res = abs(res) / 2;
                ans = max(ans, res);
            }
        }
    }

    vector<vector<pair<int, int>>> pp(n);
    for (int i = 0; i < n; i++) {
        pp[dsu.find(i)].push_back(p1[i]);
        pp[dsu.find(i)].push_back(p2[i]);
    }
    for (int i = 0; i < n; i++) {
        if (pp[i].size() <= 2) continue;
        int m = pp[i].size() / 2;
        vector<int> nums(m);
        iota(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), [&](int xx1, int xx2) {
            double x1 = pp[i][xx1 * 2].first;
            double x3 = pp[i][xx2 * 2].first;
            double x2 = pp[i][xx1 * 2 + 1].first;
            double x4 = pp[i][xx2 * 2 + 1].first;
            double y1 = pp[i][xx1 * 2].second;
            double y3 = pp[i][xx2 * 2].second;
            double y2 = pp[i][xx1 * 2 + 1].second;
            double y4 = pp[i][xx2 * 2 + 1].second;
            if (x1 == x2) {
                return x1 < x3;
            }
            double m1 = (y2 - y1) / (x2 - x1);
            double b1 = y1 - m1 * x1;
            double m2 = (y4 - y3) / (x4 - x3);
            double b2 = y3 - m2 * x3;
            return b1 < b2;
        });
        for (int j = i + 1; j < n; j++) {
            if (pp[j].size() <= 2) continue;
            int mm = pp[j].size() / 2;
            vector<int> nums2(mm);
            iota(nums2.begin(), nums2.end(), 0);
            sort(nums2.begin(), nums2.end(), [&](int xx1, int xx2) {
                double x1 = pp[j][xx1 * 2].first;
                double x3 = pp[j][xx2 * 2].first;
                double x2 = pp[j][xx1 * 2 + 1].first;
                double x4 = pp[j][xx2 * 2 + 1].first;
                double y1 = pp[j][xx1 * 2].second;
                double y3 = pp[j][xx2 * 2].second;
                double y2 = pp[j][xx1 * 2 + 1].second;
                double y4 = pp[j][xx2 * 2 + 1].second;
                if (x1 == x2) {
                    return x1 < x3;
                }
                double m1 = (y2 - y1) / (x2 - x1);
                double b1 = y1 - m1 * x1;
                double m2 = (y4 - y3) / (x4 - x3);
                double b2 = y3 - m2 * x3;
                return b1 < b2;
            });
            Point<double> p1 = cal(pp[i][nums[0] * 2].first, pp[i][nums[0] * 2 + 1].first, pp[j][nums2[0] * 2].first, pp[j][nums2[0] * 2 + 1].first, pp[i][nums[0] * 2].second, pp[i][nums[0] * 2 + 1].second, pp[j][nums2[0] * 2].second, pp[j][nums2[0] * 2 + 1].second);
            swap(nums2[0], nums2.back());
            Point<double> p2 = cal(pp[i][nums[0] * 2].first, pp[i][nums[0] * 2 + 1].first, pp[j][nums2[0] * 2].first, pp[j][nums2[0] * 2 + 1].first, pp[i][nums[0] * 2].second, pp[i][nums[0] * 2 + 1].second, pp[j][nums2[0] * 2].second, pp[j][nums2[0] * 2 + 1].second);
            swap(nums[0], nums.back());
            Point<double> p3 = cal(pp[i][nums[0] * 2].first, pp[i][nums[0] * 2 + 1].first, pp[j][nums2[0] * 2].first, pp[j][nums2[0] * 2 + 1].first, pp[i][nums[0] * 2].second, pp[i][nums[0] * 2 + 1].second, pp[j][nums2[0] * 2].second, pp[j][nums2[0] * 2 + 1].second);
            double res = ((p3 - p1) ^ (p2 - p1));
            res = abs(res);
            ans = max(ans, res);
        }
    }

    cout << fixed << setprecision(8) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}