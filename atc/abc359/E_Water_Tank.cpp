#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
void solve(){ 
    int n;
    cin>>n;
    vector<ll> h(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    ll inf = 2e9;
    h[0]=inf;
    vector<ll> ans(n+1);
    stack<ll> stk;
    stk.push(0);
    for(int i=1;i<=n;i++){
        while(h[i]>=h[stk.top()])stk.pop();
        ans[i]=ans[stk.top()]+h[i]*(i-stk.top());
        stk.push(i);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]+1<<" \n"[i==n];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}