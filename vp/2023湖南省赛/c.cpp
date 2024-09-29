#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node{
    int fa, len, nxt[26];
    Node() {
        for (int i = 0; i < 26; i++) nxt[i] = 0;
        fa = 0;
        len = 0;
    }
};

template<class T>
struct SAM{
    const int N = 1e6+5;
    int cnt, last;
    ll sum;
    vector<T> sam;
    SAM(int n) : sam(2 * n) {
        cnt = 1;
        last = 1;
        sum = 0;
    }
    SAM() : sam(N) {
        cnt = 1;
        last = 1;
        sum = 0;
    }
    void insert(char a) {
        int ch = a - 'a';
        int cur = ++cnt;
        sam[cnt].len = sam[last].len + 1;
        int p = last;
        for (; p && !sam[p].nxt[ch]; p = sam[p].fa) sam[p].nxt[ch] = cur;
        int q = sam[p].nxt[ch];
        if (q == 0) {
            sam[cur].fa = 1;
            sum += sam[cur].len - sam[sam[cur].fa].len;
        } else if (sam[q].len == sam[p].len + 1) {
            sam[cur].fa = q;
            sum += sam[cur].len - sam[sam[cur].fa].len;
        } else {
            int r = ++cnt;
            sum -= sam[q].len - sam[sam[q].fa].len;
            sam[r] = sam[q];
            sam[r].len = sam[p].len + 1;
            sam[cur].fa = sam[q].fa = r;
            sum += sam[cur].len - sam[sam[cur].fa].len;
            sum += sam[q].len - sam[sam[q].fa].len;
            sum += sam[r].len - sam[sam[r].fa].len;
            for (; p && sam[p].nxt[ch] == q; p = sam[p].fa) sam[p].nxt[ch] = r;
        }
        last = cur;
    }
    bool check(const string &s) {
        int cur = 1;
        for(auto c : s) {
            int ch = c - 'a';
            if (sam[cur].nxt[ch] == 0) return false;
            cur = sam[cur].nxt[ch];
        }
        return true;
    }
    ll count() {
        return sum;
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    SAM<Node> sam(n);
    vector<ll> cnt(26);
    for (int i = 0; i < n - m; i++) {
        ll pre = sam.count();
        sam.insert(s[i]);
        cnt[s[i] - 'a'] += sam.count() - pre;
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ll pre = sam.count();
        sam.insert(s[i + n - m]);
        ans += sam.count();
        cnt[s[i + n - m] - 'a'] += sam.count() - pre;
        if (i != 0) ans -= cnt[t[i - 1] - 'a'];
        if (i != 0 && cnt[t[i - 1] - 'a']) ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}