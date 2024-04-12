/*
 * Author: Ram
 * Date: 2024-04-11
 * Source: https://codeforces.com/gym/105053/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n*2);
    for(int i=0;i<n*2;i++){
        cin>>a[i];
    }
    vector<int> l,ans(n+1),v(n*2),f(n+1);
    priority_queue<int> q1,q2;
    for(int i=0;i<n*2;i++){
        if(a[i]>0){
            l.push_back(i);
            f[a[i]]=i;
            continue;
        }
        if(v[-a[i]]==0){
            if(q1.empty()||q1.top()<f[-a[i]]){
                while(l.size()&&l.back()>f[-a[i]]){
                    int x=l.back();
                    v[a[x]]=2;
                    l.pop_back();
                    q2.push(x);
                }
                l.pop_back();
                ans[-a[i]]=1;
            }else if(q2.empty()||q2.top()<f[-a[i]]){
                while(l.size()&&l.back()>f[-a[i]]){
                    int x=l.back();
                    v[a[x]]=1;
                    l.pop_back();
                    q1.push(x);
                }
                l.pop_back();
                ans[-a[i]]=2;
            }else {
                cout<<"*";
                return;
            }
        }else if(v[-a[i]]==1){
            while(l.size()&&l.back()>f[-a[i]]){
                int x=l.back();
                v[a[x]]=2;
                l.pop_back();
                q2.push(x);
            }
            if(q1.empty()||q1.top()!=f[-a[i]]){
                cout<<"*";
                return;
            }else{
                ans[-a[i]]=1;
            }
        }else{
            while(l.size()&&l.back()>f[-a[i]]){
                int x=l.back();
                v[a[x]]=2;
                l.pop_back();
                q1.push(x);
            }
            if(q2.empty()||q2.top()!=f[-a[i]]){
                cout<<"*";
                return;
            }else{
                ans[-a[i]]=2;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==1)cout<<"G";
        else cout<<"S";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}