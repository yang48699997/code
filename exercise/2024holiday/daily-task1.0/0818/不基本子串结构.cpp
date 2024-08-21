#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct ex_KMP{
    string s1,s2;
    vector<int> nxt,ex;
    int n,m;
    ex_KMP(string s1,string s2):nxt(s2.length()),ex(s1.length()){
        n=s1.length();
        m=s2.length();
        this->s1=s1;
        this->s2=s2;
        int a=0,p=0;
        nxt[0]=m;
        for(int i=1;i<m;i++){
            if(i>=p||i+nxt[i-a]>=p){
                if(i>=p)p=i;
                while(p<m&&s2[p]==s2[p-i])p++;
                nxt[i]=p-i;
                a=i;
            }else nxt[i]=nxt[i-a];
        }
        a=0,p=0;
        for(int i=0;i<n;i++){
            if(i>=p||i+nxt[i-a]>=p){
                if(i>=p)p=i;
                while(p<n&&p-i<m&&s1[p]==s2[p-i])p++;
                ex[i]=p-i;
                a=i;
            }else ex[i]=nxt[i-a];
        }
    }
};

void solve() {
    string a, b;
    cin >> a >> b;
    if (a.length() < b.length()) swap(a, b);
    int n = a.length();
    int m = b.length();
    ex_KMP k1(a, b);
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (k1.ex[i] == m) cnt1++;
    }    
    if (cnt1 == 1) {
        cout << n << "\n";
        return;
    } else if (cnt1 > 1) {
        cout << "-1\n";
        return;
    }
    int ans = n + m;
    for (int i = 0; i < n; i++) {
        if (k1.ex[i] + i == n) ans = min(ans, m + i);
    }
    ex_KMP k2(b, a);
    for (int i = 0; i < m; i++) {
        if (k2.ex[i] + i == m) ans = min(ans, i + n);
    }
    cout << ans << "\n";
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