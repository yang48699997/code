/*
 * Author: Ram
 * Date: 2024-05-22
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=1e6+5;
using pii=pair<int,int>;
int fa[N];
int find(int x){
    if(fa[x]==x)return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    fa[y]=x;
}
void solve(){
    int n;
    cin>>n;    
    vector<pii> a(n),b(n);
    vector<int> num(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>b[i].first;
        num[i]=a[i].second=b[i].second=i;
        fa[i]=i;
    }
    sort(num.begin(),num.end(),[&](int x,int y){
        if(a[x].first-a[x].second!=a[y].first-a[y].second)return a[x].first-a[x].second<a[y].first-a[y].second;
        return b[x].first-b[x].second>b[y].first-b[y].second;
    });
    stack<int> stk;
    for(int i:num){
        if(stk.empty()){
            stk.push(i);
            continue;
        }
        if(b[i].first-b[i].second>b[stk.top()].first-b[stk.top()].second){
            stk.push(i);
            continue;
        }else{
            int mx=stk.top();
            merge(i,stk.top());
            stk.pop();
            while(!stk.empty()&&b[i].first-b[i].second<=b[stk.top()].first-b[stk.top()].second){
                merge(i,stk.top());
                stk.pop();
            }
            stk.push(mx);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)if(find(i)==i)ans++;
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}