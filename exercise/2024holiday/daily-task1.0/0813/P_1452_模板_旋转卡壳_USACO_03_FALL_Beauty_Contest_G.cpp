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

template<class T>
struct Convex{
    int n, m;
    vector<T> p, ans;
    T point;
    Convex(vector<T> &pp) : ans(pp.size() + 1) {
        n = pp.size();
        m = 0;
        p = pp;
        point = T(p[0].x, p[0].y);
        for(int i = 1; i < n; i++) {
            double x = p[i].x, y = p[i].y;
            if(x < point.x) {
                point.x = x;
                point.y = y;
            }else if(x == point.x && y < point.y) {
                point.x = x;
                point.y = y;
            }
        }
    }
    void get_ans() {
        sort(p.begin(), p.end(), [&](auto a,auto b) {
            double res = (a - point) ^ (b - point);
            if(res > 0) return true;
            else if(res == 0 && a.dis(point) < b.dis(point)) return true;
            return false;
        });
        int i=0;
        while(i < n) {
            if(m < 2) {
                ans[m++] = p[i++];
                continue;
            }
            if(((ans[m - 1] - ans[m - 2]) ^ (p[i] - ans[m - 1])) > 0) {
                ans[m++] = p[i++];
            } else m--;
        }
    }
    ll d() {
        int j = 1;
        double res = ans[0].dis(ans[1]);
        ans[m] = ans[0];
        for (int i = 0; i < m; i++) {
            while (((ans[i] - ans[j]) ^ (ans[i + 1] - ans[j])) < ((ans[i] - ans[j + 1]) ^ (ans[i + 1] - ans[j + 1]))) {
                j = (j + 1) % m;
            }
            res = max({res, ans[i].dis(ans[j]), ans[i + 1].dis(ans[j])});
        }
        return res;
    }
};
// int rotating_calipers(){//旋转卡壳同上
//     int j=1,ans=0;
//     for(int i=0;i<m;++i){
//         while(cross(ch[i],ch[i+1],ch[j])<cross(ch[i],ch[i+1],ch[j+1])) j=(j+1)%m;
//         ans=max(ans,max(dis(ch[i],ch[j]),dis(ch[i+1],ch[j])));
//     }
//     return ans;
// }
using C = Convex<Point<double>>;

void solve() {
    int m;
    cin >> m;
    vector<Point<double>> p2;
    for (int i = 0; i < m; i++) {
        double x, y;
        cin >> x >> y;
        p2.push_back({x, y});
    }
    C c2(p2);
    c2.get_ans();
    ll ans = c2.d();

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}