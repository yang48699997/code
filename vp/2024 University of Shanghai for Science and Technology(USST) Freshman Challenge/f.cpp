#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string to_h(ll x) {
    string s;
    while (x) {
        s += (char)('a' + x % 16);
        x /= 16;
    }
    while (s.size() < 20) s += 'a';
    reverse(s.begin(), s.end());
    return s;
}

struct Trie {
    static const int N = 31;
    int cnt;
    Trie *son[16];
    Trie(){
        cnt=0;
        for (int i = 0; i < 16; i++) son[i] = nullptr;
    }
    ~Trie(){
        for(Trie *nxt: son) {
            if(nxt) delete nxt;
        }
    }

    void insert(string word, int p){
        Trie *node = this;
        for (auto w : word){
            if (node -> son[w - 'a'] == nullptr) node -> son[w - 'a'] = new Trie();
            node = node->son[w - 'a'];
        }
        node -> cnt = p;
    }

    int xor_max(string word){
        Trie *node = this;
        int res=0;
        for (auto w : word){
            int p = w - 'a';
            int mx = -1;
            int nxt = -1;
            for (int i = 0; i < 16; i++) {
                if (node -> son[i] == nullptr) continue;
                int now = (i + p) % 16;
                if (now > mx) {
                    mx = now;
                    nxt = i;
                }
            }
            node = node -> son[nxt];
        }
        return node -> cnt;
    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    Trie t{};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] - '0'>= 0 && s[j] - '0' <= 9) s[j] = (char)(s[j] - '0' + 'a');
            else s[j] = (char)(s[j] - 'A' + 10 + 'a');
        }
        reverse(s.begin(), s.end());
        while (s.size() < 20) s += 'a';
        reverse(s.begin(), s.end());
        t.insert(s, i + 1);
    }
    while (q--) {
        ll x;
        cin >> x;
        string s = to_h(x);
        cout << t.xor_max(s) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}