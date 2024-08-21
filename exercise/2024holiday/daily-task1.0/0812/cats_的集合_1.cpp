#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mx = 31;

struct Trie{
    static const int N = 31;
    int cnt;
    Trie *son[2];
    Trie(){
        cnt=0;
        for (int i = 0; i < 2; i++)
            son[i] = nullptr;
    }

    ~Trie(){
        for(Trie *nxt: son)
            if(nxt)
                delete nxt;
    }

    string to_bin(int x){
        string res;
        for (int i = 0; i < N; i++ ){
            int cur = x % 2;
            x /= 2;
            res += '0' + cur;
        }
        reverse(res.begin() ,res.end());
        return res;
    }

    int to_int(string word){
        int res=0;
        for(int i = 0; i < N; i ++){
            res = res * 2 + word[ i ] - '0' ;
        }
        return res;
    }

    void insert(int x){
        string word = to_bin(x);
        Trie *node = this;
        for (auto w : word){
            if (node->son[w - '0'] == nullptr)
                node->son[w - '0'] = new Trie();
            node = node->son[w - '0'];
            node->cnt++;
        }
        this -> cnt++;
    }

    int search(int x){
        string word = to_bin(x);
        Trie *node = this;
        for (auto w : word){
            if (node->son[w - '0'] == nullptr)
                return false;
            node = node->son[w - '0'];
        }
        return node->cnt;
    }

    void erase(int x){
        string word = to_bin(x);
        Trie *node = this;
        for (auto w : word){
            node = node->son[w - '0'];
            node -> cnt--;
        }
        this -> cnt --;
        return ;
    }

    int xor_max(int x){
        string word = to_bin(x);
        Trie *node = this;
        int res=0;
        for (auto w : word){
            if (node->son[(w - '0') ^ 1] == nullptr || node -> son[(w - '0') ^ 1] -> cnt == 0){
                node = node->son[w - '0'];
                res = res * 2;
            }
            else{
                node = node->son[(w - '0') ^ 1];
                res = res * 2 + 1;
            } 
        }
        return res;
    }

};
void solve() {
    int n, q;
    cin >> n >> q;
    Trie t = {};
    vector<int> a(n);
    vector<set<int>> st0(mx); 
    vector<set<int>> st1(mx); 
    int p = 0;
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (st.count(a[i])) continue;
        st.insert(a[i]);
        t.insert(a[i]);
        for (int j = 0; j < mx; j++) {
            if (1 << j & a[i]) st1[j].insert(a[i]);
            else st0[j].insert(a[i]);
        }
    }
    vector<int> l(n + q);
    int tot = 0;
    while (q--) {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1) {
            x ^= p;
            if (st.count(x)) continue;
            st.insert(x);
            t.insert(x);
            for (int i = 0; i < 31; i++) {
                if (1 << i & x) st1[i].insert(x);
                else st0[i].insert(x);
            }
        } else if (opt == 2) {
            tot = 0;
            for (int i = 0; i < mx; i++) {
                if (1 << i & x) {
                    for (auto p : st0[i]) {
                        if (!st.count(p)) continue;
                        st.erase(p);
                        l[tot++] = p;
                        t.erase(p);
                    }
                }
            }
            for (int i = 0; i < tot; i++) {
                for (int j = 0; j < mx; j++) {
                    st0[j].erase(l[i]);
                    st1[j].erase(l[i]);
                }
                l[i] |= x;
                if (st.count(l[i])) continue;
                st.insert(l[i]);
                t.insert(l[i]);
                for (int j = 0; j < mx; j++) {
                    if (1 << j & l[i]) st1[j].insert(l[i]);
                    else st0[j].insert(l[i]);
                }
            }
        } else if (opt == 3) {
            tot = 0;
            for (int i = 0; i < mx; i++) {
                if (!(1 << i & x)) {
                    for (auto p : st1[i]) {
                        if (!st.count(p)) continue;
                        st.erase(p);
                        l[tot++] = p;
                        t.erase(p);
                    }
                }
            }
            for (int i = 0; i < tot; i++) {
                for (int j = 0; j < mx; j++) {
                    st0[j].erase(l[i]);
                    st1[j].erase(l[i]);
                }
                l[i] &= x;
                if (st.count(l[i])) continue;
                st.insert(l[i]);
                t.insert(l[i]);
                for (int j = 0; j < mx; j++) {
                    if (1 << j & l[i]) st1[j].insert(l[i]);
                    else st0[j].insert(l[i]);
                }
            }
        } else if (opt == 4) {
            p ^= x;
        } else {
            x ^= p;
            cout << t.xor_max(x) << "\n";
        }
    }
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