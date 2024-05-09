#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define endl '\n'
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type, less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
struct Node{
    int x,y,i;
    Node(){
    }
    Node(int x,int y,int i){
        this->x=x;
        this->y=y;
        this->i=i;
    }
    bool operator< (Node &node)const{
        if(x!=node.x)return x<node.x;
        return y>node.y;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<Node> a(n);
    for(int i=0;i<n;i++){
        int x,t;
        cin>>x>>t;
        t+=x;
        Node node{x,t,i};
        a[i]=node;
    }
    sort(a.begin(),a.end());
    vector<int> ans(n);
    int cnt=n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        auto [x,y,j]=a[i];
        auto it=mp.lower_bound(y);
        if(it==mp.end()){
            ans[j]=0;
            mp[y]=0;
            continue;
        }
        ans[j]=it->second+1;
        if(it!=mp.begin()){
            it--;
            while(it->second<=ans[j]){
            if(it==mp.begin()){
                mp.erase(it--);
                break;
            }else mp.erase(it--);
        }
        }
        
        mp[y]=ans[j];
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}