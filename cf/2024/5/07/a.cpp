/*
 * Author: Ram
 * Date: 2024-05-07
 * Source: https://codeforces.com/contest/1945/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),p(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>p[i],p[i]--;
    priority_queue<pair<int,int>> q;
    vector<int> v1(n),v2(n);
    for(int i=0;i<n;i++)q.push({a[i],i});
    ll ans=q.top().first,num=1,mi=q.top().first;
    v2[q.top().second]=1;
    q.pop();
    for(int i=0;i<(n+1)/2-1;i++){
        v1[p[i]]=1;
        while(!q.empty()){
            auto [val,j]=q.top();
            q.pop();
            if(!v1[j]){
                v2[j]=1;
                mi=val;
                break;
            }
        }
        if(v2[p[i]]){
            while(!q.empty()){
                auto [val,j]=q.top();
                q.pop();
                if(!v1[j]){
                    v2[j]=1;
                    mi=val;
                    break;
                }
            }
        }
        if(mi*(i+2)>ans){
            ans=mi*(i+2);
            num=i+2;
        }
    }
    cout<<ans<<' '<<num;
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