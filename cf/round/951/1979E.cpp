#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> p(n);
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        p[i].first=x+y;
        p[i].second=-x+y;
    }
    vector<int> nums(n);
    iota(nums.begin(),nums.end(),0);
    sort(nums.begin(),nums.end(),[&](int a,int b){
        if(p[a].second!=p[b].second)return p[a].second<p[b].second;
        return p[a].first<p[b].first;
    });
    
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