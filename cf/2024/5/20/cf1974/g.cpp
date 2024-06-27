/*
 * Author: Ram
 * Date: 2024-05-21
 * Source: https://codeforces.com/contest/1974/problem/G
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,x;
    cin>>n>>x;
    priority_queue<int> q;
    int ans=0;
    int l=0,y;
    while(n--){
        cin>>y;
        if(l>=y){
            ans++;
            l-=y;
            q.push(y);
        }else if(!q.empty()&&q.top()>y){
            l+=q.top()-y;
            q.pop();
            q.push(y);
        }
        l+=x;
    }
    cout<<ans;
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