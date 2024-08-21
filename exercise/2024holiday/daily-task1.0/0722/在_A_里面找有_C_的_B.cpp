#include <bits/stdc++.h>
using namespace std;

struct Node{
    int fa,len,nxt[26];
    Node(){
        for(int i=0;i<26;i++)nxt[i]=0;
        fa=0;
        len=0;
    }
};

template<class T>
struct SAM{
    const int N=1e6+5;
    int cnt,last;
    vector<T> sam;
    SAM(int n):sam(2*n){
        cnt=1;
        last=1;
    }
    SAM():sam(N){
        cnt=1;
        last=1;
    }
    void insert(char a){
        int ch=a-'a';
        int cur=++cnt;
        sam[cnt].len=sam[last].len+1;
        int p=last;
        for(;p&&!sam[p].nxt[ch];p=sam[p].fa)sam[p].nxt[ch]=cur;
        int q=sam[p].nxt[ch];
        if(q==0){
            sam[cur].fa=1;
        }else if(sam[q].len==sam[p].len+1){
            sam[cur].fa=q;
        }else{
            int r=++cnt;
            sam[r]=sam[q];
            sam[r].len=sam[p].len+1;
            for(;p&&sam[p].nxt[ch]==q;p=sam[p].fa)sam[p].nxt[ch]=r;
            sam[cur].fa=sam[q].fa=r;
        }
        last=cur;
    }
    bool check(string s){
        int cur=1;
        for(auto c:s){
            int ch=c-'a';
            if(sam[cur].nxt[ch]==0)return false;
            cur=sam[cur].nxt[ch];
        }
        return true;
    }
};

int T;
void solve() {
    int n;
    cin >> n;
    string a, c;
    cin >> a >> c;
    int m = a.size() + 1;
    vector<int> ans;
    SAM<Node> sam(m);
    for (char ch : a) sam.insert(ch);
    for (int i = 0; i < n; i++) {
        string b1, b2;
        cin >> b1 >> b2;
        if (sam.check(b1)) {
            int p = b2.size() + 1;
            SAM<Node> s2(p);
            for (char ch : b2) s2.insert(ch);
            if (s2.check(c)) ans.push_back(i + 1);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}