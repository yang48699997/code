#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct p{
    int l,r,num;
    p(int x=0,int y=0,int z=0):l(x),r(y),num(z+1){}
    bool operator<(const p& pp)const{
        return r>pp.r;
    }
};

void solve(){
    int n;
    cin>>n;
    vector<p> pp(n);
    int l,r;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        pp[i]=p(l,r,i);
    }
    sort(pp.begin(),pp.end(),[](auto &p1,auto &p2){
        if(p1.l!=p2.l)return p1.l<p2.l;
        return p1.r<p2.r;
    });
    vector<int> ans;
    priority_queue<p> q;
    r=0;
    for(int i=0;i<n;i++){
        if(pp[i].l<=r){
            q.push(pp[i]);
            continue;
        }
        while(!q.empty()&&q.top().r<r)q.pop();
        if(!q.empty()){
            ans.push_back(q.top().num);
            q.pop();
            r++;
            i--;
        }
    }
    while(!q.empty()){
        if(q.top().r<r){
            q.pop();
            continue;
        }
        ans.push_back(q.top().num);
        q.pop();
        r++;
    }
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}