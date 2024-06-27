#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
struct Node{
    ll x;
    ll d;
    Node(ll x){
        this->x=x;
        this->d=1;
    }
    Node(ll x,ll d){
        this->x=x;
        this->d=d;
    }
    bool operator< (const Node& node)const{
        ll res1=(d*2+1)*x;
        ll res2=(node.d*2+1)*node.x;
        return res1>res2;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll ans=0;
    priority_queue<Node> q;
    for(int i=0;i<n;i++){
        q.push(Node{a[i]});
    }
    for(int i=0;i<n-2;i++){
        auto [x,d]=q.top();
        q.pop();
        q.push(Node{x,d+1});
    }
    while(!q.empty()){
        auto [x,d]=q.top();
        q.pop();
        ans+=x*d*d;
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}