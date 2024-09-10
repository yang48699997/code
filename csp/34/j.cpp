#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct Basis{
    vector<T> nums;
    int bit;
    bool zero;
    T base;
    Basis() : bit(sizeof(T) * 8 - 1), nums(sizeof(T) * 8 - 1), zero(false), base(1) {}
    void insert(T x) {
        for (int i = bit - 1; i >= 0; i--) {
            if (!(base << i & x)) continue;
            if (!(base << i & nums[i])) {
                nums[i] = x;
                return;
            } else {
                x ^= nums[i];
            }
        }
        zero = true;
        return;
    }
    T k_min(T t) {
        if (t <= 0) return -1;
        if (zero) {
            if (t == 1) return min();
            t--;
        }
        vector<T> tmp;
        for (int i = 0; i < bit; i++) {
            if (nums[i]) tmp.emplace_back(nums[i]);
        }
        for (int i = 0; i < tmp.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if ((tmp[i] ^ tmp[j]) < tmp[i]) tmp[i] ^= tmp[j];
            }
        }
        T res = 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (t & 1) {
                res ^= tmp[i];
            }
            t >>= 1;
        }
        if (t) return -1;
        return res;
    }
    T k_max(T t) {
        int cnt = 0;
        for (int i = 0; i < bit; i++) {
            if (nums[i]) cnt++;
        }
        T tot = base << cnt;
        if (!zero) tot--;
        return k_min(tot - t + 1);
    }
    T max() {
        T res = 0;
        for (int i = bit - 1; i >= 0; i--) {
            if (!(base << i & res)) {
                res ^= nums[i];
            }
        }
        return res;
    }
    T min() {
        T res = 0;
        if (zero) return res;
        for (int i = 0; i < bit; i++) {
            if (nums[i] > res) {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};

using LB = Basis<ll>;


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll res = 0;
    for (int i = 0; i < n; i++) cin >> a[i], res ^= a[i];
    for (int i = 0; i < n; i++) cin >> b[i], res ^= b[i];

    LB lb;
    ll p = 0;
    for (int i = 0; i < n; i++) {
        lb.insert(a[i] ^ b[i]);
        p ^= a[i];
    }
    int ok = 0;
    for (int i = 62; i >= 0; i--) {
        if (ok) {
            if (1LL << i & res) {
                if (1LL << i & p) {
                    if (lb.nums[i]) p ^= lb.nums[i];
                }
            } else {
                if (1LL << i & p) {
                    if (lb.nums[i]) p ^= lb.nums[i];
                }
            }
        } else {
            if (1LL << i & res) {
                ok = 1;
                if (1LL << i & p) continue;
                else p ^= lb.nums[i];
            } else if (1LL << i & p){
                if (lb.nums[i]) {
                    p ^= lb.nums[i];
                }
            }
        }
    }

    cout << max(p, p ^ res) << "\n";
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