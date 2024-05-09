/*
 * Author: Ram
 * Date: 2024-04-28
 * Source: https://codeforces.com/contest/1937/problem/C
*/
#include <bits/stdc++.h>
using namespace std;


int T;
void solve(){
    int n;
    cin>>n;
    int x=0,cur=1;
    while(cur<n){
        cout<<"? "<<x<<' '<<x<<' '<<cur<<' '<<cur<<endl;
        char c;
        cin>>c;
        if(c=='<')x=cur;
        cur++;
    }
    cur=0;
    int y=x;
    vector<int> res;
    while(cur<n){
        cout<<"? "<<x<<' '<<y<<' '<<x<<' '<<cur<<endl;
        char c;
        cin>>c;
        if(c=='<'){
            res.clear();
            res.push_back(cur);
            y=cur;
        }
        else if(c=='='){
            res.push_back(cur);
        }
        cur++;
    }
    int ans=res[0];
    cur=1;
    while(cur<res.size()){
        cout<<"? "<<ans<<' '<<ans<<' '<<res[cur]<<' '<<res[cur]<<endl;
        char c;
        cin>>c;
        if(c=='>')ans=res[cur];
        cur++;
    }
    cout<<'!'<<' '<<ans<<' '<<x<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
        cout<<'\n';
    }
    return 0;
}