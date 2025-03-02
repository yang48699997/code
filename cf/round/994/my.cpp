#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n;
    string s;
    cin >> n >> s;
    if (s[0] == 's') s[0] = '.';
    if (s[n - 1] == 'p') s[n - 1] = '.';
    set<char> st;
    for (auto c : s) if (c != '.') st.insert(c);
    if (st.size() <= 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
       solve();
    }
    return 0;
}