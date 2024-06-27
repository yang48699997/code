/*
 * Author: Ram
 * Date: 2024-05-22
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
struct Node{
    int x,y,z,op;
    Node(int x,int y,int z,int op){
        this->x=x;
        this->y=y;
        this->z=z;
        this->op=op;
    }
};
int T;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<Node>> e(n+1);
    vector<int> mx(n+1);
    vector<int> mi(n+1,1e9);
    int a,b,x,y,z;
    map<int,int> cnt;
    for(int i=0;i<m;i++){
        cin>>a>>b>>x>>y>>z;
        e[a].push_back(Node({x,y,z,b}));
        e[b].push_back(Node({y,x,z,a}));
        mx[a]=max(mx[a],x+z);
        mi[a]=min(mi[a],x);
        mx[b]=max(mx[b],y+z);
        mi[b]=min(mi[b],y);
        if(x>y)swap(x,y);
        if(x+z<=y){
            cnt[x+z]++;
            cnt[y]++;
        }else{
            cnt[(x+y+z)/2]++;
            cnt[(x+y+z)/2+(x+y+z)%2]++;
        }
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        bool ok=true;
        int c=0;
        for(int j=0;j<e[i].size();j++){
            auto [x,y,z,op]=e[i][j];
            if(mx[i]<=mi[op]){
                ok=false;
                break;
            }
            if(z==0&&x==mx[i])c++;
            else if(x+z==mx[i]&&y==x+z-1)c++;
        }
        if(!ok)continue;
        auto it=cnt.lower_bound(mx[i]);
        if(it==cnt.end())ans.push_back(i);
        else if(it->first==mx[i]&&it->second==c){
            it++;
            if(it==cnt.end())ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<' ';
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