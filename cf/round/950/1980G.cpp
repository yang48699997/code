#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
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
        this -> cnt ++;
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
                res = res * 2 + w - '0';
            }
            else{
                node = node->son[(w - '0') ^ 1];
                res = res * 2 + 1 - (w - '0');
            } 
        }
        return res;
    }

};

int T;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> e(n);
    int x,y,val;
    for(int i=1;i<n;i++){
        cin>>x>>y>>val;
        x--,y--;
        e[x].emplace_back(y,val);
        e[y].emplace_back(x,val);
    }
    vector<int> dep(n),v(n);
    auto dfs=[&](auto && self,int x,int fa)-> void{
        for(auto [nxt,val]:e[x]){
            if(nxt==fa)continue;
            dep[nxt]=dep[x]+1;
            v[nxt]=v[x]^val;
            self(self,nxt,x);
        }
    };
    dfs(dfs,0,-1);
    Trie tr0,tr1;
    for(int i=0;i<n;i++){
        if(dep[i]%2)tr1.insert(v[i]);
        else tr0.insert(v[i]);
    }
    int lazy=0;
    while(m--){
        char c;
        cin>>c;
        if(c=='^'){
            cin>>x;
            lazy^=x;
        }else{
            cin>>x>>y;
            x--;
            y^=v[x];
            if(dep[x]%2)y^=lazy,tr1.erase(v[x]);
            else tr0.erase(v[x]);
            int res=0;
            if(tr0.cnt!=0)res=y^tr0.xor_max(y);
            y^=lazy;
            if(tr1.cnt!=0)res=max(res,y^tr1.xor_max(y));
            if(dep[x]%2)tr1.insert(v[x]);
            else tr0.insert(v[x]);
            cout<<res<<' ';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
        cout<<endl;
    }
    return 0;
}