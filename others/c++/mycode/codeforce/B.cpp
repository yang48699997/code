#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
#define sp ' '
#define yes "YES"
#define no "NO"
using ll = long long;
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int,null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int mod=998'244'353;
const int MOD=1e9+7;
const int N=4e5+5;
const ll INF=1e18;
const int inf=0x3f3f3f3f;

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
    vector<ll> ans;
    vector<set<int>> e;
    ll res=0;
    SAM(int n):sam(2*n),ans(2*n),e(n*2){
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
            e[1].insert(cur);
            sam[cur].fa=1;
        }else if(sam[q].len==sam[p].len+1){
            e[q].insert(cur);
            sam[cur].fa=q;
        }else{
            int r=++cnt;
            sam[r]=sam[q];
            sam[r].len=sam[p].len+1;
            for(;p&&sam[p].nxt[ch]==q;p=sam[p].fa)sam[p].nxt[ch]=r;
            e[r].insert(q);
            e[r].insert(cur);
            int f=sam[q].fa;
            e[f].erase(e[f].find(q));
            e[f].insert(r);
            sam[cur].fa=sam[q].fa=r;
        }
        ans[cur]=1;
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
    void dfs(int x){
        for(auto nxt:e[x]){
            dfs(nxt);
            ans[x]+=ans[nxt];
        }
        if(ans[x]>1)res=max(res,sam[x].len*ans[x]);
    }
};

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    SAM<Node> sam(n+1);
    ll ans=0;
    for(auto c:s)sam.insert(c);
    sam.dfs(1);
    ans=sam.res;
    cout<<ans;
}

int main(){
	ios::sync_with_stdio(false); 
	cin.tie(0);
	
    solve();
    cout<<endl;

    return 0;
}