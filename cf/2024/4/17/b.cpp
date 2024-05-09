#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=4e5+5;
int a[N],nums[N];
int n;

void solve(){
    cin>>n;
    map<int,vector<int>> mp;
    for(int i=0;i<=n;i++)cin>>a[i],mp[a[i]].push_back(i);
    int cnt=-1,ans=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        int x=it->first;
        auto &e=it->second;
        for(int i:e){
            if(cnt++>=i)continue;
            int res=i-cnt;
            if(i%2==0){
                res++;
                if(a);
            }
            ans=max(ans,res);
        }
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