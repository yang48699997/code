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
                break;
            } else {
                x ^= nums[i];
            }
        }
        zero = true;
        return;
    }
    T k_min(T t) {
        if (zero) {
            if (t == 1) return min();
            t--;
        }
        vector<T> tmp;
        for (int i = 0; i < bit; i++) {
            if (nums[i]) tmp.emplace_back(nums[i]);
        }
        for (int i = 0; i < tmp.size(); i++) {
            for (int j = 0; j < i; j++) {
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
        return res;
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
    LB b;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        b.insert(x);
    }
    cout << b.max() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}